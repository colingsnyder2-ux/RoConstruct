// from server: 100% by auto
// roc 2009-12 00486940  unit: Ogre::GfxClustererPart  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00486940
//
// 00486940  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00486944  e877e8ffff           call 0x4851c0
// 00486949  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\dumpstak.cpp (function ?ContextThreadProc@_AtlThreadContextInfo@ATL@@SGKPAX@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dumpstak.cpp
