// from server: 100% by auto
// roc 2009-12 0080c980  unit: KKPAVCXTPImageManagerResource::?$CMap  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0080c980
//
// 0080c980  51                   push ecx
// 0080c981  8d442408             lea eax, [esp + 8]
// 0080c985  50                   push eax
// 0080c986  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0080c98a  8d542404             lea edx, [esp + 4]
// 0080c98e  52                   push edx
// 0080c98f  50                   push eax
// 0080c990  e81befffff           call 0x80b8b0
// 0080c995  85c0                 test eax, eax
// 0080c997  7504                 jne 0x80c99d
// 0080c999  59                   pop ecx
// 0080c99a  c20800               ret 8
// 0080c99d  8b4804               mov ecx, dword ptr [eax + 4]
// 0080c9a0  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0080c9a4  890a                 mov dword ptr [edx], ecx
// 0080c9a6  b801000000           mov eax, 1
// 0080c9ab  59                   pop ecx
// 0080c9ac  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxcmdusagecount.cpp (function ?Lookup@?$CMap@IIII@@QBEHIAAI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcmdusagecount.cpp
