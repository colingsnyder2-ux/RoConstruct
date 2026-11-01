// from server: 100% by auto
// roc 2009-12 0084df00  unit: CXTPPropertyGrid  size: 120 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0084df00
//
// 0084df00  53                   push ebx
// 0084df01  8b1dbccb9800         mov ebx, dword ptr [0x98cbbc]
// 0084df07  56                   push esi
// 0084df08  57                   push edi
// 0084df09  8bf9                 mov edi, ecx
// 0084df0b  8b4720               mov eax, dword ptr [edi + 0x20]
// 0084df0e  50                   push eax
// 0084df0f  ffd3                 call ebx
// 0084df11  50                   push eax
// 0084df12  e8135cfaff           call 0x7f3b2a
// 0084df17  8bf0                 mov esi, eax
// 0084df19  85f6                 test esi, esi
// 0084df1b  7453                 je 0x84df70
// 0084df1d  8bce                 mov ecx, esi
// 0084df1f  e854850d00           call 0x926478
// 0084df24  a900000100           test eax, 0x10000
// 0084df29  741c                 je 0x84df47
// 0084df2b  8bce                 mov ecx, esi
// 0084df2d  e840850d00           call 0x926472
// 0084df32  a900000040           test eax, 0x40000000
// 0084df37  740e                 je 0x84df47
// 0084df39  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0084df3c  51                   push ecx
// 0084df3d  ffd3                 call ebx
// 0084df3f  50                   push eax
// 0084df40  e8e55bfaff           call 0x7f3b2a
// 0084df45  8bf0                 mov esi, eax
// 0084df47  8b542410             mov edx, dword ptr [esp + 0x10]
// 0084df4b  8b4720               mov eax, dword ptr [edi + 0x20]
// 0084df4e  52                   push edx
// 0084df4f  50                   push eax
// 0084df50  8b4620               mov eax, dword ptr [esi + 0x20]
// 0084df53  50                   push eax
// 0084df54  ff15e4ca9800         call dword ptr [0x98cae4]
// 0084df5a  50                   push eax
// 0084df5b  e8ca5bfaff           call 0x7f3b2a
// 0084df60  8bc8                 mov ecx, eax
// 0084df62  2bc7                 sub eax, edi
// 0084df64  f7d8                 neg eax
// 0084df66  5f                   pop edi
// 0084df67  1bc0                 sbb eax, eax
// 0084df69  5e                   pop esi
// 0084df6a  23c1                 and eax, ecx
// 0084df6c  5b                   pop ebx
// 0084df6d  c20400               ret 4
// 0084df70  5f                   pop edi
// 0084df71  5e                   pop esi
// 0084df72  33c0                 xor eax, eax
// 0084df74  5b                   pop ebx
// 0084df75  c20400               ret 4
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGrid.cpp (function ?GetNextGridTabItem@CXTPPropertyGrid@@AAEPAVCWnd@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGrid.cpp
