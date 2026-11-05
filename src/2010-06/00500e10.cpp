// from server: 100% by auto
// roc 2010-06 00500e10  unit: Exposer  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00500e10
//
// 00500e10  8a442404             mov al, byte ptr [esp + 4]
// 00500e14  884108               mov byte ptr [ecx + 8], al
// 00500e17  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTOutBarCtrl.cpp (function ?EnableItem@CXTOutBarItem@@QAEX_N@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTOutBarCtrl.cpp
