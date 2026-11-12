// Compile-time layout checks for native-headers/PropertyGridItems2008.h (inactive).
// Sizes: operator new in the editor factory 00440e30 (XBrickColorItem/Vector3Item 0x13c, EnumItem 0x138,
// RefItem 0x134, ScriptItem/TextureItem/SoundItem 0x130) and in Vector3Item::OnAddChildItem 0043dae0
// (Vector3ComponentItem 0x140). Item subobject offsets: RTTI base class descriptors of each primary vtable.
// Field offsets: constructor stores 0043d6c0 (+0x130..+0x138), 0043d7d0 (+0x130, +0x134..+0x13c),
// 0043db80 (+0x130), XItem constructors 0043b400 (+0x138), 0043c440 (+0x134), 0043c020 (+0x12c).
#include <stddef.h>
#include "PropertyGridItems2008.h"

struct PropertyGridItems2008Layout {
    template<class T> static size_t item(T* p) { return (size_t)(char*)static_cast<CPropGrid::Item*>(p) - (size_t)(char*)p; }
};

C_ASSERT(sizeof(XBrickColorItem) == 0x13c);
C_ASSERT(sizeof(Vector3Item) == 0x13c);
C_ASSERT(sizeof(Vector3ComponentItem) == 0x140);
C_ASSERT(sizeof(EnumItem) == 0x138);
C_ASSERT(sizeof(RefItem) == 0x134);
C_ASSERT(sizeof(ScriptItem) == 0x130);
C_ASSERT(sizeof(TextureItem) == 0x130);
C_ASSERT(sizeof(SoundItem) == 0x130);
C_ASSERT(sizeof(ContentItem<RBX::TextureId>) == 0x130);
C_ASSERT(sizeof(ContentItem<RBX::Soundscape::SoundId>) == 0x130);
C_ASSERT(sizeof(CXTPPropertyGridItemEnum) == 0x114);

C_ASSERT(offsetof(XBrickColorItem, classes) == 0x11c);
C_ASSERT(offsetof(XBrickColorItem, grid) == 0x134);
C_ASSERT(offsetof(XBrickColorItem, descriptor) == 0x138);
C_ASSERT(offsetof(Vector3Item, descriptor) == 0x12c);
C_ASSERT(offsetof(Vector3Item, components) == 0x130);
C_ASSERT(offsetof(Vector3ComponentItem, component) == 0x130);
C_ASSERT(offsetof(Vector3ComponentItem, value) == 0x134);
C_ASSERT(offsetof(EnumItem, grid) == 0x130);
C_ASSERT(offsetof(EnumItem, descriptor) == 0x134);
C_ASSERT(offsetof(RefItem, refDescriptor) == 0x130);
C_ASSERT(offsetof(ScriptItem, descriptor) == 0x12c);

// Item subobject offsets (RTTI): 0x118 BrickColor, 0x114 Enum, 0x10c otherwise.
int brickColorItemOffset(XBrickColorItem* p) { return (int)PropertyGridItems2008Layout::item(p); }
int enumItemOffset(EnumItem* p) { return (int)PropertyGridItems2008Layout::item(p); }
int vector3ItemOffset(Vector3Item* p) { return (int)PropertyGridItems2008Layout::item(p); }
int textureItemOffset(TextureItem* p) { return (int)PropertyGridItems2008Layout::item(p); }
