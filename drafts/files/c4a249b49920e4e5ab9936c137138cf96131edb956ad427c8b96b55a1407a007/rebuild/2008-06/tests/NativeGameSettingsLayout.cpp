#include "v8datamodel/GameSettings.h"
#include <stddef.h>
// Allocation: 0044bddf pushes 13c; 0044be04 calls 005bf680.
typedef char GameSettingsLayout1[(sizeof(RBX::GameSettings) == 0x13c) ? 1 : -1];
typedef char GameSettingsLayout2[(offsetof(RBX::GameSettings, chatHistory) == 0x130) ? 1 : -1];
typedef char GameSettingsLayout3[(offsetof(RBX::GameSettings, chatScrollLength) == 0x134) ? 1 : -1];
typedef char GameSettingsLayout4[(offsetof(RBX::GameSettings, soundEnabled) == 0x138) ? 1 : -1];
typedef char GameSettingsLayout5[(offsetof(RBX::GameSettings, softwareSound) == 0x139) ? 1 : -1];
typedef char GameSettingsLayout6[(offsetof(RBX::GameSettings, animatedCharacter) == 0x13a) ? 1 : -1];
