// from server: 100% by auto
// roc 2012-06 004044c0  unit: RBX::Soundscape::VSoundChannel::?$FactoryProduct::Creator  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004044c0
//
// 004044c0  51                   push ecx
// 004044c1  55                   push ebp
// 004044c2  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 004044c6  894c2404             mov dword ptr [esp + 4], ecx
// 004044ca  85ed                 test ebp, ebp
// 004044cc  7508                 jne 0x4044d6
// 004044ce  8d450d               lea eax, [ebp + 0xd]
// 004044d1  5d                   pop ebp
// 004044d2  59                   pop ecx
// 004044d3  c20800               ret 8
// 004044d6  53                   push ebx
// 004044d7  8b1da821b200         mov ebx, dword ptr [0xb221a8]
// 004044dd  56                   push esi
// 004044de  57                   push edi
// 004044df  33ff                 xor edi, edi
// 004044e1  8bf5                 mov esi, ebp
// 004044e3  56                   push esi
// 004044e4  ffd3                 call ebx
// 004044e6  40                   inc eax
// 004044e7  03f0                 add esi, eax
// 004044e9  03f8                 add edi, eax
// 004044eb  83f801               cmp eax, 1
// 004044ee  75f3                 jne 0x4044e3
// 004044f0  8b442418             mov eax, dword ptr [esp + 0x18]
// 004044f4  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004044f8  8b11                 mov edx, dword ptr [ecx]
// 004044fa  57                   push edi
// 004044fb  55                   push ebp
// 004044fc  6a07                 push 7
// 004044fe  6a00                 push 0
// 00404500  50                   push eax
// 00404501  52                   push edx
// 00404502  ff151020b200         call dword ptr [0xb22010]
// 00404508  5f                   pop edi
// 00404509  5e                   pop esi
// 0040450a  5b                   pop ebx
// 0040450b  5d                   pop ebp
// 0040450c  59                   pop ecx
// 0040450d  c20800               ret 8
// library atl-9.0/atl.cpp (function ?SetMultiStringValue@CRegKey@ATL@@QAEJPBD0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
