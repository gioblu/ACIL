#include "BCC.h"
#include "BIPLAN.h"

BCC compiler;
BIPLAN_Interpreter interpreter;

bool error = false;

void error_callback(char *position, const char *string) {
  Serial.print("error: ");
  Serial.print(string);
  if(position) {
    Serial.print(" ");
    Serial.print(*position);
    Serial.print(" at position ");
    Serial.print(position - interpreter.program_start);
  }
  Serial.println();
  error = true;
};

char program[] =
"# BIPLAN language functions test \n\
print \"\nBIPLAN CR.1 language functions test start...\" \n\
print \"\nmillis: \", millis \n\
print \"\ndigitalRead 13: \", digitalRead 13 \n\
print \"\nanalogRead 0: \", analogRead 0 \n\
print \"\nrandom 100: \", random 100 \n\
print \"\nsqrt 81: \", sqrt 81 \n\
print \"\npinMode 13, OUTPUT: \" \n\
pinMode 13, OUTPUT \n\
print \"\nNow blink 5 times: \" \n\
for $i = 0 to 4 \n\
  print \"\nBLINK\" \n\
  digitalWrite 13, HIGH \n\
  delay 1000 \n\
  digitalWrite 13, LOW \n\
  delay 1000 \n\
next \n\
print \"\n\BIPLAN language functions test finished.\" \n\
stop\n";

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(115200);
  // Show human readable input program
  Serial.print("\nBIPLAN human-readable source:\n\n");
  Serial.print(program);
  uint16_t length = strlen(program);
  // Print stats
  Serial.println("\n--------------------------");
  Serial.print("Program length: ");
  Serial.print(length);
  Serial.println(" bytes");
  uint32_t time = millis();
  // Compile
  Serial.print("\nBCC compilation result:\n\n");
  compiler.error_callback = error_callback;
  compiler.run(program);
  // Print compiled source
  Serial.print("\nBIPLAN machine language:\n\n");
  Serial.print(program);
  uint16_t new_length = strlen(program);
  // Print Stats
  Serial.println("\n\n--------------------------");
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
  // Initialize interpreter
  interpreter.initialize(
    program,
    error_callback,
    &Serial,
    &Serial,
    &Serial
  );
  // Check for compilation errors
  if(error) {
    interpreter.ended = true;
    Serial.println("Fix your code and retry.");
  }
}

void loop() {
  while(!interpreter.ended)
    interpreter.run();
  while(true);
}
