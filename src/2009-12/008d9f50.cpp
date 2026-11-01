// from server: 100% by auto
// roc 2009-12 008d9f50  unit: CXTColorHex  size: 2261 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008d9f50
//
// 008d9f50  83ec40               sub esp, 0x40
// 008d9f53  53                   push ebx
// 008d9f54  8b5968               mov ebx, dword ptr [ecx + 0x68]
// 008d9f57  55                   push ebp
// 008d9f58  8b696c               mov ebp, dword ptr [ecx + 0x6c]
// 008d9f5b  56                   push esi
// 008d9f5c  8b3514b19800         mov esi, dword ptr [0x98b114]
// 008d9f62  57                   push edi
// 008d9f63  8b7c2454             mov edi, dword ptr [esp + 0x54]
// 008d9f67  83eb02               sub ebx, 2
// 008d9f6a  4d                   dec ebp
// 008d9f6b  c744241000000000     mov dword ptr [esp + 0x10], 0
// 008d9f73  8b442410             mov eax, dword ptr [esp + 0x10]
// 008d9f77  8b4f04               mov ecx, dword ptr [edi + 4]
// 008d9f7a  6a00                 push 0
// 008d9f7c  03c5                 add eax, ebp
// 008d9f7e  50                   push eax
// 008d9f7f  53                   push ebx
// 008d9f80  51                   push ecx
// 008d9f81  ffd6                 call esi
// 008d9f83  8b442410             mov eax, dword ptr [esp + 0x10]
// 008d9f87  40                   inc eax
// 008d9f88  83f80b               cmp eax, 0xb
// 008d9f8b  89442410             mov dword ptr [esp + 0x10], eax
// 008d9f8f  7ce2                 jl 0x8d9f73
// 008d9f91  8b5704               mov edx, dword ptr [edi + 4]
// 008d9f94  6a00                 push 0
// 008d9f96  8d450b               lea eax, [ebp + 0xb]
// 008d9f99  8d4b01               lea ecx, [ebx + 1]
// 008d9f9c  50                   push eax
// 008d9f9d  51                   push ecx
// 008d9f9e  52                   push edx
// 008d9f9f  894c2434             mov dword ptr [esp + 0x34], ecx
// 008d9fa3  ffd6                 call esi
// 008d9fa5  6a00                 push 0
// 008d9fa7  8d450b               lea eax, [ebp + 0xb]
// 008d9faa  50                   push eax
// 008d9fab  8b4704               mov eax, dword ptr [edi + 4]
// 008d9fae  8d4b02               lea ecx, [ebx + 2]
// 008d9fb1  51                   push ecx
// 008d9fb2  50                   push eax
// 008d9fb3  ffd6                 call esi
// 008d9fb5  6a00                 push 0
// 008d9fb7  8d450c               lea eax, [ebp + 0xc]
// 008d9fba  50                   push eax
// 008d9fbb  8d4b03               lea ecx, [ebx + 3]
// 008d9fbe  51                   push ecx
// 008d9fbf  8b4f04               mov ecx, dword ptr [edi + 4]
// 008d9fc2  51                   push ecx
// 008d9fc3  ffd6                 call esi
// 008d9fc5  8b5704               mov edx, dword ptr [edi + 4]
// 008d9fc8  6a00                 push 0
// 008d9fca  8d450c               lea eax, [ebp + 0xc]
// 008d9fcd  8d4b04               lea ecx, [ebx + 4]
// 008d9fd0  50                   push eax
// 008d9fd1  51                   push ecx
// 008d9fd2  52                   push edx
// 008d9fd3  894c2430             mov dword ptr [esp + 0x30], ecx
// 008d9fd7  ffd6                 call esi
// 008d9fd9  6a00                 push 0
// 008d9fdb  8d450d               lea eax, [ebp + 0xd]
// 008d9fde  50                   push eax
// 008d9fdf  8b4704               mov eax, dword ptr [edi + 4]
// 008d9fe2  8d4b05               lea ecx, [ebx + 5]
// 008d9fe5  51                   push ecx
// 008d9fe6  50                   push eax
// 008d9fe7  894c242c             mov dword ptr [esp + 0x2c], ecx
// 008d9feb  ffd6                 call esi
// 008d9fed  6a00                 push 0
// 008d9fef  8d450d               lea eax, [ebp + 0xd]
// 008d9ff2  8d4b06               lea ecx, [ebx + 6]
// 008d9ff5  50                   push eax
// 008d9ff6  51                   push ecx
// 008d9ff7  894c2424             mov dword ptr [esp + 0x24], ecx
// 008d9ffb  8b4f04               mov ecx, dword ptr [edi + 4]
// 008d9ffe  51                   push ecx
// 008d9fff  ffd6                 call esi
// 008da001  8d5307               lea edx, [ebx + 7]
// 008da004  c744241000000000     mov dword ptr [esp + 0x10], 0
// 008da00c  89542414             mov dword ptr [esp + 0x14], edx
// 008da010  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008da014  8b5704               mov edx, dword ptr [edi + 4]
// 008da017  6a00                 push 0
// 008da019  8d450e               lea eax, [ebp + 0xe]
// 008da01c  50                   push eax
// 008da01d  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008da021  03c1                 add eax, ecx
// 008da023  50                   push eax
// 008da024  52                   push edx
// 008da025  ffd6                 call esi
// 008da027  8b442410             mov eax, dword ptr [esp + 0x10]
// 008da02b  40                   inc eax
// 008da02c  83f805               cmp eax, 5
// 008da02f  89442410             mov dword ptr [esp + 0x10], eax
// 008da033  7cdb                 jl 0x8da010
// 008da035  6a00                 push 0
// 008da037  8d4d0d               lea ecx, [ebp + 0xd]
// 008da03a  51                   push ecx
// 008da03b  8d430c               lea eax, [ebx + 0xc]
// 008da03e  50                   push eax
// 008da03f  8b4704               mov eax, dword ptr [edi + 4]
// 008da042  50                   push eax
// 008da043  ffd6                 call esi
// 008da045  6a00                 push 0
// 008da047  8d4d0d               lea ecx, [ebp + 0xd]
// 008da04a  51                   push ecx
// 008da04b  8b4f04               mov ecx, dword ptr [edi + 4]
// 008da04e  8d430d               lea eax, [ebx + 0xd]
// 008da051  50                   push eax
// 008da052  51                   push ecx
// 008da053  ffd6                 call esi
// 008da055  8b5704               mov edx, dword ptr [edi + 4]
// 008da058  6a00                 push 0
// 008da05a  8d4d0c               lea ecx, [ebp + 0xc]
// 008da05d  51                   push ecx
// 008da05e  8d430e               lea eax, [ebx + 0xe]
// 008da061  50                   push eax
// 008da062  52                   push edx
// 008da063  ffd6                 call esi
// 008da065  6a00                 push 0
// 008da067  8d4d0c               lea ecx, [ebp + 0xc]
// 008da06a  51                   push ecx
// 008da06b  8d430f               lea eax, [ebx + 0xf]
// 008da06e  50                   push eax
// 008da06f  8b4704               mov eax, dword ptr [edi + 4]
// 008da072  50                   push eax
// 008da073  ffd6                 call esi
// 008da075  6a00                 push 0
// 008da077  8d4d0b               lea ecx, [ebp + 0xb]
// 008da07a  51                   push ecx
// 008da07b  8b4f04               mov ecx, dword ptr [edi + 4]
// 008da07e  8d4310               lea eax, [ebx + 0x10]
// 008da081  50                   push eax
// 008da082  51                   push ecx
// 008da083  ffd6                 call esi
// 008da085  8b5704               mov edx, dword ptr [edi + 4]
// 008da088  6a00                 push 0
// 008da08a  8d4d0b               lea ecx, [ebp + 0xb]
// 008da08d  51                   push ecx
// 008da08e  8d4311               lea eax, [ebx + 0x11]
// 008da091  50                   push eax
// 008da092  52                   push edx
// 008da093  ffd6                 call esi
// 008da095  c744241000000000     mov dword ptr [esp + 0x10], 0
// 008da09d  8d4900               lea ecx, [ecx]
// 008da0a0  8b442410             mov eax, dword ptr [esp + 0x10]
// 008da0a4  8b4f04               mov ecx, dword ptr [edi + 4]
// 008da0a7  6a00                 push 0
// 008da0a9  03c5                 add eax, ebp
// 008da0ab  50                   push eax
// 008da0ac  8d4312               lea eax, [ebx + 0x12]
// 008da0af  50                   push eax
// 008da0b0  51                   push ecx
// 008da0b1  ffd6                 call esi
// 008da0b3  8b442410             mov eax, dword ptr [esp + 0x10]
// 008da0b7  40                   inc eax
// 008da0b8  83f80b               cmp eax, 0xb
// 008da0bb  89442410             mov dword ptr [esp + 0x10], eax
// 008da0bf  7cdf                 jl 0x8da0a0
// 008da0c1  8b5704               mov edx, dword ptr [edi + 4]
// 008da0c4  6a00                 push 0
// 008da0c6  8d45ff               lea eax, [ebp - 1]
// 008da0c9  50                   push eax
// 008da0ca  8944245c             mov dword ptr [esp + 0x5c], eax
// 008da0ce  8d4310               lea eax, [ebx + 0x10]
// 008da0d1  50                   push eax
// 008da0d2  52                   push edx
// 008da0d3  ffd6                 call esi
// 008da0d5  8b442454             mov eax, dword ptr [esp + 0x54]
// 008da0d9  8b4f04               mov ecx, dword ptr [edi + 4]
// 008da0dc  6a00                 push 0
// 008da0de  50                   push eax
// 008da0df  8d4311               lea eax, [ebx + 0x11]
// 008da0e2  50                   push eax
// 008da0e3  51                   push ecx
// 008da0e4  ffd6                 call esi
// 008da0e6  8b5704               mov edx, dword ptr [edi + 4]
// 008da0e9  6a00                 push 0
// 008da0eb  8d45fe               lea eax, [ebp - 2]
// 008da0ee  50                   push eax
// 008da0ef  8d430e               lea eax, [ebx + 0xe]
// 008da0f2  50                   push eax
// 008da0f3  52                   push edx
// 008da0f4  ffd6                 call esi
// 008da0f6  6a00                 push 0
// 008da0f8  8d45fe               lea eax, [ebp - 2]
// 008da0fb  50                   push eax
// 008da0fc  8d430f               lea eax, [ebx + 0xf]
// 008da0ff  50                   push eax
// 008da100  8b4704               mov eax, dword ptr [edi + 4]
// 008da103  50                   push eax
// 008da104  ffd6                 call esi
// 008da106  8b4f04               mov ecx, dword ptr [edi + 4]
// 008da109  6a00                 push 0
// 008da10b  8d45fd               lea eax, [ebp - 3]
// 008da10e  50                   push eax
// 008da10f  8d430c               lea eax, [ebx + 0xc]
// 008da112  50                   push eax
// 008da113  51                   push ecx
// 008da114  ffd6                 call esi
// 008da116  8b5704               mov edx, dword ptr [edi + 4]
// 008da119  6a00                 push 0
// 008da11b  8d45fd               lea eax, [ebp - 3]
// 008da11e  50                   push eax
// 008da11f  8d430d               lea eax, [ebx + 0xd]
// 008da122  50                   push eax
// 008da123  52                   push edx
// 008da124  ffd6                 call esi
// 008da126  c744241000000000     mov dword ptr [esp + 0x10], 0
// 008da12e  8bff                 mov edi, edi
// 008da130  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008da134  8b5704               mov edx, dword ptr [edi + 4]
// 008da137  6a00                 push 0
// 008da139  8d45fc               lea eax, [ebp - 4]
// 008da13c  50                   push eax
// 008da13d  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008da141  03c1                 add eax, ecx
// 008da143  50                   push eax
// 008da144  52                   push edx
// 008da145  ffd6                 call esi
// 008da147  8b442410             mov eax, dword ptr [esp + 0x10]
// 008da14b  40                   inc eax
// 008da14c  83f805               cmp eax, 5
// 008da14f  89442410             mov dword ptr [esp + 0x10], eax
// 008da153  7cdb                 jl 0x8da130
// 008da155  8b4f04               mov ecx, dword ptr [edi + 4]
// 008da158  6a00                 push 0
// 008da15a  8d45fd               lea eax, [ebp - 3]
// 008da15d  50                   push eax
// 008da15e  8b442424             mov eax, dword ptr [esp + 0x24]
// 008da162  50                   push eax
// 008da163  51                   push ecx
// 008da164  ffd6                 call esi
// 008da166  8b542418             mov edx, dword ptr [esp + 0x18]
// 008da16a  6a00                 push 0
// 008da16c  8d45fd               lea eax, [ebp - 3]
// 008da16f  50                   push eax
// 008da170  8b4704               mov eax, dword ptr [edi + 4]
// 008da173  52                   push edx
// 008da174  50                   push eax
// 008da175  ffd6                 call esi
// 008da177  8b4f04               mov ecx, dword ptr [edi + 4]
// 008da17a  6a00                 push 0
// 008da17c  8d45fe               lea eax, [ebp - 2]
// 008da17f  50                   push eax
// 008da180  8d4303               lea eax, [ebx + 3]
// 008da183  50                   push eax
// 008da184  51                   push ecx
// 008da185  ffd6                 call esi
// 008da187  8b542420             mov edx, dword ptr [esp + 0x20]
// 008da18b  6a00                 push 0
// 008da18d  8d45fe               lea eax, [ebp - 2]
// 008da190  50                   push eax
// 008da191  8b4704               mov eax, dword ptr [edi + 4]
// 008da194  52                   push edx
// 008da195  50                   push eax
// 008da196  ffd6                 call esi
// 008da198  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 008da19c  8b542424             mov edx, dword ptr [esp + 0x24]
// 008da1a0  8b4704               mov eax, dword ptr [edi + 4]
// 008da1a3  6a00                 push 0
// 008da1a5  51                   push ecx
// 008da1a6  52                   push edx
// 008da1a7  50                   push eax
// 008da1a8  ffd6                 call esi
// 008da1aa  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 008da1ae  8b5704               mov edx, dword ptr [edi + 4]
// 008da1b1  6a00                 push 0
// 008da1b3  51                   push ecx
// 008da1b4  8d4302               lea eax, [ebx + 2]
// 008da1b7  50                   push eax
// 008da1b8  52                   push edx
// 008da1b9  ffd6                 call esi
// 008da1bb  c744241000000000     mov dword ptr [esp + 0x10], 0
// 008da1c3  8b442410             mov eax, dword ptr [esp + 0x10]
// 008da1c7  8b5704               mov edx, dword ptr [edi + 4]
// 008da1ca  6a00                 push 0
// 008da1cc  8d4c2802             lea ecx, [eax + ebp + 2]
// 008da1d0  51                   push ecx
// 008da1d1  8d4303               lea eax, [ebx + 3]
// 008da1d4  50                   push eax
// 008da1d5  52                   push edx
// 008da1d6  ffd6                 call esi
// 008da1d8  8b442410             mov eax, dword ptr [esp + 0x10]
// 008da1dc  40                   inc eax
// 008da1dd  83f807               cmp eax, 7
// 008da1e0  89442410             mov dword ptr [esp + 0x10], eax
// 008da1e4  7cdd                 jl 0x8da1c3
// 008da1e6  8b4f04               mov ecx, dword ptr [edi + 4]
// 008da1e9  6a00                 push 0
// 008da1eb  8d4509               lea eax, [ebp + 9]
// 008da1ee  50                   push eax
// 008da1ef  8b442428             mov eax, dword ptr [esp + 0x28]
// 008da1f3  50                   push eax
// 008da1f4  51                   push ecx
// 008da1f5  ffd6                 call esi
// 008da1f7  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 008da1fb  6a00                 push 0
// 008da1fd  8d4509               lea eax, [ebp + 9]
// 008da200  50                   push eax
// 008da201  8b4704               mov eax, dword ptr [edi + 4]
// 008da204  52                   push edx
// 008da205  50                   push eax
// 008da206  ffd6                 call esi
// 008da208  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 008da20c  8b5704               mov edx, dword ptr [edi + 4]
// 008da20f  6a00                 push 0
// 008da211  8d450a               lea eax, [ebp + 0xa]
// 008da214  50                   push eax
// 008da215  51                   push ecx
// 008da216  52                   push edx
// 008da217  ffd6                 call esi
// 008da219  8b4f04               mov ecx, dword ptr [edi + 4]
// 008da21c  6a00                 push 0
// 008da21e  8d450a               lea eax, [ebp + 0xa]
// 008da221  50                   push eax
// 008da222  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008da226  50                   push eax
// 008da227  51                   push ecx
// 008da228  ffd6                 call esi
// 008da22a  c744241000000000     mov dword ptr [esp + 0x10], 0
// 008da232  8b542410             mov edx, dword ptr [esp + 0x10]
// 008da236  8b4f04               mov ecx, dword ptr [edi + 4]
// 008da239  6a00                 push 0
// 008da23b  8d450b               lea eax, [ebp + 0xb]
// 008da23e  50                   push eax
// 008da23f  8d441308             lea eax, [ebx + edx + 8]
// 008da243  50                   push eax
// 008da244  51                   push ecx
// 008da245  ffd6                 call esi
// 008da247  8b442410             mov eax, dword ptr [esp + 0x10]
// 008da24b  40                   inc eax
// 008da24c  83f803               cmp eax, 3
// 008da24f  89442410             mov dword ptr [esp + 0x10], eax
// 008da253  7cdd                 jl 0x8da232
// 008da255  8b5704               mov edx, dword ptr [edi + 4]
// 008da258  6a00                 push 0
// 008da25a  8d4d0a               lea ecx, [ebp + 0xa]
// 008da25d  51                   push ecx
// 008da25e  8d430b               lea eax, [ebx + 0xb]
// 008da261  50                   push eax
// 008da262  52                   push edx
// 008da263  ffd6                 call esi
// 008da265  6a00                 push 0
// 008da267  8d450a               lea eax, [ebp + 0xa]
// 008da26a  50                   push eax
// 008da26b  8d430c               lea eax, [ebx + 0xc]
// 008da26e  50                   push eax
// 008da26f  8b4704               mov eax, dword ptr [edi + 4]
// 008da272  50                   push eax
// 008da273  ffd6                 call esi
// 008da275  8b4f04               mov ecx, dword ptr [edi + 4]
// 008da278  6a00                 push 0
// 008da27a  8d4509               lea eax, [ebp + 9]
// 008da27d  50                   push eax
// 008da27e  8d430d               lea eax, [ebx + 0xd]
// 008da281  50                   push eax
// 008da282  51                   push ecx
// 008da283  ffd6                 call esi
// 008da285  8b5704               mov edx, dword ptr [edi + 4]
// 008da288  6a00                 push 0
// 008da28a  8d4509               lea eax, [ebp + 9]
// 008da28d  50                   push eax
// 008da28e  8d430e               lea eax, [ebx + 0xe]
// 008da291  50                   push eax
// 008da292  52                   push edx
// 008da293  ffd6                 call esi
// 008da295  c744241000000000     mov dword ptr [esp + 0x10], 0
// 008da29d  8d4900               lea ecx, [ecx]
// 008da2a0  8b442410             mov eax, dword ptr [esp + 0x10]
// 008da2a4  8b5704               mov edx, dword ptr [edi + 4]
// 008da2a7  6a00                 push 0
// 008da2a9  8d4c2802             lea ecx, [eax + ebp + 2]
// 008da2ad  51                   push ecx
// 008da2ae  8d430f               lea eax, [ebx + 0xf]
// 008da2b1  50                   push eax
// 008da2b2  52                   push edx
// 008da2b3  ffd6                 call esi
// 008da2b5  8b442410             mov eax, dword ptr [esp + 0x10]
// 008da2b9  40                   inc eax
// 008da2ba  83f807               cmp eax, 7
// 008da2bd  89442410             mov dword ptr [esp + 0x10], eax
// 008da2c1  7cdd                 jl 0x8da2a0
// 008da2c3  6a00                 push 0
// 008da2c5  8d4501               lea eax, [ebp + 1]
// 008da2c8  50                   push eax
// 008da2c9  8d430d               lea eax, [ebx + 0xd]
// 008da2cc  50                   push eax
// 008da2cd  8b4704               mov eax, dword ptr [edi + 4]
// 008da2d0  50                   push eax
// 008da2d1  ffd6                 call esi
// 008da2d3  8b4f04               mov ecx, dword ptr [edi + 4]
// 008da2d6  6a00                 push 0
// 008da2d8  8d4501               lea eax, [ebp + 1]
// 008da2db  50                   push eax
// 008da2dc  8d430e               lea eax, [ebx + 0xe]
// 008da2df  50                   push eax
// 008da2e0  51                   push ecx
// 008da2e1  ffd6                 call esi
// 008da2e3  8b5704               mov edx, dword ptr [edi + 4]
// 008da2e6  6a00                 push 0
// 008da2e8  55                   push ebp
// 008da2e9  8d430b               lea eax, [ebx + 0xb]
// 008da2ec  50                   push eax
// 008da2ed  52                   push edx
// 008da2ee  ffd6                 call esi
// 008da2f0  6a00                 push 0
// 008da2f2  55                   push ebp
// 008da2f3  8d430c               lea eax, [ebx + 0xc]
// 008da2f6  50                   push eax
// 008da2f7  8b4704               mov eax, dword ptr [edi + 4]
// 008da2fa  50                   push eax
// 008da2fb  ffd6                 call esi
// 008da2fd  c744241000000000     mov dword ptr [esp + 0x10], 0
// 008da305  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 008da309  8b542410             mov edx, dword ptr [esp + 0x10]
// 008da30d  6a00                 push 0
// 008da30f  51                   push ecx
// 008da310  8b4f04               mov ecx, dword ptr [edi + 4]
// 008da313  8d441308             lea eax, [ebx + edx + 8]
// 008da317  50                   push eax
// 008da318  51                   push ecx
// 008da319  ffd6                 call esi
// 008da31b  8b442410             mov eax, dword ptr [esp + 0x10]
// 008da31f  40                   inc eax
// 008da320  83f803               cmp eax, 3
// 008da323  89442410             mov dword ptr [esp + 0x10], eax
// 008da327  7cdc                 jl 0x8da305
// 008da329  8b542418             mov edx, dword ptr [esp + 0x18]
// 008da32d  8b4704               mov eax, dword ptr [edi + 4]
// 008da330  6a00                 push 0
// 008da332  55                   push ebp
// 008da333  52                   push edx
// 008da334  50                   push eax
// 008da335  ffd6                 call esi
// 008da337  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008da33b  8b5704               mov edx, dword ptr [edi + 4]
// 008da33e  6a00                 push 0
// 008da340  55                   push ebp
// 008da341  51                   push ecx
// 008da342  52                   push edx
// 008da343  ffd6                 call esi
// 008da345  8b442420             mov eax, dword ptr [esp + 0x20]
// 008da349  8b4f04               mov ecx, dword ptr [edi + 4]
// 008da34c  6a00                 push 0
// 008da34e  8d5d01               lea ebx, [ebp + 1]
// 008da351  53                   push ebx
// 008da352  50                   push eax
// 008da353  51                   push ecx
// 008da354  ffd6                 call esi
// 008da356  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 008da35a  8b4704               mov eax, dword ptr [edi + 4]
// 008da35d  6a00                 push 0
// 008da35f  53                   push ebx
// 008da360  52                   push edx
// 008da361  50                   push eax
// 008da362  ffd6                 call esi
// 008da364  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 008da368  896c2420             mov dword ptr [esp + 0x20], ebp
// 008da36c  c74424240b000000     mov dword ptr [esp + 0x24], 0xb
// 008da374  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 008da378  8b5704               mov edx, dword ptr [edi + 4]
// 008da37b  68ffffff00           push 0xffffff
// 008da380  51                   push ecx
// 008da381  53                   push ebx
// 008da382  52                   push edx
// 008da383  ffd6                 call esi
// 008da385  8b442420             mov eax, dword ptr [esp + 0x20]
// 008da389  8b4f04               mov ecx, dword ptr [edi + 4]
// 008da38c  68ffffff00           push 0xffffff
// 008da391  50                   push eax
// 008da392  8d4301               lea eax, [ebx + 1]
// 008da395  50                   push eax
// 008da396  51                   push ecx
// 008da397  ffd6                 call esi
// 008da399  b801000000           mov eax, 1
// 008da39e  01442420             add dword ptr [esp + 0x20], eax
// 008da3a2  29442424             sub dword ptr [esp + 0x24], eax
// 008da3a6  75cc                 jne 0x8da374
// 008da3a8  8d5302               lea edx, [ebx + 2]
// 008da3ab  c744241000000000     mov dword ptr [esp + 0x10], 0
// 008da3b3  89542444             mov dword ptr [esp + 0x44], edx
// 008da3b7  eb07                 jmp 0x8da3c0
// 008da3b9  8da42400000000       lea esp, [esp]
// 008da3c0  8b442410             mov eax, dword ptr [esp + 0x10]
// 008da3c4  8b542444             mov edx, dword ptr [esp + 0x44]
// 008da3c8  68ffffff00           push 0xffffff
// 008da3cd  8d4c2809             lea ecx, [eax + ebp + 9]
// 008da3d1  8b4704               mov eax, dword ptr [edi + 4]
// 008da3d4  51                   push ecx
// 008da3d5  52                   push edx
// 008da3d6  50                   push eax
// 008da3d7  ffd6                 call esi
// 008da3d9  8b442410             mov eax, dword ptr [esp + 0x10]
// 008da3dd  40                   inc eax
// 008da3de  83f803               cmp eax, 3
// 008da3e1  89442410             mov dword ptr [esp + 0x10], eax
// 008da3e5  7cd9                 jl 0x8da3c0
// 008da3e7  68ffffff00           push 0xffffff
// 008da3ec  8d4d0a               lea ecx, [ebp + 0xa]
// 008da3ef  51                   push ecx
// 008da3f0  8b4f04               mov ecx, dword ptr [edi + 4]
// 008da3f3  8d4303               lea eax, [ebx + 3]
// 008da3f6  50                   push eax
// 008da3f7  51                   push ecx
// 008da3f8  89442450             mov dword ptr [esp + 0x50], eax
// 008da3fc  ffd6                 call esi
// 008da3fe  8b542440             mov edx, dword ptr [esp + 0x40]
// 008da402  68ffffff00           push 0xffffff
// 008da407  8d450b               lea eax, [ebp + 0xb]
// 008da40a  50                   push eax
// 008da40b  8b4704               mov eax, dword ptr [edi + 4]
// 008da40e  52                   push edx
// 008da40f  50                   push eax
// 008da410  ffd6                 call esi
// 008da412  8d4b04               lea ecx, [ebx + 4]
// 008da415  c744241000000000     mov dword ptr [esp + 0x10], 0
// 008da41d  894c2420             mov dword ptr [esp + 0x20], ecx
// 008da421  8b542410             mov edx, dword ptr [esp + 0x10]
// 008da425  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 008da429  68ffffff00           push 0xffffff
// 008da42e  8d442a0a             lea eax, [edx + ebp + 0xa]
// 008da432  8b5704               mov edx, dword ptr [edi + 4]
// 008da435  50                   push eax
// 008da436  51                   push ecx
// 008da437  52                   push edx
// 008da438  ffd6                 call esi
// 008da43a  8b442410             mov eax, dword ptr [esp + 0x10]
// 008da43e  40                   inc eax
// 008da43f  83f803               cmp eax, 3
// 008da442  89442410             mov dword ptr [esp + 0x10], eax
// 008da446  7cd9                 jl 0x8da421
// 008da448  68ffffff00           push 0xffffff
// 008da44d  8d4d0b               lea ecx, [ebp + 0xb]
// 008da450  8d4305               lea eax, [ebx + 5]
// 008da453  51                   push ecx
// 008da454  50                   push eax
// 008da455  89442428             mov dword ptr [esp + 0x28], eax
// 008da459  8b4704               mov eax, dword ptr [edi + 4]
// 008da45c  50                   push eax
// 008da45d  ffd6                 call esi
// 008da45f  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 008da463  8b5704               mov edx, dword ptr [edi + 4]
// 008da466  68ffffff00           push 0xffffff
// 008da46b  8d450c               lea eax, [ebp + 0xc]
// 008da46e  50                   push eax
// 008da46f  51                   push ecx
// 008da470  52                   push edx
// 008da471  ffd6                 call esi
// 008da473  8d4306               lea eax, [ebx + 6]
// 008da476  c744241000000000     mov dword ptr [esp + 0x10], 0
// 008da47e  89442418             mov dword ptr [esp + 0x18], eax
// 008da482  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008da486  8b442418             mov eax, dword ptr [esp + 0x18]
// 008da48a  68ffffff00           push 0xffffff
// 008da48f  8d54290b             lea edx, [ecx + ebp + 0xb]
// 008da493  8b4f04               mov ecx, dword ptr [edi + 4]
// 008da496  52                   push edx
// 008da497  50                   push eax
// 008da498  51                   push ecx
// 008da499  ffd6                 call esi
// 008da49b  8b442410             mov eax, dword ptr [esp + 0x10]
// 008da49f  40                   inc eax
// 008da4a0  83f803               cmp eax, 3
// 008da4a3  89442410             mov dword ptr [esp + 0x10], eax
// 008da4a7  7cd9                 jl 0x8da482
// 008da4a9  8b5704               mov edx, dword ptr [edi + 4]
// 008da4ac  68ffffff00           push 0xffffff
// 008da4b1  8d4d0c               lea ecx, [ebp + 0xc]
// 008da4b4  8d4307               lea eax, [ebx + 7]
// 008da4b7  51                   push ecx
// 008da4b8  50                   push eax
// 008da4b9  52                   push edx
// 008da4ba  89442424             mov dword ptr [esp + 0x24], eax
// 008da4be  ffd6                 call esi
// 008da4c0  8b4f04               mov ecx, dword ptr [edi + 4]
// 008da4c3  68ffffff00           push 0xffffff
// 008da4c8  8d450d               lea eax, [ebp + 0xd]
// 008da4cb  50                   push eax
// 008da4cc  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008da4d0  50                   push eax
// 008da4d1  51                   push ecx
// 008da4d2  ffd6                 call esi
// 008da4d4  8b5704               mov edx, dword ptr [edi + 4]
// 008da4d7  68ffffff00           push 0xffffff
// 008da4dc  8d4d0c               lea ecx, [ebp + 0xc]
// 008da4df  8d4308               lea eax, [ebx + 8]
// 008da4e2  51                   push ecx
// 008da4e3  50                   push eax
// 008da4e4  52                   push edx
// 008da4e5  89442434             mov dword ptr [esp + 0x34], eax
// 008da4e9  ffd6                 call esi
// 008da4eb  8b4f04               mov ecx, dword ptr [edi + 4]
// 008da4ee  68ffffff00           push 0xffffff
// 008da4f3  8d450d               lea eax, [ebp + 0xd]
// 008da4f6  50                   push eax
// 008da4f7  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 008da4fb  50                   push eax
// 008da4fc  51                   push ecx
// 008da4fd  ffd6                 call esi
// 008da4ff  8b5704               mov edx, dword ptr [edi + 4]
// 008da502  68ffffff00           push 0xffffff
// 008da507  8d4d0c               lea ecx, [ebp + 0xc]
// 008da50a  8d4309               lea eax, [ebx + 9]
// 008da50d  51                   push ecx
// 008da50e  50                   push eax
// 008da50f  52                   push edx
// 008da510  8944244c             mov dword ptr [esp + 0x4c], eax
// 008da514  ffd6                 call esi
// 008da516  8b4f04               mov ecx, dword ptr [edi + 4]
// 008da519  68ffffff00           push 0xffffff
// 008da51e  8d450d               lea eax, [ebp + 0xd]
// 008da521  50                   push eax
// 008da522  8b442444             mov eax, dword ptr [esp + 0x44]
// 008da526  50                   push eax
// 008da527  51                   push ecx
// 008da528  ffd6                 call esi
// 008da52a  8d530a               lea edx, [ebx + 0xa]
// 008da52d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 008da535  89542438             mov dword ptr [esp + 0x38], edx
// 008da539  8da42400000000       lea esp, [esp]
// 008da540  8b442410             mov eax, dword ptr [esp + 0x10]
// 008da544  8b542438             mov edx, dword ptr [esp + 0x38]
// 008da548  68ffffff00           push 0xffffff
// 008da54d  8d4c280b             lea ecx, [eax + ebp + 0xb]
// 008da551  8b4704               mov eax, dword ptr [edi + 4]
// 008da554  51                   push ecx
// 008da555  52                   push edx
// 008da556  50                   push eax
// 008da557  ffd6                 call esi
// 008da559  8b442410             mov eax, dword ptr [esp + 0x10]
// 008da55d  40                   inc eax
// 008da55e  83f803               cmp eax, 3
// 008da561  89442410             mov dword ptr [esp + 0x10], eax
// 008da565  7cd9                 jl 0x8da540
// 008da567  68ffffff00           push 0xffffff
// 008da56c  8d4d0b               lea ecx, [ebp + 0xb]
// 008da56f  51                   push ecx
// 008da570  8b4f04               mov ecx, dword ptr [edi + 4]
// 008da573  8d430b               lea eax, [ebx + 0xb]
// 008da576  50                   push eax
// 008da577  51                   push ecx
// 008da578  89442444             mov dword ptr [esp + 0x44], eax
// 008da57c  ffd6                 call esi
// 008da57e  8b542434             mov edx, dword ptr [esp + 0x34]
// 008da582  68ffffff00           push 0xffffff
// 008da587  8d450c               lea eax, [ebp + 0xc]
// 008da58a  50                   push eax
// 008da58b  8b4704               mov eax, dword ptr [edi + 4]
// 008da58e  52                   push edx
// 008da58f  50                   push eax
// 008da590  ffd6                 call esi
// 008da592  8d4b0c               lea ecx, [ebx + 0xc]
// 008da595  c744241000000000     mov dword ptr [esp + 0x10], 0
// 008da59d  894c2430             mov dword ptr [esp + 0x30], ecx
// 008da5a1  8b542410             mov edx, dword ptr [esp + 0x10]
// 008da5a5  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 008da5a9  68ffffff00           push 0xffffff
// 008da5ae  8d442a0a             lea eax, [edx + ebp + 0xa]
// 008da5b2  8b5704               mov edx, dword ptr [edi + 4]
// 008da5b5  50                   push eax
// 008da5b6  51                   push ecx
// 008da5b7  52                   push edx
// 008da5b8  ffd6                 call esi
// 008da5ba  8b442410             mov eax, dword ptr [esp + 0x10]
// 008da5be  40                   inc eax
// 008da5bf  83f803               cmp eax, 3
// 008da5c2  89442410             mov dword ptr [esp + 0x10], eax
// 008da5c6  7cd9                 jl 0x8da5a1
// 008da5c8  68ffffff00           push 0xffffff
// 008da5cd  8d4d0a               lea ecx, [ebp + 0xa]
// 008da5d0  8d430d               lea eax, [ebx + 0xd]
// 008da5d3  51                   push ecx
// 008da5d4  50                   push eax
// 008da5d5  89442438             mov dword ptr [esp + 0x38], eax
// 008da5d9  8b4704               mov eax, dword ptr [edi + 4]
// 008da5dc  50                   push eax
// 008da5dd  ffd6                 call esi
// 008da5df  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 008da5e3  8b5704               mov edx, dword ptr [edi + 4]
// 008da5e6  68ffffff00           push 0xffffff
// 008da5eb  8d450b               lea eax, [ebp + 0xb]
// 008da5ee  50                   push eax
// 008da5ef  51                   push ecx
// 008da5f0  52                   push edx
// 008da5f1  ffd6                 call esi
// 008da5f3  8d430e               lea eax, [ebx + 0xe]
// 008da5f6  c744241000000000     mov dword ptr [esp + 0x10], 0
// 008da5fe  89442428             mov dword ptr [esp + 0x28], eax
// 008da602  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008da606  8b442428             mov eax, dword ptr [esp + 0x28]
// 008da60a  68ffffff00           push 0xffffff
// 008da60f  8d542909             lea edx, [ecx + ebp + 9]
// 008da613  8b4f04               mov ecx, dword ptr [edi + 4]
// 008da616  52                   push edx
// 008da617  50                   push eax
// 008da618  51                   push ecx
// 008da619  ffd6                 call esi
// 008da61b  8b442410             mov eax, dword ptr [esp + 0x10]
// 008da61f  40                   inc eax
// 008da620  83f803               cmp eax, 3
// 008da623  89442410             mov dword ptr [esp + 0x10], eax
// 008da627  7cd9                 jl 0x8da602
// 008da629  8d530f               lea edx, [ebx + 0xf]
// 008da62c  83c310               add ebx, 0x10
// 008da62f  895c244c             mov dword ptr [esp + 0x4c], ebx
// 008da633  89542448             mov dword ptr [esp + 0x48], edx
// 008da637  8bdd                 mov ebx, ebp
// 008da639  c74424100b000000     mov dword ptr [esp + 0x10], 0xb
// 008da641  8b442448             mov eax, dword ptr [esp + 0x48]
// 008da645  8b4f04               mov ecx, dword ptr [edi + 4]
// 008da648  68ffffff00           push 0xffffff
// 008da64d  53                   push ebx
// 008da64e  50                   push eax
// 008da64f  51                   push ecx
// 008da650  ffd6                 call esi
// 008da652  8b54244c             mov edx, dword ptr [esp + 0x4c]
// 008da656  8b4704               mov eax, dword ptr [edi + 4]
// 008da659  68ffffff00           push 0xffffff
// 008da65e  53                   push ebx
// 008da65f  52                   push edx
// 008da660  50                   push eax
// 008da661  ffd6                 call esi
// 008da663  43                   inc ebx
// 008da664  836c241001           sub dword ptr [esp + 0x10], 1
// 008da669  75d6                 jne 0x8da641
// 008da66b  33db                 xor ebx, ebx
// 008da66d  8d4900               lea ecx, [ecx]
// 008da670  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 008da674  8b542428             mov edx, dword ptr [esp + 0x28]
// 008da678  8b4704               mov eax, dword ptr [edi + 4]
// 008da67b  68ffffff00           push 0xffffff
// 008da680  03cb                 add ecx, ebx
// 008da682  51                   push ecx
// 008da683  52                   push edx
// 008da684  50                   push eax
// 008da685  ffd6                 call esi
// 008da687  43                   inc ebx
// 008da688  83fb03               cmp ebx, 3
// 008da68b  7ce3                 jl 0x8da670
// 008da68d  8b5c242c             mov ebx, dword ptr [esp + 0x2c]
// 008da691  8b4f04               mov ecx, dword ptr [edi + 4]
// 008da694  68ffffff00           push 0xffffff
// 008da699  55                   push ebp
// 008da69a  53                   push ebx
// 008da69b  51                   push ecx
// 008da69c  ffd6                 call esi
// 008da69e  8b542454             mov edx, dword ptr [esp + 0x54]
// 008da6a2  8b4704               mov eax, dword ptr [edi + 4]
// 008da6a5  68ffffff00           push 0xffffff
// 008da6aa  52                   push edx
// 008da6ab  53                   push ebx
// 008da6ac  50                   push eax
// 008da6ad  ffd6                 call esi
// 008da6af  33db                 xor ebx, ebx
// 008da6b1  8b542430             mov edx, dword ptr [esp + 0x30]
// 008da6b5  8b4704               mov eax, dword ptr [edi + 4]
// 008da6b8  68ffffff00           push 0xffffff
// 008da6bd  8d4c2bfe             lea ecx, [ebx + ebp - 2]
// 008da6c1  51                   push ecx
// 008da6c2  52                   push edx
// 008da6c3  50                   push eax
// 008da6c4  ffd6                 call esi
// 008da6c6  43                   inc ebx
// 008da6c7  83fb03               cmp ebx, 3
// 008da6ca  7ce5                 jl 0x8da6b1
// 008da6cc  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 008da6d0  8b5c2434             mov ebx, dword ptr [esp + 0x34]
// 008da6d4  8b5704               mov edx, dword ptr [edi + 4]
// 008da6d7  68ffffff00           push 0xffffff
// 008da6dc  51                   push ecx
// 008da6dd  53                   push ebx
// 008da6de  52                   push edx
// 008da6df  ffd6                 call esi
// 008da6e1  68ffffff00           push 0xffffff
// 008da6e6  8d45fe               lea eax, [ebp - 2]
// 008da6e9  50                   push eax
// 008da6ea  8b4704               mov eax, dword ptr [edi + 4]
// 008da6ed  53                   push ebx
// 008da6ee  50                   push eax
// 008da6ef  ffd6                 call esi
// 008da6f1  33db                 xor ebx, ebx
// 008da6f3  8b542438             mov edx, dword ptr [esp + 0x38]
// 008da6f7  8b4704               mov eax, dword ptr [edi + 4]
// 008da6fa  68ffffff00           push 0xffffff
// 008da6ff  8d4c2bfd             lea ecx, [ebx + ebp - 3]
// 008da703  51                   push ecx
// 008da704  52                   push edx
// 008da705  50                   push eax
// 008da706  ffd6                 call esi
// 008da708  43                   inc ebx
// 008da709  83fb03               cmp ebx, 3
// 008da70c  7ce5                 jl 0x8da6f3
// 008da70e  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008da712  8b5704               mov edx, dword ptr [edi + 4]
// 008da715  68ffffff00           push 0xffffff
// 008da71a  8d5dfe               lea ebx, [ebp - 2]
// 008da71d  53                   push ebx
// 008da71e  51                   push ecx
// 008da71f  52                   push edx
// 008da720  ffd6                 call esi
// 008da722  8b4f04               mov ecx, dword ptr [edi + 4]
// 008da725  68ffffff00           push 0xffffff
// 008da72a  8d45fd               lea eax, [ebp - 3]
// 008da72d  50                   push eax
// 008da72e  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008da732  50                   push eax
// 008da733  51                   push ecx
// 008da734  ffd6                 call esi
// 008da736  8b542424             mov edx, dword ptr [esp + 0x24]
// 008da73a  8b4704               mov eax, dword ptr [edi + 4]
// 008da73d  68ffffff00           push 0xffffff
// 008da742  53                   push ebx
// 008da743  52                   push edx
// 008da744  50                   push eax
// 008da745  ffd6                 call esi
// 008da747  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 008da74b  8b5704               mov edx, dword ptr [edi + 4]
// 008da74e  68ffffff00           push 0xffffff
// 008da753  8d45fd               lea eax, [ebp - 3]
// 008da756  50                   push eax
// 008da757  51                   push ecx
// 008da758  52                   push edx
// 008da759  ffd6                 call esi
// 008da75b  8b4704               mov eax, dword ptr [edi + 4]
// 008da75e  68ffffff00           push 0xffffff
// 008da763  53                   push ebx
// 008da764  8b5c2444             mov ebx, dword ptr [esp + 0x44]
// 008da768  53                   push ebx
// 008da769  50                   push eax
// 008da76a  ffd6                 call esi
// 008da76c  8b4f04               mov ecx, dword ptr [edi + 4]
// 008da76f  68ffffff00           push 0xffffff
// 008da774  8d45fd               lea eax, [ebp - 3]
// 008da777  50                   push eax
// 008da778  53                   push ebx
// 008da779  51                   push ecx
// 008da77a  ffd6                 call esi
// 008da77c  33db                 xor ebx, ebx
// 008da77e  8bff                 mov edi, edi
// 008da780  8b442418             mov eax, dword ptr [esp + 0x18]
// 008da784  8b4f04               mov ecx, dword ptr [edi + 4]
// 008da787  68ffffff00           push 0xffffff
// 008da78c  8d542bfd             lea edx, [ebx + ebp - 3]
// 008da790  52                   push edx
// 008da791  50                   push eax
// 008da792  51                   push ecx
// 008da793  ffd6                 call esi
// 008da795  43                   inc ebx
// 008da796  83fb03               cmp ebx, 3
// 008da799  7ce5                 jl 0x8da780
// 008da79b  8b542454             mov edx, dword ptr [esp + 0x54]
// 008da79f  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 008da7a3  8b4704               mov eax, dword ptr [edi + 4]
// 008da7a6  68ffffff00           push 0xffffff
// 008da7ab  52                   push edx
// 008da7ac  53                   push ebx
// 008da7ad  50                   push eax
// 008da7ae  ffd6                 call esi
// 008da7b0  8b4f04               mov ecx, dword ptr [edi + 4]
// 008da7b3  68ffffff00           push 0xffffff
// 008da7b8  8d45fe               lea eax, [ebp - 2]
// 008da7bb  50                   push eax
// 008da7bc  53                   push ebx
// 008da7bd  51                   push ecx
// 008da7be  ffd6                 call esi
// 008da7c0  33db                 xor ebx, ebx
// 008da7c2  8b442420             mov eax, dword ptr [esp + 0x20]
// 008da7c6  8b4f04               mov ecx, dword ptr [edi + 4]
// 008da7c9  68ffffff00           push 0xffffff
// 008da7ce  8d542bfe             lea edx, [ebx + ebp - 2]
// 008da7d2  52                   push edx
// 008da7d3  50                   push eax
// 008da7d4  51                   push ecx
// 008da7d5  ffd6                 call esi
// 008da7d7  43                   inc ebx
// 008da7d8  83fb03               cmp ebx, 3
// 008da7db  7ce5                 jl 0x8da7c2
// 008da7dd  8b5704               mov edx, dword ptr [edi + 4]
// 008da7e0  68ffffff00           push 0xffffff
// 008da7e5  55                   push ebp
// 008da7e6  8b6c2448             mov ebp, dword ptr [esp + 0x48]
// 008da7ea  55                   push ebp
// 008da7eb  52                   push edx
// 008da7ec  ffd6                 call esi
// 008da7ee  8b5c2454             mov ebx, dword ptr [esp + 0x54]
// 008da7f2  8b4704               mov eax, dword ptr [edi + 4]
// 008da7f5  68ffffff00           push 0xffffff
// 008da7fa  53                   push ebx
// 008da7fb  55                   push ebp
// 008da7fc  50                   push eax
// 008da7fd  ffd6                 call esi
// 008da7ff  33ed                 xor ebp, ebp
// 008da801  8b542444             mov edx, dword ptr [esp + 0x44]
// 008da805  8b4704               mov eax, dword ptr [edi + 4]
// 008da808  68ffffff00           push 0xffffff
// 008da80d  8d0c2b               lea ecx, [ebx + ebp]
// 008da810  51                   push ecx
// 008da811  52                   push edx
// 008da812  50                   push eax
// 008da813  ffd6                 call esi
// 008da815  45                   inc ebp
// 008da816  83fd03               cmp ebp, 3
// 008da819  7ce6                 jl 0x8da801
// 008da81b  5f                   pop edi
// 008da81c  5e                   pop esi
// 008da81d  5d                   pop ebp
// 008da81e  5b                   pop ebx
// 008da81f  83c440               add esp, 0x40
// 008da822  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTColorPageStandard.cpp (function ?DrawSelectCell@CXTColorHex@@IAEXPAVCDC@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTColorPageStandard.cpp
