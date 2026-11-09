// from server: 100% by auto
// roc 2011-06 006366b0  unit: FLog::VFastLogSettingsItem::?$FactoryProduct::Creator  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 006366b0
//
// 006366b0  8b01                 mov eax, dword ptr [ecx]
// 006366b2  83e810               sub eax, 0x10
// 006366b5  8d480c               lea ecx, [eax + 0xc]
// 006366b8  83caff               or edx, 0xffffffff
// 006366bb  f00fc111             lock xadd dword ptr [ecx], edx
// 006366bf  4a                   dec edx
// 006366c0  85d2                 test edx, edx
// 006366c2  7f0a                 jg 0x6366ce
// 006366c4  8b08                 mov ecx, dword ptr [eax]
// 006366c6  8b11                 mov edx, dword ptr [ecx]
// 006366c8  50                   push eax
// 006366c9  8b4204               mov eax, dword ptr [edx + 4]
// 006366cc  ffd0                 call eax
// 006366ce  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxacceleratorkey.cpp (function ??1?$CSimpleStringT@D$0A@@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxacceleratorkey.cpp
