// from server: 100% by auto
// roc 2009-06 0061a090  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0061a090
//
// 0061a090  6aff                 push -1
// 0061a092  68485e8500           push 0x855e48
// 0061a097  64a100000000         mov eax, dword ptr fs:[0]
// 0061a09d  50                   push eax
// 0061a09e  64892500000000       mov dword ptr fs:[0], esp
// 0061a0a5  83ec0c               sub esp, 0xc
// 0061a0a8  56                   push esi
// 0061a0a9  8bf1                 mov esi, ecx
// 0061a0ab  89742404             mov dword ptr [esp + 4], esi
// 0061a0af  8b4618               mov eax, dword ptr [esi + 0x18]
// 0061a0b2  8b0e                 mov ecx, dword ptr [esi]
// 0061a0b4  8b10                 mov edx, dword ptr [eax]
// 0061a0b6  50                   push eax
// 0061a0b7  51                   push ecx
// 0061a0b8  52                   push edx
// 0061a0b9  51                   push ecx
// 0061a0ba  8d442418             lea eax, [esp + 0x18]
// 0061a0be  50                   push eax
// 0061a0bf  8bce                 mov ecx, esi
// 0061a0c1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 0061a0c9  e8b2fcffff           call 0x619d80
// 0061a0ce  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0061a0d1  51                   push ecx
// 0061a0d2  e85be90f00           call 0x718a32
// 0061a0d7  8b16                 mov edx, dword ptr [esi]
// 0061a0d9  52                   push edx
// 0061a0da  c7461800000000       mov dword ptr [esi + 0x18], 0
// 0061a0e1  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0061a0e8  e845e90f00           call 0x718a32
// 0061a0ed  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0061a0f1  83c408               add esp, 8
// 0061a0f4  5e                   pop esi
// 0061a0f5  64890d00000000       mov dword ptr fs:[0], ecx
// 0061a0fc  83c418               add esp, 0x18
// 0061a0ff  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
