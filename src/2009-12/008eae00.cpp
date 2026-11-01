// from server: 100% by auto
// roc 2009-12 008eae00  unit: CXTPScrollBase  size: 131 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008eae00
//
// 008eae00  56                   push esi
// 008eae01  57                   push edi
// 008eae02  8bf9                 mov edi, ecx
// 008eae04  8b7760               mov esi, dword ptr [edi + 0x60]
// 008eae07  85f6                 test esi, esi
// 008eae09  7473                 je 0x8eae7e
// 008eae0b  c7461400000000       mov dword ptr [esi + 0x14], 0
// 008eae12  ff1520cc9800         call dword ptr [0x98cc20]
// 008eae18  837e3000             cmp dword ptr [esi + 0x30], 0
// 008eae1c  743a                 je 0x8eae58
// 008eae1e  837c240c00           cmp dword ptr [esp + 0xc], 0
// 008eae23  7409                 je 0x8eae2e
// 008eae25  8b4634               mov eax, dword ptr [esi + 0x34]
// 008eae28  8b480c               mov ecx, dword ptr [eax + 0xc]
// 008eae2b  894e24               mov dword ptr [esi + 0x24], ecx
// 008eae2e  8b4624               mov eax, dword ptr [esi + 0x24]
// 008eae31  8b17                 mov edx, dword ptr [edi]
// 008eae33  8b5218               mov edx, dword ptr [edx + 0x18]
// 008eae36  50                   push eax
// 008eae37  6a04                 push 4
// 008eae39  8bcf                 mov ecx, edi
// 008eae3b  ffd2                 call edx
// 008eae3d  8b07                 mov eax, dword ptr [edi]
// 008eae3f  8b501c               mov edx, dword ptr [eax + 0x1c]
// 008eae42  8bcf                 mov ecx, edi
// 008eae44  ffd2                 call edx
// 008eae46  8b17                 mov edx, dword ptr [edi]
// 008eae48  8b4218               mov eax, dword ptr [edx + 0x18]
// 008eae4b  6a00                 push 0
// 008eae4d  6a08                 push 8
// 008eae4f  8bcf                 mov ecx, edi
// 008eae51  ffd0                 call eax
// 008eae53  5f                   pop edi
// 008eae54  5e                   pop esi
// 008eae55  c20400               ret 4
// 008eae58  8b4618               mov eax, dword ptr [esi + 0x18]
// 008eae5b  85c0                 test eax, eax
// 008eae5d  7412                 je 0x8eae71
// 008eae5f  50                   push eax
// 008eae60  8b462c               mov eax, dword ptr [esi + 0x2c]
// 008eae63  50                   push eax
// 008eae64  ff15d0cb9800         call dword ptr [0x98cbd0]
// 008eae6a  c7461800000000       mov dword ptr [esi + 0x18], 0
// 008eae71  8b17                 mov edx, dword ptr [edi]
// 008eae73  8b4218               mov eax, dword ptr [edx + 0x18]
// 008eae76  6a00                 push 0
// 008eae78  6a08                 push 8
// 008eae7a  8bcf                 mov ecx, edi
// 008eae7c  ffd0                 call eax
// 008eae7e  5f                   pop edi
// 008eae7f  5e                   pop esi
// 008eae80  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPScrollBase.cpp (function ?EndScroll@CXTPScrollBase@@IAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPScrollBase.cpp
