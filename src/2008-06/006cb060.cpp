// from server: 100% by auto
// roc 2008-06 006cb060  unit: VCXTPReportRow::?$CXTPHeapObjectT  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006cb060
//
// 006cb060  8b442404             mov eax, dword ptr [esp + 4]
// 006cb064  8b512c               mov edx, dword ptr [ecx + 0x2c]
// 006cb067  8910                 mov dword ptr [eax], edx
// 006cb069  8b5130               mov edx, dword ptr [ecx + 0x30]
// 006cb06c  895004               mov dword ptr [eax + 4], edx
// 006cb06f  8b5134               mov edx, dword ptr [ecx + 0x34]
// 006cb072  8b4938               mov ecx, dword ptr [ecx + 0x38]
// 006cb075  895008               mov dword ptr [eax + 8], edx
// 006cb078  89480c               mov dword ptr [eax + 0xc], ecx
// 006cb07b  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxpropertygridctrl.cpp (function ?GetRect@CMFCPropertyGridProperty@@QBE?AVCRect@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpropertygridctrl.cpp
