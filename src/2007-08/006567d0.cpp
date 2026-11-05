// from server: 100% by auto
// roc 2007-08 006567d0  unit: CXTPReportRow_Batch  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006567d0
//
// 006567d0  8b442404             mov eax, dword ptr [esp + 4]
// 006567d4  8b512c               mov edx, dword ptr [ecx + 0x2c]
// 006567d7  8910                 mov dword ptr [eax], edx
// 006567d9  8b5130               mov edx, dword ptr [ecx + 0x30]
// 006567dc  895004               mov dword ptr [eax + 4], edx
// 006567df  8b5134               mov edx, dword ptr [ecx + 0x34]
// 006567e2  8b4938               mov ecx, dword ptr [ecx + 0x38]
// 006567e5  895008               mov dword ptr [eax + 8], edx
// 006567e8  89480c               mov dword ptr [eax + 0xc], ecx
// 006567eb  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxpropertygridctrl.cpp (function ?GetRect@CMFCPropertyGridProperty@@QBE?AVCRect@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpropertygridctrl.cpp
