// from server: 100% by auto
// roc 2007-08 0040b710  unit: VCBrowserViewExternal::?$CComObjectNoLock  size: 124 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040b710
//
// 0040b710  55                   push ebp
// 0040b711  8bec                 mov ebp, esp
// 0040b713  6aff                 push -1
// 0040b715  68009a7300           push 0x739a00
// 0040b71a  64a100000000         mov eax, dword ptr fs:[0]
// 0040b720  50                   push eax
// 0040b721  83ec08               sub esp, 8
// 0040b724  53                   push ebx
// 0040b725  56                   push esi
// 0040b726  57                   push edi
// 0040b727  a188518b00           mov eax, dword ptr [0x8b5188]
// 0040b72c  33c5                 xor eax, ebp
// 0040b72e  50                   push eax
// 0040b72f  8d45f4               lea eax, [ebp - 0xc]
// 0040b732  64a300000000         mov dword ptr fs:[0], eax
// 0040b738  8965f0               mov dword ptr [ebp - 0x10], esp
// 0040b73b  6a24                 push 0x24
// 0040b73d  e8b4472200           call 0x62fef6
// 0040b742  8bf0                 mov esi, eax
// 0040b744  83c404               add esp, 4
// 0040b747  85f6                 test esi, esi
// 0040b749  8975ec               mov dword ptr [ebp - 0x14], esi
// 0040b74c  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0040b753  7405                 je 0x40b75a
// 0040b755  8b4508               mov eax, dword ptr [ebp + 8]
// 0040b758  8906                 mov dword ptr [esi], eax
// 0040b75a  8d4604               lea eax, [esi + 4]
// 0040b75d  85c0                 test eax, eax
// 0040b75f  7405                 je 0x40b766
// 0040b761  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 0040b764  8908                 mov dword ptr [eax], ecx
// 0040b766  8b5510               mov edx, dword ptr [ebp + 0x10]
// 0040b769  52                   push edx
// 0040b76a  8d4608               lea eax, [esi + 8]
// 0040b76d  50                   push eax
// 0040b76e  e8adf5ffff           call 0x40ad20
// 0040b773  83c408               add esp, 8
// 0040b776  8bc6                 mov eax, esi
// 0040b778  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0040b77b  64890d00000000       mov dword ptr fs:[0], ecx
// 0040b782  59                   pop ecx
// 0040b783  5f                   pop edi
// 0040b784  5e                   pop esi
// 0040b785  5b                   pop ebx
// 0040b786  8be5                 mov esp, ebp
// 0040b788  5d                   pop ebp
// 0040b789  c20c00               ret 0xc
// standard library list<string> (function ?_Buynode@?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEPAU_Node@?$_List_nod@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@2@PAU342@0ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
