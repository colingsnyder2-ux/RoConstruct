// from server: 100% by auto
// roc 2007-03 0045b150  unit: seg_00450000  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0045b150
//
// 0045b150  8b442410             mov eax, dword ptr [esp + 0x10]
// 0045b154  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0045b158  50                   push eax
// 0045b159  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0045b15d  52                   push edx
// 0045b15e  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0045b162  50                   push eax
// 0045b163  52                   push edx
// 0045b164  51                   push ecx
// 0045b165  ff15b4ed7700         call dword ptr [0x77edb4]
// 0045b16b  c21000               ret 0x10
// library mfc-8.0/atlmfc\src\mfc\barcore.cpp (function ?SetRect@CRect@@QAEXHHHH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barcore.cpp
