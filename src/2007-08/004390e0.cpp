// from server: 100% by auto
// roc 2007-08 004390e0  unit: CXTPPropertyGridItem  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004390e0
//
// 004390e0  56                   push esi
// 004390e1  8b742410             mov esi, dword ptr [esp + 0x10]
// 004390e5  57                   push edi
// 004390e6  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 004390ea  8bc7                 mov eax, edi
// 004390ec  c1e804               shr eax, 4
// 004390ef  8906                 mov dword ptr [esi], eax
// 004390f1  33d2                 xor edx, edx
// 004390f3  f77108               div dword ptr [ecx + 8]
// 004390f6  8b442410             mov eax, dword ptr [esp + 0x10]
// 004390fa  8910                 mov dword ptr [eax], edx
// 004390fc  8b4904               mov ecx, dword ptr [ecx + 4]
// 004390ff  85c9                 test ecx, ecx
// 00439101  741d                 je 0x439120
// 00439103  8b0491               mov eax, dword ptr [ecx + edx*4]
// 00439106  85c0                 test eax, eax
// 00439108  7416                 je 0x439120
// 0043910a  8b36                 mov esi, dword ptr [esi]
// 0043910c  8d642400             lea esp, [esp]
// 00439110  39700c               cmp dword ptr [eax + 0xc], esi
// 00439113  7504                 jne 0x439119
// 00439115  3938                 cmp dword ptr [eax], edi
// 00439117  7409                 je 0x439122
// 00439119  8b4008               mov eax, dword ptr [eax + 8]
// 0043911c  85c0                 test eax, eax
// 0043911e  75f0                 jne 0x439110
// 00439120  33c0                 xor eax, eax
// 00439122  5f                   pop edi
// 00439123  5e                   pop esi
// 00439124  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ?GetAssocAt@?$CMap@PAUHICON__@@PAU1@HH@@IBEPAVCAssoc@1@PAUHICON__@@AAI1@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
