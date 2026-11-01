// from server: 100% by auto
// roc 2009-12 008090d0  unit: CXTPCommandBar  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008090d0
//
// 008090d0  8b5124               mov edx, dword ptr [ecx + 0x24]
// 008090d3  8b442404             mov eax, dword ptr [esp + 4]
// 008090d7  8b4928               mov ecx, dword ptr [ecx + 0x28]
// 008090da  8910                 mov dword ptr [eax], edx
// 008090dc  894804               mov dword ptr [eax + 4], ecx
// 008090df  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?GetExtent@CXTPImageManagerResource@@QBE?AVCSize@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
