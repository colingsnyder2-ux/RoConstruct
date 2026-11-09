// from server: 100% by auto
// roc 2007-08 0040a760  unit: RBX::VDebugSettings::?$FactoryProduct::Creator  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040a760
//
// 0040a760  85c9                 test ecx, ecx
// 0040a762  7503                 jne 0x40a767
// 0040a764  33c0                 xor eax, eax
// 0040a766  c3                   ret 
// 0040a767  8b4120               mov eax, dword ptr [ecx + 0x20]
// 0040a76a  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\appui1.cpp (function ?GetSafeHwnd@CWnd@@QBEPAUHWND__@@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/appui1.cpp
