// from server: 100% by auto
// roc 2009-12 007e24f0  unit: std::D::DU?$char_traits::V?$basic_string::?$thread_specific_ptr::delete_data  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007e24f0
//
// 007e24f0  8b01                 mov eax, dword ptr [ecx]
// 007e24f2  85c0                 test eax, eax
// 007e24f4  7407                 je 0x7e24fd
// 007e24f6  50                   push eax
// 007e24f7  e8a4ffffff           call 0x7e24a0
// 007e24fc  59                   pop ecx
// 007e24fd  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\dumpstak.cpp (function ??1?$CAtlArray@PAXV?$CElementTraits@PAX@ATL@@@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dumpstak.cpp
