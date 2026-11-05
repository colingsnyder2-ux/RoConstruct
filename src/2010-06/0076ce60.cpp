// from server: 100% by auto
// roc 2010-06 0076ce60  unit: RBX::ChatOutput  size: 562 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0076ce60
//
// 0076ce60  83ec14               sub esp, 0x14
// 0076ce63  56                   push esi
// 0076ce64  8bf1                 mov esi, ecx
// 0076ce66  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 0076ce6a  57                   push edi
// 0076ce6b  7521                 jne 0x76ce8e
// 0076ce6d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0076ce71  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0076ce74  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0076ce78  50                   push eax
// 0076ce79  51                   push ecx
// 0076ce7a  6a01                 push 1
// 0076ce7c  57                   push edi
// 0076ce7d  8bce                 mov ecx, esi
// 0076ce7f  e84cf8ffff           call 0x76c6d0
// 0076ce84  8bc7                 mov eax, edi
// 0076ce86  5f                   pop edi
// 0076ce87  5e                   pop esi
// 0076ce88  83c414               add esp, 0x14
// 0076ce8b  c21000               ret 0x10
// 0076ce8e  8b442424             mov eax, dword ptr [esp + 0x24]
// 0076ce92  8b5618               mov edx, dword ptr [esi + 0x18]
// 0076ce95  8b3a                 mov edi, dword ptr [edx]
// 0076ce97  8b0e                 mov ecx, dword ptr [esi]
// 0076ce99  53                   push ebx
// 0076ce9a  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 0076cea0  85c0                 test eax, eax
// 0076cea2  7404                 je 0x76cea8
// 0076cea4  3bc1                 cmp eax, ecx
// 0076cea6  7406                 je 0x76ceae
// 0076cea8  ffd3                 call ebx
// 0076ceaa  8b442428             mov eax, dword ptr [esp + 0x28]
// 0076ceae  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 0076ceb2  55                   push ebp
// 0076ceb3  3bd7                 cmp edx, edi
// 0076ceb5  753a                 jne 0x76cef1
// 0076ceb7  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 0076cebb  83c20c               add edx, 0xc
// 0076cebe  52                   push edx
// 0076cebf  57                   push edi
// 0076cec0  ff151ca59e00         call dword ptr [0x9ea51c]
// 0076cec6  83c408               add esp, 8
// 0076cec9  84c0                 test al, al
// 0076cecb  0f849a010000         je 0x76d06b
// 0076ced1  8b442430             mov eax, dword ptr [esp + 0x30]
// 0076ced5  57                   push edi
// 0076ced6  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0076ceda  50                   push eax
// 0076cedb  6a01                 push 1
// 0076cedd  57                   push edi
// 0076cede  8bce                 mov ecx, esi
// 0076cee0  e8ebf7ffff           call 0x76c6d0
// 0076cee5  5d                   pop ebp
// 0076cee6  5b                   pop ebx
// 0076cee7  8bc7                 mov eax, edi
// 0076cee9  5f                   pop edi
// 0076ceea  5e                   pop esi
// 0076ceeb  83c414               add esp, 0x14
// 0076ceee  c21000               ret 0x10
// 0076cef1  8b7e18               mov edi, dword ptr [esi + 0x18]
// 0076cef4  8b0e                 mov ecx, dword ptr [esi]
// 0076cef6  85c0                 test eax, eax
// 0076cef8  7404                 je 0x76cefe
// 0076cefa  3bc1                 cmp eax, ecx
// 0076cefc  7406                 je 0x76cf04
// 0076cefe  ffd3                 call ebx
// 0076cf00  8b542430             mov edx, dword ptr [esp + 0x30]
// 0076cf04  3bd7                 cmp edx, edi
// 0076cf06  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 0076cf0a  753e                 jne 0x76cf4a
// 0076cf0c  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0076cf0f  8b4108               mov eax, dword ptr [ecx + 8]
// 0076cf12  83c00c               add eax, 0xc
// 0076cf15  57                   push edi
// 0076cf16  50                   push eax
// 0076cf17  ff151ca59e00         call dword ptr [0x9ea51c]
// 0076cf1d  83c408               add esp, 8
// 0076cf20  84c0                 test al, al
// 0076cf22  0f8443010000         je 0x76d06b
// 0076cf28  8b5618               mov edx, dword ptr [esi + 0x18]
// 0076cf2b  8b4208               mov eax, dword ptr [edx + 8]
// 0076cf2e  57                   push edi
// 0076cf2f  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0076cf33  50                   push eax
// 0076cf34  6a00                 push 0
// 0076cf36  57                   push edi
// 0076cf37  8bce                 mov ecx, esi
// 0076cf39  e892f7ffff           call 0x76c6d0
// 0076cf3e  5d                   pop ebp
// 0076cf3f  5b                   pop ebx
// 0076cf40  8bc7                 mov eax, edi
// 0076cf42  5f                   pop edi
// 0076cf43  5e                   pop esi
// 0076cf44  83c414               add esp, 0x14
// 0076cf47  c21000               ret 0x10
// 0076cf4a  8b2d1ca59e00         mov ebp, dword ptr [0x9ea51c]
// 0076cf50  83c20c               add edx, 0xc
// 0076cf53  52                   push edx
// 0076cf54  57                   push edi
// 0076cf55  ffd5                 call ebp
// 0076cf57  83c408               add esp, 8
// 0076cf5a  84c0                 test al, al
// 0076cf5c  746c                 je 0x76cfca
// 0076cf5e  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0076cf62  8b542430             mov edx, dword ptr [esp + 0x30]
// 0076cf66  894c2410             mov dword ptr [esp + 0x10], ecx
// 0076cf6a  8d4c2410             lea ecx, [esp + 0x10]
// 0076cf6e  89542414             mov dword ptr [esp + 0x14], edx
// 0076cf72  e8d9e0ffff           call 0x76b050
// 0076cf77  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 0076cf7b  57                   push edi
// 0076cf7c  8d430c               lea eax, [ebx + 0xc]
// 0076cf7f  50                   push eax
// 0076cf80  8d4e08               lea ecx, [esi + 8]
// 0076cf83  e8c862d0ff           call 0x473250
// 0076cf88  84c0                 test al, al
// 0076cf8a  743e                 je 0x76cfca
// 0076cf8c  8b4b08               mov ecx, dword ptr [ebx + 8]
// 0076cf8f  80794d00             cmp byte ptr [ecx + 0x4d], 0
// 0076cf93  57                   push edi
// 0076cf94  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0076cf98  8bce                 mov ecx, esi
// 0076cf9a  7415                 je 0x76cfb1
// 0076cf9c  53                   push ebx
// 0076cf9d  6a00                 push 0
// 0076cf9f  57                   push edi
// 0076cfa0  e82bf7ffff           call 0x76c6d0
// 0076cfa5  5d                   pop ebp
// 0076cfa6  5b                   pop ebx
// 0076cfa7  8bc7                 mov eax, edi
// 0076cfa9  5f                   pop edi
// 0076cfaa  5e                   pop esi
// 0076cfab  83c414               add esp, 0x14
// 0076cfae  c21000               ret 0x10
// 0076cfb1  8b542434             mov edx, dword ptr [esp + 0x34]
// 0076cfb5  52                   push edx
// 0076cfb6  6a01                 push 1
// 0076cfb8  57                   push edi
// 0076cfb9  e812f7ffff           call 0x76c6d0
// 0076cfbe  5d                   pop ebp
// 0076cfbf  5b                   pop ebx
// 0076cfc0  8bc7                 mov eax, edi
// 0076cfc2  5f                   pop edi
// 0076cfc3  5e                   pop esi
// 0076cfc4  83c414               add esp, 0x14
// 0076cfc7  c21000               ret 0x10
// 0076cfca  8b442430             mov eax, dword ptr [esp + 0x30]
// 0076cfce  83c00c               add eax, 0xc
// 0076cfd1  57                   push edi
// 0076cfd2  50                   push eax
// 0076cfd3  ffd5                 call ebp
// 0076cfd5  83c408               add esp, 8
// 0076cfd8  84c0                 test al, al
// 0076cfda  0f848b000000         je 0x76d06b
// 0076cfe0  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0076cfe4  8b542430             mov edx, dword ptr [esp + 0x30]
// 0076cfe8  8b4618               mov eax, dword ptr [esi + 0x18]
// 0076cfeb  894c2410             mov dword ptr [esp + 0x10], ecx
// 0076cfef  8b0e                 mov ecx, dword ptr [esi]
// 0076cff1  894c2418             mov dword ptr [esp + 0x18], ecx
// 0076cff5  8d4c2410             lea ecx, [esp + 0x10]
// 0076cff9  89542414             mov dword ptr [esp + 0x14], edx
// 0076cffd  8944241c             mov dword ptr [esp + 0x1c], eax
// 0076d001  e8dadfffff           call 0x76afe0
// 0076d006  8d542418             lea edx, [esp + 0x18]
// 0076d00a  52                   push edx
// 0076d00b  8d4c2414             lea ecx, [esp + 0x14]
// 0076d00f  e86c9fcfff           call 0x466f80
// 0076d014  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 0076d018  84c0                 test al, al
// 0076d01a  7511                 jne 0x76d02d
// 0076d01c  8d430c               lea eax, [ebx + 0xc]
// 0076d01f  50                   push eax
// 0076d020  57                   push edi
// 0076d021  8d4e08               lea ecx, [esi + 8]
// 0076d024  e82762d0ff           call 0x473250
// 0076d029  84c0                 test al, al
// 0076d02b  743e                 je 0x76d06b
// 0076d02d  8b442430             mov eax, dword ptr [esp + 0x30]
// 0076d031  8b4808               mov ecx, dword ptr [eax + 8]
// 0076d034  80794d00             cmp byte ptr [ecx + 0x4d], 0
// 0076d038  57                   push edi
// 0076d039  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0076d03d  8bce                 mov ecx, esi
// 0076d03f  7415                 je 0x76d056
// 0076d041  50                   push eax
// 0076d042  6a00                 push 0
// 0076d044  57                   push edi
// 0076d045  e886f6ffff           call 0x76c6d0
// 0076d04a  5d                   pop ebp
// 0076d04b  5b                   pop ebx
// 0076d04c  8bc7                 mov eax, edi
// 0076d04e  5f                   pop edi
// 0076d04f  5e                   pop esi
// 0076d050  83c414               add esp, 0x14
// 0076d053  c21000               ret 0x10
// 0076d056  53                   push ebx
// 0076d057  6a01                 push 1
// 0076d059  57                   push edi
// 0076d05a  e871f6ffff           call 0x76c6d0
// 0076d05f  5d                   pop ebp
// 0076d060  5b                   pop ebx
// 0076d061  8bc7                 mov eax, edi
// 0076d063  5f                   pop edi
// 0076d064  5e                   pop esi
// 0076d065  83c414               add esp, 0x14
// 0076d068  c21000               ret 0x10
// 0076d06b  57                   push edi
// 0076d06c  8d54241c             lea edx, [esp + 0x1c]
// 0076d070  52                   push edx
// 0076d071  8bce                 mov ecx, esi
// 0076d073  e848fbffff           call 0x76cbc0
// 0076d078  8b10                 mov edx, dword ptr [eax]
// 0076d07a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0076d07e  5d                   pop ebp
// 0076d07f  5b                   pop ebx
// 0076d080  8911                 mov dword ptr [ecx], edx
// 0076d082  8b4004               mov eax, dword ptr [eax + 4]
// 0076d085  5f                   pop edi
// 0076d086  894104               mov dword ptr [ecx + 4], eax
// 0076d089  8bc1                 mov eax, ecx
// 0076d08b  5e                   pop esi
// 0076d08c  83c414               add esp, 0x14
// 0076d08f  c21000               ret 0x10
// standard library map_str<pod36> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod36>
struct E { int v[9]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
