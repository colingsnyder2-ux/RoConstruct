// from server: 100% by auto
// roc 2010-06 00406f30  unit: VCApp::?$CComContainedObject  size: 283 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00406f30
//
// 00406f30  83ec08               sub esp, 8
// 00406f33  53                   push ebx
// 00406f34  8bd9                 mov ebx, ecx
// 00406f36  33c0                 xor eax, eax
// 00406f38  39430c               cmp dword ptr [ebx + 0xc], eax
// 00406f3b  7405                 je 0x406f42
// 00406f3d  394314               cmp dword ptr [ebx + 0x14], eax
// 00406f40  750a                 jne 0x406f4c
// 00406f42  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00406f46  50                   push eax
// 00406f47  e8e4faffff           call 0x406a30
// 00406f4c  837b0c00             cmp dword ptr [ebx + 0xc], 0
// 00406f50  0f84d1000000         je 0x407027
// 00406f56  837b1400             cmp dword ptr [ebx + 0x14], 0
// 00406f5a  55                   push ebp
// 00406f5b  56                   push esi
// 00406f5c  57                   push edi
// 00406f5d  0f84a7000000         je 0x40700a
// 00406f63  837c242401           cmp dword ptr [esp + 0x24], 1
// 00406f68  0f859c000000         jne 0x40700a
// 00406f6e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00406f72  8b01                 mov eax, dword ptr [ecx]
// 00406f74  50                   push eax
// 00406f75  ff15a8a39e00         call dword ptr [0x9ea3a8]
// 00406f7b  8b7b18               mov edi, dword ptr [ebx + 0x18]
// 00406f7e  83ef01               sub edi, 1
// 00406f81  89442410             mov dword ptr [esp + 0x10], eax
// 00406f85  0f887f000000         js 0x40700a
// 00406f8b  8b4314               mov eax, dword ptr [ebx + 0x14]
// 00406f8e  8d2c7f               lea ebp, [edi + edi*2]
// 00406f91  03ed                 add ebp, ebp
// 00406f93  03ed                 add ebp, ebp
// 00406f95  8d542804             lea edx, [eax + ebp + 4]
// 00406f99  89442414             mov dword ptr [esp + 0x14], eax
// 00406f9d  89542428             mov dword ptr [esp + 0x28], edx
// 00406fa1  8b442410             mov eax, dword ptr [esp + 0x10]
// 00406fa5  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00406fa9  3b01                 cmp eax, dword ptr [ecx]
// 00406fab  7550                 jne 0x406ffd
// 00406fad  8b5314               mov edx, dword ptr [ebx + 0x14]
// 00406fb0  8b4c2a04             mov ecx, dword ptr [edx + ebp + 4]
// 00406fb4  8b442420             mov eax, dword ptr [esp + 0x20]
// 00406fb8  8b30                 mov esi, dword ptr [eax]
// 00406fba  03d5                 add edx, ebp
// 00406fbc  8b12                 mov edx, dword ptr [edx]
// 00406fbe  03c9                 add ecx, ecx
// 00406fc0  83f904               cmp ecx, 4
// 00406fc3  7214                 jb 0x406fd9
// 00406fc5  8b02                 mov eax, dword ptr [edx]
// 00406fc7  3b06                 cmp eax, dword ptr [esi]
// 00406fc9  7532                 jne 0x406ffd
// 00406fcb  83e904               sub ecx, 4
// 00406fce  83c604               add esi, 4
// 00406fd1  83c204               add edx, 4
// 00406fd4  83f904               cmp ecx, 4
// 00406fd7  73ec                 jae 0x406fc5
// 00406fd9  85c9                 test ecx, ecx
// 00406fdb  7451                 je 0x40702e
// 00406fdd  8a06                 mov al, byte ptr [esi]
// 00406fdf  3a02                 cmp al, byte ptr [edx]
// 00406fe1  751a                 jne 0x406ffd
// 00406fe3  83f901               cmp ecx, 1
// 00406fe6  7646                 jbe 0x40702e
// 00406fe8  8a4601               mov al, byte ptr [esi + 1]
// 00406feb  3a4201               cmp al, byte ptr [edx + 1]
// 00406fee  750d                 jne 0x406ffd
// 00406ff0  83f902               cmp ecx, 2
// 00406ff3  7639                 jbe 0x40702e
// 00406ff5  8a4e02               mov cl, byte ptr [esi + 2]
// 00406ff8  3a4a02               cmp cl, byte ptr [edx + 2]
// 00406ffb  7431                 je 0x40702e
// 00406ffd  836c24280c           sub dword ptr [esp + 0x28], 0xc
// 00407002  4f                   dec edi
// 00407003  83ed0c               sub ebp, 0xc
// 00407006  85ff                 test edi, edi
// 00407008  7d97                 jge 0x406fa1
// 0040700a  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 0040700e  8b430c               mov eax, dword ptr [ebx + 0xc]
// 00407011  8b08                 mov ecx, dword ptr [eax]
// 00407013  52                   push edx
// 00407014  8b542428             mov edx, dword ptr [esp + 0x28]
// 00407018  52                   push edx
// 00407019  8b542428             mov edx, dword ptr [esp + 0x28]
// 0040701d  52                   push edx
// 0040701e  50                   push eax
// 0040701f  8b4128               mov eax, dword ptr [ecx + 0x28]
// 00407022  ffd0                 call eax
// 00407024  5f                   pop edi
// 00407025  5e                   pop esi
// 00407026  5d                   pop ebp
// 00407027  5b                   pop ebx
// 00407028  83c408               add esp, 8
// 0040702b  c21400               ret 0x14
// 0040702e  8b442414             mov eax, dword ptr [esp + 0x14]
// 00407032  8d147f               lea edx, [edi + edi*2]
// 00407035  8b4c9008             mov ecx, dword ptr [eax + edx*4 + 8]
// 00407039  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 0040703d  5f                   pop edi
// 0040703e  5e                   pop esi
// 0040703f  5d                   pop ebp
// 00407040  890a                 mov dword ptr [edx], ecx
// 00407042  33c0                 xor eax, eax
// 00407044  5b                   pop ebx
// 00407045  83c408               add esp, 8
// 00407048  c21400               ret 0x14
// library atl-9.0/atl.cpp (function ?GetIDsOfNames@CComTypeInfoHolder@ATL@@QAEJABU_GUID@@PAPA_WIKPAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
