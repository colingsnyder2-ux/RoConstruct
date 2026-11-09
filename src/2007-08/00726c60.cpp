// from server: 100% by auto
// roc 2007-08 00726c60  unit: boost::thread_resource_error  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00726c60
//
// 00726c60  e86b010000           call 0x726dd0
// 00726c65  33c0                 xor eax, eax
// 00726c67  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\ctlppg.cpp (function ?OnInitDialog@COlePropertyPage@@UAEHXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlppg.cpp
