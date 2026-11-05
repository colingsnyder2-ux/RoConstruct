#include "v8datamodel/SpecialShape.h"
#include <stddef.h>
// Creator 0041ec30 passes 0x18c to malloc at 0041ec59 before ctor 0059fbb0.
// Compiled successfully with MSVC 2008 RTM 21022 on 2026-11-04.
typedef char ScaleOffset[(offsetof(RBX::SpecialShape, scale)==0x134)?1:-1];
typedef char MeshOffset[(offsetof(RBX::SpecialShape, meshId)==0x140)?1:-1];
typedef char TextureOffset[(offsetof(RBX::SpecialShape, textureId)==0x160)?1:-1];
typedef char ColorOffset[(offsetof(RBX::SpecialShape, vertColor)==0x180)?1:-1];
typedef char ObservedExtent[(sizeof(RBX::SpecialShape)==0x18c)?1:-1];
