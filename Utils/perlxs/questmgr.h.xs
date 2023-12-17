
#include "features.h"
#ifdef EMBPERL
#include "Logger.h"
#include "embperl.h"

#include "client.h"
#include "mob.h"
#include "questmgr.h"

#ifdef THIS	/* this macro seems to leak out on some systems */
#undef THIS
#endif

MODULE = QuestManager   PACKAGE = QuestManager

PROTOTYPES: ENABLE



