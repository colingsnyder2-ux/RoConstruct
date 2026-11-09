// from server: 100% by auto
// roc 2010-06 0040cc70  unit: RBX::Reflection::Metadata::VMember::?$FactoryProduct::Creator  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0040cc70
//
// 0040cc70  85c9                 test ecx, ecx
// 0040cc72  7503                 jne 0x40cc77
// 0040cc74  33c0                 xor eax, eax
// 0040cc76  c3                   ret 
// 0040cc77  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0040cc7a  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxbasepane.cpp (function ?GetSafeHwnd@CWnd@@QBEPAUHWND__@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasepane.cpp
