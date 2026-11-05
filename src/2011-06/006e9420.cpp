// from server: 100% by auto
// roc 2011-06 006e9420  unit: std::D::V?$allocator::V?$basic_gzip_decompressor::?$stream_buffer  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 006e9420
//
// 006e9420  8b01                 mov eax, dword ptr [ecx]
// 006e9422  50                   push eax
// 006e9423  ff15181da400         call dword ptr [0xa41d18]
// 006e9429  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\ThemeHelper.cpp (function ??1CComBSTR@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ThemeHelper.cpp
