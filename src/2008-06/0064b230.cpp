// from server: 100% by auto
// roc 2008-06 0064b230  unit: RBX::SleepStage  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0064b230
//
// 0064b230  6aff                 push -1
// 0064b232  6828d97b00           push 0x7bd928
// 0064b237  64a100000000         mov eax, dword ptr fs:[0]
// 0064b23d  50                   push eax
// 0064b23e  64892500000000       mov dword ptr fs:[0], esp
// 0064b245  83ec0c               sub esp, 0xc
// 0064b248  56                   push esi
// 0064b249  8bf1                 mov esi, ecx
// 0064b24b  89742404             mov dword ptr [esp + 4], esi
// 0064b24f  8b4618               mov eax, dword ptr [esi + 0x18]
// 0064b252  8b0e                 mov ecx, dword ptr [esi]
// 0064b254  8b10                 mov edx, dword ptr [eax]
// 0064b256  50                   push eax
// 0064b257  51                   push ecx
// 0064b258  52                   push edx
// 0064b259  51                   push ecx
// 0064b25a  8d442418             lea eax, [esp + 0x18]
// 0064b25e  50                   push eax
// 0064b25f  8bce                 mov ecx, esi
// 0064b261  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 0064b269  e8c2faffff           call 0x64ad30
// 0064b26e  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0064b271  51                   push ecx
// 0064b272  e803540500           call 0x6a067a
// 0064b277  8b16                 mov edx, dword ptr [esi]
// 0064b279  52                   push edx
// 0064b27a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 0064b281  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0064b288  e8ed530500           call 0x6a067a
// 0064b28d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0064b291  83c408               add esp, 8
// 0064b294  5e                   pop esi
// 0064b295  64890d00000000       mov dword ptr fs:[0], ecx
// 0064b29c  83c418               add esp, 0x18
// 0064b29f  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
