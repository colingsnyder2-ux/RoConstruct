// from server: 100% by auto
// roc 2009-06 0078bf60  unit: CPropertyGridItemBrickColor  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0078bf60
//
// 0078bf60  56                   push esi
// 0078bf61  8b742408             mov esi, dword ptr [esp + 8]
// 0078bf65  56                   push esi
// 0078bf66  e845f2ffff           call 0x78b1b0
// 0078bf6b  830619               add dword ptr [esi], 0x19
// 0078bf6e  8bc6                 mov eax, esi
// 0078bf70  5e                   pop esi
// 0078bf71  c20400               ret 4
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridItemColor.cpp (function ?GetValueRect@CXTPPropertyGridItemColor@@MAE?AVCRect@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridItemColor.cpp
