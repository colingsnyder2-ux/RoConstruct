// from server: 100% by auto
// roc 2010-06 009df020  unit: seg_009d0000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009df020
//
// 009df020  8b0d4cbdc000         mov ecx, dword ptr [0xc0bd4c]
// 009df026  85c9                 test ecx, ecx
// 009df028  7408                 je 0x9df032
// 009df02a  8b01                 mov eax, dword ptr [ecx]
// 009df02c  8b10                 mov edx, dword ptr [eax]
// 009df02e  6a01                 push 1
// 009df030  ffd2                 call edx
// 009df032  c3                   ret 
// library xtp-13.2.1/Source\SkinFramework\XTPSkinManager.cpp (function ??1CDestructor@CXTPSkinManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/SkinFramework/XTPSkinManager.cpp
