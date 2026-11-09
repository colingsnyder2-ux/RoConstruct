// from server: 100% by auto
// roc 2008-06 0044df30  unit: CRobloxControlColorSelector  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0044df30
//
// 0044df30  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0044df34  8bc1                 mov eax, ecx
// 0044df36  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0044df3a  03d1                 add edx, ecx
// 0044df3c  895008               mov dword ptr [eax + 8], edx
// 0044df3f  8b542410             mov edx, dword ptr [esp + 0x10]
// 0044df43  8908                 mov dword ptr [eax], ecx
// 0044df45  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0044df49  03d1                 add edx, ecx
// 0044df4b  894804               mov dword ptr [eax + 4], ecx
// 0044df4e  89500c               mov dword ptr [eax + 0xc], edx
// 0044df51  c21000               ret 0x10
// library mfc-9.0/atlmfc\src\mfc\afxcaptionbar.cpp (function ??0CRect@@QAE@UtagPOINT@@UtagSIZE@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcaptionbar.cpp
