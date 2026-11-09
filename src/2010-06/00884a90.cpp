// from server: 100% by auto
// roc 2010-06 00884a90  unit: CXTPTabPaintManager  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00884a90
//
// 00884a90  8b442404             mov eax, dword ptr [esp + 4]
// 00884a94  8b08                 mov ecx, dword ptr [eax]
// 00884a96  8b542408             mov edx, dword ptr [esp + 8]
// 00884a9a  8b02                 mov eax, dword ptr [edx]
// 00884a9c  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 00884a9f  2b4820               sub ecx, dword ptr [eax + 0x20]
// 00884aa2  8bc1                 mov eax, ecx
// 00884aa4  c3                   ret 
// library xtp-13.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ?_SizeToFitCompare@CXTPTabPaintManager@@KAHPBX0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManager.cpp
