// from server: 100% by auto
// roc 2009-12 0063ebc0  unit: RBX::VStandardOut::?$sp_counted_impl_p  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0063ebc0
//
// 0063ebc0  53                   push ebx
// 0063ebc1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0063ebc5  57                   push edi
// 0063ebc6  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0063ebca  57                   push edi
// 0063ebcb  53                   push ebx
// 0063ebcc  ff15f0b19800         call dword ptr [0x98b1f0]
// 0063ebd2  85c0                 test eax, eax
// 0063ebd4  7503                 jne 0x63ebd9
// 0063ebd6  5f                   pop edi
// 0063ebd7  5b                   pop ebx
// 0063ebd8  c3                   ret 
// 0063ebd9  56                   push esi
// 0063ebda  50                   push eax
// 0063ebdb  ff157cb29800         call dword ptr [0x98b27c]
// 0063ebe1  8bf0                 mov esi, eax
// 0063ebe3  85f6                 test esi, esi
// 0063ebe5  742d                 je 0x63ec14
// 0063ebe7  57                   push edi
// 0063ebe8  53                   push ebx
// 0063ebe9  ff15f4b19800         call dword ptr [0x98b1f4]
// 0063ebef  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0063ebf3  03c6                 add eax, esi
// 0063ebf5  83e10f               and ecx, 0xf
// 0063ebf8  7616                 jbe 0x63ec10
// 0063ebfa  8d9b00000000         lea ebx, [ebx]
// 0063ec00  3bf0                 cmp esi, eax
// 0063ec02  7310                 jae 0x63ec14
// 0063ec04  83e901               sub ecx, 1
// 0063ec07  0fb716               movzx edx, word ptr [esi]
// 0063ec0a  8d745602             lea esi, [esi + edx*2 + 2]
// 0063ec0e  75f0                 jne 0x63ec00
// 0063ec10  3bf0                 cmp esi, eax
// 0063ec12  7206                 jb 0x63ec1a
// 0063ec14  5e                   pop esi
// 0063ec15  5f                   pop edi
// 0063ec16  33c0                 xor eax, eax
// 0063ec18  5b                   pop ebx
// 0063ec19  c3                   ret 
// 0063ec1a  0fb706               movzx eax, word ptr [esi]
// 0063ec1d  f7d8                 neg eax
// 0063ec1f  1bc0                 sbb eax, eax
// 0063ec21  23c6                 and eax, esi
// 0063ec23  5e                   pop esi
// 0063ec24  5f                   pop edi
// 0063ec25  5b                   pop ebx
// 0063ec26  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxbasepane.cpp (function ?_AtlGetStringResourceImage@ATL@@YAPBUATLSTRINGRESOURCEIMAGE@1@PAUHINSTANCE__@@PAUHRSRC__@@I@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasepane.cpp
