// from server: 100% by auto
// roc 2009-12 00402c60  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00402c60
//
// 00402c60  ff1530b29800         call dword ptr [0x98b230]
// 00402c66  85c0                 test eax, eax
// 00402c68  7e0a                 jle 0x402c74
// 00402c6a  25ffff0000           and eax, 0xffff
// 00402c6f  0d00000780           or eax, 0x80070000
// 00402c74  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\winctrl3.cpp (function ?AtlHresultFromLastError@ATL@@YAJXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/winctrl3.cpp
