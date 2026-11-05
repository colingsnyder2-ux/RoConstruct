// from server: 100% by auto
// roc 2010-06 0080a3d0  unit: CXTPTabClientWnd  size: 105 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0080a3d0
//
// 0080a3d0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0080a3d4  56                   push esi
// 0080a3d5  57                   push edi
// 0080a3d6  e8155debff           call 0x6c00f0
// 0080a3db  8b3d54ba9e00         mov edi, dword ptr [0x9eba54]
// 0080a3e1  6a00                 push 0
// 0080a3e3  6a00                 push 0
// 0080a3e5  8bf0                 mov esi, eax
// 0080a3e7  6860280000           push 0x2860
// 0080a3ec  56                   push esi
// 0080a3ed  ffd7                 call edi
// 0080a3ef  85c0                 test eax, eax
// 0080a3f1  7541                 jne 0x80a434
// 0080a3f3  50                   push eax
// 0080a3f4  50                   push eax
// 0080a3f5  6a7f                 push 0x7f
// 0080a3f7  56                   push esi
// 0080a3f8  ffd7                 call edi
// 0080a3fa  85c0                 test eax, eax
// 0080a3fc  7536                 jne 0x80a434
// 0080a3fe  50                   push eax
// 0080a3ff  6a01                 push 1
// 0080a401  6a7f                 push 0x7f
// 0080a403  56                   push esi
// 0080a404  ffd7                 call edi
// 0080a406  85c0                 test eax, eax
// 0080a408  752a                 jne 0x80a434
// 0080a40a  8b3dc0ba9e00         mov edi, dword ptr [0x9ebac0]
// 0080a410  6ade                 push -0x22
// 0080a412  56                   push esi
// 0080a413  ffd7                 call edi
// 0080a415  85c0                 test eax, eax
// 0080a417  751b                 jne 0x80a434
// 0080a419  6af2                 push -0xe
// 0080a41b  56                   push esi
// 0080a41c  ffd7                 call edi
// 0080a41e  85c0                 test eax, eax
// 0080a420  7512                 jne 0x80a434
// 0080a422  e837d8f9ff           call 0x7a7c5e
// 0080a427  68057f0000           push 0x7f05
// 0080a42c  6a00                 push 0
// 0080a42e  ff1538bc9e00         call dword ptr [0x9ebc38]
// 0080a434  5f                   pop edi
// 0080a435  5e                   pop esi
// 0080a436  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?GetItemIcon@CXTPTabClientWnd@@MBEPAUHICON__@@PBVCXTPTabManagerItem@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPTabClientWnd.cpp
