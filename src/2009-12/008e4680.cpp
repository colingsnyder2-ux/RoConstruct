// from server: 100% by auto
// roc 2009-12 008e4680  unit: CXTCaptionTheme  size: 302 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e4680
//
// 008e4680  83ec10               sub esp, 0x10
// 008e4683  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008e4687  8b5004               mov edx, dword ptr [eax + 4]
// 008e468a  53                   push ebx
// 008e468b  55                   push ebp
// 008e468c  56                   push esi
// 008e468d  8bf1                 mov esi, ecx
// 008e468f  8b08                 mov ecx, dword ptr [eax]
// 008e4691  894c240c             mov dword ptr [esp + 0xc], ecx
// 008e4695  8b4808               mov ecx, dword ptr [eax + 8]
// 008e4698  57                   push edi
// 008e4699  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 008e469d  89542414             mov dword ptr [esp + 0x14], edx
// 008e46a1  8b500c               mov edx, dword ptr [eax + 0xc]
// 008e46a4  894c2418             mov dword ptr [esp + 0x18], ecx
// 008e46a8  6a01                 push 1
// 008e46aa  8bcf                 mov ecx, edi
// 008e46ac  89542420             mov dword ptr [esp + 0x20], edx
// 008e46b0  e8db1d0400           call 0x926490
// 008e46b5  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 008e46b9  8b4370               mov eax, dword ptr [ebx + 0x70]
// 008e46bc  50                   push eax
// 008e46bd  8d4c2414             lea ecx, [esp + 0x14]
// 008e46c1  51                   push ecx
// 008e46c2  8bcf                 mov ecx, edi
// 008e46c4  e835fff0ff           call 0x7f45fe
// 008e46c9  8b83c8000000         mov eax, dword ptr [ebx + 0xc8]
// 008e46cf  8b2d58ca9800         mov ebp, dword ptr [0x98ca58]
// 008e46d5  a801                 test al, 1
// 008e46d7  746c                 je 0x8e4745
// 008e46d9  8b4628               mov eax, dword ptr [esi + 0x28]
// 008e46dc  83f8ff               cmp eax, -1
// 008e46df  7505                 jne 0x8e46e6
// 008e46e1  8b4e24               mov ecx, dword ptr [esi + 0x24]
// 008e46e4  eb02                 jmp 0x8e46e8
// 008e46e6  8bc8                 mov ecx, eax
// 008e46e8  8b461c               mov eax, dword ptr [esi + 0x1c]
// 008e46eb  83f8ff               cmp eax, -1
// 008e46ee  7503                 jne 0x8e46f3
// 008e46f0  8b4618               mov eax, dword ptr [esi + 0x18]
// 008e46f3  51                   push ecx
// 008e46f4  50                   push eax
// 008e46f5  8d542418             lea edx, [esp + 0x18]
// 008e46f9  52                   push edx
// 008e46fa  8bcf                 mov ecx, edi
// 008e46fc  e8f7fef0ff           call 0x7f45f8
// 008e4701  6aff                 push -1
// 008e4703  6aff                 push -1
// 008e4705  8d442418             lea eax, [esp + 0x18]
// 008e4709  50                   push eax
// 008e470a  ffd5                 call ebp
// 008e470c  8b461c               mov eax, dword ptr [esi + 0x1c]
// 008e470f  83f8ff               cmp eax, -1
// 008e4712  7503                 jne 0x8e4717
// 008e4714  8b4618               mov eax, dword ptr [esi + 0x18]
// 008e4717  8b4e28               mov ecx, dword ptr [esi + 0x28]
// 008e471a  83f9ff               cmp ecx, -1
// 008e471d  7505                 jne 0x8e4724
// 008e471f  8b7624               mov esi, dword ptr [esi + 0x24]
// 008e4722  eb02                 jmp 0x8e4726
// 008e4724  8bf1                 mov esi, ecx
// 008e4726  50                   push eax
// 008e4727  56                   push esi
// 008e4728  8d4c2418             lea ecx, [esp + 0x18]
// 008e472c  51                   push ecx
// 008e472d  8bcf                 mov ecx, edi
// 008e472f  e8c4fef0ff           call 0x7f45f8
// 008e4734  837b6c00             cmp dword ptr [ebx + 0x6c], 0
// 008e4738  754c                 jne 0x8e4786
// 008e473a  6aff                 push -1
// 008e473c  6aff                 push -1
// 008e473e  8d542418             lea edx, [esp + 0x18]
// 008e4742  52                   push edx
// 008e4743  eb3f                 jmp 0x8e4784
// 008e4745  a802                 test al, 2
// 008e4747  743d                 je 0x8e4786
// 008e4749  8b461c               mov eax, dword ptr [esi + 0x1c]
// 008e474c  83f8ff               cmp eax, -1
// 008e474f  7505                 jne 0x8e4756
// 008e4751  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 008e4754  eb02                 jmp 0x8e4758
// 008e4756  8bc8                 mov ecx, eax
// 008e4758  8b4628               mov eax, dword ptr [esi + 0x28]
// 008e475b  83f8ff               cmp eax, -1
// 008e475e  7505                 jne 0x8e4765
// 008e4760  8b7624               mov esi, dword ptr [esi + 0x24]
// 008e4763  eb02                 jmp 0x8e4767
// 008e4765  8bf0                 mov esi, eax
// 008e4767  51                   push ecx
// 008e4768  56                   push esi
// 008e4769  8d442418             lea eax, [esp + 0x18]
// 008e476d  50                   push eax
// 008e476e  8bcf                 mov ecx, edi
// 008e4770  e883fef0ff           call 0x7f45f8
// 008e4775  837b6c00             cmp dword ptr [ebx + 0x6c], 0
// 008e4779  750b                 jne 0x8e4786
// 008e477b  6aff                 push -1
// 008e477d  6aff                 push -1
// 008e477f  8d4c2418             lea ecx, [esp + 0x18]
// 008e4783  51                   push ecx
// 008e4784  ffd5                 call ebp
// 008e4786  8b436c               mov eax, dword ptr [ebx + 0x6c]
// 008e4789  f7d8                 neg eax
// 008e478b  50                   push eax
// 008e478c  50                   push eax
// 008e478d  8d542418             lea edx, [esp + 0x18]
// 008e4791  52                   push edx
// 008e4792  ffd5                 call ebp
// 008e4794  8b4374               mov eax, dword ptr [ebx + 0x74]
// 008e4797  50                   push eax
// 008e4798  8d4c2414             lea ecx, [esp + 0x14]
// 008e479c  51                   push ecx
// 008e479d  8bcf                 mov ecx, edi
// 008e479f  e85afef0ff           call 0x7f45fe
// 008e47a4  5f                   pop edi
// 008e47a5  5e                   pop esi
// 008e47a6  5d                   pop ebp
// 008e47a7  5b                   pop ebx
// 008e47a8  83c410               add esp, 0x10
// 008e47ab  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTCaptionTheme.cpp (function ?DrawCaptionBack@CXTCaptionTheme@@UAEXPAVCDC@@PAVCXTCaption@@AAVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTCaptionTheme.cpp
