// from server: 100% by auto
// roc 2010-06 006a8890  unit: std::D::V?$allocator::V?$basic_gzip_decompressor::?$stream_buffer  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006a8890
//
// 006a8890  8b01                 mov eax, dword ptr [ecx]
// 006a8892  50                   push eax
// 006a8893  ff1514bd9e00         call dword ptr [0x9ebd14]
// 006a8899  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\ThemeHelper.cpp (function ??1CComBSTR@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ThemeHelper.cpp
