// from server: 100% by auto
// roc 2007-03 0077c0b0  unit: seg_00770000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0077c0b0
//
// 0077c0b0  8b0d9c1e8c00         mov ecx, dword ptr [0x8c1e9c]
// 0077c0b6  85c9                 test ecx, ecx
// 0077c0b8  7408                 je 0x77c0c2
// 0077c0ba  8b01                 mov eax, dword ptr [ecx]
// 0077c0bc  8b10                 mov edx, dword ptr [eax]
// 0077c0be  6a01                 push 1
// 0077c0c0  ffd2                 call edx
// 0077c0c2  c3                   ret 
// library xtp-15.2.1/Source\SkinFramework\XTPSkinManager.cpp (function ??1CDestructor@CXTPSkinManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinManager.cpp
