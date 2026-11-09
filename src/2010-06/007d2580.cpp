// from server: 100% by auto
// roc 2010-06 007d2580  unit: VCXTPReportRow::?$CXTPHeapObjectT  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007d2580
//
// 007d2580  8b442404             mov eax, dword ptr [esp + 4]
// 007d2584  8b512c               mov edx, dword ptr [ecx + 0x2c]
// 007d2587  8910                 mov dword ptr [eax], edx
// 007d2589  8b5130               mov edx, dword ptr [ecx + 0x30]
// 007d258c  895004               mov dword ptr [eax + 4], edx
// 007d258f  8b5134               mov edx, dword ptr [ecx + 0x34]
// 007d2592  8b4938               mov ecx, dword ptr [ecx + 0x38]
// 007d2595  895008               mov dword ptr [eax + 8], edx
// 007d2598  89480c               mov dword ptr [eax + 0xc], ecx
// 007d259b  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxpropertygridctrl.cpp (function ?GetRect@CMFCPropertyGridProperty@@QBE?AVCRect@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpropertygridctrl.cpp
