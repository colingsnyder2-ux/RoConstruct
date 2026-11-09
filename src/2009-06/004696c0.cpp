// from server: 100% by auto
// roc 2009-06 004696c0  unit: CTaskSchedulerPaneView  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004696c0
//
// 004696c0  d9ee                 fldz 
// 004696c2  d9442404             fld dword ptr [esp + 4]
// 004696c6  d8d1                 fcom st(1)
// 004696c8  dfe0                 fnstsw ax
// 004696ca  f6c441               test ah, 0x41
// 004696cd  7507                 jne 0x4696d6
// 004696cf  ddd9                 fstp st(1)
// 004696d1  ddd8                 fstp st(0)
// 004696d3  d9e8                 fld1 
// 004696d5  c3                   ret 
// 004696d6  d8d9                 fcomp st(1)
// 004696d8  dfe0                 fnstsw ax
// 004696da  f6c405               test ah, 5
// 004696dd  7a08                 jp 0x4696e7
// 004696df  ddd8                 fstp st(0)
// 004696e1  d90594758b00         fld dword ptr [0x8b7594]
// 004696e7  c3                   ret 
// library rbx2016-g3d/Capsule.cpp (function ?sign@G3D@@YAMM@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d Capsule.cpp
