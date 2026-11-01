// from server: 100% by auto
// roc 2007-03 00701960  unit: seg_00700000  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00701960
//
// 00701960  56                   push esi
// 00701961  8bf1                 mov esi, ecx
// 00701963  8b4608               mov eax, dword ptr [esi + 8]
// 00701966  83f8ff               cmp eax, -1
// 00701969  7413                 je 0x70197e
// 0070196b  8b5610               mov edx, dword ptr [esi + 0x10]
// 0070196e  8d4e18               lea ecx, [esi + 0x18]
// 00701971  51                   push ecx
// 00701972  50                   push eax
// 00701973  ffd2                 call edx
// 00701975  85c0                 test eax, eax
// 00701977  7405                 je 0x70197e
// 00701979  8b4634               mov eax, dword ptr [esi + 0x34]
// 0070197c  5e                   pop esi
// 0070197d  c3                   ret 
// 0070197e  33c0                 xor eax, eax
// 00701980  5e                   pop esi
// 00701981  c3                   ret 
// library xtp-15.2.1/Source\SkinFramework\XTPSkinManagerModuleList.cpp (function ?GetNextModule@CToolHelpModuleEnumerator@CXTPSkinManagerModuleList@@UAEPAUHINSTANCE__@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinManagerModuleList.cpp
