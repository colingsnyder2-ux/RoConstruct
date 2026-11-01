// from server: 100% by auto
// roc 2009-06 00892a70  unit: seg_00890000  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00892a70
//
// 00892a70  6800338f00           push 0x8f3300
// 00892a75  ff155cee8900         call dword ptr [0x89ee5c]
// 00892a7b  66a36c19a500         mov word ptr [0xa5196c], ax
// 00892a81  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ??__E?m_nAlphaClipFormat@CXTPImageManager@@2GA@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
