// from server: 100% by auto
// roc 2007-08 0061ab40  unit: RBX::ToolMouseCommand  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0061ab40
//
// 0061ab40  56                   push esi
// 0061ab41  57                   push edi
// 0061ab42  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0061ab46  57                   push edi
// 0061ab47  8bf1                 mov esi, ecx
// 0061ab49  e8d2feffff           call 0x61aa20
// 0061ab4e  57                   push edi
// 0061ab4f  8bce                 mov ecx, esi
// 0061ab51  e8da69feff           call 0x601530
// 0061ab56  5f                   pop edi
// 0061ab57  5e                   pop esi
// 0061ab58  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\ctlcore.cpp (function ?DoPropExchange@COleControl@@UAEXPAVCPropExchange@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlcore.cpp
