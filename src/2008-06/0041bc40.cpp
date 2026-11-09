// from server: 100% by auto
// roc 2008-06 0041bc40  unit: VDHTMLWindow::?$BoundFuncDesc  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0041bc40
//
// 0041bc40  e8abfaffff           call 0x41b6f0
// 0041bc45  a34ccc9600           mov dword ptr [0x96cc4c], eax
// 0041bc4a  c3                   ret 
// library boost-1.36.0/libs\filesystem\src\operations.cpp (function ??__Esystem_category@system@boost@@YAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/filesystem/src/operations.cpp
