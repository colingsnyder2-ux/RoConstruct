#pragma once
// >>> native-status (generated) -- do not edit >>>
// MaterialFactory2008 | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 651b0345 | roc native-status --write
// 2008-06 native RBX::ViewNew::MaterialFactory: destructor declaration only (inactive). Named *2008.h so it never
// shadows the donor RbxView/MaterialFactory.h (a later source base).
//   Evidence: new 0x10 before the ctor 004f0920(G3D::TextureManager*) in the ViewRbxGfx ctor (004d9ac1) and the ViewG3D
//   ctor; out-of-line non-virtual dtor 004d7460 (no vptr: it releases four G3D ReferenceCountedPointers at +0xc,
//   +0x8, +0x4, +0x0 through ReferenceCountedObject_zeroWeakPointers 0045ad90 and slot 0); the ViewBase dtor 004d8920
//   calls it and then operator delete for the auto_ptr<MaterialFactory> member.
//   NO LAYOUT IS DERIVED HERE: the real class is 0x10 bytes, the ctor fills +0x4 / +0x8 from the texture-proxy factory
//   00551920(textureManager, name, true / false) and +0x0 from 00551a30, and the pointee type of +0xc is not derived.
//   The class is declared without members, so this header must never be used for `new`, sizeof or member access: it
//   only lets std::auto_ptr<MaterialFactory> call the out-of-line destructor. The ctor is not declared (its callers,
//   the ViewRbxGfx / ViewG3D ctors, stay blocked on the Lighting service).

namespace RBX
{
	namespace ViewNew
	{
		class MaterialFactory
		{
		public:
			~MaterialFactory();                                          // 004d7460
		};
	}
}
