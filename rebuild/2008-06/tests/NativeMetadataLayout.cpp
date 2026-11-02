#include <stddef.h>
#include "reflection/Metadata.h"
#include "AuthoringSettings.h"
// Metadata::Item/Class from constructors 0040cff0/0040dba0 and factory 0040dc70 (0x158);
// Metadata::Reflection from creator 0040b320 (0x134); AuthoringSettings from 0040d410 (0x134) and 0040d140.
typedef char MetadataItemSize[sizeof(RBX::Reflection::Metadata::Item) == 0x150 ? 1 : -1];
typedef char MetadataClassSize[sizeof(RBX::Reflection::Metadata::Class) == 0x158 ? 1 : -1];
typedef char MetadataItem130[offsetof(RBX::Reflection::Metadata::Item, unknown_130) == 0x130 ? 1 : -1];
typedef char MetadataItem131[offsetof(RBX::Reflection::Metadata::Item, unknown_131) == 0x131 ? 1 : -1];
typedef char MetadataItem132[offsetof(RBX::Reflection::Metadata::Item, unknown_132) == 0x132 ? 1 : -1];
typedef char MetadataItem134[offsetof(RBX::Reflection::Metadata::Item, unknown_134) == 0x134 ? 1 : -1];
typedef char MetadataClass150[offsetof(RBX::Reflection::Metadata::Class, unknown_150) == 0x150 ? 1 : -1];
typedef char MetadataClass154[offsetof(RBX::Reflection::Metadata::Class, unknown_154) == 0x154 ? 1 : -1];
typedef char MetadataReflectionSize[sizeof(RBX::Metadata::Reflection) == 0x134 ? 1 : -1];
typedef char MetadataReflectionClasses[offsetof(RBX::Metadata::Reflection, classes) == 0x130 ? 1 : -1];
typedef char AuthoringSettingsSize[sizeof(AuthoringSettings) == 0x134 ? 1 : -1];
typedef char AuthoringDeprecated[offsetof(AuthoringSettings, showDepricatedObjects) == 0x130 ? 1 : -1];
typedef char AuthoringPreliminary[offsetof(AuthoringSettings, showPreliminaryObjects) == 0x131 ? 1 : -1];
