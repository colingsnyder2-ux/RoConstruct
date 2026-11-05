// from server: 100% by auto
// roc 2008-06 004f1830  unit: RBX::RenderBase::VMaterialBase::?$WeakReferenceCountedPointer  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004f1830
//
// 004f1830  83ec08               sub esp, 8
// 004f1833  53                   push ebx
// 004f1834  55                   push ebp
// 004f1835  8b2d90288000         mov ebp, dword ptr [0x802890]
// 004f183b  56                   push esi
// 004f183c  8bf1                 mov esi, ecx
// 004f183e  8b4618               mov eax, dword ptr [esi + 0x18]
// 004f1841  8b18                 mov ebx, dword ptr [eax]
// 004f1843  8b06                 mov eax, dword ptr [esi]
// 004f1845  57                   push edi
// 004f1846  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004f184a  85ff                 test edi, edi
// 004f184c  7404                 je 0x4f1852
// 004f184e  3bf8                 cmp edi, eax
// 004f1850  7406                 je 0x4f1858
// 004f1852  ffd5                 call ebp
// 004f1854  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004f1858  395c2424             cmp dword ptr [esp + 0x24], ebx
// 004f185c  7562                 jne 0x4f18c0
// 004f185e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004f1862  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 004f1865  8b06                 mov eax, dword ptr [esi]
// 004f1867  85c9                 test ecx, ecx
// 004f1869  7404                 je 0x4f186f
// 004f186b  3bc8                 cmp ecx, eax
// 004f186d  7406                 je 0x4f1875
// 004f186f  ffd5                 call ebp
// 004f1871  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004f1875  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 004f1879  7545                 jne 0x4f18c0
// 004f187b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004f187e  8b5104               mov edx, dword ptr [ecx + 4]
// 004f1881  52                   push edx
// 004f1882  8bce                 mov ecx, esi
// 004f1884  e8e7fbffff           call 0x4f1470
// 004f1889  8b4618               mov eax, dword ptr [esi + 0x18]
// 004f188c  894004               mov dword ptr [eax + 4], eax
// 004f188f  8b4618               mov eax, dword ptr [esi + 0x18]
// 004f1892  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004f1899  8900                 mov dword ptr [eax], eax
// 004f189b  8b4618               mov eax, dword ptr [esi + 0x18]
// 004f189e  894008               mov dword ptr [eax + 8], eax
// 004f18a1  8b4618               mov eax, dword ptr [esi + 0x18]
// 004f18a4  8b16                 mov edx, dword ptr [esi]
// 004f18a6  8b08                 mov ecx, dword ptr [eax]
// 004f18a8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004f18ac  5f                   pop edi
// 004f18ad  5e                   pop esi
// 004f18ae  5d                   pop ebp
// 004f18af  894804               mov dword ptr [eax + 4], ecx
// 004f18b2  8910                 mov dword ptr [eax], edx
// 004f18b4  5b                   pop ebx
// 004f18b5  83c408               add esp, 8
// 004f18b8  c21400               ret 0x14
// 004f18bb  eb03                 jmp 0x4f18c0
// 004f18bd  8d4900               lea ecx, [ecx]
// 004f18c0  85ff                 test edi, edi
// 004f18c2  7406                 je 0x4f18ca
// 004f18c4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 004f18c8  7406                 je 0x4f18d0
// 004f18ca  ffd5                 call ebp
// 004f18cc  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004f18d0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004f18d4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 004f18d8  741d                 je 0x4f18f7
// 004f18da  8d4c2420             lea ecx, [esp + 0x20]
// 004f18de  e85d59feff           call 0x4d7240
// 004f18e3  53                   push ebx
// 004f18e4  57                   push edi
// 004f18e5  8d442418             lea eax, [esp + 0x18]
// 004f18e9  50                   push eax
// 004f18ea  8bce                 mov ecx, esi
// 004f18ec  e88ff8ffff           call 0x4f1180
// 004f18f1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004f18f5  ebc9                 jmp 0x4f18c0
// 004f18f7  8b36                 mov esi, dword ptr [esi]
// 004f18f9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004f18fd  5f                   pop edi
// 004f18fe  8930                 mov dword ptr [eax], esi
// 004f1900  5e                   pop esi
// 004f1901  5d                   pop ebp
// 004f1902  895804               mov dword ptr [eax + 4], ebx
// 004f1905  5b                   pop ebx
// 004f1906  83c408               add esp, 8
// 004f1909  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
