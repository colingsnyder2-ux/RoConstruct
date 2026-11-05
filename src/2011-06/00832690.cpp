// from server: 100% by auto
// roc 2011-06 00832690  unit: VCXTPReportRow::?$CXTPHeapObjectT  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00832690
//
// 00832690  8b442404             mov eax, dword ptr [esp + 4]
// 00832694  8b512c               mov edx, dword ptr [ecx + 0x2c]
// 00832697  8910                 mov dword ptr [eax], edx
// 00832699  8b5130               mov edx, dword ptr [ecx + 0x30]
// 0083269c  895004               mov dword ptr [eax + 4], edx
// 0083269f  8b5134               mov edx, dword ptr [ecx + 0x34]
// 008326a2  8b4938               mov ecx, dword ptr [ecx + 0x38]
// 008326a5  895008               mov dword ptr [eax + 8], edx
// 008326a8  89480c               mov dword ptr [eax + 0xc], ecx
// 008326ab  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxpropertygridctrl.cpp (function ?GetRect@CMFCPropertyGridProperty@@QBE?AVCRect@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpropertygridctrl.cpp
