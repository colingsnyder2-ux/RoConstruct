// from server: 100% by auto
// roc 2009-12 0081e520  unit: VCXTPReportRow::?$CXTPHeapObjectT  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0081e520
//
// 0081e520  8b442404             mov eax, dword ptr [esp + 4]
// 0081e524  8b512c               mov edx, dword ptr [ecx + 0x2c]
// 0081e527  8910                 mov dword ptr [eax], edx
// 0081e529  8b5130               mov edx, dword ptr [ecx + 0x30]
// 0081e52c  895004               mov dword ptr [eax + 4], edx
// 0081e52f  8b5134               mov edx, dword ptr [ecx + 0x34]
// 0081e532  8b4938               mov ecx, dword ptr [ecx + 0x38]
// 0081e535  895008               mov dword ptr [eax + 8], edx
// 0081e538  89480c               mov dword ptr [eax + 0xc], ecx
// 0081e53b  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxpropertygridctrl.cpp (function ?GetRect@CMFCPropertyGridProperty@@QBE?AVCRect@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpropertygridctrl.cpp
