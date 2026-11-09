// from server: 100% by auto
// roc 2012-06 009aac90  unit: VCXTPReportRow::?$CXTPHeapObjectT  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009aac90
//
// 009aac90  8b442404             mov eax, dword ptr [esp + 4]
// 009aac94  8b512c               mov edx, dword ptr [ecx + 0x2c]
// 009aac97  8910                 mov dword ptr [eax], edx
// 009aac99  8b5130               mov edx, dword ptr [ecx + 0x30]
// 009aac9c  895004               mov dword ptr [eax + 4], edx
// 009aac9f  8b5134               mov edx, dword ptr [ecx + 0x34]
// 009aaca2  8b4938               mov ecx, dword ptr [ecx + 0x38]
// 009aaca5  895008               mov dword ptr [eax + 8], edx
// 009aaca8  89480c               mov dword ptr [eax + 0xc], ecx
// 009aacab  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxpropertygridctrl.cpp (function ?GetRect@CMFCPropertyGridProperty@@QBE?AVCRect@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpropertygridctrl.cpp
