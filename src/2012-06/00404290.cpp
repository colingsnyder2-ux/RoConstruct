// from server: 100% by auto
// roc 2012-06 00404290  unit: RBX::Soundscape::VSoundChannel::?$FactoryProduct::Creator  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00404290
//
// 00404290  ff15bc21b200         call dword ptr [0xb221bc]
// 00404296  85c0                 test eax, eax
// 00404298  7e0a                 jle 0x4042a4
// 0040429a  25ffff0000           and eax, 0xffff
// 0040429f  0d00000780           or eax, 0x80070000
// 004042a4  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\winctrl3.cpp (function ?AtlHresultFromLastError@ATL@@YAJXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/winctrl3.cpp
