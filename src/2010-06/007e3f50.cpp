// from server: 100% by auto
// roc 2010-06 007e3f50  unit: CXTPColorManager  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e3f50
//
// 007e3f50  8b442408             mov eax, dword ptr [esp + 8]
// 007e3f54  8b542404             mov edx, dword ptr [esp + 4]
// 007e3f58  50                   push eax
// 007e3f59  52                   push edx
// 007e3f5a  e851ffffff           call 0x7e3eb0
// 007e3f5f  e80253fcff           call 0x7a9266
// 007e3f64  d95c2408             fstp dword ptr [esp + 8]
// 007e3f68  d9442408             fld dword ptr [esp + 8]
// 007e3f6c  c20800               ret 8
// library xtp-13.2.1/Source\Common\XTPColorManager.cpp (function ?Length@CXTPColorManager@@AAEMKK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPColorManager.cpp
