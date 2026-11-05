// from server: 100% by auto
// roc 2010-06 007bd270  unit: CXTPCommandBar  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007bd270
//
// 007bd270  8b5124               mov edx, dword ptr [ecx + 0x24]
// 007bd273  8b442404             mov eax, dword ptr [esp + 4]
// 007bd277  8b4928               mov ecx, dword ptr [ecx + 0x28]
// 007bd27a  8910                 mov dword ptr [eax], edx
// 007bd27c  894804               mov dword ptr [eax + 4], ecx
// 007bd27f  c20400               ret 4
// library xtp-13.2.1/Source\Common\XTPImageManager.cpp (function ?GetExtent@CXTPImageManagerResource@@QBE?AVCSize@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPImageManager.cpp
