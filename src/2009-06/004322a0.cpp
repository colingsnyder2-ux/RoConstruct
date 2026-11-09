// from server: 100% by auto
// roc 2009-06 004322a0  unit: RBX::Soundscape::VSoundId::?$XItem  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004322a0
//
// 004322a0  56                   push esi
// 004322a1  8b742410             mov esi, dword ptr [esp + 0x10]
// 004322a5  57                   push edi
// 004322a6  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 004322aa  8bc7                 mov eax, edi
// 004322ac  c1e804               shr eax, 4
// 004322af  8906                 mov dword ptr [esi], eax
// 004322b1  33d2                 xor edx, edx
// 004322b3  f77108               div dword ptr [ecx + 8]
// 004322b6  8b442410             mov eax, dword ptr [esp + 0x10]
// 004322ba  8910                 mov dword ptr [eax], edx
// 004322bc  8b4904               mov ecx, dword ptr [ecx + 4]
// 004322bf  85c9                 test ecx, ecx
// 004322c1  741d                 je 0x4322e0
// 004322c3  8b0491               mov eax, dword ptr [ecx + edx*4]
// 004322c6  85c0                 test eax, eax
// 004322c8  7416                 je 0x4322e0
// 004322ca  8b36                 mov esi, dword ptr [esi]
// 004322cc  8d642400             lea esp, [esp]
// 004322d0  39700c               cmp dword ptr [eax + 0xc], esi
// 004322d3  7504                 jne 0x4322d9
// 004322d5  3938                 cmp dword ptr [eax], edi
// 004322d7  7409                 je 0x4322e2
// 004322d9  8b4008               mov eax, dword ptr [eax + 8]
// 004322dc  85c0                 test eax, eax
// 004322de  75f0                 jne 0x4322d0
// 004322e0  33c0                 xor eax, eax
// 004322e2  5f                   pop edi
// 004322e3  5e                   pop esi
// 004322e4  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ?GetAssocAt@?$CMap@PAUHICON__@@PAU1@HH@@IBEPAVCAssoc@1@PAUHICON__@@AAI1@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
