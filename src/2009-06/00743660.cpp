// from server: 100% by auto
// roc 2009-06 00743660  unit: VCXTPReportRow::?$CXTPHeapObjectT  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00743660
//
// 00743660  8b442404             mov eax, dword ptr [esp + 4]
// 00743664  8b512c               mov edx, dword ptr [ecx + 0x2c]
// 00743667  8910                 mov dword ptr [eax], edx
// 00743669  8b5130               mov edx, dword ptr [ecx + 0x30]
// 0074366c  895004               mov dword ptr [eax + 4], edx
// 0074366f  8b5134               mov edx, dword ptr [ecx + 0x34]
// 00743672  8b4938               mov ecx, dword ptr [ecx + 0x38]
// 00743675  895008               mov dword ptr [eax + 8], edx
// 00743678  89480c               mov dword ptr [eax + 0xc], ecx
// 0074367b  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxpropertygridctrl.cpp (function ?GetRect@CMFCPropertyGridProperty@@QBE?AVCRect@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpropertygridctrl.cpp
