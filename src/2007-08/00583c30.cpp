// from server: 100% by auto
// roc 2007-08 00583c30  unit: RBX::VHat::?$FactoryProduct  size: 696 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00583c30
//
// 00583c30  64a100000000         mov eax, dword ptr fs:[0]
// 00583c36  6aff                 push -1
// 00583c38  68b2417500           push 0x7541b2
// 00583c3d  50                   push eax
// 00583c3e  64892500000000       mov dword ptr fs:[0], esp
// 00583c45  8b442418             mov eax, dword ptr [esp + 0x18]
// 00583c49  83ec48               sub esp, 0x48
// 00583c4c  80782100             cmp byte ptr [eax + 0x21], 0
// 00583c50  55                   push ebp
// 00583c51  8be9                 mov ebp, ecx
// 00583c53  7459                 je 0x583cae
// 00583c55  68dc4e7800           push 0x784edc
// 00583c5a  8d4c240c             lea ecx, [esp + 0xc]
// 00583c5e  ff1598e67700         call dword ptr [0x77e698]
// 00583c64  8d4c2424             lea ecx, [esp + 0x24]
// 00583c68  c744245400000000     mov dword ptr [esp + 0x54], 0
// 00583c70  ff15f8e67700         call dword ptr [0x77e6f8]
// 00583c76  8d442408             lea eax, [esp + 8]
// 00583c7a  50                   push eax
// 00583c7b  8d4c2434             lea ecx, [esp + 0x34]
// 00583c7f  c644245801           mov byte ptr [esp + 0x58], 1
// 00583c84  c7442428604e7800     mov dword ptr [esp + 0x28], 0x784e60
// 00583c8c  ff159ce67700         call dword ptr [0x77e69c]
// 00583c92  6864f38300           push 0x83f364
// 00583c97  8d4c2428             lea ecx, [esp + 0x28]
// 00583c9b  51                   push ecx
// 00583c9c  c644245c00           mov byte ptr [esp + 0x5c], 0
// 00583ca1  c744242c784e7800     mov dword ptr [esp + 0x2c], 0x784e78
// 00583ca9  e8f0ce0a00           call 0x630b9e
// 00583cae  53                   push ebx
// 00583caf  56                   push esi
// 00583cb0  8bd8                 mov ebx, eax
// 00583cb2  57                   push edi
// 00583cb3  8d4c246c             lea ecx, [esp + 0x6c]
// 00583cb7  895c2410             mov dword ptr [esp + 0x10], ebx
// 00583cbb  e8b0cbf4ff           call 0x4d0870
// 00583cc0  8b03                 mov eax, dword ptr [ebx]
// 00583cc2  80782100             cmp byte ptr [eax + 0x21], 0
// 00583cc6  7405                 je 0x583ccd
// 00583cc8  8b7b08               mov edi, dword ptr [ebx + 8]
// 00583ccb  eb18                 jmp 0x583ce5
// 00583ccd  8b5308               mov edx, dword ptr [ebx + 8]
// 00583cd0  807a2100             cmp byte ptr [edx + 0x21], 0
// 00583cd4  7404                 je 0x583cda
// 00583cd6  8bf8                 mov edi, eax
// 00583cd8  eb0b                 jmp 0x583ce5
// 00583cda  8b4c2470             mov ecx, dword ptr [esp + 0x70]
// 00583cde  3bcb                 cmp ecx, ebx
// 00583ce0  8b7908               mov edi, dword ptr [ecx + 8]
// 00583ce3  756b                 jne 0x583d50
// 00583ce5  807f2100             cmp byte ptr [edi + 0x21], 0
// 00583ce9  8b7304               mov esi, dword ptr [ebx + 4]
// 00583cec  7503                 jne 0x583cf1
// 00583cee  897704               mov dword ptr [edi + 4], esi
// 00583cf1  8b4504               mov eax, dword ptr [ebp + 4]
// 00583cf4  395804               cmp dword ptr [eax + 4], ebx
// 00583cf7  7505                 jne 0x583cfe
// 00583cf9  897804               mov dword ptr [eax + 4], edi
// 00583cfc  eb0b                 jmp 0x583d09
// 00583cfe  391e                 cmp dword ptr [esi], ebx
// 00583d00  7504                 jne 0x583d06
// 00583d02  893e                 mov dword ptr [esi], edi
// 00583d04  eb03                 jmp 0x583d09
// 00583d06  897e08               mov dword ptr [esi + 8], edi
// 00583d09  8b5d04               mov ebx, dword ptr [ebp + 4]
// 00583d0c  8b03                 mov eax, dword ptr [ebx]
// 00583d0e  3b442410             cmp eax, dword ptr [esp + 0x10]
// 00583d12  7515                 jne 0x583d29
// 00583d14  807f2100             cmp byte ptr [edi + 0x21], 0
// 00583d18  7404                 je 0x583d1e
// 00583d1a  8bc6                 mov eax, esi
// 00583d1c  eb09                 jmp 0x583d27
// 00583d1e  57                   push edi
// 00583d1f  e86c51ebff           call 0x438e90
// 00583d24  83c404               add esp, 4
// 00583d27  8903                 mov dword ptr [ebx], eax
// 00583d29  8b5d04               mov ebx, dword ptr [ebp + 4]
// 00583d2c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00583d30  394b08               cmp dword ptr [ebx + 8], ecx
// 00583d33  7572                 jne 0x583da7
// 00583d35  807f2100             cmp byte ptr [edi + 0x21], 0
// 00583d39  7407                 je 0x583d42
// 00583d3b  8bc6                 mov eax, esi
// 00583d3d  894308               mov dword ptr [ebx + 8], eax
// 00583d40  eb65                 jmp 0x583da7
// 00583d42  57                   push edi
// 00583d43  e89898f4ff           call 0x4cd5e0
// 00583d48  83c404               add esp, 4
// 00583d4b  894308               mov dword ptr [ebx + 8], eax
// 00583d4e  eb57                 jmp 0x583da7
// 00583d50  894804               mov dword ptr [eax + 4], ecx
// 00583d53  8b13                 mov edx, dword ptr [ebx]
// 00583d55  8911                 mov dword ptr [ecx], edx
// 00583d57  3b4b08               cmp ecx, dword ptr [ebx + 8]
// 00583d5a  7504                 jne 0x583d60
// 00583d5c  8bf1                 mov esi, ecx
// 00583d5e  eb1a                 jmp 0x583d7a
// 00583d60  807f2100             cmp byte ptr [edi + 0x21], 0
// 00583d64  8b7104               mov esi, dword ptr [ecx + 4]
// 00583d67  7503                 jne 0x583d6c
// 00583d69  897704               mov dword ptr [edi + 4], esi
// 00583d6c  893e                 mov dword ptr [esi], edi
// 00583d6e  8b4308               mov eax, dword ptr [ebx + 8]
// 00583d71  894108               mov dword ptr [ecx + 8], eax
// 00583d74  8b5308               mov edx, dword ptr [ebx + 8]
// 00583d77  894a04               mov dword ptr [edx + 4], ecx
// 00583d7a  8b4504               mov eax, dword ptr [ebp + 4]
// 00583d7d  395804               cmp dword ptr [eax + 4], ebx
// 00583d80  7505                 jne 0x583d87
// 00583d82  894804               mov dword ptr [eax + 4], ecx
// 00583d85  eb0e                 jmp 0x583d95
// 00583d87  8b4304               mov eax, dword ptr [ebx + 4]
// 00583d8a  3918                 cmp dword ptr [eax], ebx
// 00583d8c  7504                 jne 0x583d92
// 00583d8e  8908                 mov dword ptr [eax], ecx
// 00583d90  eb03                 jmp 0x583d95
// 00583d92  894808               mov dword ptr [eax + 8], ecx
// 00583d95  8b4304               mov eax, dword ptr [ebx + 4]
// 00583d98  894104               mov dword ptr [ecx + 4], eax
// 00583d9b  8a5320               mov dl, byte ptr [ebx + 0x20]
// 00583d9e  8a4120               mov al, byte ptr [ecx + 0x20]
// 00583da1  885120               mov byte ptr [ecx + 0x20], dl
// 00583da4  884320               mov byte ptr [ebx + 0x20], al
// 00583da7  8b442410             mov eax, dword ptr [esp + 0x10]
// 00583dab  b301                 mov bl, 1
// 00583dad  385820               cmp byte ptr [eax + 0x20], bl
// 00583db0  0f85f2000000         jne 0x583ea8
// 00583db6  8b4d04               mov ecx, dword ptr [ebp + 4]
// 00583db9  3b7904               cmp edi, dword ptr [ecx + 4]
// 00583dbc  0f84e3000000         je 0x583ea5
// 00583dc2  385f20               cmp byte ptr [edi + 0x20], bl
// 00583dc5  0f85da000000         jne 0x583ea5
// 00583dcb  8b06                 mov eax, dword ptr [esi]
// 00583dcd  3bf8                 cmp edi, eax
// 00583dcf  7563                 jne 0x583e34
// 00583dd1  8b4608               mov eax, dword ptr [esi + 8]
// 00583dd4  80782000             cmp byte ptr [eax + 0x20], 0
// 00583dd8  7512                 jne 0x583dec
// 00583dda  885820               mov byte ptr [eax + 0x20], bl
// 00583ddd  56                   push esi
// 00583dde  8bcd                 mov ecx, ebp
// 00583de0  c6462000             mov byte ptr [esi + 0x20], 0
// 00583de4  e82799f4ff           call 0x4cd710
// 00583de9  8b4608               mov eax, dword ptr [esi + 8]
// 00583dec  80782100             cmp byte ptr [eax + 0x21], 0
// 00583df0  7572                 jne 0x583e64
// 00583df2  8b10                 mov edx, dword ptr [eax]
// 00583df4  385a20               cmp byte ptr [edx + 0x20], bl
// 00583df7  7508                 jne 0x583e01
// 00583df9  8b4808               mov ecx, dword ptr [eax + 8]
// 00583dfc  385920               cmp byte ptr [ecx + 0x20], bl
// 00583dff  745f                 je 0x583e60
// 00583e01  8b4808               mov ecx, dword ptr [eax + 8]
// 00583e04  385920               cmp byte ptr [ecx + 0x20], bl
// 00583e07  7512                 jne 0x583e1b
// 00583e09  885a20               mov byte ptr [edx + 0x20], bl
// 00583e0c  50                   push eax
// 00583e0d  8bcd                 mov ecx, ebp
// 00583e0f  c6402000             mov byte ptr [eax + 0x20], 0
// 00583e13  e8d8c4f4ff           call 0x4d02f0
// 00583e18  8b4608               mov eax, dword ptr [esi + 8]
// 00583e1b  8a4e20               mov cl, byte ptr [esi + 0x20]
// 00583e1e  884820               mov byte ptr [eax + 0x20], cl
// 00583e21  885e20               mov byte ptr [esi + 0x20], bl
// 00583e24  8b5008               mov edx, dword ptr [eax + 8]
// 00583e27  56                   push esi
// 00583e28  8bcd                 mov ecx, ebp
// 00583e2a  885a20               mov byte ptr [edx + 0x20], bl
// 00583e2d  e8de98f4ff           call 0x4cd710
// 00583e32  eb71                 jmp 0x583ea5
// 00583e34  80782000             cmp byte ptr [eax + 0x20], 0
// 00583e38  7511                 jne 0x583e4b
// 00583e3a  885820               mov byte ptr [eax + 0x20], bl
// 00583e3d  56                   push esi
// 00583e3e  8bcd                 mov ecx, ebp
// 00583e40  c6462000             mov byte ptr [esi + 0x20], 0
// 00583e44  e8a7c4f4ff           call 0x4d02f0
// 00583e49  8b06                 mov eax, dword ptr [esi]
// 00583e4b  80782100             cmp byte ptr [eax + 0x21], 0
// 00583e4f  7513                 jne 0x583e64
// 00583e51  8b5008               mov edx, dword ptr [eax + 8]
// 00583e54  385a20               cmp byte ptr [edx + 0x20], bl
// 00583e57  751e                 jne 0x583e77
// 00583e59  8b08                 mov ecx, dword ptr [eax]
// 00583e5b  385920               cmp byte ptr [ecx + 0x20], bl
// 00583e5e  7517                 jne 0x583e77
// 00583e60  c6402000             mov byte ptr [eax + 0x20], 0
// 00583e64  8b5504               mov edx, dword ptr [ebp + 4]
// 00583e67  8bfe                 mov edi, esi
// 00583e69  3b7a04               cmp edi, dword ptr [edx + 4]
// 00583e6c  8b7604               mov esi, dword ptr [esi + 4]
// 00583e6f  0f854dffffff         jne 0x583dc2
// 00583e75  eb2e                 jmp 0x583ea5
// 00583e77  8b08                 mov ecx, dword ptr [eax]
// 00583e79  385920               cmp byte ptr [ecx + 0x20], bl
// 00583e7c  7511                 jne 0x583e8f
// 00583e7e  885a20               mov byte ptr [edx + 0x20], bl
// 00583e81  50                   push eax
// 00583e82  8bcd                 mov ecx, ebp
// 00583e84  c6402000             mov byte ptr [eax + 0x20], 0
// 00583e88  e88398f4ff           call 0x4cd710
// 00583e8d  8b06                 mov eax, dword ptr [esi]
// 00583e8f  8a4e20               mov cl, byte ptr [esi + 0x20]
// 00583e92  884820               mov byte ptr [eax + 0x20], cl
// 00583e95  885e20               mov byte ptr [esi + 0x20], bl
// 00583e98  8b10                 mov edx, dword ptr [eax]
// 00583e9a  56                   push esi
// 00583e9b  8bcd                 mov ecx, ebp
// 00583e9d  885a20               mov byte ptr [edx + 0x20], bl
// 00583ea0  e84bc4f4ff           call 0x4d02f0
// 00583ea5  885f20               mov byte ptr [edi + 0x20], bl
// 00583ea8  8b442410             mov eax, dword ptr [esp + 0x10]
// 00583eac  50                   push eax
// 00583ead  e8b0bd0a00           call 0x62fc62
// 00583eb2  8b4508               mov eax, dword ptr [ebp + 8]
// 00583eb5  83c404               add esp, 4
// 00583eb8  85c0                 test eax, eax
// 00583eba  5f                   pop edi
// 00583ebb  5e                   pop esi
// 00583ebc  5b                   pop ebx
// 00583ebd  7606                 jbe 0x583ec5
// 00583ebf  83c0ff               add eax, -1
// 00583ec2  894508               mov dword ptr [ebp + 8], eax
// 00583ec5  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 00583ec9  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 00583ecd  8b542464             mov edx, dword ptr [esp + 0x64]
// 00583ed1  8908                 mov dword ptr [eax], ecx
// 00583ed3  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00583ed7  895004               mov dword ptr [eax + 4], edx
// 00583eda  5d                   pop ebp
// 00583edb  64890d00000000       mov dword ptr fs:[0], ecx
// 00583ee2  83c454               add esp, 0x54
// 00583ee5  c20c00               ret 0xc
// standard library set<pod20> (function ?erase@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE?AViterator@12@V312@@Z)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
