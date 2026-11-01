// from server: 100% by auto
// roc 2009-06 0080a0b0  unit: CXTCaptionButtonTheme  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0080a0b0
//
// 0080a0b0  53                   push ebx
// 0080a0b1  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 0080a0b5  56                   push esi
// 0080a0b6  8bb3ac000000         mov esi, dword ptr [ebx + 0xac]
// 0080a0bc  57                   push edi
// 0080a0bd  8bf9                 mov edi, ecx
// 0080a0bf  85f6                 test esi, esi
// 0080a0c1  7504                 jne 0x80a0c7
// 0080a0c3  33c0                 xor eax, eax
// 0080a0c5  eb03                 jmp 0x80a0ca
// 0080a0c7  8b4620               mov eax, dword ptr [esi + 0x20]
// 0080a0ca  50                   push eax
// 0080a0cb  ff15e0ed8900         call dword ptr [0x89ede0]
// 0080a0d1  85c0                 test eax, eax
// 0080a0d3  740d                 je 0x80a0e2
// 0080a0d5  8b4e74               mov ecx, dword ptr [esi + 0x74]
// 0080a0d8  8b07                 mov eax, dword ptr [edi]
// 0080a0da  8b502c               mov edx, dword ptr [eax + 0x2c]
// 0080a0dd  51                   push ecx
// 0080a0de  8bcf                 mov ecx, edi
// 0080a0e0  ffd2                 call edx
// 0080a0e2  8b442410             mov eax, dword ptr [esp + 0x10]
// 0080a0e6  53                   push ebx
// 0080a0e7  50                   push eax
// 0080a0e8  8bcf                 mov ecx, edi
// 0080a0ea  e851020100           call 0x81a340
// 0080a0ef  5f                   pop edi
// 0080a0f0  5e                   pop esi
// 0080a0f1  5b                   pop ebx
// 0080a0f2  c20800               ret 8
// library xtp-13.2.1/Source\Controls\XTCaptionTheme.cpp (function ?DrawButtonThemeBackground@CXTCaptionButtonTheme@@MAEHPAUtagDRAWITEMSTRUCT@@PAVCXTButton@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionTheme.cpp
