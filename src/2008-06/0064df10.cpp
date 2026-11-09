// from server: 100% by auto
// roc 2008-06 0064df10  unit: RBX::ToolMouseCommand  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0064df10
//
// 0064df10  56                   push esi
// 0064df11  57                   push edi
// 0064df12  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0064df16  57                   push edi
// 0064df17  8bf1                 mov esi, ecx
// 0064df19  e8d2feffff           call 0x64ddf0
// 0064df1e  57                   push edi
// 0064df1f  8bce                 mov ecx, esi
// 0064df21  e86a51ffff           call 0x643090
// 0064df26  5f                   pop edi
// 0064df27  5e                   pop esi
// 0064df28  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\ctlcore.cpp (function ?DoPropExchange@COleControl@@UAEXPAVCPropExchange@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ctlcore.cpp
