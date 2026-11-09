// from server: 100% by auto
// roc 2008-06 0048d7a0  unit: RBX::VBrickColor::?$TypedPropertyDescriptor  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0048d7a0
//
// 0048d7a0  6aff                 push -1
// 0048d7a2  6828d97b00           push 0x7bd928
// 0048d7a7  64a100000000         mov eax, dword ptr fs:[0]
// 0048d7ad  50                   push eax
// 0048d7ae  64892500000000       mov dword ptr fs:[0], esp
// 0048d7b5  83ec0c               sub esp, 0xc
// 0048d7b8  56                   push esi
// 0048d7b9  8bf1                 mov esi, ecx
// 0048d7bb  89742404             mov dword ptr [esp + 4], esi
// 0048d7bf  8b4618               mov eax, dword ptr [esi + 0x18]
// 0048d7c2  8b0e                 mov ecx, dword ptr [esi]
// 0048d7c4  8b10                 mov edx, dword ptr [eax]
// 0048d7c6  50                   push eax
// 0048d7c7  51                   push ecx
// 0048d7c8  52                   push edx
// 0048d7c9  51                   push ecx
// 0048d7ca  8d442418             lea eax, [esp + 0x18]
// 0048d7ce  50                   push eax
// 0048d7cf  8bce                 mov ecx, esi
// 0048d7d1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 0048d7d9  e8d2612000           call 0x6939b0
// 0048d7de  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0048d7e1  51                   push ecx
// 0048d7e2  e8932e2100           call 0x6a067a
// 0048d7e7  8b16                 mov edx, dword ptr [esi]
// 0048d7e9  52                   push edx
// 0048d7ea  c7461800000000       mov dword ptr [esi + 0x18], 0
// 0048d7f1  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0048d7f8  e87d2e2100           call 0x6a067a
// 0048d7fd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0048d801  83c408               add esp, 8
// 0048d804  5e                   pop esi
// 0048d805  64890d00000000       mov dword ptr fs:[0], ecx
// 0048d80c  83c418               add esp, 0x18
// 0048d80f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
