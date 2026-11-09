// from server: 100% by auto
// roc 2009-06 006b6640  unit: RBX::ToolMouseCommand  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b6640
//
// 006b6640  56                   push esi
// 006b6641  57                   push edi
// 006b6642  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006b6646  57                   push edi
// 006b6647  8bf1                 mov esi, ecx
// 006b6649  e8d2feffff           call 0x6b6520
// 006b664e  57                   push edi
// 006b664f  8bce                 mov ecx, esi
// 006b6651  e80af4ffff           call 0x6b5a60
// 006b6656  5f                   pop edi
// 006b6657  5e                   pop esi
// 006b6658  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\ctlcore.cpp (function ?DoPropExchange@COleControl@@UAEXPAVCPropExchange@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ctlcore.cpp
