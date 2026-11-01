// from server: 100% by auto
// roc 2007-03 006bdc80  unit: seg_006b0000  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006bdc80
//
// 006bdc80  8b442404             mov eax, dword ptr [esp + 4]
// 006bdc84  8b512c               mov edx, dword ptr [ecx + 0x2c]
// 006bdc87  8910                 mov dword ptr [eax], edx
// 006bdc89  8b5130               mov edx, dword ptr [ecx + 0x30]
// 006bdc8c  895004               mov dword ptr [eax + 4], edx
// 006bdc8f  8b5134               mov edx, dword ptr [ecx + 0x34]
// 006bdc92  8b4938               mov ecx, dword ptr [ecx + 0x38]
// 006bdc95  895008               mov dword ptr [eax + 8], edx
// 006bdc98  89480c               mov dword ptr [eax + 0xc], ecx
// 006bdc9b  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxpropertygridctrl.cpp (function ?GetRect@CMFCPropertyGridProperty@@QBE?AVCRect@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpropertygridctrl.cpp
