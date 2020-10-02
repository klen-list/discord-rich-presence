#include "api.h"

using namespace GarrysMod::Lua;

const char* GetPlayersCount(ILuaBase* Lua)
{
	Lua->PushSpecial(SPECIAL_GLOB);
		Lua->GetField(-1, "player");
		Lua->GetField(-1, "GetCount");
	Lua->Call(0, 1);
		Lua->GetField(-3, "tostring");
	Lua->Push(-2);
	Lua->Call(1, 1);

	const char* players = Lua->GetString(-1);
	Lua->Pop(3);

	return players;
}

const char* GetMaxPlayerCount(ILuaBase* Lua)
{
	Lua->PushSpecial(SPECIAL_GLOB);
		Lua->GetField(-1, "game");
		Lua->GetField(-1, "MaxPlayers");
	Lua->Call(0, 1);
		Lua->GetField(-3, "tostring");
	Lua->Push(-2);
	Lua->Call(1, 1);

	const char* max_players = Lua->GetString(-1);
	Lua->Pop(3);

	return max_players;
}

const char* GetMapName(ILuaBase* Lua)
{
	Lua->PushSpecial(SPECIAL_GLOB);
		Lua->GetField(-1, "game");
		Lua->GetField(-1, "GetMap");
	Lua->Call(0, 1);

	const char* map_name = Lua->GetString();
	Lua->Pop(3);

	return map_name;
}

const char* GetHostName(ILuaBase* Lua)
{
	Lua->PushSpecial(SPECIAL_GLOB);
		Lua->GetField(-1, "GetHostName");
	Lua->Call(0, 1);

	const char* host_name = Lua->GetString();
	Lua->Pop(2);

	return host_name;
}

/*
void DebugLuaPrint(ILuaBase* Lua, const char* Argument)
{
	Lua->PushSpecial(SPECIAL_GLOB);
		Lua->GetField(-1, "print");
		Lua->PushString(Argument);
	Lua->Call(1, 0);
	Lua->Pop();
}
*/

LUA_FUNCTION( InitPresence )
{
	RPC_Init();
	RPC_Update(LUA);
	return 0;
}

LUA_FUNCTION( UpdatePresence )
{
	RPC_Update(LUA);
	return 0;
}

LUA_FUNCTION( EndPresence )
{
	Discord_Shutdown();
	return 0;
}

GMOD_MODULE_OPEN()
{
	LUA->PushSpecial(SPECIAL_GLOB);
		LUA->PushCFunction(InitPresence);
		LUA->SetField(-2, "DiscordRPCInit");
		
		LUA->PushCFunction(UpdatePresence);
		LUA->SetField(-2, "DiscordRPCUpdate");

		LUA->PushCFunction(EndPresence);
		LUA->SetField(-2, "DiscordRPCEnd");
	LUA->Pop();

	return 0;
}

GMOD_MODULE_CLOSE()
{
	Discord_Shutdown();
	return 0;
}