// from server: 100% by auto
// roc 2007-03 00401110  unit: seg_00400000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00401110
//
// 00401110  e89ba70400           call 0x44b8b0
// 00401115  b801000000           mov eax, 1
// 0040111a  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\ctlmodul.cpp (function ?InitInstance@COleControlModule@@UAEHXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlmodul.cpp
