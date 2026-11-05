// from server: 100% by auto
// roc 2010-06 00407290  unit: VCApp::?$CComAggObject  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00407290
//
// 00407290  8b442404             mov eax, dword ptr [esp + 4]
// 00407294  ff4004               inc dword ptr [eax + 4]
// 00407297  8b4004               mov eax, dword ptr [eax + 4]
// 0040729a  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTDropSource.cpp (function ?AddRef@CXTDropSource@@UAGKXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTDropSource.cpp
