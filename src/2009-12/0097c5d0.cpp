// from server: 100% by auto
// roc 2009-12 0097c5d0  unit: seg_00970000  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097c5d0
//
// 0097c5d0  68c8329f00           push 0x9f32c8
// 0097c5d5  ff1508cc9800         call dword ptr [0x98cc08]
// 0097c5db  66a3b4adb900         mov word ptr [0xb9adb4], ax
// 0097c5e1  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ??__E?m_nAlphaClipFormat@CXTPImageManager@@2GA@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
