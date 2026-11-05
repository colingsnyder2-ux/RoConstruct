// from server: 100% by auto
// roc 2009-06 00709ec0  unit: boost::detail::thread_data_base  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00709ec0
//
// 00709ec0  8b01                 mov eax, dword ptr [ecx]
// 00709ec2  50                   push eax
// 00709ec3  e848a31200           call 0x834210
// 00709ec8  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxtoolbarimages.cpp (function ??1Graphics@Gdiplus@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtoolbarimages.cpp
