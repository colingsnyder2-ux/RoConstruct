// =============================================================================
// RakSleep.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/network/raknet30/source/RakSleep.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#if defined(_CONSOLE_1)
#include "Console1Includes.h"
#elif defined(_WIN32)
#include <windows.h> // Sleep
#elif defined(_CONSOLE_2)
#include "Console2Includes.h"
#else
#include <unistd.h> // usleep
#endif

void RakSleep(unsigned int ms)
{
#ifdef _WIN32
	Sleep(ms);
#elif defined(_CONSOLE_2)
	// Use the version of usleep on the console here, this is a macro
	_CONSOLE_2_usleep(ms * 1000);
#else
	usleep(ms * 1000);
#endif
}
