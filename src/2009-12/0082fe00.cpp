// from server: 100% by auto
// roc 2009-12 0082fe00  unit: CXTPColorManager  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0082fe00
//
// 0082fe00  8b442408             mov eax, dword ptr [esp + 8]
// 0082fe04  8b542404             mov edx, dword ptr [esp + 4]
// 0082fe08  50                   push eax
// 0082fe09  52                   push edx
// 0082fe0a  e851ffffff           call 0x82fd60
// 0082fe0f  e81253fcff           call 0x7f5126
// 0082fe14  d95c2408             fstp dword ptr [esp + 8]
// 0082fe18  d9442408             fld dword ptr [esp + 8]
// 0082fe1c  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPColorManager.cpp (function ?Length@CXTPColorManager@@AAEMKK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPColorManager.cpp
