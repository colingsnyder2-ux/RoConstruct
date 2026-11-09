// from server: 100% by auto
// roc 2009-12 00708570  unit: RBX::VInstance::?$NonFactoryProduct  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00708570
//
// 00708570  6aff                 push -1
// 00708572  68888f9400           push 0x948f88
// 00708577  64a100000000         mov eax, dword ptr fs:[0]
// 0070857d  50                   push eax
// 0070857e  64892500000000       mov dword ptr fs:[0], esp
// 00708585  83ec0c               sub esp, 0xc
// 00708588  56                   push esi
// 00708589  8bf1                 mov esi, ecx
// 0070858b  89742404             mov dword ptr [esp + 4], esi
// 0070858f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00708592  8b0e                 mov ecx, dword ptr [esi]
// 00708594  8b10                 mov edx, dword ptr [eax]
// 00708596  50                   push eax
// 00708597  51                   push ecx
// 00708598  52                   push edx
// 00708599  51                   push ecx
// 0070859a  8d442418             lea eax, [esp + 0x18]
// 0070859e  50                   push eax
// 0070859f  8bce                 mov ecx, esi
// 007085a1  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 007085a9  e822e7ffff           call 0x706cd0
// 007085ae  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007085b1  51                   push ecx
// 007085b2  e8a3b20e00           call 0x7f385a
// 007085b7  8b16                 mov edx, dword ptr [esi]
// 007085b9  52                   push edx
// 007085ba  c7461800000000       mov dword ptr [esi + 0x18], 0
// 007085c1  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 007085c8  e88db20e00           call 0x7f385a
// 007085cd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007085d1  83c408               add esp, 8
// 007085d4  5e                   pop esi
// 007085d5  64890d00000000       mov dword ptr fs:[0], ecx
// 007085dc  83c418               add esp, 0x18
// 007085df  c3                   ret 
// standard library set<ptr> (function ??1?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE@XZ)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
