/*
 * This file was generated automatically by xsubpp version 1.9508 from the
 * contents of tmp. Do not edit this file, edit tmp instead.
 *
 *		ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#include "features.h"
#ifdef EMBPERL
#include "Logger.h"
#include "embperl.h"

#include "entity.h"
#include "EntityList.h"

#ifdef THIS	 /* this macro seems to leak out on some systems */
#undef THIS		
#endif



XS(XS_EntityList_GetMob); /* prototype to pass -Wmissing-prototypes */
XS(XS_EntityList_GetMob)
{
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: EntityList::GetMob(THIS, name)");
	{
		EntityList *		THIS;
		Mob *		RETVAL;
		char*		name = (char *)SvPV_nolen(ST(1));

		if (sv_derived_from(ST(0), "EntityList")) {
			IV tmp = SvIV((SV*)SvRV(ST(0)));
			THIS = INT2PTR(EntityList *,tmp);
		}
		else
			Perl_croak(aTHX_ "THIS is not of type EntityList");
		if(THIS == NULL)
			Perl_croak(aTHX_ "THIS is NULL, avoiding crash.");

		RETVAL = THIS->GetMob(name);
		ST(0) = sv_newmortal();
		sv_setref_pv(ST(0), "Mob", (void*)RETVAL);
	}
	XSRETURN(1);
}


XS(XS_EntityList_GetMobByNpcTypeID); /* prototype to pass -Wmissing-prototypes */
XS(XS_EntityList_GetMobByNpcTypeID)
{
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: EntityList::GetMobByNpcTypeID(THIS, get_id)");
	{
		EntityList *		THIS;
		Mob *		RETVAL;
		int32		get_id = (int32)SvUV(ST(1));

		if (sv_derived_from(ST(0), "EntityList")) {
			IV tmp = SvIV((SV*)SvRV(ST(0)));
			THIS = INT2PTR(EntityList *,tmp);
		}
		else
			Perl_croak(aTHX_ "THIS is not of type EntityList");
		if(THIS == NULL)
			Perl_croak(aTHX_ "THIS is NULL, avoiding crash.");

		RETVAL = THIS->GetMobByNpcTypeID(get_id);
		ST(0) = sv_newmortal();
		sv_setref_pv(ST(0), "Mob", (void*)RETVAL);
	}
	XSRETURN(1);
}


XS(XS_EntityList_GetClientByName); /* prototype to pass -Wmissing-prototypes */
XS(XS_EntityList_GetClientByName)
{
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: EntityList::GetClientByName(THIS, name)");
	{
		EntityList *		THIS;
		Client *		RETVAL;
		char *		name = (char *)SvPV_nolen(ST(1));

		if (sv_derived_from(ST(0), "EntityList")) {
			IV tmp = SvIV((SV*)SvRV(ST(0)));
			THIS = INT2PTR(EntityList *,tmp);
		}
		else
			Perl_croak(aTHX_ "THIS is not of type EntityList");
		if(THIS == NULL)
			Perl_croak(aTHX_ "THIS is NULL, avoiding crash.");

		RETVAL = THIS->GetClientByName(name);
		ST(0) = sv_newmortal();
		sv_setref_pv(ST(0), "Client", (void*)RETVAL);
	}
	XSRETURN(1);
}


XS(XS_EntityList_GetClientByAccID); /* prototype to pass -Wmissing-prototypes */
XS(XS_EntityList_GetClientByAccID)
{
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: EntityList::GetClientByAccID(THIS, accid)");
	{
		EntityList *		THIS;
		Client *		RETVAL;
		int32		accid = (int32)SvUV(ST(1));

		if (sv_derived_from(ST(0), "EntityList")) {
			IV tmp = SvIV((SV*)SvRV(ST(0)));
			THIS = INT2PTR(EntityList *,tmp);
		}
		else
			Perl_croak(aTHX_ "THIS is not of type EntityList");
		if(THIS == NULL)
			Perl_croak(aTHX_ "THIS is NULL, avoiding crash.");

		RETVAL = THIS->GetClientByAccID(accid);
		ST(0) = sv_newmortal();
		sv_setref_pv(ST(0), "Client", (void*)RETVAL);
	}
	XSRETURN(1);
}


