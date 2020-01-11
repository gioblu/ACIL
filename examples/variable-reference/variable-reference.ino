#include "BCC.h"
#include "BIPLAN.h"

BCC    bcc;
BIPLAN_Interpreter interpreter;

void error_callback(char *position, const char *string) {
  Serial.print("error: ");
  Serial.print(string);
  Serial.print(" ");
  Serial.print(*position);
  Serial.print(" at position ");
  Serial.println(position - interpreter.program_start);
};

char program[] =
"# Variables \n\
$a = 10\n\
$b = 22\n\
$c = 14\n\
$d = 9\n\
print \"Variables initial state \n\" \n\
# Print all variables \n\
for $i = 0 to 3 \n\
  print $[$i], \"\n\" \n\
next \n\
# Set all variables \n\
for $i = 0 to 3 \n\
  $[$i] = $i \n\
next \n\
print \"Variables state changed by reference \n\" \n\
# Print all variables \n\
for $i = 0 to 3 \n\
  print $[$i], \"\n\" \n\
next \n\
end\n";

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(115200);
  Serial.print(program);
  uint16_t length;
  for(length = 0; program[length] != 0; length++);
  Serial.println("--------------------------");
  Serial.print("Program length: ");
  Serial.print(length);
  Serial.println(" bytes");
  Serial.println();
  uint32_t time = millis();

  bcc.compile(program);
  interpreter.initialize(
    program,
    error_callback,
    &Serial,
    &Serial,
    &Serial
  );

  Serial.print(program);
  uint16_t new_length;
  for(new_length = 0; program[new_length] != 0; new_length++);
  Serial.println("--------------------------");
  Serial.print("Compilation duration: ");
  Serial.print(millis() - time);
  Serial.println(" milliseconds");
  Serial.print("BIPLAN program length: ");
  Serial.print(length);
  Serial.println(" bytes");
  Serial.print("BIPLAN compiled program length: ");
  Serial.print(new_length);
  Serial.println(" bytes");
  Serial.print("Reduction: ");
  Serial.print(100 - (new_length * 100.0) / length);
  Serial.println("%");
  Serial.println("Program output:");
  Serial.println();
}

void loop() {
  do {
    interpreter.run();
  } while(!interpreter.finished());
  while(true);
}
