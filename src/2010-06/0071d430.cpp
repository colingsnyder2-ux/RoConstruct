// from server: 100% by auto
// roc 2010-06 0071d430  unit: RBX::ToolMouseCommand  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0071d430
//
// 0071d430  56                   push esi
// 0071d431  57                   push edi
// 0071d432  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0071d436  57                   push edi
// 0071d437  8bf1                 mov esi, ecx
// 0071d439  e8a2feffff           call 0x71d2e0
// 0071d43e  57                   push edi
// 0071d43f  8bce                 mov ecx, esi
// 0071d441  e85afbffff           call 0x71cfa0
// 0071d446  5f                   pop edi
// 0071d447  5e                   pop esi
// 0071d448  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\ctlcore.cpp (function ?DoPropExchange@COleControl@@UAEXPAVCPropExchange@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ctlcore.cpp