XS(XS_EntityList_ClearClientPetitionQueue); /* prototype to pass -Wmissing-prototypes */
XS(XS_EntityList_ClearClientPetitionQueue)
{
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: EntityList::ClearClientPetitionQueue(THIS)");
	{
		EntityList *		THIS;

		if (sv_derived_from(ST(0), "EntityList")) {
			IV tmp = SvIV((SV*)SvRV(ST(0)));
			THIS = INT2PTR(EntityList *,tmp);
		}
		else
			Perl_croak(aTHX_ "THIS is not of type EntityList");
		if(THIS == NULL)
			Perl_croak(aTHX_ "THIS is NULL, avoiding crash.");

		THIS->ClearClientPetitionQueue();
	}
	XSRETURN_EMPTY;
}


XS(XS_EntityList_Clear); /* prototype to pass -Wmissing-prototypes */
XS(XS_EntityList_Clear)
{
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: EntityList::Clear(THIS)");
	{
		EntityList *		THIS;

		if (sv_derived_from(ST(0), "EntityList")) {
			IV tmp = SvIV((SV*)SvRV(ST(0)));
			THIS = INT2PTR(EntityList *,tmp);
		}
		else
			Perl_croak(aTHX_ "THIS is not of type EntityList");
		if(THIS == NULL)
			Perl_croak(aTHX_ "THIS is NULL, avoiding crash.");

		THIS->Clear();
	}
	XSRETURN_EMPTY;
}


XS(XS_EntityList_Message); /* prototype to pass -Wmissing-prototypes */
XS(XS_EntityList_Message)
{
	dXSARGS;
	if (items < 4)
		Perl_croak(aTHX_ "Usage: EntityList::Message(THIS, to_guilddbid, type, message, ...)");
	{
		EntityList *		THIS;
		int32		to_guilddbid = (int32)SvUV(ST(1));
		MessageFormat		type = (MessageFormat)SvUV(ST(2));
		char*		message = (char *)SvPV_nolen(ST(3));

		if (sv_derived_from(ST(0), "EntityList")) {
			IV tmp = SvIV((SV*)SvRV(ST(0)));
			THIS = INT2PTR(EntityList *,tmp);
		}
		else
			Perl_croak(aTHX_ "THIS is not of type EntityList");
		if(THIS == NULL)
			Perl_croak(aTHX_ "THIS is NULL, avoiding crash.");

		THIS->Message(to_guilddbid, type, message);
	}
	XSRETURN_EMPTY;
}


XS(XS_EntityList_MessageClose); /* prototype to pass -Wmissing-prototypes */
XS(XS_EntityList_MessageClose)
{
	dXSARGS;
	if (items < 6)
		Perl_croak(aTHX_ "Usage: EntityList::MessageClose(THIS, sender, skipsender, dist, type, message, ...)");
	{
		EntityList *		THIS;
		Mob*		sender;
		bool		skipsender = (bool)SvTRUE(ST(2));
		float		dist = (float)SvNV(ST(3));
		MessageFormat		type = (MessageFormat)SvUV(ST(4));
		char*		message = (char *)SvPV_nolen(ST(5));

		if (sv_derived_from(ST(0), "EntityList")) {
			IV tmp = SvIV((SV*)SvRV(ST(0)));
			THIS = INT2PTR(EntityList *,tmp);
		}
		else
			Perl_croak(aTHX_ "THIS is not of type EntityList");
		if(THIS == NULL)
			Perl_croak(aTHX_ "THIS is NULL, avoiding crash.");

		if (sv_derived_from(ST(1), "Mob")) {
			IV tmp = SvIV((SV*)SvRV(ST(1)));
			sender = INT2PTR(Mob *,tmp);
		}
		else
			Perl_croak(aTHX_ "sender is not of type Mob");
		if(sender == NULL)
			Perl_croak(aTHX_ "sender is NULL, avoiding crash.");

		THIS->MessageClose(sender, skipsender, dist, type, message);
	}
	XSRETURN_EMPTY;
}


XS(XS_EntityList_RemoveFromTargets); /* prototype to pass -Wmissing-prototypes */
XS(XS_EntityList_RemoveFromTargets)
{
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: EntityList::RemoveFromTargets(THIS, mob)");
	{
		EntityList *		THIS;
		Mob*		mob;

		if (sv_derived_from(ST(0), "EntityList")) {
			IV tmp = SvIV((SV*)SvRV(ST(0)));
			THIS = INT2PTR(EntityList *,tmp);
		}
		else
			Perl_croak(aTHX_ "THIS is not of type EntityList");
		if(THIS == NULL)
			Perl_croak(aTHX_ "THIS is NULL, avoiding crash.");

		if (sv_derived_from(ST(1), "Mob")) {
			IV tmp = SvIV((SV*)SvRV(ST(1)));
			mob = INT2PTR(Mob *,tmp);
		}
		else
			Perl_croak(aTHX_ "mob is not of type Mob");
		if(mob == NULL)
			Perl_croak(aTHX_ "mob is NULL, avoiding crash.");

		THIS->RemoveFromTargets(mob);
	}
	XSRETURN_EMPTY;
}


