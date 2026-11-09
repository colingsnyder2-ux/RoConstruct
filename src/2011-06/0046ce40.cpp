// from server: 100% by auto
// roc 2011-06 0046ce40  unit: CRobloxControlColorSelector  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0046ce40
//
// 0046ce40  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0046ce44  8bc1                 mov eax, ecx
// 0046ce46  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0046ce4a  03d1                 add edx, ecx
// 0046ce4c  895008               mov dword ptr [eax + 8], edx
// 0046ce4f  8b542410             mov edx, dword ptr [esp + 0x10]
// 0046ce53  8908                 mov dword ptr [eax], ecx
// 0046ce55  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0046ce59  03d1                 add edx, ecx
// 0046ce5b  894804               mov dword ptr [eax + 4], ecx
// 0046ce5e  89500c               mov dword ptr [eax + 0xc], edx
// 0046ce61  c21000               ret 0x10
// library mfc-9.0/atlmfc\src\mfc\afxcaptionbar.cpp (function ??0CRect@@QAE@UtagPOINT@@UtagSIZE@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcaptionbar.cpp
