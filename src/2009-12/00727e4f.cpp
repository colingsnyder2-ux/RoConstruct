// roc 2009-12 00727e4f  unit: boost::iostreams::Uinput::?$filtering_stream  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00727e4f
//
// 00727e4f  b8557e7200           mov eax, 0x727e55
// 00727e54  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\appcore.cpp (function ?GetThisMessageMap@CWinApp@@KGPBUAFX_MSGMAP@@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/appcore.cpp