XS(XS_EntityList_MakeNameUnique); /* prototype to pass -Wmissing-prototypes */
XS(XS_EntityList_MakeNameUnique)
{
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: EntityList::MakeNameUnique(THIS, name)");
	{
		EntityList *		THIS;
		char *		RETVAL;
		dXSTARG;
		char*		name = (char *)SvPV_nolen(ST(1));

		if (sv_derived_from(ST(0), "EntityList")) {
			IV tmp = SvIV((SV*)SvRV(ST(0)));
			THIS = INT2PTR(EntityList *,tmp);
		}
		else
			Perl_croak(aTHX_ "THIS is not of type EntityList");
		if(THIS == NULL)
			Perl_croak(aTHX_ "THIS is NULL, avoiding crash.");

		RETVAL = THIS->MakeNameUnique(name);
		sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
	}
	XSRETURN(1);
}


XS(XS_EntityList_RemoveNumbers); /* prototype to pass -Wmissing-prototypes */
XS(XS_EntityList_RemoveNumbers)
{
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: EntityList::RemoveNumbers(CLASS, name)");
	{
		char *		CLASS = (char *)SvPV_nolen(ST(0));
		char *		RETVAL;
		dXSTARG;
		char*		name = (char *)SvPV_nolen(ST(1));

		RETVAL = EntityList::RemoveNumbers(name);
		sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
	}
	XSRETURN(1);
}


XS(XS_EntityList_SignalMobsByNPCID); /* prototype to pass -Wmissing-prototypes */
XS(XS_EntityList_SignalMobsByNPCID)
{
	dXSARGS;
	if (items != 3)
		Perl_croak(aTHX_ "Usage: EntityList::SignalMobsByNPCID(THIS, npc_type, signal_id)");
	{
		EntityList *		THIS;
		int32		npc_type = (int32)SvUV(ST(1));
		int		signal_id = (int)SvIV(ST(2));

		if (sv_derived_from(ST(0), "EntityList")) {
			IV tmp = SvIV((SV*)SvRV(ST(0)));
			THIS = INT2PTR(EntityList *,tmp);
		}
		else
			Perl_croak(aTHX_ "THIS is not of type EntityList");
		if(THIS == NULL)
			Perl_croak(aTHX_ "THIS is NULL, avoiding crash.");

		THIS->SignalMobsByNPCID(npc_type, signal_id);
	}
	XSRETURN_EMPTY;
}


XS(XS_EntityList_RemoveEntity); /* prototype to pass -Wmissing-prototypes */
XS(XS_EntityList_RemoveEntity)
{
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: EntityList::RemoveEntity(THIS, id)");
	{
		EntityList *		THIS;
		int16		id = (int16)SvUV(ST(1));

		if (sv_derived_from(ST(0), "EntityList")) {
			IV tmp = SvIV((SV*)SvRV(ST(0)));
			THIS = INT2PTR(EntityList *,tmp);
		}
		else
			Perl_croak(aTHX_ "THIS is not of type EntityList");
		if(THIS == NULL)
			Perl_croak(aTHX_ "THIS is NULL, avoiding crash.");

		THIS->RemoveEntity(id);
	}
	XSRETURN_EMPTY;
}


XS(XS_EntityList_DeleteNPCCorpses); /* prototype to pass -Wmissing-prototypes */
XS(XS_EntityList_DeleteNPCCorpses)
{
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: EntityList::DeleteNPCCorpses(THIS)");
	{
		EntityList *		THIS;
		sint32		RETVAL;
		dXSTARG;

		if (sv_derived_from(ST(0), "EntityList")) {
			IV tmp = SvIV((SV*)SvRV(ST(0)));
			THIS = INT2PTR(EntityList *,tmp);
		}
		else
			Perl_croak(aTHX_ "THIS is not of type EntityList");
		if(THIS == NULL)
			Perl_croak(aTHX_ "THIS is NULL, avoiding crash.");

		RETVAL = THIS->DeleteNPCCorpses();
		XSprePUSH; PUSHi((IV)RETVAL);
	}
	XSRETURN(1);
}


