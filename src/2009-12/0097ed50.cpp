// from server: 100% by auto
// roc 2009-12 0097ed50  unit: seg_00970000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097ed50
//
// 0097ed50  8b0d78cbb700         mov ecx, dword ptr [0xb7cb78]
// 0097ed56  85c9                 test ecx, ecx
// 0097ed58  7408                 je 0x97ed62
// 0097ed5a  8b01                 mov eax, dword ptr [ecx]
// 0097ed5c  8b10                 mov edx, dword ptr [eax]
// 0097ed5e  6a01                 push 1
// 0097ed60  ffd2                 call edx
// 0097ed62  c3                   ret 
// library xtp-15.2.1/Source\SkinFramework\XTPSkinManager.cpp (function ??1CDestructor@CXTPSkinManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinManager.cpp
