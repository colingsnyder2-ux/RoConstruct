// from server: 100% by auto
// roc 2008-06 0055d760  unit: std::D::DU?$char_traits::V?$basic_string::?$sp_counted_impl_p  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0055d760
//
// 0055d760  8b01                 mov eax, dword ptr [ecx]
// 0055d762  83e810               sub eax, 0x10
// 0055d765  8d480c               lea ecx, [eax + 0xc]
// 0055d768  83caff               or edx, 0xffffffff
// 0055d76b  f00fc111             lock xadd dword ptr [ecx], edx
// 0055d76f  4a                   dec edx
// 0055d770  85d2                 test edx, edx
// 0055d772  7f0a                 jg 0x55d77e
// 0055d774  8b08                 mov ecx, dword ptr [eax]
// 0055d776  8b11                 mov edx, dword ptr [ecx]
// 0055d778  50                   push eax
// 0055d779  8b4204               mov eax, dword ptr [edx + 4]
// 0055d77c  ffd0                 call eax
// 0055d77e  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxacceleratorkey.cpp (function ??1?$CSimpleStringT@D$0A@@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxacceleratorkey.cpp
