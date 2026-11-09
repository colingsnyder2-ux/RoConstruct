// from server: 100% by auto
// roc 2010-06 008a82f0  unit: CXTCaptionButtonTheme  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008a82f0
//
// 008a82f0  8b01                 mov eax, dword ptr [ecx]
// 008a82f2  8b5014               mov edx, dword ptr [eax + 0x14]
// 008a82f5  56                   push esi
// 008a82f6  8b742408             mov esi, dword ptr [esp + 8]
// 008a82fa  56                   push esi
// 008a82fb  ffd2                 call edx
// 008a82fd  85c0                 test eax, eax
// 008a82ff  7409                 je 0x8a830a
// 008a8301  b801000000           mov eax, 1
// 008a8306  5e                   pop esi
// 008a8307  c20400               ret 4
// 008a830a  8b06                 mov eax, dword ptr [esi]
// 008a830c  8b9068010000         mov edx, dword ptr [eax + 0x168]
// 008a8312  8bce                 mov ecx, esi
// 008a8314  ffd2                 call edx
// 008a8316  a803                 test al, 3
// 008a8318  b800000000           mov eax, 0
// 008a831d  0f95c0               setne al
// 008a8320  5e                   pop esi
// 008a8321  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\Controls\XTButtonTheme.cpp (function ?CanHilite@CXTButtonTheme@@UAEHPAVCXTButton@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Controls/XTButtonTheme.cpp
