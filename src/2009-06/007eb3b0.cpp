// from server: 100% by auto
// roc 2009-06 007eb3b0  unit: CXTPControlCustom  size: 109 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007eb3b0
//
// 007eb3b0  55                   push ebp
// 007eb3b1  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 007eb3b5  56                   push esi
// 007eb3b6  57                   push edi
// 007eb3b7  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007eb3bb  8bb7a0000000         mov esi, dword ptr [edi + 0xa0]
// 007eb3c1  55                   push ebp
// 007eb3c2  8bce                 mov ecx, esi
// 007eb3c4  e833e5f2ff           call 0x7198fc
// 007eb3c9  85c0                 test eax, eax
// 007eb3cb  740e                 je 0x7eb3db
// 007eb3cd  55                   push ebp
// 007eb3ce  8bce                 mov ecx, esi
// 007eb3d0  e827e5f2ff           call 0x7198fc
// 007eb3d5  5f                   pop edi
// 007eb3d6  5e                   pop esi
// 007eb3d7  5d                   pop ebp
// 007eb3d8  c20800               ret 8
// 007eb3db  33f6                 xor esi, esi
// 007eb3dd  39b784000000         cmp dword ptr [edi + 0x84], esi
// 007eb3e3  53                   push ebx
// 007eb3e4  7e1f                 jle 0x7eb405
// 007eb3e6  56                   push esi
// 007eb3e7  8bcf                 mov ecx, edi
// 007eb3e9  e842ecf3ff           call 0x72a030
// 007eb3ee  8bd8                 mov ebx, eax
// 007eb3f0  55                   push ebp
// 007eb3f1  8bcb                 mov ecx, ebx
// 007eb3f3  e804e5f2ff           call 0x7198fc
// 007eb3f8  85c0                 test eax, eax
// 007eb3fa  7512                 jne 0x7eb40e
// 007eb3fc  46                   inc esi
// 007eb3fd  3bb784000000         cmp esi, dword ptr [edi + 0x84]
// 007eb403  7ce1                 jl 0x7eb3e6
// 007eb405  5b                   pop ebx
// 007eb406  5f                   pop edi
// 007eb407  5e                   pop esi
// 007eb408  33c0                 xor eax, eax
// 007eb40a  5d                   pop ebp
// 007eb40b  c20800               ret 8
// 007eb40e  55                   push ebp
// 007eb40f  8bcb                 mov ecx, ebx
// 007eb411  e8e6e4f2ff           call 0x7198fc
// 007eb416  5b                   pop ebx
// 007eb417  5f                   pop edi
// 007eb418  5e                   pop esi
// 007eb419  5d                   pop ebp
// 007eb41a  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPControlCustom.cpp (function ?FindChildWindow@CXTPControlCustom@@AAEPAVCWnd@@PAVCXTPCommandBars@@I@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlCustom.cpp
