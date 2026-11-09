// from server: 100% by auto
// roc 2010-06 00891a00  unit: CXTColorBase  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00891a00
//
// 00891a00  56                   push esi
// 00891a01  8bf1                 mov esi, ecx
// 00891a03  e86865f1ff           call 0x7a7f70
// 00891a08  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00891a0c  8b06                 mov eax, dword ptr [esi]
// 00891a0e  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00891a12  8b804c010000         mov eax, dword ptr [eax + 0x14c]
// 00891a18  51                   push ecx
// 00891a19  52                   push edx
// 00891a1a  8bce                 mov ecx, esi
// 00891a1c  ffd0                 call eax
// 00891a1e  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00891a21  8b354cba9e00         mov esi, dword ptr [0x9eba4c]
// 00891a27  51                   push ecx
// 00891a28  ffd6                 call esi
// 00891a2a  50                   push eax
// 00891a2b  e83a62f1ff           call 0x7a7c6a
// 00891a30  8b5020               mov edx, dword ptr [eax + 0x20]
// 00891a33  52                   push edx
// 00891a34  ffd6                 call esi
// 00891a36  50                   push eax
// 00891a37  e82e62f1ff           call 0x7a7c6a
// 00891a3c  6a01                 push 1
// 00891a3e  8bc8                 mov ecx, eax
// 00891a40  e899bc0e00           call 0x97d6de
// 00891a45  5e                   pop esi
// 00891a46  c20c00               ret 0xc
// library xtp-13.2.1-shared-mfc/Source\Controls\XTColorPageCustom.cpp (function ?OnLButtonDblClk@CXTColorBase@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Controls/XTColorPageCustom.cpp
