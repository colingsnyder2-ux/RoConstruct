// from server: 100% by auto
// roc 2008-06 005f9440  unit: boost::iostreams::Uinput::V?$chain::?$filtering_stream_base  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005f9440
//
// 005f9440  8b01                 mov eax, dword ptr [ecx]
// 005f9442  50                   push eax
// 005f9443  ff15782e8000         call dword ptr [0x802e78]
// 005f9449  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\ThemeHelper.cpp (function ??1CComBSTR@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ThemeHelper.cpp
