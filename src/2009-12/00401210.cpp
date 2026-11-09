// from server: 100% by auto
// roc 2009-12 00401210  unit: CAboutRobloxDialog  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00401210
//
// 00401210  e80b380500           call 0x454a20
// 00401215  b801000000           mov eax, 1
// 0040121a  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\ctlmodul.cpp (function ?InitInstance@COleControlModule@@UAEHXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlmodul.cpp
