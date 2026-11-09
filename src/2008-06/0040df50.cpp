// from server: 100% by auto
// roc 2008-06 0040df50  unit: RBX::Reflection::Metadata::VMember::?$FactoryProduct::Creator  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0040df50
//
// 0040df50  85c9                 test ecx, ecx
// 0040df52  7503                 jne 0x40df57
// 0040df54  33c0                 xor eax, eax
// 0040df56  c3                   ret 
// 0040df57  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0040df5a  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxbasepane.cpp (function ?GetSafeHwnd@CWnd@@QBEPAUHWND__@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasepane.cpp
