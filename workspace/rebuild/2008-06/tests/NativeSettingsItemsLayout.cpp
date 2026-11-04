// Layout and instantiation probe for the inactive native GameSettings / DebugSettings headers.
// tests/record_native_settings_items.py checks each size function is `mov eax, imm32; ret` with the allocation size the
// binary passes to malloc, and compares the instantiated creator (and the shared_ptr helper it emits) with the original:
//   sizeof(GameSettings)   0x13c  Creatable<Instance>::create<GameSettings>  0044bdc0 (emitted by native-classes/GameSettings.cpp
//                                 through GlobalSettingsItem<GameSettings>::singleton 0044bee0)
//   sizeof(DebugSettings)  0x138  Creatable<Instance>::create<DebugSettings> 00407820
// Field offsets are compile-time asserts (NativeSettingsItemsLayout is a friend of each class).
#include <stddef.h>
#include "v8datamodel/GameSettings.h"
#include "v8datamodel/DebugSettings.h"

struct NativeSettingsItemsLayout
{
	typedef char GameChatHistory[offsetof(RBX::GameSettings, chatHistory) == 0x130 ? 1 : -1];
	typedef char GameChatScrollLength[offsetof(RBX::GameSettings, chatScrollLength) == 0x134 ? 1 : -1];
	typedef char GameSoundEnabled[offsetof(RBX::GameSettings, soundEnabled) == 0x138 ? 1 : -1];
	typedef char GameSoftwareSound[offsetof(RBX::GameSettings, softwareSound) == 0x139 ? 1 : -1];
	typedef char GameFunnyPhysics[offsetof(RBX::GameSettings, funnyPhysics) == 0x13a ? 1 : -1];
	typedef char DebugStackTracing[offsetof(RBX::DebugSettings, stackTracingEnabled) == 0x130 ? 1 : -1];
	typedef char DebugIoEnabled[offsetof(RBX::DebugSettings, ioEnabled) == 0x131 ? 1 : -1];
	typedef char DebugValidatingDebug[offsetof(RBX::DebugSettings, validatingDebug) == 0x132 ? 1 : -1];
	typedef char DebugSoundWarnings[offsetof(RBX::DebugSettings, soundWarnings) == 0x133 ? 1 : -1];
	typedef char DebugErrorReporting[offsetof(RBX::DebugSettings, errorReporting) == 0x134 ? 1 : -1];
};

size_t nativeGameSettingsSize() { return sizeof(RBX::GameSettings); }
size_t nativeDebugSettingsSize() { return sizeof(RBX::DebugSettings); }

// The original emits this creator in the unit that first creates the item (CRobloxApp module, 00407820).
template boost::shared_ptr<RBX::DebugSettings> RBX::Creatable<RBX::Instance>::create<RBX::DebugSettings>();
