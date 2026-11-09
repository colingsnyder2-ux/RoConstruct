// from server: 100% by auto
// roc 2010-06 004349a0  unit: CPropertyGridItemBrickColor  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004349a0
//
// 004349a0  56                   push esi
// 004349a1  8b742410             mov esi, dword ptr [esp + 0x10]
// 004349a5  57                   push edi
// 004349a6  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 004349aa  8bc7                 mov eax, edi
// 004349ac  c1e804               shr eax, 4
// 004349af  8906                 mov dword ptr [esi], eax
// 004349b1  33d2                 xor edx, edx
// 004349b3  f77108               div dword ptr [ecx + 8]
// 004349b6  8b442410             mov eax, dword ptr [esp + 0x10]
// 004349ba  8910                 mov dword ptr [eax], edx
// 004349bc  8b4904               mov ecx, dword ptr [ecx + 4]
// 004349bf  85c9                 test ecx, ecx
// 004349c1  741d                 je 0x4349e0
// 004349c3  8b0491               mov eax, dword ptr [ecx + edx*4]
// 004349c6  85c0                 test eax, eax
// 004349c8  7416                 je 0x4349e0
// 004349ca  8b36                 mov esi, dword ptr [esi]
// 004349cc  8d642400             lea esp, [esp]
// 004349d0  39700c               cmp dword ptr [eax + 0xc], esi
// 004349d3  7504                 jne 0x4349d9
// 004349d5  3938                 cmp dword ptr [eax], edi
// 004349d7  7409                 je 0x4349e2
// 004349d9  8b4008               mov eax, dword ptr [eax + 8]
// 004349dc  85c0                 test eax, eax
// 004349de  75f0                 jne 0x4349d0
// 004349e0  33c0                 xor eax, eax
// 004349e2  5f                   pop edi
// 004349e3  5e                   pop esi
// 004349e4  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ?GetAssocAt@?$CMap@PAUHICON__@@PAU1@HH@@IBEPAVCAssoc@1@PAUHICON__@@AAI1@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
