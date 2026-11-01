// from server: 100% by auto
// roc 2009-12 008316f0  unit: CRobloxTreeCtrl  size: 196 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008316f0
//
// 008316f0  51                   push ecx
// 008316f1  56                   push esi
// 008316f2  8bf1                 mov esi, ecx
// 008316f4  837e0400             cmp dword ptr [esi + 4], 0
// 008316f8  c744240400000000     mov dword ptr [esp + 4], 0
// 00831700  750a                 jne 0x83170c
// 00831702  b801000000           mov eax, 1
// 00831707  5e                   pop esi
// 00831708  59                   pop ecx
// 00831709  c21000               ret 0x10
// 0083170c  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00831710  8b542414             mov edx, dword ptr [esp + 0x14]
// 00831714  55                   push ebp
// 00831715  57                   push edi
// 00831716  8d44240c             lea eax, [esp + 0xc]
// 0083171a  50                   push eax
// 0083171b  51                   push ecx
// 0083171c  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 0083171f  52                   push edx
// 00831720  e8ef2afcff           call 0x7f4214
// 00831725  8bf8                 mov edi, eax
// 00831727  85ff                 test edi, edi
// 00831729  7465                 je 0x831790
// 0083172b  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0083172f  83e010               and eax, 0x10
// 00831732  7574                 jne 0x8317a8
// 00831734  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 00831738  85ed                 test ebp, ebp
// 0083173a  7416                 je 0x831752
// 0083173c  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 0083173f  e82e4d0f00           call 0x926472
// 00831744  a900010000           test eax, 0x100
// 00831749  740b                 je 0x831756
// 0083174b  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0083174f  83e040               and eax, 0x40
// 00831752  85c0                 test eax, eax
// 00831754  7552                 jne 0x8317a8
// 00831756  f644240c29           test byte ptr [esp + 0xc], 0x29
// 0083175b  7533                 jne 0x831790
// 0083175d  8b06                 mov eax, dword ptr [esi]
// 0083175f  8b5058               mov edx, dword ptr [eax + 0x58]
// 00831762  53                   push ebx
// 00831763  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 00831767  53                   push ebx
// 00831768  55                   push ebp
// 00831769  57                   push edi
// 0083176a  8bce                 mov ecx, esi
// 0083176c  ffd2                 call edx
// 0083176e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00831772  8b542420             mov edx, dword ptr [esp + 0x20]
// 00831776  8b06                 mov eax, dword ptr [esi]
// 00831778  8b405c               mov eax, dword ptr [eax + 0x5c]
// 0083177b  51                   push ecx
// 0083177c  52                   push edx
// 0083177d  53                   push ebx
// 0083177e  55                   push ebp
// 0083177f  57                   push edi
// 00831780  8bce                 mov ecx, esi
// 00831782  ffd0                 call eax
// 00831784  0fb64638             movzx eax, byte ptr [esi + 0x38]
// 00831788  5b                   pop ebx
// 00831789  5f                   pop edi
// 0083178a  5d                   pop ebp
// 0083178b  5e                   pop esi
// 0083178c  59                   pop ecx
// 0083178d  c21000               ret 0x10
// 00831790  8b442420             mov eax, dword ptr [esp + 0x20]
// 00831794  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00831798  8b16                 mov edx, dword ptr [esi]
// 0083179a  8b5260               mov edx, dword ptr [edx + 0x60]
// 0083179d  50                   push eax
// 0083179e  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008317a2  51                   push ecx
// 008317a3  50                   push eax
// 008317a4  8bce                 mov ecx, esi
// 008317a6  ffd2                 call edx
// 008317a8  5f                   pop edi
// 008317a9  5d                   pop ebp
// 008317aa  b801000000           mov eax, 1
// 008317af  5e                   pop esi
// 008317b0  59                   pop ecx
// 008317b1  c21000               ret 0x10
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?OnButtonDown@CXTPTreeBase@@MAEHHIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
