// from server: 100% by auto
// roc 2009-12 007c3570  unit: RBX::Network::$$A6AXABVChatMessage::?$signal::slot  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007c3570
//
// 007c3570  6aff                 push -1
// 007c3572  68888f9400           push 0x948f88
// 007c3577  64a100000000         mov eax, dword ptr fs:[0]
// 007c357d  50                   push eax
// 007c357e  64892500000000       mov dword ptr fs:[0], esp
// 007c3585  83ec0c               sub esp, 0xc
// 007c3588  56                   push esi
// 007c3589  8bf1                 mov esi, ecx
// 007c358b  89742404             mov dword ptr [esp + 4], esi
// 007c358f  8b4618               mov eax, dword ptr [esi + 0x18]
// 007c3592  8b0e                 mov ecx, dword ptr [esi]
// 007c3594  8b10                 mov edx, dword ptr [eax]
// 007c3596  50                   push eax
// 007c3597  51                   push ecx
// 007c3598  52                   push edx
// 007c3599  51                   push ecx
// 007c359a  8d442418             lea eax, [esp + 0x18]
// 007c359e  50                   push eax
// 007c359f  8bce                 mov ecx, esi
// 007c35a1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 007c35a9  e882fbffff           call 0x7c3130
// 007c35ae  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007c35b1  51                   push ecx
// 007c35b2  e8a3020300           call 0x7f385a
// 007c35b7  8b16                 mov edx, dword ptr [esi]
// 007c35b9  52                   push edx
// 007c35ba  c7461800000000       mov dword ptr [esi + 0x18], 0
// 007c35c1  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 007c35c8  e88d020300           call 0x7f385a
// 007c35cd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007c35d1  83c408               add esp, 8
// 007c35d4  5e                   pop esi
// 007c35d5  64890d00000000       mov dword ptr fs:[0], ecx
// 007c35dc  83c418               add esp, 0x18
// 007c35df  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
