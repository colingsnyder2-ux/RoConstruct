// from server: 100% by auto
// roc 2011-06 007faa80  unit: RBX::worker_thread::Udata::?$sp_counted_impl_p  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007faa80
//
// 007faa80  8b01                 mov eax, dword ptr [ecx]
// 007faa82  50                   push eax
// 007faa83  e852271200           call 0x91d1da
// 007faa88  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxtoolbarimages.cpp (function ??1Graphics@Gdiplus@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtoolbarimages.cpp
