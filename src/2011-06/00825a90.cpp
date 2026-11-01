// from server: 100% by auto
// roc 2011-06 00825a90  unit: CXTPImageManagerIcon  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00825a90
//
// 00825a90  56                   push esi
// 00825a91  57                   push edi
// 00825a92  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00825a96  57                   push edi
// 00825a97  8bf1                 mov esi, ecx
// 00825a99  e852daffff           call 0x8234f0
// 00825a9e  85c0                 test eax, eax
// 00825aa0  7413                 je 0x825ab5
// 00825aa2  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00825aa6  6a01                 push 1
// 00825aa8  51                   push ecx
// 00825aa9  8bc8                 mov ecx, eax
// 00825aab  e850d9ffff           call 0x823400
// 00825ab0  5f                   pop edi
// 00825ab1  5e                   pop esi
// 00825ab2  c20800               ret 8
// 00825ab5  57                   push edi
// 00825ab6  8bce                 mov ecx, esi
// 00825ab8  e883cfffff           call 0x822a40
// 00825abd  85c0                 test eax, eax
// 00825abf  740d                 je 0x825ace
// 00825ac1  57                   push edi
// 00825ac2  8bc8                 mov ecx, eax
// 00825ac4  e847dfffff           call 0x823a10
// 00825ac9  5f                   pop edi
// 00825aca  5e                   pop esi
// 00825acb  c20800               ret 8
// 00825ace  5f                   pop edi
// 00825acf  33c0                 xor eax, eax
// 00825ad1  5e                   pop esi
// 00825ad2  c20800               ret 8
// copied from an identical function in another client (function ?setImage@CXTPImageManager@ns_ROCX000037@ns_ROCX00002b@@QAEPAXHH@Z)

namespace ns_ROCX000037 {
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControl.cpp
}
