// from server: 100% by auto
// roc 2010-06 00891950  unit: CXTColorBase  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00891950
//
// 00891950  56                   push esi
// 00891951  8bf1                 mov esi, ecx
// 00891953  e81866f1ff           call 0x7a7f70
// 00891958  8b4620               mov eax, dword ptr [esi + 0x20]
// 0089195b  50                   push eax
// 0089195c  ff1580bc9e00         call dword ptr [0x9ebc80]
// 00891962  50                   push eax
// 00891963  e80263f1ff           call 0x7a7c6a
// 00891968  8b442410             mov eax, dword ptr [esp + 0x10]
// 0089196c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00891970  8b16                 mov edx, dword ptr [esi]
// 00891972  8b924c010000         mov edx, dword ptr [edx + 0x14c]
// 00891978  50                   push eax
// 00891979  51                   push ecx
// 0089197a  8bce                 mov ecx, esi
// 0089197c  ffd2                 call edx
// 0089197e  ff1580ba9e00         call dword ptr [0x9eba80]
// 00891984  50                   push eax
// 00891985  e8e062f1ff           call 0x7a7c6a
// 0089198a  3bc6                 cmp eax, esi
// 0089198c  7407                 je 0x891995
// 0089198e  8bce                 mov ecx, esi
// 00891990  e8ad63f1ff           call 0x7a7d42
// 00891995  5e                   pop esi
// 00891996  c20c00               ret 0xc
// library xtp-13.2.1-shared-mfc/Source\Controls\XTColorPageCustom.cpp (function ?OnLButtonDown@CXTColorBase@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Controls/XTColorPageCustom.cpp
