// from server: 100% by auto
// roc 2007-03 007208d0  unit: seg_00720000  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 007208d0
//
// 007208d0  53                   push ebx
// 007208d1  55                   push ebp
// 007208d2  56                   push esi
// 007208d3  57                   push edi
// 007208d4  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 007208d8  8b5f20               mov ebx, dword ptr [edi + 0x20]
// 007208db  85db                 test ebx, ebx
// 007208dd  7511                 jne 0x7208f0
// 007208df  0fb74f0e             movzx ecx, word ptr [edi + 0xe]
// 007208e3  6683f908             cmp cx, 8
// 007208e7  7707                 ja 0x7208f0
// 007208e9  bb01000000           mov ebx, 1
// 007208ee  d3e3                 shl ebx, cl
// 007208f0  6a00                 push 0
// 007208f2  ff1500ee7700         call dword ptr [0x77ee00]
// 007208f8  8b2d98d07700         mov ebp, dword ptr [0x77d098]
// 007208fe  8bf0                 mov esi, eax
// 00720900  8b442418             mov eax, dword ptr [esp + 0x18]
// 00720904  6a00                 push 0
// 00720906  50                   push eax
// 00720907  56                   push esi
// 00720908  ffd5                 call ebp
// 0072090a  6a00                 push 0
// 0072090c  57                   push edi
// 0072090d  8d4c9f28             lea ecx, [edi + ebx*4 + 0x28]
// 00720911  51                   push ecx
// 00720912  6a04                 push 4
// 00720914  57                   push edi
// 00720915  56                   push esi
// 00720916  8944242c             mov dword ptr [esp + 0x2c], eax
// 0072091a  ff1594d07700         call dword ptr [0x77d094]
// 00720920  8b542414             mov edx, dword ptr [esp + 0x14]
// 00720924  6a00                 push 0
// 00720926  52                   push edx
// 00720927  56                   push esi
// 00720928  8bf8                 mov edi, eax
// 0072092a  ffd5                 call ebp
// 0072092c  56                   push esi
// 0072092d  6a00                 push 0
// 0072092f  ff150cee7700         call dword ptr [0x77ee0c]
// 00720935  8bc7                 mov eax, edi
// 00720937  5f                   pop edi
// 00720938  5e                   pop esi
// 00720939  5d                   pop ebp
// 0072093a  5b                   pop ebx
// 0072093b  c3                   ret 
// library xtp-15.2.1/Source\SkinFramework\XTPSkinDrawTools.cpp (function ?XTPSkinFrameworkCreateDDBFromPackedDIBitmap@@YAPAUHBITMAP__@@PAUtagBITMAPINFO@@PAUHPALETTE__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinDrawTools.cpp
