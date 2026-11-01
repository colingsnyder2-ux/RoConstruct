// from server: 100% by auto
// roc 2007-03 00776260  unit: seg_00770000  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00776260
//
// 00776260  68ac357c00           push 0x7c35ac
// 00776265  ff15d0ec7700         call dword ptr [0x77ecd0]
// 0077626b  66a3b8178c00         mov word ptr [0x8c17b8], ax
// 00776271  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ??__E?m_nAlphaClipFormat@CXTPImageManager@@2GA@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
