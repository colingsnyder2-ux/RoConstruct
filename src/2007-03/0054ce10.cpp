// from server: 100% by auto
// roc 2007-03 0054ce10  unit: seg_00540000  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0054ce10
//
// 0054ce10  8b542404             mov edx, dword ptr [esp + 4]
// 0054ce14  85d2                 test edx, edx
// 0054ce16  57                   push edi
// 0054ce17  8bf9                 mov edi, ecx
// 0054ce19  750f                 jne 0x54ce2a
// 0054ce1b  33c0                 xor eax, eax
// 0054ce1d  50                   push eax
// 0054ce1e  52                   push edx
// 0054ce1f  e80ce0ffff           call 0x54ae30
// 0054ce24  8bc7                 mov eax, edi
// 0054ce26  5f                   pop edi
// 0054ce27  c20400               ret 4
// 0054ce2a  8bc2                 mov eax, edx
// 0054ce2c  56                   push esi
// 0054ce2d  8d7001               lea esi, [eax + 1]
// 0054ce30  8a08                 mov cl, byte ptr [eax]
// 0054ce32  83c001               add eax, 1
// 0054ce35  84c9                 test cl, cl
// 0054ce37  75f7                 jne 0x54ce30
// 0054ce39  2bc6                 sub eax, esi
// 0054ce3b  5e                   pop esi
// 0054ce3c  50                   push eax
// 0054ce3d  52                   push edx
// 0054ce3e  8bcf                 mov ecx, edi
// 0054ce40  e8ebdfffff           call 0x54ae30
// 0054ce45  8bc7                 mov eax, edi
// 0054ce47  5f                   pop edi
// 0054ce48  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\afxstate.cpp (function ??4?$CSimpleStringT@D$0A@@ATL@@QAEAAV01@PBD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxstate.cpp
