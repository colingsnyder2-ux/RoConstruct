// from server: 100% by auto
// roc 2009-06 00754f50  unit: CXTPColorManager  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00754f50
//
// 00754f50  8b442408             mov eax, dword ptr [esp + 8]
// 00754f54  8b542404             mov edx, dword ptr [esp + 4]
// 00754f58  50                   push eax
// 00754f59  52                   push edx
// 00754f5a  e851ffffff           call 0x754eb0
// 00754f5f  e82656fcff           call 0x71a58a
// 00754f64  d95c2408             fstp dword ptr [esp + 8]
// 00754f68  d9442408             fld dword ptr [esp + 8]
// 00754f6c  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPColorManager.cpp (function ?Length@CXTPColorManager@@AAEMKK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPColorManager.cpp
