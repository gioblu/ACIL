#include "BCC.h"
#include "BIPLAN.h"

BCC compiler;
BIPLAN_Interpreter interpreter;

bool error = false;

void error_callback(char *position, const char *string) {
  if(position) Serial.print("Runtime error: ");
  else Serial.print("Compilation error: ");
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
"# Unary test \n\
print \"Chained unary test:\n\" \n\
$unary = 0 \n\
print \"Expected: 2 - 0\n\" \n\
print ++++$unary----, \" - \",  $unary, \"\n\" \n\
print \"Expected: 2 - 1\n\" \n\
print ++++$unary--, \" - \", $unary, \"\n\" \n\
print \"Expected: 2 - 5\n\" \n\
print --++++$unary++++++, \" - \", $unary, \"\n\" \n\
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
  Serial.println(" bytes\n");
  uint32_t time = millis();
  // Compile
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
