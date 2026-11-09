// from server: 100% by auto
// roc 2009-06 00632450  unit: std::strstream  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00632450
//
// 00632450  8b542404             mov edx, dword ptr [esp + 4]
// 00632454  57                   push edi
// 00632455  8bf9                 mov edi, ecx
// 00632457  85d2                 test edx, edx
// 00632459  750f                 jne 0x63246a
// 0063245b  33c0                 xor eax, eax
// 0063245d  50                   push eax
// 0063245e  52                   push edx
// 0063245f  e88cfeffff           call 0x6322f0
// 00632464  8bc7                 mov eax, edi
// 00632466  5f                   pop edi
// 00632467  c20400               ret 4
// 0063246a  8bc2                 mov eax, edx
// 0063246c  56                   push esi
// 0063246d  8d7001               lea esi, [eax + 1]
// 00632470  8a08                 mov cl, byte ptr [eax]
// 00632472  40                   inc eax
// 00632473  84c9                 test cl, cl
// 00632475  75f9                 jne 0x632470
// 00632477  2bc6                 sub eax, esi
// 00632479  5e                   pop esi
// 0063247a  50                   push eax
// 0063247b  52                   push edx
// 0063247c  8bcf                 mov ecx, edi
// 0063247e  e86dfeffff           call 0x6322f0
// 00632483  8bc7                 mov eax, edi
// 00632485  5f                   pop edi
// 00632486  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxacceleratorkey.cpp (function ??4?$CSimpleStringT@D$0A@@ATL@@QAEAAV01@PBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxacceleratorkey.cpp
