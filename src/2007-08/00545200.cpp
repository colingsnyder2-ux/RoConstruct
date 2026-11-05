// from server: 100% by auto
// roc 2007-08 00545200  unit: RBX::VDebugSettings::?$GlobalSettingsItem  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00545200
//
// 00545200  53                   push ebx
// 00545201  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00545205  57                   push edi
// 00545206  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0054520a  57                   push edi
// 0054520b  53                   push ebx
// 0054520c  ff15d4d27700         call dword ptr [0x77d2d4]
// 00545212  85c0                 test eax, eax
// 00545214  7503                 jne 0x545219
// 00545216  5f                   pop edi
// 00545217  5b                   pop ebx
// 00545218  c3                   ret 
// 00545219  56                   push esi
// 0054521a  50                   push eax
// 0054521b  ff1568d27700         call dword ptr [0x77d268]
// 00545221  8bf0                 mov esi, eax
// 00545223  85f6                 test esi, esi
// 00545225  742d                 je 0x545254
// 00545227  57                   push edi
// 00545228  53                   push ebx
// 00545229  ff15d8d27700         call dword ptr [0x77d2d8]
// 0054522f  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00545233  03c6                 add eax, esi
// 00545235  83e10f               and ecx, 0xf
// 00545238  7616                 jbe 0x545250
// 0054523a  8d9b00000000         lea ebx, [ebx]
// 00545240  3bf0                 cmp esi, eax
// 00545242  7310                 jae 0x545254
// 00545244  83e901               sub ecx, 1
// 00545247  0fb716               movzx edx, word ptr [esi]
// 0054524a  8d745602             lea esi, [esi + edx*2 + 2]
// 0054524e  75f0                 jne 0x545240
// 00545250  3bf0                 cmp esi, eax
// 00545252  7206                 jb 0x54525a
// 00545254  5e                   pop esi
// 00545255  5f                   pop edi
// 00545256  33c0                 xor eax, eax
// 00545258  5b                   pop ebx
// 00545259  c3                   ret 
// 0054525a  668b06               mov ax, word ptr [esi]
// 0054525d  66f7d8               neg ax
// 00545260  1bc0                 sbb eax, eax
// 00545262  23c6                 and eax, esi
// 00545264  5e                   pop esi
// 00545265  5f                   pop edi
// 00545266  5b                   pop ebx
// 00545267  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\afxstate.cpp (function ?_AtlGetStringResourceImage@ATL@@YAPBUATLSTRINGRESOURCEIMAGE@1@PAUHINSTANCE__@@PAUHRSRC__@@I@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/afxstate.cpp
