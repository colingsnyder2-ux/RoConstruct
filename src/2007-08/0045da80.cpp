// from server: 100% by auto
// roc 2007-08 0045da80  unit: HH::?$CArray  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0045da80
//
// 0045da80  8b442404             mov eax, dword ptr [esp + 4]
// 0045da84  8b5004               mov edx, dword ptr [eax + 4]
// 0045da87  56                   push esi
// 0045da88  8b30                 mov esi, dword ptr [eax]
// 0045da8a  57                   push edi
// 0045da8b  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0045da8f  57                   push edi
// 0045da90  8b780c               mov edi, dword ptr [eax + 0xc]
// 0045da93  8b4008               mov eax, dword ptr [eax + 8]
// 0045da96  2bfa                 sub edi, edx
// 0045da98  57                   push edi
// 0045da99  2bc6                 sub eax, esi
// 0045da9b  50                   push eax
// 0045da9c  52                   push edx
// 0045da9d  56                   push esi
// 0045da9e  e891251d00           call 0x630034
// 0045daa3  5f                   pop edi
// 0045daa4  5e                   pop esi
// 0045daa5  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\ctlppg.cpp (function ?MoveWindow@CWnd@@QAEXPBUtagRECT@@H@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlppg.cpp
