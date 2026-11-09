// from server: 100% by auto
// roc 2010-06 009db9a0  unit: seg_009d0000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009db9a0
//
// 009db9a0  8b0dac19c000         mov ecx, dword ptr [0xc019ac]
// 009db9a6  85c9                 test ecx, ecx
// 009db9a8  7408                 je 0x9db9b2
// 009db9aa  8b01                 mov eax, dword ptr [ecx]
// 009db9ac  8b10                 mov edx, dword ptr [eax]
// 009db9ae  6a01                 push 1
// 009db9b0  ffd2                 call edx
// 009db9b2  c3                   ret 
// library xtp-13.2.1/Source\SkinFramework\XTPSkinManager.cpp (function ??1CDestructor@CXTPSkinManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/SkinFramework/XTPSkinManager.cpp
