// roc 2009-12 00728bdb  unit: boost::iostreams::Uinput::?$filtering_stream  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00728bdb
//
// 00728bdb  b8e18b7200           mov eax, 0x728be1
// 00728be0  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\appcore.cpp (function ?GetThisMessageMap@CWinApp@@KGPBUAFX_MSGMAP@@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/appcore.cpp
