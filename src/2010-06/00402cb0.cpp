// from server: 100% by auto
// roc 2010-06 00402cb0  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00402cb0
//
// 00402cb0  ff15a0a39e00         call dword ptr [0x9ea3a0]
// 00402cb6  85c0                 test eax, eax
// 00402cb8  7e0a                 jle 0x402cc4
// 00402cba  25ffff0000           and eax, 0xffff
// 00402cbf  0d00000780           or eax, 0x80070000
// 00402cc4  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\winctrl3.cpp (function ?AtlHresultFromLastError@ATL@@YAJXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/winctrl3.cpp
