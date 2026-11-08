#pragma once
// >>> native-status (generated) -- do not edit >>>
// GameSettings | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 57423bda | roc native-status --write
// 2008-06 native RBX::GameSettings (inactive). Shape after the donor tools/rbxgs v8datamodel/GameSettings.h; every
// base, field and descriptor below is read from the 2008-06 binary:
//   RTTI       vtable 00838774 .?AVGameSettings@RBX@@ -> GlobalSettingsItem<GameSettings, sGameSettings> (vtable
//              008385f4) -> DescribedCreatable<GameSettings, GlobalSettings::Item, sGameSettings> (008386b4) ->
//              FactoryProduct (00838534), and the empty Service (mdisp 0x130). sGameSettings is mangled
//              $1?sGameSettings@2@3QBDB: a const char array in .rdata at 00838478 holding "GameSettings" (pushed by the
//              GlobalSettingsItem constructor 005bf580 and the class descriptor 005bf280).
//   size       0x13c: Creatable<Instance>::create<GameSettings> 0044bdc0 allocates 0x13c and calls the constructor
//              005bf680, which stores the fields below in declaration order and calls setName("Game Options")
//              (string 008387b4).
//   fields     from the constructor and the property initializers 007f5560..007f5620 (member offsets pushed):
//              +0x130 ChatHistory (int, 50), +0x134 ChatScrollLength (int, 5) ("Online");
//              +0x138 SoundEnabled (bool, true), +0x139 SoftwareSound (bool, false) ("Sound");
//              +0x13a FunnyPhysics (bool, false) ("Debug"; the later donor has AnimatedCharacter here).
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
