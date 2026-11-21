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
