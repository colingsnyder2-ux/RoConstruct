// from server: 100% by auto
// roc 2011-06 004048f0  unit: VCApp::?$CComObject  size: 324 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004048f0
//
// 004048f0  55                   push ebp
// 004048f1  8bec                 mov ebp, esp
// 004048f3  83e4f8               and esp, 0xfffffff8
// 004048f6  81ec1c010000         sub esp, 0x11c
// 004048fc  8b01                 mov eax, dword ptr [ecx]
// 004048fe  8b5508               mov edx, dword ptr [ebp + 8]
// 00404901  53                   push ebx
// 00404902  56                   push esi
// 00404903  8b7104               mov esi, dword ptr [ecx + 4]
// 00404906  57                   push edi
// 00404907  894c241c             mov dword ptr [esp + 0x1c], ecx
// 0040490b  8d4c2418             lea ecx, [esp + 0x18]
// 0040490f  51                   push ecx
// 00404910  33db                 xor ebx, ebx
// 00404912  81ce1f000200         or esi, 0x2001f
// 00404918  56                   push esi
// 00404919  53                   push ebx
// 0040491a  52                   push edx
// 0040491b  50                   push eax
// 0040491c  895c2420             mov dword ptr [esp + 0x20], ebx
// 00404920  895c2424             mov dword ptr [esp + 0x24], ebx
// 00404924  895c242c             mov dword ptr [esp + 0x2c], ebx
// 00404928  ff154000a400         call dword ptr [0xa40040]
// 0040492e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00404932  8bf8                 mov edi, eax
// 00404934  3bfb                 cmp edi, ebx
// 00404936  7525                 jne 0x40495d
// 00404938  33c0                 xor eax, eax
// 0040493a  3bcb                 cmp ecx, ebx
// 0040493c  7407                 je 0x404945
// 0040493e  51                   push ecx
// 0040493f  ff150400a400         call dword ptr [0xa40004]
// 00404945  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00404949  81e600030000         and esi, 0x300
// 0040494f  8bf8                 mov edi, eax
// 00404951  894c240c             mov dword ptr [esp + 0xc], ecx
// 00404955  89742410             mov dword ptr [esp + 0x10], esi
// 00404959  3bc3                 cmp eax, ebx
// 0040495b  7416                 je 0x404973
// 0040495d  3bcb                 cmp ecx, ebx
// 0040495f  7407                 je 0x404968
// 00404961  51                   push ecx
// 00404962  ff150400a400         call dword ptr [0xa40004]
// 00404968  8bc7                 mov eax, edi
// 0040496a  5f                   pop edi
// 0040496b  5e                   pop esi
// 0040496c  5b                   pop ebx
// 0040496d  8be5                 mov esp, ebp
// 0040496f  5d                   pop ebp
// 00404970  c20400               ret 4
// 00404973  8b354c00a400         mov esi, dword ptr [0xa4004c]
// 00404979  8d442420             lea eax, [esp + 0x20]
// 0040497d  50                   push eax
// 0040497e  53                   push ebx
// 0040497f  53                   push ebx
// 00404980  53                   push ebx
// 00404981  8d542424             lea edx, [esp + 0x24]
// 00404985  52                   push edx
// 00404986  8d44243c             lea eax, [esp + 0x3c]
// 0040498a  50                   push eax
// 0040498b  53                   push ebx
// 0040498c  51                   push ecx
// 0040498d  c744243400010000     mov dword ptr [esp + 0x34], 0x100
// 00404995  ffd6                 call esi
// 00404997  85c0                 test eax, eax
// 00404999  753f                 jne 0x4049da
// 0040499b  eb03                 jmp 0x4049a0
// 0040499d  8d4900               lea ecx, [ecx]
// 004049a0  8d4c2428             lea ecx, [esp + 0x28]
// 004049a4  51                   push ecx
// 004049a5  8d4c2410             lea ecx, [esp + 0x10]
// 004049a9  e842ffffff           call 0x4048f0
// 004049ae  8bf8                 mov edi, eax
// 004049b0  3bfb                 cmp edi, ebx
// 004049b2  7566                 jne 0x404a1a
// 004049b4  8d542420             lea edx, [esp + 0x20]
// 004049b8  52                   push edx
// 004049b9  8b542410             mov edx, dword ptr [esp + 0x10]
// 004049bd  53                   push ebx
// 004049be  53                   push ebx
// 004049bf  53                   push ebx
// 004049c0  8d442424             lea eax, [esp + 0x24]
// 004049c4  50                   push eax
// 004049c5  8d4c243c             lea ecx, [esp + 0x3c]
// 004049c9  51                   push ecx
// 004049ca  53                   push ebx
// 004049cb  52                   push edx
// 004049cc  c744243400010000     mov dword ptr [esp + 0x34], 0x100
// 004049d4  ffd6                 call esi
// 004049d6  85c0                 test eax, eax
// 004049d8  74c6                 je 0x4049a0
// 004049da  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004049de  3bc3                 cmp eax, ebx
// 004049e0  740b                 je 0x4049ed
// 004049e2  50                   push eax
// 004049e3  ff150400a400         call dword ptr [0xa40004]
// 004049e9  895c240c             mov dword ptr [esp + 0xc], ebx
// 004049ed  8b4508               mov eax, dword ptr [ebp + 8]
// 004049f0  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004049f4  50                   push eax
// 004049f5  895c2414             mov dword ptr [esp + 0x14], ebx
// 004049f9  e822eeffff           call 0x403820
// 004049fe  8bf0                 mov esi, eax
// 00404a00  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00404a04  3bc3                 cmp eax, ebx
// 00404a06  7407                 je 0x404a0f
// 00404a08  50                   push eax
// 00404a09  ff150400a400         call dword ptr [0xa40004]
// 00404a0f  8bc6                 mov eax, esi
// 00404a11  5f                   pop edi
// 00404a12  5e                   pop esi
// 00404a13  5b                   pop ebx
// 00404a14  8be5                 mov esp, ebp
// 00404a16  5d                   pop ebp
// 00404a17  c20400               ret 4
// 00404a1a  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00404a1e  3bc3                 cmp eax, ebx
// 00404a20  7407                 je 0x404a29
// 00404a22  50                   push eax
// 00404a23  ff150400a400         call dword ptr [0xa40004]
// 00404a29  8bc7                 mov eax, edi
// 00404a2b  5f                   pop edi
// 00404a2c  5e                   pop esi
// 00404a2d  5b                   pop ebx
// 00404a2e  8be5                 mov esp, ebp
// 00404a30  5d                   pop ebp
// 00404a31  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ?RecurseDeleteKey@CRegKey@ATL@@QAEJPBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp
