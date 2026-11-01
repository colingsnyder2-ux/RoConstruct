// from server: 100% by auto
// roc 2009-06 00731f50  unit: CXTPCommandBar  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00731f50
//
// 00731f50  8b5124               mov edx, dword ptr [ecx + 0x24]
// 00731f53  8b442404             mov eax, dword ptr [esp + 4]
// 00731f57  8b4928               mov ecx, dword ptr [ecx + 0x28]
// 00731f5a  8910                 mov dword ptr [eax], edx
// 00731f5c  894804               mov dword ptr [eax + 4], ecx
// 00731f5f  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?GetExtent@CXTPImageManagerResource@@QBE?AVCSize@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
