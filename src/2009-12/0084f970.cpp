// from server: 100% by auto
// roc 2009-12 0084f970  unit: CXTPPropertyGrid  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0084f970
//
// 0084f970  51                   push ecx
// 0084f971  8d442408             lea eax, [esp + 8]
// 0084f975  50                   push eax
// 0084f976  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0084f97a  8d542404             lea edx, [esp + 4]
// 0084f97e  52                   push edx
// 0084f97f  50                   push eax
// 0084f980  e8db3bbeff           call 0x433560
// 0084f985  85c0                 test eax, eax
// 0084f987  7504                 jne 0x84f98d
// 0084f989  59                   pop ecx
// 0084f98a  c20800               ret 8
// 0084f98d  8b4804               mov ecx, dword ptr [eax + 4]
// 0084f990  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0084f994  890a                 mov dword ptr [edx], ecx
// 0084f996  b801000000           mov eax, 1
// 0084f99b  59                   pop ecx
// 0084f99c  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxcmdusagecount.cpp (function ?Lookup@?$CMap@IIII@@QBEHIAAI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcmdusagecount.cpp
