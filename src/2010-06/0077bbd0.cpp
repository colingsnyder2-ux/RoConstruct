// from server: 100% by auto
// roc 2010-06 0077bbd0  unit: RBX::PartDropTool  size: 448 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0077bbd0
//
// 0077bbd0  55                   push ebp
// 0077bbd1  8bec                 mov ebp, esp
// 0077bbd3  83e4c0               and esp, 0xffffffc0
// 0077bbd6  83ec3c               sub esp, 0x3c
// 0077bbd9  53                   push ebx
// 0077bbda  8bd8                 mov ebx, eax
// 0077bbdc  8b4608               mov eax, dword ptr [esi + 8]
// 0077bbdf  b903000000           mov ecx, 3
// 0077bbe4  3bc1                 cmp eax, ecx
// 0077bbe6  7506                 jne 0x77bbee
// 0077bbe8  89742418             mov dword ptr [esp + 0x18], esi
// 0077bbec  eb41                 jmp 0x77bc2f
// 0077bbee  83f804               cmp eax, 4
// 0077bbf1  0f8519010000         jne 0x77bd10
// 0077bbf7  8b0e                 mov ecx, dword ptr [esi]
// 0077bbf9  8d442418             lea eax, [esp + 0x18]
// 0077bbfd  50                   push eax
// 0077bbfe  83c110               add ecx, 0x10
// 0077bc01  51                   push ecx
// 0077bc02  e8e96dfbff           call 0x7329f0
// 0077bc07  83c408               add esp, 8
// 0077bc0a  85c0                 test eax, eax
// 0077bc0c  0f84fe000000         je 0x77bd10
// 0077bc12  dd442418             fld qword ptr [esp + 0x18]
// 0077bc16  8d542430             lea edx, [esp + 0x30]
// 0077bc1a  dd5c2430             fstp qword ptr [esp + 0x30]
// 0077bc1e  c744243803000000     mov dword ptr [esp + 0x38], 3
// 0077bc26  89542418             mov dword ptr [esp + 0x18], edx
// 0077bc2a  b903000000           mov ecx, 3
// 0077bc2f  8b4308               mov eax, dword ptr [ebx + 8]
// 0077bc32  3bc1                 cmp eax, ecx
// 0077bc34  743d                 je 0x77bc73
// 0077bc36  83f804               cmp eax, 4
// 0077bc39  0f85d1000000         jne 0x77bd10
// 0077bc3f  8b0b                 mov ecx, dword ptr [ebx]
// 0077bc41  8d442420             lea eax, [esp + 0x20]
// 0077bc45  50                   push eax
// 0077bc46  83c110               add ecx, 0x10
// 0077bc49  51                   push ecx
// 0077bc4a  e8a16dfbff           call 0x7329f0
// 0077bc4f  83c408               add esp, 8
// 0077bc52  85c0                 test eax, eax
// 0077bc54  0f84b6000000         je 0x77bd10
// 0077bc5a  dd442420             fld qword ptr [esp + 0x20]
// 0077bc5e  c744242803000000     mov dword ptr [esp + 0x28], 3
// 0077bc66  dd5c2420             fstp qword ptr [esp + 0x20]
// 0077bc6a  8d5c2420             lea ebx, [esp + 0x20]
// 0077bc6e  b903000000           mov ecx, 3
// 0077bc73  8b542418             mov edx, dword ptr [esp + 0x18]
// 0077bc77  dd02                 fld qword ptr [edx]
// 0077bc79  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0077bc7c  dd542418             fst qword ptr [esp + 0x18]
// 0077bc80  83c0fb               add eax, -5
// 0077bc83  dd03                 fld qword ptr [ebx]
// 0077bc85  dd542420             fst qword ptr [esp + 0x20]
// 0077bc89  83f806               cmp eax, 6
// 0077bc8c  0f87d7000000         ja 0x77bd69
// 0077bc92  ff248574bd7700       jmp dword ptr [eax*4 + 0x77bd74]
// 0077bc99  dec1                 faddp st(1)
// 0077bc9b  894f08               mov dword ptr [edi + 8], ecx
// 0077bc9e  dd1f                 fstp qword ptr [edi]
// 0077bca0  5b                   pop ebx
// 0077bca1  8be5                 mov esp, ebp
// 0077bca3  5d                   pop ebp
// 0077bca4  c3                   ret 
// 0077bca5  dee9                 fsubp st(1)
// 0077bca7  894f08               mov dword ptr [edi + 8], ecx
// 0077bcaa  dd1f                 fstp qword ptr [edi]
// 0077bcac  5b                   pop ebx
// 0077bcad  8be5                 mov esp, ebp
// 0077bcaf  5d                   pop ebp
// 0077bcb0  c3                   ret 
// 0077bcb1  dec9                 fmulp st(1)
// 0077bcb3  894f08               mov dword ptr [edi + 8], ecx
// 0077bcb6  dd1f                 fstp qword ptr [edi]
// 0077bcb8  5b                   pop ebx
// 0077bcb9  8be5                 mov esp, ebp
// 0077bcbb  5d                   pop ebp
// 0077bcbc  c3                   ret 
// 0077bcbd  def9                 fdivp st(1)
// 0077bcbf  894f08               mov dword ptr [edi + 8], ecx
// 0077bcc2  dd1f                 fstp qword ptr [edi]
// 0077bcc4  5b                   pop ebx
// 0077bcc5  8be5                 mov esp, ebp
// 0077bcc7  5d                   pop ebp
// 0077bcc8  c3                   ret 
// 0077bcc9  def9                 fdivp st(1)
// 0077bccb  83ec08               sub esp, 8
// 0077bcce  dd1c24               fstp qword ptr [esp]
// 0077bcd1  e81ad50200           call 0x7a91f0
// 0077bcd6  dc4c2428             fmul qword ptr [esp + 0x28]
// 0077bcda  83c408               add esp, 8
// 0077bcdd  c7470803000000       mov dword ptr [edi + 8], 3
// 0077bce4  dc6c2418             fsubr qword ptr [esp + 0x18]
// 0077bce8  dd1f                 fstp qword ptr [edi]
// 0077bcea  5b                   pop ebx
// 0077bceb  8be5                 mov esp, ebp
// 0077bced  5d                   pop ebp
// 0077bcee  c3                   ret 
// 0077bcef  e86cd50200           call 0x7a9260
// 0077bcf4  dd1f                 fstp qword ptr [edi]
// 0077bcf6  c7470803000000       mov dword ptr [edi + 8], 3
// 0077bcfd  5b                   pop ebx
// 0077bcfe  8be5                 mov esp, ebp
// 0077bd00  5d                   pop ebp
// 0077bd01  c3                   ret 
// 0077bd02  ddd8                 fstp st(0)
// 0077bd04  894f08               mov dword ptr [edi + 8], ecx
// 0077bd07  d9e0                 fchs 
// 0077bd09  dd1f                 fstp qword ptr [edi]
// 0077bd0b  5b                   pop ebx
// 0077bd0c  8be5                 mov esp, ebp
// 0077bd0e  5d                   pop ebp
// 0077bd0f  c3                   ret 
// 0077bd10  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0077bd13  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0077bd16  50                   push eax
// 0077bd17  56                   push esi
// 0077bd18  51                   push ecx
// 0077bd19  e8b2f3ffff           call 0x77b0d0
// 0077bd1e  83c40c               add esp, 0xc
// 0077bd21  83780800             cmp dword ptr [eax + 8], 0
// 0077bd25  7517                 jne 0x77bd3e
// 0077bd27  8b550c               mov edx, dword ptr [ebp + 0xc]
// 0077bd2a  8b4508               mov eax, dword ptr [ebp + 8]
// 0077bd2d  52                   push edx
// 0077bd2e  53                   push ebx
// 0077bd2f  50                   push eax
// 0077bd30  e89bf3ffff           call 0x77b0d0
// 0077bd35  83c40c               add esp, 0xc
// 0077bd38  83780800             cmp dword ptr [eax + 8], 0
// 0077bd3c  7418                 je 0x77bd56
// 0077bd3e  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0077bd41  50                   push eax
// 0077bd42  51                   push ecx
// 0077bd43  8bcb                 mov ecx, ebx
// 0077bd45  8bd6                 mov edx, esi
// 0077bd47  8bc7                 mov eax, edi
// 0077bd49  e832f5ffff           call 0x77b280
// 0077bd4e  83c408               add esp, 8
// 0077bd51  5b                   pop ebx
// 0077bd52  8be5                 mov esp, ebp
// 0077bd54  5d                   pop ebp
// 0077bd55  c3                   ret 
// 0077bd56  8b5508               mov edx, dword ptr [ebp + 8]
// 0077bd59  53                   push ebx
// 0077bd5a  56                   push esi
// 0077bd5b  52                   push edx
// 0077bd5c  e82f81fbff           call 0x733e90
// 0077bd61  83c40c               add esp, 0xc
// 0077bd64  5b                   pop ebx
// 0077bd65  8be5                 mov esp, ebp
// 0077bd67  5d                   pop ebp
// 0077bd68  c3                   ret 
// 0077bd69  ddd8                 fstp st(0)
// 0077bd6b  5b                   pop ebx
// 0077bd6c  ddd8                 fstp st(0)
// 0077bd6e  8be5                 mov esp, ebp
// 0077bd70  5d                   pop ebp
// 0077bd71  c3                   ret 
// 0077bd72  8bff                 mov edi, edi
// 0077bd74  99                   cdq 
// 0077bd75  bc7700a5bc           mov esp, 0xbca50077
// 0077bd7a  7700                 ja 0x77bd7c
// 0077bd7c  b1bc                 mov cl, 0xbc
// 0077bd7e  7700                 ja 0x77bd80
// 0077bd80  bdbc7700c9           mov ebp, 0xc90077bc
// 0077bd85  bc7700efbc           mov esp, 0xbcef0077
// 0077bd8a  7700                 ja 0x77bd8c
// library lua-5.1.2/lvm.c (function _Arith)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 lvm.c
