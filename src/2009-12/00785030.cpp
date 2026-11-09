// from server: 100% by auto
// roc 2009-12 00785030  unit: RBX::ToolMouseCommand  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00785030
//
// 00785030  56                   push esi
// 00785031  57                   push edi
// 00785032  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00785036  57                   push edi
// 00785037  8bf1                 mov esi, ecx
// 00785039  e8a2feffff           call 0x784ee0
// 0078503e  57                   push edi
// 0078503f  8bce                 mov ecx, esi
// 00785041  e84afbffff           call 0x784b90
// 00785046  5f                   pop edi
// 00785047  5e                   pop esi
// 00785048  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\ctlcore.cpp (function ?DoPropExchange@COleControl@@UAEXPAVCPropExchange@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlcore.cpp
