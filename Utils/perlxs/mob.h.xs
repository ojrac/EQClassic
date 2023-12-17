#include "features.h"
#ifdef EMBPERL
#include "Logger.h"
#include "embperl.h"

typedef const char Const_char;

#include "mob.h"

#ifdef THIS     /* this macro seems to leak out on some systems */
#undef THIS        
#endif


MODULE = Mob   PACKAGE = Mob

PROTOTYPES: ENABLE



