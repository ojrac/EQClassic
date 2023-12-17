#ifndef GUILDDATABASE_H
#define GUILDDATABASE_H

#include "GuildNetwork.h"
#include "database.h"

using namespace EQC::Common;
using namespace EQC::Common::Network;

namespace EQC
{
	namespace Common
	{
		class GuildDatabase
			{
			public:
				void LoadGuilds(Guild_Struct** out_guilds);
				
			private:
				Guild_Struct* CreateBlankGuild_Stract();

			};
		}
}
#endif