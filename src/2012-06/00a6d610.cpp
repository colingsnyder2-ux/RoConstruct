// roc 2012-06 00a6d610  unit: CXTPTabPaintManager::CColorSetDefault  size: 421 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a6d610
//
// 00a6d610  56                   push esi
// 00a6d611  57                   push edi
// 00a6d612  8bf1                 mov esi, ecx
// 00a6d614  e817f8ffff           call 0xa6ce30
// 00a6d619  6afe                 push -2
// 00a6d61b  8d8ee0000000         lea ecx, [esi + 0xe0]
// 00a6d621  e88a01f5ff           call 0x9bd7b0
// 00a6d626  e83502f5ff           call 0x9bd860
// 00a6d62b  6a14                 push 0x14
// 00a6d62d  8bc8                 mov ecx, eax
// 00a6d62f  e8acf9f4ff           call 0x9bcfe0
// 00a6d634  8bf8                 mov edi, eax
// 00a6d636  e82502f5ff           call 0x9bd860
// 00a6d63b  d9057027b600         fld dword ptr [0xb62770]
// 00a6d641  51                   push ecx
// 00a6d642  d91c24               fstp dword ptr [esp]
// 00a6d645  57                   push edi
// 00a6d646  6a10                 push 0x10
// 00a6d648  8bc8                 mov ecx, eax
// 00a6d64a  e891f9f4ff           call 0x9bcfe0
// 00a6d64f  50                   push eax
// 00a6d650  8d8e00010000         lea ecx, [esi + 0x100]
// 00a6d656  e8e5f6f4ff           call 0x9bcd40
// 00a6d65b  e80002f5ff           call 0x9bd860
// 00a6d660  6a12                 push 0x12
// 00a6d662  8bc8                 mov ecx, eax
// 00a6d664  e877f9f4ff           call 0x9bcfe0
// 00a6d669  898690010000         mov dword ptr [esi + 0x190], eax
// 00a6d66f  e8ec01f5ff           call 0x9bd860
// 00a6d674  6a12                 push 0x12
// 00a6d676  8bc8                 mov ecx, eax
// 00a6d678  e863f9f4ff           call 0x9bcfe0
// 00a6d67d  898678010000         mov dword ptr [esi + 0x178], eax
// 00a6d683  e8d801f5ff           call 0x9bd860
// 00a6d688  6a12                 push 0x12
// 00a6d68a  8bc8                 mov ecx, eax
// 00a6d68c  e84ff9f4ff           call 0x9bcfe0
// 00a6d691  898684010000         mov dword ptr [esi + 0x184], eax
// 00a6d697  e8c401f5ff           call 0x9bd860
// 00a6d69c  6a05                 push 5
// 00a6d69e  8bc8                 mov ecx, eax
// 00a6d6a0  e83bf9f4ff           call 0x9bcfe0
// 00a6d6a5  89869c010000         mov dword ptr [esi + 0x19c], eax
// 00a6d6ab  e8b001f5ff           call 0x9bd860
// 00a6d6b0  6a10                 push 0x10
// 00a6d6b2  8bc8                 mov ecx, eax
// 00a6d6b4  e827f9f4ff           call 0x9bcfe0
// 00a6d6b9  8986b4010000         mov dword ptr [esi + 0x1b4], eax
// 00a6d6bf  e89c01f5ff           call 0x9bd860
// 00a6d6c4  6a10                 push 0x10
// 00a6d6c6  8bc8                 mov ecx, eax
// 00a6d6c8  e813f9f4ff           call 0x9bcfe0
// 00a6d6cd  8986a8010000         mov dword ptr [esi + 0x1a8], eax
// 00a6d6d3  8b867c010000         mov eax, dword ptr [esi + 0x17c]
// 00a6d6d9  8986c4010000         mov dword ptr [esi + 0x1c4], eax
// 00a6d6df  8b8e78010000         mov ecx, dword ptr [esi + 0x178]
// 00a6d6e5  898ec0010000         mov dword ptr [esi + 0x1c0], ecx
// 00a6d6eb  8b9688010000         mov edx, dword ptr [esi + 0x188]
// 00a6d6f1  8996d0010000         mov dword ptr [esi + 0x1d0], edx
// 00a6d6f7  8b8684010000         mov eax, dword ptr [esi + 0x184]
// 00a6d6fd  8986cc010000         mov dword ptr [esi + 0x1cc], eax
// 00a6d703  8b8e94010000         mov ecx, dword ptr [esi + 0x194]
// 00a6d709  898edc010000         mov dword ptr [esi + 0x1dc], ecx
// 00a6d70f  8b9690010000         mov edx, dword ptr [esi + 0x190]
// 00a6d715  8996d8010000         mov dword ptr [esi + 0x1d8], edx
// 00a6d71b  8b86a0010000         mov eax, dword ptr [esi + 0x1a0]
// 00a6d721  8986e8010000         mov dword ptr [esi + 0x1e8], eax
// 00a6d727  8b8e9c010000         mov ecx, dword ptr [esi + 0x19c]
// 00a6d72d  898ee4010000         mov dword ptr [esi + 0x1e4], ecx
// 00a6d733  8b96ac010000         mov edx, dword ptr [esi + 0x1ac]
// 00a6d739  8996f4010000         mov dword ptr [esi + 0x1f4], edx
// 00a6d73f  8b86a8010000         mov eax, dword ptr [esi + 0x1a8]
// 00a6d745  8986f0010000         mov dword ptr [esi + 0x1f0], eax
// 00a6d74b  8b8eb8010000         mov ecx, dword ptr [esi + 0x1b8]
// 00a6d751  898e00020000         mov dword ptr [esi + 0x200], ecx
// 00a6d757  8b8e04020000         mov ecx, dword ptr [esi + 0x204]
// 00a6d75d  83c8ff               or eax, 0xffffffff
// 00a6d760  8986e4010000         mov dword ptr [esi + 0x1e4], eax
// 00a6d766  8986f0010000         mov dword ptr [esi + 0x1f0], eax
// 00a6d76c  8986fc010000         mov dword ptr [esi + 0x1fc], eax
// 00a6d772  e8c93ef8ff           call 0x9f1640
// 00a6d777  83f807               cmp eax, 7
// 00a6d77a  7536                 jne 0xa6d7b2
// 00a6d77c  e8df00f5ff           call 0x9bd860
// 00a6d781  6a0f                 push 0xf
// 00a6d783  8bc8                 mov ecx, eax
// 00a6d785  e856f8f4ff           call 0x9bcfe0
// 00a6d78a  894678               mov dword ptr [esi + 0x78], eax
// 00a6d78d  e8ce00f5ff           call 0x9bd860
// 00a6d792  6a05                 push 5
// 00a6d794  8bc8                 mov ecx, eax
// 00a6d796  e845f8f4ff           call 0x9bcfe0
// 00a6d79b  89869c000000         mov dword ptr [esi + 0x9c], eax
// 00a6d7a1  e8ba00f5ff           call 0x9bd860
// 00a6d7a6  6a12                 push 0x12
// 00a6d7a8  8bc8                 mov ecx, eax
// 00a6d7aa  e831f8f4ff           call 0x9bcfe0
// 00a6d7af  894648               mov dword ptr [esi + 0x48], eax
// 00a6d7b2  5f                   pop edi
// 00a6d7b3  5e                   pop esi
// 00a6d7b4  c3                   ret 
// copied from an identical function in another client (function ?RefreshMetrics@CColorSetDefault@CXTPTabPaintManager@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/TabManager/XTPTabPaintManagerColors.cpp