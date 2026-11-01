// from server: 100% by auto
// roc 2009-12 00981d90  unit: seg_00980000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00981d90
//
// 00981d90  8b0da45bb800         mov ecx, dword ptr [0xb85ba4]
// 00981d96  85c9                 test ecx, ecx
// 00981d98  7408                 je 0x981da2
// 00981d9a  8b01                 mov eax, dword ptr [ecx]
// 00981d9c  8b10                 mov edx, dword ptr [eax]
// 00981d9e  6a01                 push 1
// 00981da0  ffd2                 call edx
// 00981da2  c3                   ret 
// library xtp-15.2.1/Source\SkinFramework\XTPSkinManager.cpp (function ??1CDestructor@CXTPSkinManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinManager.cpp
