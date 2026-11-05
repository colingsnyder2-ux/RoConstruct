// from server: 100% by auto
// roc 2008-06 00655800  unit: RBX::ScoreHud  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00655800
//
// 00655800  6aff                 push -1
// 00655802  6828d97b00           push 0x7bd928
// 00655807  64a100000000         mov eax, dword ptr fs:[0]
// 0065580d  50                   push eax
// 0065580e  64892500000000       mov dword ptr fs:[0], esp
// 00655815  83ec0c               sub esp, 0xc
// 00655818  56                   push esi
// 00655819  8bf1                 mov esi, ecx
// 0065581b  89742404             mov dword ptr [esp + 4], esi
// 0065581f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00655822  8b0e                 mov ecx, dword ptr [esi]
// 00655824  8b10                 mov edx, dword ptr [eax]
// 00655826  50                   push eax
// 00655827  51                   push ecx
// 00655828  52                   push edx
// 00655829  51                   push ecx
// 0065582a  8d442418             lea eax, [esp + 0x18]
// 0065582e  50                   push eax
// 0065582f  8bce                 mov ecx, esi
// 00655831  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00655839  e832ecffff           call 0x654470
// 0065583e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00655841  51                   push ecx
// 00655842  e833ae0400           call 0x6a067a
// 00655847  8b16                 mov edx, dword ptr [esi]
// 00655849  52                   push edx
// 0065584a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00655851  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00655858  e81dae0400           call 0x6a067a
// 0065585d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00655861  83c408               add esp, 8
// 00655864  5e                   pop esi
// 00655865  64890d00000000       mov dword ptr fs:[0], ecx
// 0065586c  83c418               add esp, 0x18
// 0065586f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
