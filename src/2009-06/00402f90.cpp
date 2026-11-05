// from server: 100% by auto
// roc 2009-06 00402f90  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00402f90
//
// 00402f90  ff15f8e18900         call dword ptr [0x89e1f8]
// 00402f96  85c0                 test eax, eax
// 00402f98  7e0a                 jle 0x402fa4
// 00402f9a  25ffff0000           and eax, 0xffff
// 00402f9f  0d00000780           or eax, 0x80070000
// 00402fa4  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\winctrl3.cpp (function ?AtlHresultFromLastError@ATL@@YAJXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/winctrl3.cpp
