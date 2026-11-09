// from server: 100% by auto
// roc 2010-06 006116d0  unit: RBX::VScriptContext::?$FactoryProduct  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006116d0
//
// 006116d0  83ec08               sub esp, 8
// 006116d3  53                   push ebx
// 006116d4  55                   push ebp
// 006116d5  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 006116db  56                   push esi
// 006116dc  8bf1                 mov esi, ecx
// 006116de  8b4618               mov eax, dword ptr [esi + 0x18]
// 006116e1  8b18                 mov ebx, dword ptr [eax]
// 006116e3  8b06                 mov eax, dword ptr [esi]
// 006116e5  57                   push edi
// 006116e6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006116ea  85ff                 test edi, edi
// 006116ec  7404                 je 0x6116f2
// 006116ee  3bf8                 cmp edi, eax
// 006116f0  7406                 je 0x6116f8
// 006116f2  ffd5                 call ebp
// 006116f4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006116f8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 006116fc  7562                 jne 0x611760
// 006116fe  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00611702  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00611705  8b06                 mov eax, dword ptr [esi]
// 00611707  85c9                 test ecx, ecx
// 00611709  7404                 je 0x61170f
// 0061170b  3bc8                 cmp ecx, eax
// 0061170d  7406                 je 0x611715
// 0061170f  ffd5                 call ebp
// 00611711  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00611715  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 00611719  7545                 jne 0x611760
// 0061171b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0061171e  8b5104               mov edx, dword ptr [ecx + 4]
// 00611721  52                   push edx
// 00611722  8bce                 mov ecx, esi
// 00611724  e8e7ebffff           call 0x610310
// 00611729  8b4618               mov eax, dword ptr [esi + 0x18]
// 0061172c  894004               mov dword ptr [eax + 4], eax
// 0061172f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00611732  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00611739  8900                 mov dword ptr [eax], eax
// 0061173b  8b4618               mov eax, dword ptr [esi + 0x18]
// 0061173e  894008               mov dword ptr [eax + 8], eax
// 00611741  8b4618               mov eax, dword ptr [esi + 0x18]
// 00611744  8b16                 mov edx, dword ptr [esi]
// 00611746  8b08                 mov ecx, dword ptr [eax]
// 00611748  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0061174c  5f                   pop edi
// 0061174d  5e                   pop esi
// 0061174e  5d                   pop ebp
// 0061174f  894804               mov dword ptr [eax + 4], ecx
// 00611752  8910                 mov dword ptr [eax], edx
// 00611754  5b                   pop ebx
// 00611755  83c408               add esp, 8
// 00611758  c21400               ret 0x14
// 0061175b  eb03                 jmp 0x611760
// 0061175d  8d4900               lea ecx, [ecx]
// 00611760  85ff                 test edi, edi
// 00611762  7406                 je 0x61176a
// 00611764  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00611768  7406                 je 0x611770
// 0061176a  ffd5                 call ebp
// 0061176c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00611770  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00611774  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00611778  741d                 je 0x611797
// 0061177a  8d4c2420             lea ecx, [esp + 0x20]
// 0061177e  e8bd9effff           call 0x60b640
// 00611783  53                   push ebx
// 00611784  57                   push edi
// 00611785  8d442418             lea eax, [esp + 0x18]
// 00611789  50                   push eax
// 0061178a  8bce                 mov ecx, esi
// 0061178c  e87fe8ffff           call 0x610010
// 00611791  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00611795  ebc9                 jmp 0x611760
// 00611797  8b36                 mov esi, dword ptr [esi]
// 00611799  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0061179d  5f                   pop edi
// 0061179e  8930                 mov dword ptr [eax], esi
// 006117a0  5e                   pop esi
// 006117a1  5d                   pop ebp
// 006117a2  895804               mov dword ptr [eax + 4], ebx
// 006117a5  5b                   pop ebx
// 006117a6  83c408               add esp, 8
// 006117a9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
