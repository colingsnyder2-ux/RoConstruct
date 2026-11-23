// =============================================================================
// GameSettings.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/v8datamodel/GameSettings.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include "v8datamodel/GlobalSettings.h"

struct NativeSettingsItemsLayout;

namespace RBX
{
	extern const char sGameSettings[];

	class GameSettings : public GlobalSettingsItem<GameSettings, sGameSettings>
	{
		friend struct ::NativeSettingsItemsLayout; // tests/NativeSettingsItemsLayout.cpp offset asserts

	public:
		int chatHistory;        // +0x130
		int chatScrollLength;   // +0x134
		bool soundEnabled;      // +0x138
		bool softwareSound;     // +0x139
		bool funnyPhysics;      // +0x13a

	public:
		GameSettings();         // 005bf680
	};
}
