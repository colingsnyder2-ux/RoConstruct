// from server: 100% by auto
// roc 2011-06 004446b0  unit: G3D::VVector3::?$XItem  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004446b0
//
// 004446b0  56                   push esi
// 004446b1  8b742410             mov esi, dword ptr [esp + 0x10]
// 004446b5  57                   push edi
// 004446b6  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 004446ba  8bc7                 mov eax, edi
// 004446bc  c1e804               shr eax, 4
// 004446bf  8906                 mov dword ptr [esi], eax
// 004446c1  33d2                 xor edx, edx
// 004446c3  f77108               div dword ptr [ecx + 8]
// 004446c6  8b442410             mov eax, dword ptr [esp + 0x10]
// 004446ca  8910                 mov dword ptr [eax], edx
// 004446cc  8b4904               mov ecx, dword ptr [ecx + 4]
// 004446cf  85c9                 test ecx, ecx
// 004446d1  741d                 je 0x4446f0
// 004446d3  8b0491               mov eax, dword ptr [ecx + edx*4]
// 004446d6  85c0                 test eax, eax
// 004446d8  7416                 je 0x4446f0
// 004446da  8b36                 mov esi, dword ptr [esi]
// 004446dc  8d642400             lea esp, [esp]
// 004446e0  39700c               cmp dword ptr [eax + 0xc], esi
// 004446e3  7504                 jne 0x4446e9
// 004446e5  3938                 cmp dword ptr [eax], edi
// 004446e7  7409                 je 0x4446f2
// 004446e9  8b4008               mov eax, dword ptr [eax + 8]
// 004446ec  85c0                 test eax, eax
// 004446ee  75f0                 jne 0x4446e0
// 004446f0  33c0                 xor eax, eax
// 004446f2  5f                   pop edi
// 004446f3  5e                   pop esi
// 004446f4  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ?GetAssocAt@?$CMap@PAUHICON__@@PAU1@HH@@IBEPAVCAssoc@1@PAUHICON__@@AAI1@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
