// from server: 100% by auto
// roc 2009-12 00705b50  unit: RBX::VInstance::?$NonFactoryProduct  size: 562 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00705b50
//
// 00705b50  83ec14               sub esp, 0x14
// 00705b53  56                   push esi
// 00705b54  8bf1                 mov esi, ecx
// 00705b56  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 00705b5a  57                   push edi
// 00705b5b  7521                 jne 0x705b7e
// 00705b5d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00705b61  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00705b64  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00705b68  50                   push eax
// 00705b69  51                   push ecx
// 00705b6a  6a01                 push 1
// 00705b6c  57                   push edi
// 00705b6d  8bce                 mov ecx, esi
// 00705b6f  e80ce1ffff           call 0x703c80
// 00705b74  8bc7                 mov eax, edi
// 00705b76  5f                   pop edi
// 00705b77  5e                   pop esi
// 00705b78  83c414               add esp, 0x14
// 00705b7b  c21000               ret 0x10
// 00705b7e  8b442424             mov eax, dword ptr [esp + 0x24]
// 00705b82  8b5618               mov edx, dword ptr [esi + 0x18]
// 00705b85  8b3a                 mov edi, dword ptr [edx]
// 00705b87  8b0e                 mov ecx, dword ptr [esi]
// 00705b89  53                   push ebx
// 00705b8a  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 00705b90  85c0                 test eax, eax
// 00705b92  7404                 je 0x705b98
// 00705b94  3bc1                 cmp eax, ecx
// 00705b96  7406                 je 0x705b9e
// 00705b98  ffd3                 call ebx
// 00705b9a  8b442428             mov eax, dword ptr [esp + 0x28]
// 00705b9e  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 00705ba2  55                   push ebp
// 00705ba3  3bd7                 cmp edx, edi
// 00705ba5  753a                 jne 0x705be1
// 00705ba7  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 00705bab  83c20c               add edx, 0xc
// 00705bae  52                   push edx
// 00705baf  57                   push edi
// 00705bb0  ff15d8b59800         call dword ptr [0x98b5d8]
// 00705bb6  83c408               add esp, 8
// 00705bb9  84c0                 test al, al
// 00705bbb  0f849a010000         je 0x705d5b
// 00705bc1  8b442430             mov eax, dword ptr [esp + 0x30]
// 00705bc5  57                   push edi
// 00705bc6  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00705bca  50                   push eax
// 00705bcb  6a01                 push 1
// 00705bcd  57                   push edi
// 00705bce  8bce                 mov ecx, esi
// 00705bd0  e8abe0ffff           call 0x703c80
// 00705bd5  5d                   pop ebp
// 00705bd6  5b                   pop ebx
// 00705bd7  8bc7                 mov eax, edi
// 00705bd9  5f                   pop edi
// 00705bda  5e                   pop esi
// 00705bdb  83c414               add esp, 0x14
// 00705bde  c21000               ret 0x10
// 00705be1  8b7e18               mov edi, dword ptr [esi + 0x18]
// 00705be4  8b0e                 mov ecx, dword ptr [esi]
// 00705be6  85c0                 test eax, eax
// 00705be8  7404                 je 0x705bee
// 00705bea  3bc1                 cmp eax, ecx
// 00705bec  7406                 je 0x705bf4
// 00705bee  ffd3                 call ebx
// 00705bf0  8b542430             mov edx, dword ptr [esp + 0x30]
// 00705bf4  3bd7                 cmp edx, edi
// 00705bf6  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 00705bfa  753e                 jne 0x705c3a
// 00705bfc  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00705bff  8b4108               mov eax, dword ptr [ecx + 8]
// 00705c02  83c00c               add eax, 0xc
// 00705c05  57                   push edi
// 00705c06  50                   push eax
// 00705c07  ff15d8b59800         call dword ptr [0x98b5d8]
// 00705c0d  83c408               add esp, 8
// 00705c10  84c0                 test al, al
// 00705c12  0f8443010000         je 0x705d5b
// 00705c18  8b5618               mov edx, dword ptr [esi + 0x18]
// 00705c1b  8b4208               mov eax, dword ptr [edx + 8]
// 00705c1e  57                   push edi
// 00705c1f  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00705c23  50                   push eax
// 00705c24  6a00                 push 0
// 00705c26  57                   push edi
// 00705c27  8bce                 mov ecx, esi
// 00705c29  e852e0ffff           call 0x703c80
// 00705c2e  5d                   pop ebp
// 00705c2f  5b                   pop ebx
// 00705c30  8bc7                 mov eax, edi
// 00705c32  5f                   pop edi
// 00705c33  5e                   pop esi
// 00705c34  83c414               add esp, 0x14
// 00705c37  c21000               ret 0x10
// 00705c3a  8b2dd8b59800         mov ebp, dword ptr [0x98b5d8]
// 00705c40  83c20c               add edx, 0xc
// 00705c43  52                   push edx
// 00705c44  57                   push edi
// 00705c45  ffd5                 call ebp
// 00705c47  83c408               add esp, 8
// 00705c4a  84c0                 test al, al
// 00705c4c  746c                 je 0x705cba
// 00705c4e  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00705c52  8b542430             mov edx, dword ptr [esp + 0x30]
// 00705c56  894c2410             mov dword ptr [esp + 0x10], ecx
// 00705c5a  8d4c2410             lea ecx, [esp + 0x10]
// 00705c5e  89542414             mov dword ptr [esp + 0x14], edx
// 00705c62  e8f9dbe0ff           call 0x513860
// 00705c67  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 00705c6b  57                   push edi
// 00705c6c  8d430c               lea eax, [ebx + 0xc]
// 00705c6f  50                   push eax
// 00705c70  8d4e08               lea ecx, [esi + 8]
// 00705c73  e8d84bd7ff           call 0x47a850
// 00705c78  84c0                 test al, al
// 00705c7a  743e                 je 0x705cba
// 00705c7c  8b4b08               mov ecx, dword ptr [ebx + 8]
// 00705c7f  80793100             cmp byte ptr [ecx + 0x31], 0
// 00705c83  57                   push edi
// 00705c84  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00705c88  8bce                 mov ecx, esi
// 00705c8a  7415                 je 0x705ca1
// 00705c8c  53                   push ebx
// 00705c8d  6a00                 push 0
// 00705c8f  57                   push edi
// 00705c90  e8ebdfffff           call 0x703c80
// 00705c95  5d                   pop ebp
// 00705c96  5b                   pop ebx
// 00705c97  8bc7                 mov eax, edi
// 00705c99  5f                   pop edi
// 00705c9a  5e                   pop esi
// 00705c9b  83c414               add esp, 0x14
// 00705c9e  c21000               ret 0x10
// 00705ca1  8b542434             mov edx, dword ptr [esp + 0x34]
// 00705ca5  52                   push edx
// 00705ca6  6a01                 push 1
// 00705ca8  57                   push edi
// 00705ca9  e8d2dfffff           call 0x703c80
// 00705cae  5d                   pop ebp
// 00705caf  5b                   pop ebx
// 00705cb0  8bc7                 mov eax, edi
// 00705cb2  5f                   pop edi
// 00705cb3  5e                   pop esi
// 00705cb4  83c414               add esp, 0x14
// 00705cb7  c21000               ret 0x10
// 00705cba  8b442430             mov eax, dword ptr [esp + 0x30]
// 00705cbe  83c00c               add eax, 0xc
// 00705cc1  57                   push edi
// 00705cc2  50                   push eax
// 00705cc3  ffd5                 call ebp
// 00705cc5  83c408               add esp, 8
// 00705cc8  84c0                 test al, al
// 00705cca  0f848b000000         je 0x705d5b
// 00705cd0  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00705cd4  8b542430             mov edx, dword ptr [esp + 0x30]
// 00705cd8  8b4618               mov eax, dword ptr [esi + 0x18]
// 00705cdb  894c2410             mov dword ptr [esp + 0x10], ecx
// 00705cdf  8b0e                 mov ecx, dword ptr [esi]
// 00705ce1  894c2418             mov dword ptr [esp + 0x18], ecx
// 00705ce5  8d4c2410             lea ecx, [esp + 0x10]
// 00705ce9  89542414             mov dword ptr [esp + 0x14], edx
// 00705ced  8944241c             mov dword ptr [esp + 0x1c], eax
// 00705cf1  e8fadbe0ff           call 0x5138f0
// 00705cf6  8d542418             lea edx, [esp + 0x18]
// 00705cfa  52                   push edx
// 00705cfb  8d4c2414             lea ecx, [esp + 0x14]
// 00705cff  e85c66ecff           call 0x5cc360
// 00705d04  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 00705d08  84c0                 test al, al
// 00705d0a  7511                 jne 0x705d1d
// 00705d0c  8d430c               lea eax, [ebx + 0xc]
// 00705d0f  50                   push eax
// 00705d10  57                   push edi
// 00705d11  8d4e08               lea ecx, [esi + 8]
// 00705d14  e8374bd7ff           call 0x47a850
// 00705d19  84c0                 test al, al
// 00705d1b  743e                 je 0x705d5b
// 00705d1d  8b442430             mov eax, dword ptr [esp + 0x30]
// 00705d21  8b4808               mov ecx, dword ptr [eax + 8]
// 00705d24  80793100             cmp byte ptr [ecx + 0x31], 0
// 00705d28  57                   push edi
// 00705d29  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00705d2d  8bce                 mov ecx, esi
// 00705d2f  7415                 je 0x705d46
// 00705d31  50                   push eax
// 00705d32  6a00                 push 0
// 00705d34  57                   push edi
// 00705d35  e846dfffff           call 0x703c80
// 00705d3a  5d                   pop ebp
// 00705d3b  5b                   pop ebx
// 00705d3c  8bc7                 mov eax, edi
// 00705d3e  5f                   pop edi
// 00705d3f  5e                   pop esi
// 00705d40  83c414               add esp, 0x14
// 00705d43  c21000               ret 0x10
// 00705d46  53                   push ebx
// 00705d47  6a01                 push 1
// 00705d49  57                   push edi
// 00705d4a  e831dfffff           call 0x703c80
// 00705d4f  5d                   pop ebp
// 00705d50  5b                   pop ebx
// 00705d51  8bc7                 mov eax, edi
// 00705d53  5f                   pop edi
// 00705d54  5e                   pop esi
// 00705d55  83c414               add esp, 0x14
// 00705d58  c21000               ret 0x10
// 00705d5b  57                   push edi
// 00705d5c  8d54241c             lea edx, [esp + 0x1c]
// 00705d60  52                   push edx
// 00705d61  8bce                 mov ecx, esi
// 00705d63  e818eaffff           call 0x704780
// 00705d68  8b10                 mov edx, dword ptr [eax]
// 00705d6a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00705d6e  5d                   pop ebp
// 00705d6f  5b                   pop ebx
// 00705d70  8911                 mov dword ptr [ecx], edx
// 00705d72  8b4004               mov eax, dword ptr [eax + 4]
// 00705d75  5f                   pop edi
// 00705d76  894104               mov dword ptr [ecx + 4], eax
// 00705d79  8bc1                 mov eax, ecx
// 00705d7b  5e                   pop esi
// 00705d7c  83c414               add esp, 0x14
// 00705d7f  c21000               ret 0x10
// standard library map_str<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod8>
struct E { int v[2]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
