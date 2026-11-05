// from server: 100% by auto
// roc 2007-03 0044a310  unit: seg_00440000  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0044a310
//
// 0044a310  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0044a314  8bc1                 mov eax, ecx
// 0044a316  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0044a31a  03d1                 add edx, ecx
// 0044a31c  895008               mov dword ptr [eax + 8], edx
// 0044a31f  8b542410             mov edx, dword ptr [esp + 0x10]
// 0044a323  8908                 mov dword ptr [eax], ecx
// 0044a325  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0044a329  03d1                 add edx, ecx
// 0044a32b  894804               mov dword ptr [eax + 4], ecx
// 0044a32e  89500c               mov dword ptr [eax + 0xc], edx
// 0044a331  c21000               ret 0x10
// library mfc-8.0/atlmfc\src\mfc\bardock.cpp (function ??0CRect@@QAE@UtagPOINT@@UtagSIZE@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/bardock.cpp
