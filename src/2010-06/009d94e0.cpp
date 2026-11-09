// from server: 100% by auto
// roc 2010-06 009d94e0  unit: seg_009d0000  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009d94e0
//
// 009d94e0  68a075a500           push 0xa575a0
// 009d94e5  ff15a4bc9e00         call dword ptr [0x9ebca4]
// 009d94eb  66a3dc54c200         mov word ptr [0xc254dc], ax
// 009d94f1  c3                   ret 
// library xtp-13.2.1/Source\Common\XTPImageManager.cpp (function ??__E?m_nImageClipFormat@CXTPImageManager@@2GA@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPImageManager.cpp
