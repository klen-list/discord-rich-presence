-- Discord RPC GLua API

local dllname = "examplerpc"

--------------------------------------

local dllname32 = "gmcl_" .. dllname .. "_win32.dll"
local dllname64 = "gmcl_" .. dllname .. "_win64.dll"
local dllexist = false

if file.Exists("bin/" .. dllname32, "lsv") then
	require(dllname)
	dllexist = true
elseif file.Exists("bin/" .. dllname64, "lsv") then
	require(dllname)
	dllexist = true
end

if not dllexist then return end

MsgC(">> DiscordRPC dll loaded!\n", Color(80, 238, 252))

if not ConVarExists"discordrpc_enabled" then
	CreateClientConVar("discordrpc_enabled", 1)
end

cvars.AddChangeCallback("discordrpc_enabled", function(_, __, new)
	if tobool(new) then
		DiscordRPCInit()
	else
		DiscordRPCEnd()
	end
end)

if GetConVar"discordrpc_enabled":GetBool() then
	DiscordRPCInit()

	timer.Create("discord_rpc_update", 60, 0, DiscordRPCUpdate)
end