// Layout probes for the inactive native Mouse.h; tests/record_native_mouse.py checks each function body is
// `mov eax, imm32; ret` with the value from the binary:
//   sizeof(Mouse)      0x168  Creatable<Instance>::create<Mouse> 005ff600 pushes 0x168 to operator new
//   lastEvent          0x130  constructor 005ff3b0 stores eventType / userInput at +0x130 / +0x134; cacheUIEvent
//                             0064df60 copies five dwords to +0x130..+0x140
//   icon               0x144  constructor (std::string ctor on +0x144, Name::getNullName() to +0x160), destructor
//                             005ff520, getIcon 00642f80, setIcon 0064e180
//   command            0x164  constructor (NULL), checkActive 00642f10, getTarget 0064e020, getOrigin 0064e050
//   sizeof(UIEvent)    0x14   cacheUIEvent copies 0x14 bytes
//   sizeof(TextureId)  0x20   std::string (0x1c) + mimeTypePtr (+0x1c, 0064e180 / 00642f80)
#include <stddef.h>
#include "v8datamodel/Mouse.h"

struct NativeMouseLayout
{
	static size_t mouseSize() { return sizeof(RBX::Mouse); }
	static size_t lastEvent() { return offsetof(RBX::Mouse, lastEvent); }
	static size_t icon() { return offsetof(RBX::Mouse, icon); }
	static size_t command() { return offsetof(RBX::Mouse, command); }
};

size_t nativeMouseSize() { return NativeMouseLayout::mouseSize(); }
size_t nativeMouseLastEvent() { return NativeMouseLayout::lastEvent(); }
size_t nativeMouseIcon() { return NativeMouseLayout::icon(); }
size_t nativeMouseCommand() { return NativeMouseLayout::command(); }
size_t nativeUIEventSize() { return sizeof(RBX::UIEvent); }
size_t nativeTextureIdSize() { return sizeof(RBX::TextureId); }
size_t nativeInstanceSize() { return sizeof(RBX::Instance); }
