// from server: 100% by auto
// roc 2011-06 00870d80  unit: CXTColorDialog  size: 120 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00870d80
//
// 00870d80  53                   push ebx
// 00870d81  56                   push esi
// 00870d82  8bf1                 mov esi, ecx
// 00870d84  e8d7be1500           call 0x9ccc60
// 00870d89  8bd8                 mov ebx, eax
// 00870d8b  8b06                 mov eax, dword ptr [esi]
// 00870d8d  8b9054010000         mov edx, dword ptr [eax + 0x154]
// 00870d93  8bce                 mov ecx, esi
// 00870d95  ffd2                 call edx
// 00870d97  6a00                 push 0
// 00870d99  8bce                 mov ecx, esi
// 00870d9b  e8babe1500           call 0x9ccc5a
// 00870da0  8d86b0000000         lea eax, [esi + 0xb0]
// 00870da6  85c0                 test eax, eax
// 00870da8  7449                 je 0x870df3
// 00870daa  83782000             cmp dword ptr [eax + 0x20], 0
// 00870dae  7443                 je 0x870df3
// 00870db0  8b4620               mov eax, dword ptr [esi + 0x20]
// 00870db3  57                   push edi
// 00870db4  8b3dc019a400         mov edi, dword ptr [0xa419c0]
// 00870dba  6a00                 push 0
// 00870dbc  6a00                 push 0
// 00870dbe  6a31                 push 0x31
// 00870dc0  50                   push eax
// 00870dc1  ffd7                 call edi
// 00870dc3  50                   push eax
// 00870dc4  e89f9df9ff           call 0x80ab68
// 00870dc9  85c0                 test eax, eax
// 00870dcb  7514                 jne 0x870de1
// 00870dcd  8b8ed0000000         mov ecx, dword ptr [esi + 0xd0]
// 00870dd3  6a01                 push 1
// 00870dd5  50                   push eax
// 00870dd6  6a30                 push 0x30
// 00870dd8  51                   push ecx
// 00870dd9  ffd7                 call edi
// 00870ddb  5f                   pop edi
// 00870ddc  5e                   pop esi
// 00870ddd  8bc3                 mov eax, ebx
// 00870ddf  5b                   pop ebx
// 00870de0  c3                   ret 
// 00870de1  8b4004               mov eax, dword ptr [eax + 4]
// 00870de4  8b8ed0000000         mov ecx, dword ptr [esi + 0xd0]
// 00870dea  6a01                 push 1
// 00870dec  50                   push eax
// 00870ded  6a30                 push 0x30
// 00870def  51                   push ecx
// 00870df0  ffd7                 call edi
// 00870df2  5f                   pop edi
// 00870df3  5e                   pop esi
// 00870df4  8bc3                 mov eax, ebx
// 00870df6  5b                   pop ebx
// 00870df7  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\Controls\Dialog\XTPColorDialog.cpp (function ?OnInitDialog@CXTPColorDialog@@MAEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Controls/Dialog/XTPColorDialog.cpp
