// from server: 100% by auto
// roc 2009-06 00894890  unit: seg_00890000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00894890
//
// 00894890  8b0d3cb1a300         mov ecx, dword ptr [0xa3b13c]
// 00894896  85c9                 test ecx, ecx
// 00894898  7408                 je 0x8948a2
// 0089489a  8b01                 mov eax, dword ptr [ecx]
// 0089489c  8b10                 mov edx, dword ptr [eax]
// 0089489e  6a01                 push 1
// 008948a0  ffd2                 call edx
// 008948a2  c3                   ret 
// library xtp-15.2.1/Source\SkinFramework\XTPSkinManager.cpp (function ??1CDestructor@CXTPSkinManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinManager.cpp
