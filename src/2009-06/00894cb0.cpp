// from server: 100% by auto
// roc 2009-06 00894cb0  unit: seg_00890000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00894cb0
//
// 00894cb0  8b0d38c5a300         mov ecx, dword ptr [0xa3c538]
// 00894cb6  85c9                 test ecx, ecx
// 00894cb8  7408                 je 0x894cc2
// 00894cba  8b01                 mov eax, dword ptr [ecx]
// 00894cbc  8b10                 mov edx, dword ptr [eax]
// 00894cbe  6a01                 push 1
// 00894cc0  ffd2                 call edx
// 00894cc2  c3                   ret 
// library xtp-15.2.1/Source\SkinFramework\XTPSkinManager.cpp (function ??1CDestructor@CXTPSkinManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinManager.cpp
