// from server: 100% by auto
// roc 2009-06 00404440  unit: ATL::CRegObject  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00404440
//
// 00404440  8b01                 mov eax, dword ptr [ecx]
// 00404442  83e810               sub eax, 0x10
// 00404445  8d480c               lea ecx, [eax + 0xc]
// 00404448  83caff               or edx, 0xffffffff
// 0040444b  f00fc111             lock xadd dword ptr [ecx], edx
// 0040444f  4a                   dec edx
// 00404450  85d2                 test edx, edx
// 00404452  7f0a                 jg 0x40445e
// 00404454  8b08                 mov ecx, dword ptr [eax]
// 00404456  8b11                 mov edx, dword ptr [ecx]
// 00404458  50                   push eax
// 00404459  8b4204               mov eax, dword ptr [edx + 4]
// 0040445c  ffd0                 call eax
// 0040445e  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxacceleratorkey.cpp (function ??1?$CSimpleStringT@D$0A@@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxacceleratorkey.cpp
