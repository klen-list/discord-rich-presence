#include "api.h"

using namespace std;

time_t start_time;

void RPC_Init()
{
	start_time = time(NULL);
	DiscordEventHandlers handlers;
	memset(&handlers, 0, sizeof(handlers));
	Discord_Initialize("YOUR_RPCAPP_CLIENTID", &handlers, TRUE, nullptr); // change YOUR_RPCAPP_CLIENTID to clientid ur app
}

void RPC_Update(GarrysMod::Lua::ILuaBase* Lua)
{
	DiscordRichPresence discordPresence;
	memset(&discordPresence, 0, sizeof(discordPresence));
	
	string details = string("Server: ") + GetHostName(Lua);
	discordPresence.details = details.c_str();

	string state = string("Map: ") + GetMapName(Lua) + ", players: " + GetPlayersCount(Lua) + "/" + GetMaxPlayerCount(Lua);
	discordPresence.state = state.c_str();

	discordPresence.startTimestamp = start_time;

	/* Uncomment this if u want using images

	discordPresence.largeImageKey = "Image name in devapp";
	discordPresence.largeImageText = "Hover text";

	discordPresence.smallImageKey = "Image name in devapp";
	discordPresence.smallImageText = "Hover text";

	*/

	Discord_UpdatePresence(&discordPresence);
}