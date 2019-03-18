// dllmain.cpp : Defines the entry point for the DLL application.
#include "TimmyAIO.h"

PLUGIN_SETUP("Lord Tryndamere", OnLoad);

void __cdecl OnLoad(void* UserData) {
	LOAD_ENVIRONMENT();

	if (Player.PTR() && pSDK && pCore) {
		MyTemplateClass::Init();
	}
}
