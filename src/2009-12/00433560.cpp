// from server: 100% by auto
// roc 2009-12 00433560  unit: std::D::DU?$char_traits::V?$basic_string::?$XItem  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00433560
//
// 00433560  56                   push esi
// 00433561  8b742410             mov esi, dword ptr [esp + 0x10]
// 00433565  57                   push edi
// 00433566  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0043356a  8bc7                 mov eax, edi
// 0043356c  c1e804               shr eax, 4
// 0043356f  8906                 mov dword ptr [esi], eax
// 00433571  33d2                 xor edx, edx
// 00433573  f77108               div dword ptr [ecx + 8]
// 00433576  8b442410             mov eax, dword ptr [esp + 0x10]
// 0043357a  8910                 mov dword ptr [eax], edx
// 0043357c  8b4904               mov ecx, dword ptr [ecx + 4]
// 0043357f  85c9                 test ecx, ecx
// 00433581  741d                 je 0x4335a0
// 00433583  8b0491               mov eax, dword ptr [ecx + edx*4]
// 00433586  85c0                 test eax, eax
// 00433588  7416                 je 0x4335a0
// 0043358a  8b36                 mov esi, dword ptr [esi]
// 0043358c  8d642400             lea esp, [esp]
// 00433590  39700c               cmp dword ptr [eax + 0xc], esi
// 00433593  7504                 jne 0x433599
// 00433595  3938                 cmp dword ptr [eax], edi
// 00433597  7409                 je 0x4335a2
// 00433599  8b4008               mov eax, dword ptr [eax + 8]
// 0043359c  85c0                 test eax, eax
// 0043359e  75f0                 jne 0x433590
// 004335a0  33c0                 xor eax, eax
// 004335a2  5f                   pop edi
// 004335a3  5e                   pop esi
// 004335a4  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ?GetAssocAt@?$CMap@PAUHICON__@@PAU1@HH@@IBEPAVCAssoc@1@PAUHICON__@@AAI1@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
