// from server: 100% by auto
// roc 2011-06 00403680  unit: RBX::VRenderHooksService::?$FactoryProduct::Creator  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00403680
//
// 00403680  ff158803a400         call dword ptr [0xa40388]
// 00403686  85c0                 test eax, eax
// 00403688  7e0a                 jle 0x403694
// 0040368a  25ffff0000           and eax, 0xffff
// 0040368f  0d00000780           or eax, 0x80070000
// 00403694  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\winctrl3.cpp (function ?AtlHresultFromLastError@ATL@@YAJXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/winctrl3.cpp
