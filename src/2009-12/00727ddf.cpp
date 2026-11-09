// roc 2009-12 00727ddf  unit: boost::iostreams::Uinput::?$filtering_stream  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00727ddf
//
// 00727ddf  b8e57d7200           mov eax, 0x727de5
// 00727de4  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\appcore.cpp (function ?GetThisMessageMap@CWinApp@@KGPBUAFX_MSGMAP@@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/appcore.cpp
