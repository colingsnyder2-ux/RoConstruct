// from server: 100% by auto
// roc 2010-06 00453680  unit: CRobloxControlColorSelector  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00453680
//
// 00453680  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00453684  8bc1                 mov eax, ecx
// 00453686  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0045368a  03d1                 add edx, ecx
// 0045368c  895008               mov dword ptr [eax + 8], edx
// 0045368f  8b542410             mov edx, dword ptr [esp + 0x10]
// 00453693  8908                 mov dword ptr [eax], ecx
// 00453695  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00453699  03d1                 add edx, ecx
// 0045369b  894804               mov dword ptr [eax + 4], ecx
// 0045369e  89500c               mov dword ptr [eax + 0xc], edx
// 004536a1  c21000               ret 0x10
// library mfc-9.0/atlmfc\src\mfc\afxcaptionbar.cpp (function ??0CRect@@QAE@UtagPOINT@@UtagSIZE@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcaptionbar.cpp
