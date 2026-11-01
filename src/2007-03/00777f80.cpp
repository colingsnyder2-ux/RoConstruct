// from server: 100% by auto
// roc 2007-03 00777f80  unit: seg_00770000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00777f80
//
// 00777f80  8b0d0c768b00         mov ecx, dword ptr [0x8b760c]
// 00777f86  85c9                 test ecx, ecx
// 00777f88  7408                 je 0x777f92
// 00777f8a  8b01                 mov eax, dword ptr [ecx]
// 00777f8c  8b10                 mov edx, dword ptr [eax]
// 00777f8e  6a01                 push 1
// 00777f90  ffd2                 call edx
// 00777f92  c3                   ret 
// library xtp-15.2.1/Source\SkinFramework\XTPSkinManager.cpp (function ??1CDestructor@CXTPSkinManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinManager.cpp
