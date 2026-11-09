// from server: 100% by auto
// roc 2010-06 009dc050  unit: seg_009d0000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009dc050
//
// 009dc050  8b0d8c30c000         mov ecx, dword ptr [0xc0308c]
// 009dc056  85c9                 test ecx, ecx
// 009dc058  7408                 je 0x9dc062
// 009dc05a  8b01                 mov eax, dword ptr [ecx]
// 009dc05c  8b10                 mov edx, dword ptr [eax]
// 009dc05e  6a01                 push 1
// 009dc060  ffd2                 call edx
// 009dc062  c3                   ret 
// library xtp-13.2.1/Source\SkinFramework\XTPSkinManager.cpp (function ??1CDestructor@CXTPSkinManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/SkinFramework/XTPSkinManager.cpp
