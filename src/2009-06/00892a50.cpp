// from server: 100% by auto
// roc 2009-06 00892a50  unit: seg_00890000  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00892a50
//
// 00892a50  68e8328f00           push 0x8f32e8
// 00892a55  ff155cee8900         call dword ptr [0x89ee5c]
// 00892a5b  66a36819a500         mov word ptr [0xa51968], ax
// 00892a61  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ??__E?m_nImageClipFormat@CXTPImageManager@@2GA@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
