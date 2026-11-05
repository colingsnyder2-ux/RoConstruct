// from server: 100% by auto
// roc 2007-03 006f7530  unit: seg_006f0000  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006f7530
//
// 006f7530  8b442404             mov eax, dword ptr [esp + 4]
// 006f7534  8b91ac000000         mov edx, dword ptr [ecx + 0xac]
// 006f753a  8910                 mov dword ptr [eax], edx
// 006f753c  8b91b0000000         mov edx, dword ptr [ecx + 0xb0]
// 006f7542  895004               mov dword ptr [eax + 4], edx
// 006f7545  8b91b4000000         mov edx, dword ptr [ecx + 0xb4]
// 006f754b  8b89b8000000         mov ecx, dword ptr [ecx + 0xb8]
// 006f7551  895008               mov dword ptr [eax + 8], edx
// 006f7554  89480c               mov dword ptr [eax + 0xc], ecx
// 006f7557  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxmultipaneframewnd.cpp (function ?GetRecentFloatingRect@CPaneFrameWnd@@QBE?AVCRect@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxmultipaneframewnd.cpp
