// from server: 100% by auto
// roc 2009-12 00426890  unit: RBX::Security::VContext::?$thread_specific_ptr::delete_data  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00426890
//
// 00426890  8b442404             mov eax, dword ptr [esp + 4]
// 00426894  50                   push eax
// 00426895  e8c0cf3c00           call 0x7f385a
// 0042689a  59                   pop ecx
// 0042689b  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\appcore.cpp (function ??3CObject@@SGXPAX@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/appcore.cpp
