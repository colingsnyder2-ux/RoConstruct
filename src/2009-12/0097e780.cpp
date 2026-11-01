// from server: 100% by auto
// roc 2009-12 0097e780  unit: seg_00970000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097e780
//
// 0097e780  8b0decb3b700         mov ecx, dword ptr [0xb7b3ec]
// 0097e786  85c9                 test ecx, ecx
// 0097e788  7408                 je 0x97e792
// 0097e78a  8b01                 mov eax, dword ptr [ecx]
// 0097e78c  8b10                 mov edx, dword ptr [eax]
// 0097e78e  6a01                 push 1
// 0097e790  ffd2                 call edx
// 0097e792  c3                   ret 
// library xtp-15.2.1/Source\SkinFramework\XTPSkinManager.cpp (function ??1CDestructor@CXTPSkinManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinManager.cpp
