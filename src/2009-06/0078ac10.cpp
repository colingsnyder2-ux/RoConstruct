// from server: 100% by auto
// roc 2009-06 0078ac10  unit: CPropertyGridItemBrickColor  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0078ac10
//
// 0078ac10  8b442404             mov eax, dword ptr [esp + 4]
// 0078ac14  85c0                 test eax, eax
// 0078ac16  7c0e                 jl 0x78ac26
// 0078ac18  3b4128               cmp eax, dword ptr [ecx + 0x28]
// 0078ac1b  7d09                 jge 0x78ac26
// 0078ac1d  8b4924               mov ecx, dword ptr [ecx + 0x24]
// 0078ac20  8b0481               mov eax, dword ptr [ecx + eax*4]
// 0078ac23  c20400               ret 4
// 0078ac26  33c0                 xor eax, eax
// 0078ac28  c20400               ret 4
// library xtp-15.2.1/Source\FlowGraph\XTPFlowGraphConnectionPoint.cpp (function ?GetAt@CXTPFlowGraphImages@@QBEPAVCXTPFlowGraphImage@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/FlowGraph/XTPFlowGraphConnectionPoint.cpp
