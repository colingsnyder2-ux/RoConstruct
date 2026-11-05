// from server: 100% by auto
// roc 2007-03 0040d2b0  unit: seg_00400000  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0040d2b0
//
// 0040d2b0  8b442404             mov eax, dword ptr [esp + 4]
// 0040d2b4  83400401             add dword ptr [eax + 4], 1
// 0040d2b8  8b4004               mov eax, dword ptr [eax + 4]
// 0040d2bb  c20400               ret 4
// library atl-8.0/atl.cpp (function ?AddRef@?$CComPolyObject@VCAxHostWindow@ATL@@@ATL@@UAGKXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
