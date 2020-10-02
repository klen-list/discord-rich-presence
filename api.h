#pragma once

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <time.h>
#include <string>

// LUA API

#include "Interface.h"

const char* GetPlayersCount(GarrysMod::Lua::ILuaBase*);
const char* GetMaxPlayerCount(GarrysMod::Lua::ILuaBase*);
const char* GetMapName(GarrysMod::Lua::ILuaBase*);
const char* GetHostName(GarrysMod::Lua::ILuaBase*);

// RPC API

#include "discord_rpc.h" 
#include "discord_register.h"
// change XX to 86 or 64
#pragma comment(lib, "./discord-rpc-xXX.lib")

void RPC_Init();
void RPC_Update(GarrysMod::Lua::ILuaBase*);