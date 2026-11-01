// from server: 100% by auto
// roc 2007-03 00720940  unit: seg_00720000  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00720940
//
// 00720940  83ec10               sub esp, 0x10
// 00720943  8b442428             mov eax, dword ptr [esp + 0x28]
// 00720947  53                   push ebx
// 00720948  56                   push esi
// 00720949  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0072094d  57                   push edi
// 0072094e  8b3df8d07700         mov edi, dword ptr [0x77d0f8]
// 00720954  50                   push eax
// 00720955  56                   push esi
// 00720956  ffd7                 call edi
// 00720958  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 0072095c  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00720960  8bd8                 mov ebx, eax
// 00720962  8b442424             mov eax, dword ptr [esp + 0x24]
// 00720966  8944240c             mov dword ptr [esp + 0xc], eax
// 0072096a  6a00                 push 0
// 0072096c  03c2                 add eax, edx
// 0072096e  6a00                 push 0
// 00720970  8944241c             mov dword ptr [esp + 0x1c], eax
// 00720974  8b442438             mov eax, dword ptr [esp + 0x38]
// 00720978  894c2418             mov dword ptr [esp + 0x18], ecx
// 0072097c  03c8                 add ecx, eax
// 0072097e  6a00                 push 0
// 00720980  894c2424             mov dword ptr [esp + 0x24], ecx
// 00720984  8d4c2418             lea ecx, [esp + 0x18]
// 00720988  51                   push ecx
// 00720989  6a02                 push 2
// 0072098b  6a00                 push 0
// 0072098d  6a00                 push 0
// 0072098f  56                   push esi
// 00720990  ff15c0d07700         call dword ptr [0x77d0c0]
// 00720996  53                   push ebx
// 00720997  56                   push esi
// 00720998  ffd7                 call edi
// 0072099a  5f                   pop edi
// 0072099b  5e                   pop esi
// 0072099c  b801000000           mov eax, 1
// 007209a1  5b                   pop ebx
// 007209a2  83c410               add esp, 0x10
// 007209a5  c3                   ret 
// library xtp-15.2.1/Source\SkinFramework\XTPSkinDrawTools.cpp (function ?XTPFillSolidRect@@YAHPAUHDC__@@HHHHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinDrawTools.cpp
