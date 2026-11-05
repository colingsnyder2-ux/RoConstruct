// from server: 100% by auto
// roc 2009-06 00645a90  unit: RBX::Soundscape::W4ReverbType::?$EnumDesc  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00645a90
//
// 00645a90  6aff                 push -1
// 00645a92  68485e8500           push 0x855e48
// 00645a97  64a100000000         mov eax, dword ptr fs:[0]
// 00645a9d  50                   push eax
// 00645a9e  64892500000000       mov dword ptr fs:[0], esp
// 00645aa5  83ec0c               sub esp, 0xc
// 00645aa8  56                   push esi
// 00645aa9  8bf1                 mov esi, ecx
// 00645aab  89742404             mov dword ptr [esp + 4], esi
// 00645aaf  8b4618               mov eax, dword ptr [esi + 0x18]
// 00645ab2  8b0e                 mov ecx, dword ptr [esi]
// 00645ab4  8b10                 mov edx, dword ptr [eax]
// 00645ab6  50                   push eax
// 00645ab7  51                   push ecx
// 00645ab8  52                   push edx
// 00645ab9  51                   push ecx
// 00645aba  8d442418             lea eax, [esp + 0x18]
// 00645abe  50                   push eax
// 00645abf  8bce                 mov ecx, esi
// 00645ac1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00645ac9  e8c2faffff           call 0x645590
// 00645ace  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00645ad1  51                   push ecx
// 00645ad2  e85b2f0d00           call 0x718a32
// 00645ad7  8b16                 mov edx, dword ptr [esi]
// 00645ad9  52                   push edx
// 00645ada  c7461800000000       mov dword ptr [esi + 0x18], 0
// 00645ae1  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00645ae8  e8452f0d00           call 0x718a32
// 00645aed  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00645af1  83c408               add esp, 8
// 00645af4  5e                   pop esi
// 00645af5  64890d00000000       mov dword ptr fs:[0], ecx
// 00645afc  83c418               add esp, 0x18
// 00645aff  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
