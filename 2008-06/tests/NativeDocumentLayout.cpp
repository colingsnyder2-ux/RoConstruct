#include "../native-classes/CRobloxDoc.cpp"
#include "../native-classes/StandardVerbs.cpp"
#include "../native-headers/RobloxLib.h"
#include <cstddef>

typedef char XmlElementSize[sizeof(XmlElement) == 0x28 ? 1 : -1];
typedef char XmlElementAlignment[__alignof(XmlElement) == 8 ? 1 : -1];
typedef char WorkspaceInterfaceSize[sizeof(IWorkspace) == 4 ? 1 : -1];
typedef char ContentInterfaceSize[sizeof(IContent) == 4 ? 1 : -1];
typedef char NativeVariantSize[sizeof(VARIANT) == 16 ? 1 : -1];
typedef char DocumentSize[sizeof(CRobloxDoc) == 0x98 ? 1 : -1];
typedef char SnapshotOffset[offsetof(CRobloxDoc, savedState) == 0x74 ? 1 : -1];
typedef char VerbsOffset[offsetof(CRobloxDoc, ownedVerbs) == 0x78 ? 1 : -1];
typedef char StandardVerbsOffset[offsetof(CRobloxDoc, standardVerbs) == 0x90 ? 1 : -1];
typedef char WorkspaceOffset[offsetof(CRobloxDoc, workspace) == 0x94 ? 1 : -1];
