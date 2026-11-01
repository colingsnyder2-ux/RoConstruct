// from server: 100% by auto
// roc 2007-03 00776f60  unit: seg_00770000  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00776f60
//
// 00776f60  6888b77c00           push 0x7cb788
// 00776f65  ff15c0ed7700         call dword ptr [0x77edc0]
// 00776f6b  a398278c00           mov dword ptr [0x8c2798], eax
// 00776f70  c3                   ret 
// library xtp-15.2.1/Source\SkinFramework\XTPSkinObject.cpp (function ??__E?m_nMsgQuerySkinState@CXTPSkinObject@@2IA@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinObject.cpp
