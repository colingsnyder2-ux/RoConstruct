// from server: 100% by auto
// roc 2009-06 00809bc0  unit: CXTCaptionTheme  size: 302 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00809bc0
//
// 00809bc0  83ec10               sub esp, 0x10
// 00809bc3  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00809bc7  8b5004               mov edx, dword ptr [eax + 4]
// 00809bca  53                   push ebx
// 00809bcb  55                   push ebp
// 00809bcc  56                   push esi
// 00809bcd  8bf1                 mov esi, ecx
// 00809bcf  8b08                 mov ecx, dword ptr [eax]
// 00809bd1  894c240c             mov dword ptr [esp + 0xc], ecx
// 00809bd5  8b4808               mov ecx, dword ptr [eax + 8]
// 00809bd8  57                   push edi
// 00809bd9  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00809bdd  89542414             mov dword ptr [esp + 0x14], edx
// 00809be1  8b500c               mov edx, dword ptr [eax + 0xc]
// 00809be4  894c2418             mov dword ptr [esp + 0x18], ecx
// 00809be8  6a01                 push 1
// 00809bea  8bcf                 mov ecx, edi
// 00809bec  89542420             mov dword ptr [esp + 0x20], edx
// 00809bf0  e811230400           call 0x84bf06
// 00809bf5  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 00809bf9  8b4370               mov eax, dword ptr [ebx + 0x70]
// 00809bfc  50                   push eax
// 00809bfd  8d4c2414             lea ecx, [esp + 0x14]
// 00809c01  51                   push ecx
// 00809c02  8bcf                 mov ecx, edi
// 00809c04  e8c7fbf0ff           call 0x7197d0
// 00809c09  8b83c8000000         mov eax, dword ptr [ebx + 0xc8]
// 00809c0f  8b2dbced8900         mov ebp, dword ptr [0x89edbc]
// 00809c15  a801                 test al, 1
// 00809c17  746c                 je 0x809c85
// 00809c19  8b4628               mov eax, dword ptr [esi + 0x28]
// 00809c1c  83f8ff               cmp eax, -1
// 00809c1f  7505                 jne 0x809c26
// 00809c21  8b4e24               mov ecx, dword ptr [esi + 0x24]
// 00809c24  eb02                 jmp 0x809c28
// 00809c26  8bc8                 mov ecx, eax
// 00809c28  8b461c               mov eax, dword ptr [esi + 0x1c]
// 00809c2b  83f8ff               cmp eax, -1
// 00809c2e  7503                 jne 0x809c33
// 00809c30  8b4618               mov eax, dword ptr [esi + 0x18]
// 00809c33  51                   push ecx
// 00809c34  50                   push eax
// 00809c35  8d542418             lea edx, [esp + 0x18]
// 00809c39  52                   push edx
// 00809c3a  8bcf                 mov ecx, edi
// 00809c3c  e889fbf0ff           call 0x7197ca
// 00809c41  6aff                 push -1
// 00809c43  6aff                 push -1
// 00809c45  8d442418             lea eax, [esp + 0x18]
// 00809c49  50                   push eax
// 00809c4a  ffd5                 call ebp
// 00809c4c  8b461c               mov eax, dword ptr [esi + 0x1c]
// 00809c4f  83f8ff               cmp eax, -1
// 00809c52  7503                 jne 0x809c57
// 00809c54  8b4618               mov eax, dword ptr [esi + 0x18]
// 00809c57  8b4e28               mov ecx, dword ptr [esi + 0x28]
// 00809c5a  83f9ff               cmp ecx, -1
// 00809c5d  7505                 jne 0x809c64
// 00809c5f  8b7624               mov esi, dword ptr [esi + 0x24]
// 00809c62  eb02                 jmp 0x809c66
// 00809c64  8bf1                 mov esi, ecx
// 00809c66  50                   push eax
// 00809c67  56                   push esi
// 00809c68  8d4c2418             lea ecx, [esp + 0x18]
// 00809c6c  51                   push ecx
// 00809c6d  8bcf                 mov ecx, edi
// 00809c6f  e856fbf0ff           call 0x7197ca
// 00809c74  837b6c00             cmp dword ptr [ebx + 0x6c], 0
// 00809c78  754c                 jne 0x809cc6
// 00809c7a  6aff                 push -1
// 00809c7c  6aff                 push -1
// 00809c7e  8d542418             lea edx, [esp + 0x18]
// 00809c82  52                   push edx
// 00809c83  eb3f                 jmp 0x809cc4
// 00809c85  a802                 test al, 2
// 00809c87  743d                 je 0x809cc6
// 00809c89  8b461c               mov eax, dword ptr [esi + 0x1c]
// 00809c8c  83f8ff               cmp eax, -1
// 00809c8f  7505                 jne 0x809c96
// 00809c91  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00809c94  eb02                 jmp 0x809c98
// 00809c96  8bc8                 mov ecx, eax
// 00809c98  8b4628               mov eax, dword ptr [esi + 0x28]
// 00809c9b  83f8ff               cmp eax, -1
// 00809c9e  7505                 jne 0x809ca5
// 00809ca0  8b7624               mov esi, dword ptr [esi + 0x24]
// 00809ca3  eb02                 jmp 0x809ca7
// 00809ca5  8bf0                 mov esi, eax
// 00809ca7  51                   push ecx
// 00809ca8  56                   push esi
// 00809ca9  8d442418             lea eax, [esp + 0x18]
// 00809cad  50                   push eax
// 00809cae  8bcf                 mov ecx, edi
// 00809cb0  e815fbf0ff           call 0x7197ca
// 00809cb5  837b6c00             cmp dword ptr [ebx + 0x6c], 0
// 00809cb9  750b                 jne 0x809cc6
// 00809cbb  6aff                 push -1
// 00809cbd  6aff                 push -1
// 00809cbf  8d4c2418             lea ecx, [esp + 0x18]
// 00809cc3  51                   push ecx
// 00809cc4  ffd5                 call ebp
// 00809cc6  8b436c               mov eax, dword ptr [ebx + 0x6c]
// 00809cc9  f7d8                 neg eax
// 00809ccb  50                   push eax
// 00809ccc  50                   push eax
// 00809ccd  8d542418             lea edx, [esp + 0x18]
// 00809cd1  52                   push edx
// 00809cd2  ffd5                 call ebp
// 00809cd4  8b4374               mov eax, dword ptr [ebx + 0x74]
// 00809cd7  50                   push eax
// 00809cd8  8d4c2414             lea ecx, [esp + 0x14]
// 00809cdc  51                   push ecx
// 00809cdd  8bcf                 mov ecx, edi
// 00809cdf  e8ecfaf0ff           call 0x7197d0
// 00809ce4  5f                   pop edi
// 00809ce5  5e                   pop esi
// 00809ce6  5d                   pop ebp
// 00809ce7  5b                   pop ebx
// 00809ce8  83c410               add esp, 0x10
// 00809ceb  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTCaptionTheme.cpp (function ?DrawCaptionBack@CXTCaptionTheme@@UAEXPAVCDC@@PAVCXTCaption@@AAVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionTheme.cpp
