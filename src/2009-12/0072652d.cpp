// roc 2009-12 0072652d  unit: std::D::V?$allocator::V?$basic_gzip_decompressor::?$stream_buffer  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0072652d
//
// 0072652d  b833657200           mov eax, 0x726533
// 00726532  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\appcore.cpp (function ?GetThisMessageMap@CWinApp@@KGPBUAFX_MSGMAP@@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/appcore.cpp
