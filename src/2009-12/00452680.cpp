// from server: 100% by auto
// roc 2009-12 00452680  unit: CRobloxControlColorSelector  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00452680
//
// 00452680  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00452684  8bc1                 mov eax, ecx
// 00452686  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0045268a  03d1                 add edx, ecx
// 0045268c  895008               mov dword ptr [eax + 8], edx
// 0045268f  8b542410             mov edx, dword ptr [esp + 0x10]
// 00452693  8908                 mov dword ptr [eax], ecx
// 00452695  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00452699  03d1                 add edx, ecx
// 0045269b  894804               mov dword ptr [eax + 4], ecx
// 0045269e  89500c               mov dword ptr [eax + 0xc], edx
// 004526a1  c21000               ret 0x10
// library mfc-8.0/atlmfc\src\mfc\bardock.cpp (function ??0CRect@@QAE@UtagPOINT@@UtagSIZE@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/bardock.cpp
