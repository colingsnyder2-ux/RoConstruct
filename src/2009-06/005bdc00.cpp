// from server: 100% by auto
// roc 2009-06 005bdc00  unit: RBX::AggregateChunk  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005bdc00
//
// 005bdc00  55                   push ebp
// 005bdc01  8bec                 mov ebp, esp
// 005bdc03  51                   push ecx
// 005bdc04  894dfc               mov dword ptr [ebp - 4], ecx
// 005bdc07  8b45fc               mov eax, dword ptr [ebp - 4]
// 005bdc0a  83c028               add eax, 0x28
// 005bdc0d  8be5                 mov esp, ebp
// 005bdc0f  5d                   pop ebp
// 005bdc10  c3                   ret 
// library wildmagic-2-core/Geometry\WmlArc2.cpp (function ?End1@?$Arc2@N@Wml@@QBEABV?$Vector2@N@2@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlArc2.cpp
