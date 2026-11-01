// from server: 100% by colin
// roc 2007-03 0054cac0  unit: seg_00540000  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0054cac0
//
// 0054cac0  8b442410             mov eax, dword ptr [esp + 0x10]
// 0054cac4  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0054cac8  50                   push eax
// 0054cac9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0054cacd  52                   push edx
// 0054cace  99                   cdq 
// 0054cacf  52                   push edx
// 0054cad0  50                   push eax
// 0054cad1  8b442414             mov eax, dword ptr [esp + 0x14]
// 0054cad5  50                   push eax
// 0054cad6  e835feffff           call 0x54c910
// copied from an identical function in another client (function ?seekoff@?$indirect_streambuf@V?$back_insert_device@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@iostreams@boost@@U?$char_traits@D@std@@V?$allocator@D@5@Uoutput@23@@detail@iostreams@boost@@MAE?AV?$fpos@H@std@@JHH@Z)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 roc_string_sink_401c42386b16c308.cpp