// from server: 100% by auto
// roc 2010-06 00614c80  unit: RBX::VScriptContext::?$BoundFuncDesc  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00614c80
//
// 00614c80  6aff                 push -1
// 00614c82  68b8d19b00           push 0x9bd1b8
// 00614c87  64a100000000         mov eax, dword ptr fs:[0]
// 00614c8d  50                   push eax
// 00614c8e  64892500000000       mov dword ptr fs:[0], esp
// 00614c95  83ec0c               sub esp, 0xc
// 00614c98  56                   push esi
// 00614c99  8bf1                 mov esi, ecx
// 00614c9b  89742404             mov dword ptr [esp + 4], esi
// 00614c9f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00614ca2  8b0e                 mov ecx, dword ptr [esi]
// 00614ca4  8b10                 mov edx, dword ptr [eax]
// 00614ca6  50                   push eax
// 00614ca7  51                   push ecx
// 00614ca8  52                   push edx
// 00614ca9  51                   push ecx
// 00614caa  8d442418             lea eax, [esp + 0x18]
// 00614cae  50                   push eax
// 00614caf  8bce                 mov ecx, esi
// 00614cb1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00614cb9  e822eeffff           call 0x613ae0
// 00614cbe  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00614cc1  51                   push ecx
// 00614cc2  e8d32c1900           call 0x7a799a
// 00614cc7  8b16                 mov edx, dword ptr [esi]
// 00614cc9  52                   push edx
// 00614cca  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00614cd1  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00614cd8  e8bd2c1900           call 0x7a799a
// 00614cdd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00614ce1  83c408               add esp, 8
// 00614ce4  5e                   pop esi
// 00614ce5  64890d00000000       mov dword ptr fs:[0], ecx
// 00614cec  83c418               add esp, 0x18
// 00614cef  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
