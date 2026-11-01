// from server: 100% by auto
// roc 2007-08 0068ea40  unit: CXTColorDialog  size: 120 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0068ea40
//
// 0068ea40  53                   push ebx
// 0068ea41  56                   push esi
// 0068ea42  8bf1                 mov esi, ecx
// 0068ea44  e8db9c0a00           call 0x738724
// 0068ea49  8bd8                 mov ebx, eax
// 0068ea4b  8b06                 mov eax, dword ptr [esi]
// 0068ea4d  8b904c010000         mov edx, dword ptr [eax + 0x14c]
// 0068ea53  8bce                 mov ecx, esi
// 0068ea55  ffd2                 call edx
// 0068ea57  6a00                 push 0
// 0068ea59  8bce                 mov ecx, esi
// 0068ea5b  e8dc9c0a00           call 0x73873c
// 0068ea60  8d86b0000000         lea eax, [esi + 0xb0]
// 0068ea66  85c0                 test eax, eax
// 0068ea68  7449                 je 0x68eab3
// 0068ea6a  83782000             cmp dword ptr [eax + 0x20], 0
// 0068ea6e  7443                 je 0x68eab3
// 0068ea70  8b4620               mov eax, dword ptr [esi + 0x20]
// 0068ea73  57                   push edi
// 0068ea74  8b3dd8ec7700         mov edi, dword ptr [0x77ecd8]
// 0068ea7a  6a00                 push 0
// 0068ea7c  6a00                 push 0
// 0068ea7e  6a31                 push 0x31
// 0068ea80  50                   push eax
// 0068ea81  ffd7                 call edi
// 0068ea83  50                   push eax
// 0068ea84  e8a51bfaff           call 0x63062e
// 0068ea89  85c0                 test eax, eax
// 0068ea8b  7514                 jne 0x68eaa1
// 0068ea8d  8b8ed0000000         mov ecx, dword ptr [esi + 0xd0]
// 0068ea93  6a01                 push 1
// 0068ea95  50                   push eax
// 0068ea96  6a30                 push 0x30
// 0068ea98  51                   push ecx
// 0068ea99  ffd7                 call edi
// 0068ea9b  5f                   pop edi
// 0068ea9c  5e                   pop esi
// 0068ea9d  8bc3                 mov eax, ebx
// 0068ea9f  5b                   pop ebx
// 0068eaa0  c3                   ret 
// 0068eaa1  8b4004               mov eax, dword ptr [eax + 4]
// 0068eaa4  8b8ed0000000         mov ecx, dword ptr [esi + 0xd0]
// 0068eaaa  6a01                 push 1
// 0068eaac  50                   push eax
// 0068eaad  6a30                 push 0x30
// 0068eaaf  51                   push ecx
// 0068eab0  ffd7                 call edi
// 0068eab2  5f                   pop edi
// 0068eab3  5e                   pop esi
// 0068eab4  8bc3                 mov eax, ebx
// 0068eab6  5b                   pop ebx
// 0068eab7  c3                   ret 
// library xtp-15.2.1/Source\Controls\Dialog\XTPColorDialog.cpp (function ?OnInitDialog@CXTPColorDialog@@MAEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Dialog/XTPColorDialog.cpp
