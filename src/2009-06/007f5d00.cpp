// from server: 100% by auto
// roc 2009-06 007f5d00  unit: CXTPTabPaintManager  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007f5d00
//
// 007f5d00  8b442404             mov eax, dword ptr [esp + 4]
// 007f5d04  8b08                 mov ecx, dword ptr [eax]
// 007f5d06  8b542408             mov edx, dword ptr [esp + 8]
// 007f5d0a  8b02                 mov eax, dword ptr [edx]
// 007f5d0c  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 007f5d0f  2b4820               sub ecx, dword ptr [eax + 0x20]
// 007f5d12  8bc1                 mov eax, ecx
// 007f5d14  c3                   ret 
// library xtp-15.2.1/Source\TabManager\XTPTabPaintManager.cpp (function ?_SizeToFitCompare@CXTPTabPaintManager@@KAHPBX0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabPaintManager.cpp
