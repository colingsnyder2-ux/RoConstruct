// from server: 100% by auto
// roc 2007-08 00684730  unit: CXTPPropertyGrid  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00684730
//
// 00684730  51                   push ecx
// 00684731  8d442408             lea eax, [esp + 8]
// 00684735  50                   push eax
// 00684736  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0068473a  8d542404             lea edx, [esp + 4]
// 0068473e  52                   push edx
// 0068473f  50                   push eax
// 00684740  e89b49dbff           call 0x4390e0
// 00684745  85c0                 test eax, eax
// 00684747  7504                 jne 0x68474d
// 00684749  59                   pop ecx
// 0068474a  c20800               ret 8
// 0068474d  8b4804               mov ecx, dword ptr [eax + 4]
// 00684750  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00684754  890a                 mov dword ptr [edx], ecx
// 00684756  b801000000           mov eax, 1
// 0068475b  59                   pop ecx
// 0068475c  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxcmdusagecount.cpp (function ?Lookup@?$CMap@IIII@@QBEHIAAI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcmdusagecount.cpp
