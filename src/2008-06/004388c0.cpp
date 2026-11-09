// from server: 100% by auto
// roc 2008-06 004388c0  unit: RBX::Soundscape::VSoundId::?$XItem  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004388c0
//
// 004388c0  56                   push esi
// 004388c1  8b742410             mov esi, dword ptr [esp + 0x10]
// 004388c5  57                   push edi
// 004388c6  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 004388ca  8bc7                 mov eax, edi
// 004388cc  c1e804               shr eax, 4
// 004388cf  8906                 mov dword ptr [esi], eax
// 004388d1  33d2                 xor edx, edx
// 004388d3  f77108               div dword ptr [ecx + 8]
// 004388d6  8b442410             mov eax, dword ptr [esp + 0x10]
// 004388da  8910                 mov dword ptr [eax], edx
// 004388dc  8b4904               mov ecx, dword ptr [ecx + 4]
// 004388df  85c9                 test ecx, ecx
// 004388e1  741d                 je 0x438900
// 004388e3  8b0491               mov eax, dword ptr [ecx + edx*4]
// 004388e6  85c0                 test eax, eax
// 004388e8  7416                 je 0x438900
// 004388ea  8b36                 mov esi, dword ptr [esi]
// 004388ec  8d642400             lea esp, [esp]
// 004388f0  39700c               cmp dword ptr [eax + 0xc], esi
// 004388f3  7504                 jne 0x4388f9
// 004388f5  3938                 cmp dword ptr [eax], edi
// 004388f7  7409                 je 0x438902
// 004388f9  8b4008               mov eax, dword ptr [eax + 8]
// 004388fc  85c0                 test eax, eax
// 004388fe  75f0                 jne 0x4388f0
// 00438900  33c0                 xor eax, eax
// 00438902  5f                   pop edi
// 00438903  5e                   pop esi
// 00438904  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ?GetAssocAt@?$CMap@PAUHICON__@@PAU1@HH@@IBEPAVCAssoc@1@PAUHICON__@@AAI1@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
