// from server: 100% by auto
// roc 2009-12 00407940  unit: VCApp::?$CComAggObject  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00407940
//
// 00407940  8b442404             mov eax, dword ptr [esp + 4]
// 00407944  ff4004               inc dword ptr [eax + 4]
// 00407947  8b4004               mov eax, dword ptr [eax + 4]
// 0040794a  c20400               ret 4
// library atl-8.0/atl.cpp (function ?AddRef@?$CComPolyObject@VCAxHostWindow@ATL@@@ATL@@UAGKXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O1 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