XS(XS_EntityList_DeletePlayerCorpses); /* prototype to pass -Wmissing-prototypes */
XS(XS_EntityList_DeletePlayerCorpses)
{
	dXSARGS;
	if (items != 1)
		Perl_croak(aTHX_ "Usage: EntityList::DeletePlayerCorpses(THIS)");
	{
		EntityList *		THIS;
		sint32		RETVAL;
		dXSTARG;

		if (sv_derived_from(ST(0), "EntityList")) {
			IV tmp = SvIV((SV*)SvRV(ST(0)));
			THIS = INT2PTR(EntityList *,tmp);
		}
		else
			Perl_croak(aTHX_ "THIS is not of type EntityList");
		if(THIS == NULL)
			Perl_croak(aTHX_ "THIS is NULL, avoiding crash.");

		RETVAL = THIS->DeletePlayerCorpses();
		XSprePUSH; PUSHi((IV)RETVAL);
	}
	XSRETURN(1);
}


XS(XS_EntityList_ClearFeignAggro); /* prototype to pass -Wmissing-prototypes */
XS(XS_EntityList_ClearFeignAggro)
{
	dXSARGS;
	if (items != 2)
		Perl_croak(aTHX_ "Usage: EntityList::ClearFeignAggro(THIS, targ)");
	{
		EntityList *		THIS;
		Mob*		targ;

		if (sv_derived_from(ST(0), "EntityList")) {
			IV tmp = SvIV((SV*)SvRV(ST(0)));
			THIS = INT2PTR(EntityList *,tmp);
		}
		else
			Perl_croak(aTHX_ "THIS is not of type EntityList");
		if(THIS == NULL)
			Perl_croak(aTHX_ "THIS is NULL, avoiding crash.");

		if (sv_derived_from(ST(1), "Mob")) {
			IV tmp = SvIV((SV*)SvRV(ST(1)));
			targ = INT2PTR(Mob *,tmp);
		}
		else
			Perl_croak(aTHX_ "targ is not of type Mob");
		if(targ == NULL)
			Perl_croak(aTHX_ "targ is NULL, avoiding crash.");

		THIS->ClearFeignAggro(targ);
	}
	XSRETURN_EMPTY;
}

#ifdef __cplusplus
extern "C"
#endif
XS(boot_EntityList); /* prototype to pass -Wmissing-prototypes */
XS(boot_EntityList)
{
	dXSARGS;
	char file[256];
	strncpy(file, __FILE__, 256);
	file[255] = 0;
	
	if(items != 1)
		fprintf(stderr, "boot_quest does not take any arguments.");
	char buf[128];

	//add the strcpy stuff to get rid of const warnings....



	XS_VERSION_BOOTCHECK ;

		newXSproto(strcpy(buf, "GetMob"), XS_EntityList_GetMob, file, "$$");
		newXSproto(strcpy(buf, "GetMobByNpcTypeID"), XS_EntityList_GetMobByNpcTypeID, file, "$$");
		newXSproto(strcpy(buf, "GetClientByName"), XS_EntityList_GetClientByName, file, "$$");
		newXSproto(strcpy(buf, "GetClientByAccID"), XS_EntityList_GetClientByAccID, file, "$$");
		newXSproto(strcpy(buf, "ClearClientPetitionQueue"), XS_EntityList_ClearClientPetitionQueue, file, "$");
		newXSproto(strcpy(buf, "Clear"), XS_EntityList_Clear, file, "$");
		newXSproto(strcpy(buf, "Message"), XS_EntityList_Message, file, "$$$$;@");
		newXSproto(strcpy(buf, "MessageClose"), XS_EntityList_MessageClose, file, "$$$$$$;@");
		newXSproto(strcpy(buf, "RemoveFromTargets"), XS_EntityList_RemoveFromTargets, file, "$$");
		newXSproto(strcpy(buf, "MakeNameUnique"), XS_EntityList_MakeNameUnique, file, "$$");
		newXSproto(strcpy(buf, "RemoveNumbers"), XS_EntityList_RemoveNumbers, file, "$$");
		newXSproto(strcpy(buf, "SignalMobsByNPCID"), XS_EntityList_SignalMobsByNPCID, file, "$$$");
		newXSproto(strcpy(buf, "RemoveEntity"), XS_EntityList_RemoveEntity, file, "$$");
		newXSproto(strcpy(buf, "DeleteNPCCorpses"), XS_EntityList_DeleteNPCCorpses, file, "$");
		newXSproto(strcpy(buf, "DeletePlayerCorpses"), XS_EntityList_DeletePlayerCorpses, file, "$");
		newXSproto(strcpy(buf, "ClearFeignAggro"), XS_EntityList_ClearFeignAggro, file, "$$");
	XSRETURN_YES;
}

#endif //EMBPERL_XS_CLASSES

