// from server: 100% by auto
// roc 2011-06 00403e00  unit: RBX::VRenderHooksService::?$FactoryProduct::Creator  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00403e00
//
// 00403e00  51                   push ecx
// 00403e01  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00403e05  6a00                 push 0
// 00403e07  6a00                 push 0
// 00403e09  6a00                 push 0
// 00403e0b  6a00                 push 0
// 00403e0d  6a00                 push 0
// 00403e0f  6a00                 push 0
// 00403e11  6a00                 push 0
// 00403e13  8d44241c             lea eax, [esp + 0x1c]
// 00403e17  50                   push eax
// 00403e18  6a00                 push 0
// 00403e1a  6a00                 push 0
// 00403e1c  6a00                 push 0
// 00403e1e  51                   push ecx
// 00403e1f  c744243000000000     mov dword ptr [esp + 0x30], 0
// 00403e27  ff154800a400         call dword ptr [0xa40048]
// 00403e2d  85c0                 test eax, eax
// 00403e2f  7406                 je 0x403e37
// 00403e31  33c0                 xor eax, eax
// 00403e33  59                   pop ecx
// 00403e34  c20400               ret 4
// 00403e37  33d2                 xor edx, edx
// 00403e39  3b1424               cmp edx, dword ptr [esp]
// 00403e3c  1bc0                 sbb eax, eax
// 00403e3e  f7d8                 neg eax
// 00403e40  59                   pop ecx
// 00403e41  c20400               ret 4
// library atl-8.0/atl.cpp (function ?HasSubKeys@CRegParser@ATL@@IAEHPAUHKEY__@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
