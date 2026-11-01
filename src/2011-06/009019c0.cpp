// from server: 100% by auto
// roc 2011-06 009019c0  unit: CXTCaptionButtonTheme  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 009019c0
//
// 009019c0  8b01                 mov eax, dword ptr [ecx]
// 009019c2  8b5014               mov edx, dword ptr [eax + 0x14]
// 009019c5  56                   push esi
// 009019c6  8b742408             mov esi, dword ptr [esp + 8]
// 009019ca  56                   push esi
// 009019cb  ffd2                 call edx
// 009019cd  85c0                 test eax, eax
// 009019cf  7409                 je 0x9019da
// 009019d1  b801000000           mov eax, 1
// 009019d6  5e                   pop esi
// 009019d7  c20400               ret 4
// 009019da  8b06                 mov eax, dword ptr [esi]
// 009019dc  8b9068010000         mov edx, dword ptr [eax + 0x168]
// 009019e2  8bce                 mov ecx, esi
// 009019e4  ffd2                 call edx
// 009019e6  a803                 test al, 3
// 009019e8  b800000000           mov eax, 0
// 009019ed  0f95c0               setne al
// 009019f0  5e                   pop esi
// 009019f1  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\Controls\Deprecated\XTButtonTheme.cpp (function ?CanHilite@CXTButtonTheme@@UAEHPAVCXTButton@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Controls/Deprecated/XTButtonTheme.cpp
