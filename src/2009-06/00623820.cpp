// from server: 100% by auto
// roc 2009-06 00623820  unit: ArchiveBinder  size: 562 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00623820
//
// 00623820  83ec14               sub esp, 0x14
// 00623823  56                   push esi
// 00623824  8bf1                 mov esi, ecx
// 00623826  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 0062382a  57                   push edi
// 0062382b  7521                 jne 0x62384e
// 0062382d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00623831  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00623834  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00623838  50                   push eax
// 00623839  51                   push ecx
// 0062383a  6a01                 push 1
// 0062383c  57                   push edi
// 0062383d  8bce                 mov ecx, esi
// 0062383f  e8ecfcffff           call 0x623530
// 00623844  8bc7                 mov eax, edi
// 00623846  5f                   pop edi
// 00623847  5e                   pop esi
// 00623848  83c414               add esp, 0x14
// 0062384b  c21000               ret 0x10
// 0062384e  8b442424             mov eax, dword ptr [esp + 0x24]
// 00623852  8b5618               mov edx, dword ptr [esi + 0x18]
// 00623855  8b3a                 mov edi, dword ptr [edx]
// 00623857  8b0e                 mov ecx, dword ptr [esi]
// 00623859  53                   push ebx
// 0062385a  8b1dace98900         mov ebx, dword ptr [0x89e9ac]
// 00623860  85c0                 test eax, eax
// 00623862  7404                 je 0x623868
// 00623864  3bc1                 cmp eax, ecx
// 00623866  7406                 je 0x62386e
// 00623868  ffd3                 call ebx
// 0062386a  8b442428             mov eax, dword ptr [esp + 0x28]
// 0062386e  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 00623872  55                   push ebp
// 00623873  3bd7                 cmp edx, edi
// 00623875  753a                 jne 0x6238b1
// 00623877  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 0062387b  83c20c               add edx, 0xc
// 0062387e  52                   push edx
// 0062387f  57                   push edi
// 00623880  ff15e0e48900         call dword ptr [0x89e4e0]
// 00623886  83c408               add esp, 8
// 00623889  84c0                 test al, al
// 0062388b  0f849a010000         je 0x623a2b
// 00623891  8b442430             mov eax, dword ptr [esp + 0x30]
// 00623895  57                   push edi
// 00623896  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0062389a  50                   push eax
// 0062389b  6a01                 push 1
// 0062389d  57                   push edi
// 0062389e  8bce                 mov ecx, esi
// 006238a0  e88bfcffff           call 0x623530
// 006238a5  5d                   pop ebp
// 006238a6  5b                   pop ebx
// 006238a7  8bc7                 mov eax, edi
// 006238a9  5f                   pop edi
// 006238aa  5e                   pop esi
// 006238ab  83c414               add esp, 0x14
// 006238ae  c21000               ret 0x10
// 006238b1  8b7e18               mov edi, dword ptr [esi + 0x18]
// 006238b4  8b0e                 mov ecx, dword ptr [esi]
// 006238b6  85c0                 test eax, eax
// 006238b8  7404                 je 0x6238be
// 006238ba  3bc1                 cmp eax, ecx
// 006238bc  7406                 je 0x6238c4
// 006238be  ffd3                 call ebx
// 006238c0  8b542430             mov edx, dword ptr [esp + 0x30]
// 006238c4  3bd7                 cmp edx, edi
// 006238c6  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 006238ca  753e                 jne 0x62390a
// 006238cc  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006238cf  8b4108               mov eax, dword ptr [ecx + 8]
// 006238d2  83c00c               add eax, 0xc
// 006238d5  57                   push edi
// 006238d6  50                   push eax
// 006238d7  ff15e0e48900         call dword ptr [0x89e4e0]
// 006238dd  83c408               add esp, 8
// 006238e0  84c0                 test al, al
// 006238e2  0f8443010000         je 0x623a2b
// 006238e8  8b5618               mov edx, dword ptr [esi + 0x18]
// 006238eb  8b4208               mov eax, dword ptr [edx + 8]
// 006238ee  57                   push edi
// 006238ef  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 006238f3  50                   push eax
// 006238f4  6a00                 push 0
// 006238f6  57                   push edi
// 006238f7  8bce                 mov ecx, esi
// 006238f9  e832fcffff           call 0x623530
// 006238fe  5d                   pop ebp
// 006238ff  5b                   pop ebx
// 00623900  8bc7                 mov eax, edi
// 00623902  5f                   pop edi
// 00623903  5e                   pop esi
// 00623904  83c414               add esp, 0x14
// 00623907  c21000               ret 0x10
// 0062390a  8b2de0e48900         mov ebp, dword ptr [0x89e4e0]
// 00623910  83c20c               add edx, 0xc
// 00623913  52                   push edx
// 00623914  57                   push edi
// 00623915  ffd5                 call ebp
// 00623917  83c408               add esp, 8
// 0062391a  84c0                 test al, al
// 0062391c  746c                 je 0x62398a
// 0062391e  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00623922  8b542430             mov edx, dword ptr [esp + 0x30]
// 00623926  894c2410             mov dword ptr [esp + 0x10], ecx
// 0062392a  8d4c2410             lea ecx, [esp + 0x10]
// 0062392e  89542414             mov dword ptr [esp + 0x14], edx
// 00623932  e879faffff           call 0x6233b0
// 00623937  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 0062393b  57                   push edi
// 0062393c  8d430c               lea eax, [ebx + 0xc]
// 0062393f  50                   push eax
// 00623940  8d4e08               lea ecx, [esi + 8]
// 00623943  e8c856fbff           call 0x5d9010
// 00623948  84c0                 test al, al
// 0062394a  743e                 je 0x62398a
// 0062394c  8b4b08               mov ecx, dword ptr [ebx + 8]
// 0062394f  80793100             cmp byte ptr [ecx + 0x31], 0
// 00623953  57                   push edi
// 00623954  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00623958  8bce                 mov ecx, esi
// 0062395a  7415                 je 0x623971
// 0062395c  53                   push ebx
// 0062395d  6a00                 push 0
// 0062395f  57                   push edi
// 00623960  e8cbfbffff           call 0x623530
// 00623965  5d                   pop ebp
// 00623966  5b                   pop ebx
// 00623967  8bc7                 mov eax, edi
// 00623969  5f                   pop edi
// 0062396a  5e                   pop esi
// 0062396b  83c414               add esp, 0x14
// 0062396e  c21000               ret 0x10
// 00623971  8b542434             mov edx, dword ptr [esp + 0x34]
// 00623975  52                   push edx
// 00623976  6a01                 push 1
// 00623978  57                   push edi
// 00623979  e8b2fbffff           call 0x623530
// 0062397e  5d                   pop ebp
// 0062397f  5b                   pop ebx
// 00623980  8bc7                 mov eax, edi
// 00623982  5f                   pop edi
// 00623983  5e                   pop esi
// 00623984  83c414               add esp, 0x14
// 00623987  c21000               ret 0x10
// 0062398a  8b442430             mov eax, dword ptr [esp + 0x30]
// 0062398e  83c00c               add eax, 0xc
// 00623991  57                   push edi
// 00623992  50                   push eax
// 00623993  ffd5                 call ebp
// 00623995  83c408               add esp, 8
// 00623998  84c0                 test al, al
// 0062399a  0f848b000000         je 0x623a2b
// 006239a0  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 006239a4  8b542430             mov edx, dword ptr [esp + 0x30]
// 006239a8  8b4618               mov eax, dword ptr [esi + 0x18]
// 006239ab  894c2410             mov dword ptr [esp + 0x10], ecx
// 006239af  8b0e                 mov ecx, dword ptr [esi]
// 006239b1  894c2418             mov dword ptr [esp + 0x18], ecx
// 006239b5  8d4c2410             lea ecx, [esp + 0x10]
// 006239b9  89542414             mov dword ptr [esp + 0x14], edx
// 006239bd  8944241c             mov dword ptr [esp + 0x1c], eax
// 006239c1  e8eae80b00           call 0x6e22b0
// 006239c6  8d542418             lea edx, [esp + 0x18]
// 006239ca  52                   push edx
// 006239cb  8d4c2414             lea ecx, [esp + 0x14]
// 006239cf  e8ccfa0100           call 0x6434a0
// 006239d4  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 006239d8  84c0                 test al, al
// 006239da  7511                 jne 0x6239ed
// 006239dc  8d430c               lea eax, [ebx + 0xc]
// 006239df  50                   push eax
// 006239e0  57                   push edi
// 006239e1  8d4e08               lea ecx, [esi + 8]
// 006239e4  e82756fbff           call 0x5d9010
// 006239e9  84c0                 test al, al
// 006239eb  743e                 je 0x623a2b
// 006239ed  8b442430             mov eax, dword ptr [esp + 0x30]
// 006239f1  8b4808               mov ecx, dword ptr [eax + 8]
// 006239f4  80793100             cmp byte ptr [ecx + 0x31], 0
// 006239f8  57                   push edi
// 006239f9  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 006239fd  8bce                 mov ecx, esi
// 006239ff  7415                 je 0x623a16
// 00623a01  50                   push eax
// 00623a02  6a00                 push 0
// 00623a04  57                   push edi
// 00623a05  e826fbffff           call 0x623530
// 00623a0a  5d                   pop ebp
// 00623a0b  5b                   pop ebx
// 00623a0c  8bc7                 mov eax, edi
// 00623a0e  5f                   pop edi
// 00623a0f  5e                   pop esi
// 00623a10  83c414               add esp, 0x14
// 00623a13  c21000               ret 0x10
// 00623a16  53                   push ebx
// 00623a17  6a01                 push 1
// 00623a19  57                   push edi
// 00623a1a  e811fbffff           call 0x623530
// 00623a1f  5d                   pop ebp
// 00623a20  5b                   pop ebx
// 00623a21  8bc7                 mov eax, edi
// 00623a23  5f                   pop edi
// 00623a24  5e                   pop esi
// 00623a25  83c414               add esp, 0x14
// 00623a28  c21000               ret 0x10
// 00623a2b  57                   push edi
// 00623a2c  8d54241c             lea edx, [esp + 0x1c]
// 00623a30  52                   push edx
// 00623a31  8bce                 mov ecx, esi
// 00623a33  e8f8fcffff           call 0x623730
// 00623a38  8b10                 mov edx, dword ptr [eax]
// 00623a3a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00623a3e  5d                   pop ebp
// 00623a3f  5b                   pop ebx
// 00623a40  8911                 mov dword ptr [ecx], edx
// 00623a42  8b4004               mov eax, dword ptr [eax + 4]
// 00623a45  5f                   pop edi
// 00623a46  894104               mov dword ptr [ecx + 4], eax
// 00623a49  8bc1                 mov eax, ecx
// 00623a4b  5e                   pop esi
// 00623a4c  83c414               add esp, 0x14
// 00623a4f  c21000               ret 0x10
// standard library map_str<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod8>
struct E { int v[2]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
