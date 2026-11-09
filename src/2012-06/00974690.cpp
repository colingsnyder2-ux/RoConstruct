// from server: 100% by auto
// roc 2012-06 00974690  unit: RBX::worker_thread::Udata::?$sp_counted_impl_p  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00974690
//
// 00974690  8b01                 mov eax, dword ptr [ecx]
// 00974692  50                   push eax
// 00974693  e8420b1200           call 0xa951da
// 00974698  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxtoolbarimages.cpp (function ??1Graphics@Gdiplus@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtoolbarimages.cpp
