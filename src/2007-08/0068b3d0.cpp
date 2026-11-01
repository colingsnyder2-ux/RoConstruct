// from server: 100% by auto
// roc 2007-08 0068b3d0  unit: CXTPTabClientWnd  size: 116 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0068b3d0
//
// 0068b3d0  56                   push esi
// 0068b3d1  8bf1                 mov esi, ecx
// 0068b3d3  8b06                 mov eax, dword ptr [esi]
// 0068b3d5  8b904c010000         mov edx, dword ptr [eax + 0x14c]
// 0068b3db  ffd2                 call edx
// 0068b3dd  85c0                 test eax, eax
// 0068b3df  7448                 je 0x68b429
// 0068b3e1  83beb000000000       cmp dword ptr [esi + 0xb0], 0
// 0068b3e8  751c                 jne 0x68b406
// 0068b3ea  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0068b3ee  8b5104               mov edx, dword ptr [ecx + 4]
// 0068b3f1  8b06                 mov eax, dword ptr [esi]
// 0068b3f3  8b8018010000         mov eax, dword ptr [eax + 0x118]
// 0068b3f9  6a00                 push 0
// 0068b3fb  52                   push edx
// 0068b3fc  6a0f                 push 0xf
// 0068b3fe  8bce                 mov ecx, esi
// 0068b400  ffd0                 call eax
// 0068b402  5e                   pop esi
// 0068b403  c21400               ret 0x14
// 0068b406  6a0c                 push 0xc
// 0068b408  8bc8                 mov ecx, eax
// 0068b40a  e8c16dfaff           call 0x6321d0
// 0068b40f  8bc8                 mov ecx, eax
// 0068b411  e85a19fbff           call 0x63cd70
// 0068b416  50                   push eax
// 0068b417  8d4c2410             lea ecx, [esp + 0x10]
// 0068b41b  51                   push ecx
// 0068b41c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0068b420  e88b54faff           call 0x6308b0
// 0068b425  5e                   pop esi
// 0068b426  c21400               ret 0x14
// 0068b429  6a0c                 push 0xc
// 0068b42b  ff1558ee7700         call dword ptr [0x77ee58]
// 0068b431  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0068b435  50                   push eax
// 0068b436  8d542410             lea edx, [esp + 0x10]
// 0068b43a  52                   push edx
// 0068b43b  e87054faff           call 0x6308b0
// 0068b440  5e                   pop esi
// 0068b441  c21400               ret 0x14
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?OnFillBackground@CXTPTabClientWnd@@UAEXPAVCDC@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
