#if BP_LAN == BP_LAN_EN
  #define BP_ERROR_STATEMENT           "unexpected statement"
  #define BP_ERROR_SYMBOL              "unexpected symbol"
  #define BP_ERROR_VARIABLE_GET        "variable access out of bound"
  #define BP_ERROR_VARIABLE_SET        "variable update out of bound"
  #define BP_ERROR_FUNCTION_CALL       "function call maximum depth exceeded"
  #define BP_ERROR_FUNCTION_DEFINITION "function definition not found"
  #define BP_ERROR_FUNCTION_END        "function end not found"
  #define BP_ERROR_PARAMETERS          "parameter list too long"
  #define BP_ERROR_RETURN              "non matching return"
  #define BP_ERROR_CYCLE_MAX           "cycle maximum depth exceeded"
  #define BP_ERROR_CYCLE_NEXT          "non matching next"
  #define BP_ERROR_WHILE_MAX           "while maximum depth exceeded"
  #define BP_ERROR_REDO                "non matching redo"
  #define BP_ERROR_BLOCK               "expected condition end not found"
#endif
