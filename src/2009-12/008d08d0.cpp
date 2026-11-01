// from server: 100% by auto
// roc 2009-12 008d08d0  unit: CXTPTabPaintManager  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008d08d0
//
// 008d08d0  8b442404             mov eax, dword ptr [esp + 4]
// 008d08d4  8b08                 mov ecx, dword ptr [eax]
// 008d08d6  8b542408             mov edx, dword ptr [esp + 8]
// 008d08da  8b02                 mov eax, dword ptr [edx]
// 008d08dc  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 008d08df  2b4820               sub ecx, dword ptr [eax + 0x20]
// 008d08e2  8bc1                 mov eax, ecx
// 008d08e4  c3                   ret 
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ?_SizeToFitCompare@CXTPTabPaintManager@@KAHPBX0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManager.cpp
