// from server: 100% by auto
// roc 2009-12 0097c5b0  unit: seg_00970000  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097c5b0
//
// 0097c5b0  68b0329f00           push 0x9f32b0
// 0097c5b5  ff1508cc9800         call dword ptr [0x98cc08]
// 0097c5bb  66a3b0adb900         mov word ptr [0xb9adb0], ax
// 0097c5c1  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ??__E?m_nImageClipFormat@CXTPImageManager@@2GA@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
