// from server: 100% by auto
// roc 2007-03 00776f40  unit: seg_00770000  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00776f40
//
// 00776f40  68a4b77c00           push 0x7cb7a4
// 00776f45  ff15c0ed7700         call dword ptr [0x77edc0]
// 00776f4b  a394278c00           mov dword ptr [0x8c2794], eax
// 00776f50  c3                   ret 
// library xtp-15.2.1/Source\SkinFramework\XTPSkinObject.cpp (function ??__E?m_nMsgUpdateSkinState@CXTPSkinObject@@2IA@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinObject.cpp
