// from server: 100% by auto
// roc 2010-06 007e7640  unit: CXTTreeBase::PAXPAXUCLRFONT::?$CMap  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e7640
//
// 007e7640  83ec10               sub esp, 0x10
// 007e7643  57                   push edi
// 007e7644  8bf9                 mov edi, ecx
// 007e7646  837f0400             cmp dword ptr [edi + 4], 0
// 007e764a  7444                 je 0x7e7690
// 007e764c  56                   push esi
// 007e764d  e8cef0ffff           call 0x7e6720
// 007e7652  8bf0                 mov esi, eax
// 007e7654  85f6                 test esi, esi
// 007e7656  7437                 je 0x7e768f
// 007e7658  53                   push ebx
// 007e7659  8b1d78ba9e00         mov ebx, dword ptr [0x9eba78]
// 007e765f  90                   nop 
// 007e7660  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 007e7663  6a01                 push 1
// 007e7665  8d442410             lea eax, [esp + 0x10]
// 007e7669  50                   push eax
// 007e766a  56                   push esi
// 007e766b  e8c60cfcff           call 0x7a8336
// 007e7670  8b5734               mov edx, dword ptr [edi + 0x34]
// 007e7673  8b4220               mov eax, dword ptr [edx + 0x20]
// 007e7676  6a01                 push 1
// 007e7678  8d4c2410             lea ecx, [esp + 0x10]
// 007e767c  51                   push ecx
// 007e767d  50                   push eax
// 007e767e  ffd3                 call ebx
// 007e7680  56                   push esi
// 007e7681  8bcf                 mov ecx, edi
// 007e7683  e8e8f0ffff           call 0x7e6770
// 007e7688  8bf0                 mov esi, eax
// 007e768a  85f6                 test esi, esi
// 007e768c  75d2                 jne 0x7e7660
// 007e768e  5b                   pop ebx
// 007e768f  5e                   pop esi
// 007e7690  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 007e7693  e8d808fcff           call 0x7a7f70
// 007e7698  5f                   pop edi
// 007e7699  83c410               add esp, 0x10
// 007e769c  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTTreeBase.cpp (function ?OnSetFocus@CXTTreeBase@@IAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTreeBase.cpp
