#if BP_LAN == BP_LAN_IT
  #define BP_ERROR_STATEMENT           "istruzione sconosciuta"
  #define BP_ERROR_SYMBOL              "simbolo sconosciuto"
  #define BP_ERROR_VARIABLE_GET        "accesso variable non consentito"
  #define BP_ERROR_VARIABLE_SET        "aggiornamento variabile non consentito"
  #define BP_ERROR_FUNCTION_CALL       "massima profondità chiamata a funzione raggiunta"
  #define BP_ERROR_FUNCTION_DEFINITION "definizione funzione non trovata"
  #define BP_ERROR_FUNCTION_END        "fine funzione non trovata"
  #define BP_ERROR_PARAMETERS          "lista parametri troppo lunga"
  #define BP_ERROR_RETURN              "chiamata a return non consentita"
  #define BP_ERROR_CYCLE_MAX           "massima profondità cycle raggiunta"
  #define BP_ERROR_CYCLE_NEXT          "next non consentito"
  #define BP_ERROR_WHILE_MAX           "massima profondità while raggiunta"
  #define BP_ERROR_REDO                "chiamata a redo non consentita"
  #define BP_ERROR_BLOCK               "fine blocco condizione non trovato"
#endif
