// from server: 100% by auto
// roc 2008-06 00552760  unit: RBX::RenderBase::AggregateChunk  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00552760
//
// 00552760  55                   push ebp
// 00552761  8bec                 mov ebp, esp
// 00552763  51                   push ecx
// 00552764  894dfc               mov dword ptr [ebp - 4], ecx
// 00552767  8b45fc               mov eax, dword ptr [ebp - 4]
// 0055276a  83c030               add eax, 0x30
// 0055276d  8be5                 mov esp, ebp
// 0055276f  5d                   pop ebp
// 00552770  c3                   ret 
// library wildmagic-2-core/Geometry\WmlBox2.cpp (function ?Extents@?$Box2@N@Wml@@QBEPBNXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlBox2.cpp
