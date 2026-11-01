// from server: 100% by auto
// roc 2009-06 00804da0  unit: CXTPRichRender  size: 343 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00804da0
//
// 00804da0  83ec30               sub esp, 0x30
// 00804da3  53                   push ebx
// 00804da4  8bd9                 mov ebx, ecx
// 00804da6  8b4b24               mov ecx, dword ptr [ebx + 0x24]
// 00804da9  55                   push ebp
// 00804daa  33ed                 xor ebp, ebp
// 00804dac  3bcd                 cmp ecx, ebp
// 00804dae  7511                 jne 0x804dc1
// 00804db0  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 00804db4  8928                 mov dword ptr [eax], ebp
// 00804db6  896804               mov dword ptr [eax + 4], ebp
// 00804db9  5d                   pop ebp
// 00804dba  5b                   pop ebx
// 00804dbb  83c430               add esp, 0x30
// 00804dbe  c20c00               ret 0xc
// 00804dc1  56                   push esi
// 00804dc2  8d542414             lea edx, [esp + 0x14]
// 00804dc6  52                   push edx
// 00804dc7  6800000400           push 0x40000
// 00804dcc  896c241c             mov dword ptr [esp + 0x1c], ebp
// 00804dd0  8b01                 mov eax, dword ptr [ecx]
// 00804dd2  8b400c               mov eax, dword ptr [eax + 0xc]
// 00804dd5  55                   push ebp
// 00804dd6  6845040000           push 0x445
// 00804ddb  ffd0                 call eax
// 00804ddd  8b442448             mov eax, dword ptr [esp + 0x48]
// 00804de1  33f6                 xor esi, esi
// 00804de3  03c0                 add eax, eax
// 00804de5  89ab28010000         mov dword ptr [ebx + 0x128], ebp
// 00804deb  89ab24010000         mov dword ptr [ebx + 0x124], ebp
// 00804df1  89742410             mov dword ptr [esp + 0x10], esi
// 00804df5  896c240c             mov dword ptr [esp + 0xc], ebp
// 00804df9  89442448             mov dword ptr [esp + 0x48], eax
// 00804dfd  896c241c             mov dword ptr [esp + 0x1c], ebp
// 00804e01  896c2420             mov dword ptr [esp + 0x20], ebp
// 00804e05  896c2424             mov dword ptr [esp + 0x24], ebp
// 00804e09  896c2428             mov dword ptr [esp + 0x28], ebp
// 00804e0d  57                   push edi
// 00804e0e  8bff                 mov edi, edi
// 00804e10  8b7b24               mov edi, dword ptr [ebx + 0x24]
// 00804e13  55                   push ebp
// 00804e14  55                   push ebp
// 00804e15  03c6                 add eax, esi
// 00804e17  55                   push ebp
// 00804e18  99                   cdq 
// 00804e19  8d4c242c             lea ecx, [esp + 0x2c]
// 00804e1d  51                   push ecx
// 00804e1e  8b4c2458             mov ecx, dword ptr [esp + 0x58]
// 00804e22  2bc2                 sub eax, edx
// 00804e24  55                   push ebp
// 00804e25  8d542444             lea edx, [esp + 0x44]
// 00804e29  8bf0                 mov esi, eax
// 00804e2b  52                   push edx
// 00804e2c  d1fe                 sar esi, 1
// 00804e2e  55                   push ebp
// 00804e2f  896c244c             mov dword ptr [esp + 0x4c], ebp
// 00804e33  896c2450             mov dword ptr [esp + 0x50], ebp
// 00804e37  89742454             mov dword ptr [esp + 0x54], esi
// 00804e3b  c744245801000000     mov dword ptr [esp + 0x58], 1
// 00804e43  e818e4f1ff           call 0x723260
// 00804e48  50                   push eax
// 00804e49  8b07                 mov eax, dword ptr [edi]
// 00804e4b  8b4010               mov eax, dword ptr [eax + 0x10]
// 00804e4e  33ed                 xor ebp, ebp
// 00804e50  55                   push ebp
// 00804e51  55                   push ebp
// 00804e52  55                   push ebp
// 00804e53  6a01                 push 1
// 00804e55  8bcf                 mov ecx, edi
// 00804e57  ffd0                 call eax
// 00804e59  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00804e5d  3bcd                 cmp ecx, ebp
// 00804e5f  750a                 jne 0x804e6b
// 00804e61  8b8b28010000         mov ecx, dword ptr [ebx + 0x128]
// 00804e67  894c2410             mov dword ptr [esp + 0x10], ecx
// 00804e6b  398b28010000         cmp dword ptr [ebx + 0x128], ecx
// 00804e71  7e0b                 jle 0x804e7e
// 00804e73  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 00804e77  46                   inc esi
// 00804e78  89742414             mov dword ptr [esp + 0x14], esi
// 00804e7c  eb0b                 jmp 0x804e89
// 00804e7e  8d46ff               lea eax, [esi - 1]
// 00804e81  8b742414             mov esi, dword ptr [esp + 0x14]
// 00804e85  8944244c             mov dword ptr [esp + 0x4c], eax
// 00804e89  3bf0                 cmp esi, eax
// 00804e8b  7c83                 jl 0x804e10
// 00804e8d  398b28010000         cmp dword ptr [ebx + 0x128], ecx
// 00804e93  5f                   pop edi
// 00804e94  7e43                 jle 0x804ed9
// 00804e96  40                   inc eax
// 00804e97  89442434             mov dword ptr [esp + 0x34], eax
// 00804e9b  8b442444             mov eax, dword ptr [esp + 0x44]
// 00804e9f  896c242c             mov dword ptr [esp + 0x2c], ebp
// 00804ea3  896c2430             mov dword ptr [esp + 0x30], ebp
// 00804ea7  c744243801000000     mov dword ptr [esp + 0x38], 1
// 00804eaf  3bc5                 cmp eax, ebp
// 00804eb1  7504                 jne 0x804eb7
// 00804eb3  33c0                 xor eax, eax
// 00804eb5  eb03                 jmp 0x804eba
// 00804eb7  8b4004               mov eax, dword ptr [eax + 4]
// 00804eba  8b4b24               mov ecx, dword ptr [ebx + 0x24]
// 00804ebd  8b11                 mov edx, dword ptr [ecx]
// 00804ebf  55                   push ebp
// 00804ec0  55                   push ebp
// 00804ec1  55                   push ebp
// 00804ec2  8d742428             lea esi, [esp + 0x28]
// 00804ec6  56                   push esi
// 00804ec7  55                   push ebp
// 00804ec8  8d742440             lea esi, [esp + 0x40]
// 00804ecc  56                   push esi
// 00804ecd  55                   push ebp
// 00804ece  50                   push eax
// 00804ecf  8b4210               mov eax, dword ptr [edx + 0x10]
// 00804ed2  55                   push ebp
// 00804ed3  55                   push ebp
// 00804ed4  55                   push ebp
// 00804ed5  6a01                 push 1
// 00804ed7  ffd0                 call eax
// 00804ed9  8b8b24010000         mov ecx, dword ptr [ebx + 0x124]
// 00804edf  8b442440             mov eax, dword ptr [esp + 0x40]
// 00804ee3  8b9328010000         mov edx, dword ptr [ebx + 0x128]
// 00804ee9  5e                   pop esi
// 00804eea  5d                   pop ebp
// 00804eeb  8908                 mov dword ptr [eax], ecx
// 00804eed  895004               mov dword ptr [eax + 4], edx
// 00804ef0  5b                   pop ebx
// 00804ef1  83c430               add esp, 0x30
// 00804ef4  c20c00               ret 0xc
// library xtp-15.2.1/Source\Common\XTPRichRender.cpp (function ?GetTextExtent@CXTPRichRender@@QAE?AVCSize@@PAVCDC@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPRichRender.cpp
