// from server: 100% by auto
// roc 2007-03 0044a340  unit: seg_00440000  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0044a340
//
// 0044a340  8b442408             mov eax, dword ptr [esp + 8]
// 0044a344  8b542404             mov edx, dword ptr [esp + 4]
// 0044a348  50                   push eax
// 0044a349  52                   push edx
// 0044a34a  51                   push ecx
// 0044a34b  ff1598ed7700         call dword ptr [0x77ed98]
// 0044a351  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\barcore.cpp (function ?OffsetRect@CRect@@QAEXHH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barcore.cpp
