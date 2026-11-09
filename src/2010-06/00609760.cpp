// from server: 100% by auto
// roc 2010-06 00609760  unit: std::strstream  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00609760
//
// 00609760  8b01                 mov eax, dword ptr [ecx]
// 00609762  83e810               sub eax, 0x10
// 00609765  8d480c               lea ecx, [eax + 0xc]
// 00609768  83caff               or edx, 0xffffffff
// 0060976b  f00fc111             lock xadd dword ptr [ecx], edx
// 0060976f  4a                   dec edx
// 00609770  85d2                 test edx, edx
// 00609772  7f0a                 jg 0x60977e
// 00609774  8b08                 mov ecx, dword ptr [eax]
// 00609776  8b11                 mov edx, dword ptr [ecx]
// 00609778  50                   push eax
// 00609779  8b4204               mov eax, dword ptr [edx + 4]
// 0060977c  ffd0                 call eax
// 0060977e  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxacceleratorkey.cpp (function ??1?$CSimpleStringT@D$0A@@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxacceleratorkey.cpp
