// from server: 100% by auto
// roc 2011-06 0045cca0  unit: VCRoblox3D::?$CComObject  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0045cca0
//
// 0045cca0  837c240400           cmp dword ptr [esp + 4], 0
// 0045cca5  750d                 jne 0x45ccb4
// 0045cca7  c744240400000000     mov dword ptr [esp + 4], 0
// 0045ccaf  e95ce7ffff           jmp 0x45b410
// 0045ccb4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0045ccb8  85c0                 test eax, eax
// 0045ccba  7508                 jne 0x45ccc4
// 0045ccbc  b803400080           mov eax, 0x80004003
// 0045ccc1  c20c00               ret 0xc
// 0045ccc4  c70000000000         mov dword ptr [eax], 0
// 0045ccca  b810010480           mov eax, 0x80040110
// 0045cccf  c20c00               ret 0xc
// library atl-8.0/atl.cpp (function ?CreateInstance@?$CComCreator2@V?$CComCreator@V?$CComObject@VCDLLRegObject@@@ATL@@@ATL@@V?$CComFailCreator@$0?HPPLPOPA@@2@@ATL@@SGJPAXABU_GUID@@PAPAX@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
