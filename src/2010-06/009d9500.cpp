// from server: 100% by auto
// roc 2010-06 009d9500  unit: seg_009d0000  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009d9500
//
// 009d9500  68b875a500           push 0xa575b8
// 009d9505  ff15a4bc9e00         call dword ptr [0x9ebca4]
// 009d950b  66a3e054c200         mov word ptr [0xc254e0], ax
// 009d9511  c3                   ret 
// library xtp-13.2.1/Source\Common\XTPImageManager.cpp (function ??__E?m_nAlphaClipFormat@CXTPImageManager@@2GA@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPImageManager.cpp
