// from server: 100% by auto
// roc 2007-03 00776240  unit: seg_00770000  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00776240
//
// 00776240  6894357c00           push 0x7c3594
// 00776245  ff15d0ec7700         call dword ptr [0x77ecd0]
// 0077624b  66a34c178c00         mov word ptr [0x8c174c], ax
// 00776251  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ??__E?m_nImageClipFormat@CXTPImageManager@@2GA@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
