// from server: 100% by auto
// roc 2007-03 007209f0  unit: seg_00720000  size: 122 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 007209f0
//
// 007209f0  53                   push ebx
// 007209f1  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 007209f5  55                   push ebp
// 007209f6  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 007209fa  56                   push esi
// 007209fb  8b742414             mov esi, dword ptr [esp + 0x14]
// 007209ff  8b06                 mov eax, dword ptr [esi]
// 00720a01  8b4e08               mov ecx, dword ptr [esi + 8]
// 00720a04  8b5604               mov edx, dword ptr [esi + 4]
// 00720a07  57                   push edi
// 00720a08  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00720a0c  53                   push ebx
// 00720a0d  57                   push edi
// 00720a0e  2bc8                 sub ecx, eax
// 00720a10  2bcf                 sub ecx, edi
// 00720a12  51                   push ecx
// 00720a13  52                   push edx
// 00720a14  50                   push eax
// 00720a15  55                   push ebp
// 00720a16  e825ffffff           call 0x720940
// 00720a1b  8b4604               mov eax, dword ptr [esi + 4]
// 00720a1e  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00720a21  8b16                 mov edx, dword ptr [esi]
// 00720a23  53                   push ebx
// 00720a24  2bc8                 sub ecx, eax
// 00720a26  2bcf                 sub ecx, edi
// 00720a28  51                   push ecx
// 00720a29  57                   push edi
// 00720a2a  50                   push eax
// 00720a2b  52                   push edx
// 00720a2c  55                   push ebp
// 00720a2d  e80effffff           call 0x720940
// 00720a32  8b4604               mov eax, dword ptr [esi + 4]
// 00720a35  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00720a38  8b5608               mov edx, dword ptr [esi + 8]
// 00720a3b  53                   push ebx
// 00720a3c  2bc8                 sub ecx, eax
// 00720a3e  51                   push ecx
// 00720a3f  f7df                 neg edi
// 00720a41  57                   push edi
// 00720a42  50                   push eax
// 00720a43  52                   push edx
// 00720a44  55                   push ebp
// 00720a45  e8f6feffff           call 0x720940
// 00720a4a  8b06                 mov eax, dword ptr [esi]
// 00720a4c  8b4e08               mov ecx, dword ptr [esi + 8]
// 00720a4f  8b560c               mov edx, dword ptr [esi + 0xc]
// 00720a52  83c448               add esp, 0x48
// 00720a55  53                   push ebx
// 00720a56  57                   push edi
// 00720a57  2bc8                 sub ecx, eax
// 00720a59  51                   push ecx
// 00720a5a  52                   push edx
// 00720a5b  50                   push eax
// 00720a5c  55                   push ebp
// 00720a5d  e8defeffff           call 0x720940
// 00720a62  83c418               add esp, 0x18
// 00720a65  5f                   pop edi
// 00720a66  5e                   pop esi
// 00720a67  5d                   pop ebp
// 00720a68  5b                   pop ebx
// 00720a69  c3                   ret 
// library xtp-15.2.1/Source\SkinFramework\XTPSkinDrawTools.cpp (function ?XTPSkinFrameworkDrawFrame@@YAXPAUHDC__@@PAUtagRECT@@HK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinDrawTools.cpp
