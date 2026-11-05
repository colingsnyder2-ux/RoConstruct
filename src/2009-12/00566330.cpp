// from server: 100% by auto
// roc 2009-12 00566330  unit: RakPeer  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00566330
//
// 00566330  8b442404             mov eax, dword ptr [esp + 4]
// 00566334  50                   push eax
// 00566335  e8f6f4ffff           call 0x565830
// 0056633a  83c404               add esp, 4
// 0056633d  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\appui2.cpp (function ??2CObject@@SGPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/appui2.cpp
