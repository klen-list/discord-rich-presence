Garry's Mod Discord Rich Presence Dll Module Source
=====================

~~Source for creating dll lua module.~~

### Using steps:
`1. Download and unpack folder.`

`2. Add files to your IDE as dll project.`

`3. Select release and architecture (Default gmod - x86, chromium - x64), disable precompiled headers.`

`4. Add includes to project and put needed lib to source files.`

`5. Change in api.h XX to your selested architecture.`

`6. Register new app on discord.com/developers/applications/ and copy clientID.`

`7. Change in rpc.cpp YOUR_RPCAPP_CLIENTID to clientID your application.`

`8. Compile project and rename output dll as gmcl_dllname_winXX.dll, where dllname - want name, XX - project settings(86/64).`

`9. Move renamed dll to ...\GarrysMod\garrysmod\lua\bin\ and lua folder to ...\GarrysMod\garrysmod\`

Lua script contains client cvar *discordrpc_enabled* for disable/enable rpc from game.
