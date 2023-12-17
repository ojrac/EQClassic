#include "features.h"
#ifdef EMBPERL
#include "Logger.h"
#include "embperl.h"

typedef const char Const_char;

#include "npc.h"

#ifdef THIS     /* this macro seems to leak out on some systems */
#undef THIS        
#endif


MODULE = NPC   PACKAGE = NPC

PROTOTYPES: ENABLE



