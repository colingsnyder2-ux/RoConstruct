// from server: 100% by auto
// roc 2007-08 0044ecf0  unit: RBX::Humanoid  size: 679 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0044ecf0
//
// 0044ecf0  6aff                 push -1
// 0044ecf2  68e9a07400           push 0x74a0e9
// 0044ecf7  64a100000000         mov eax, dword ptr fs:[0]
// 0044ecfd  50                   push eax
// 0044ecfe  83ec48               sub esp, 0x48
// 0044ed01  53                   push ebx
// 0044ed02  55                   push ebp
// 0044ed03  56                   push esi
// 0044ed04  57                   push edi
// 0044ed05  a188518b00           mov eax, dword ptr [0x8b5188]
// 0044ed0a  33c4                 xor eax, esp
// 0044ed0c  50                   push eax
// 0044ed0d  8d44245c             lea eax, [esp + 0x5c]
// 0044ed11  64a300000000         mov dword ptr fs:[0], eax
// 0044ed17  8be9                 mov ebp, ecx
// 0044ed19  8b442474             mov eax, dword ptr [esp + 0x74]
// 0044ed1d  80781500             cmp byte ptr [eax + 0x15], 0
// 0044ed21  743c                 je 0x44ed5f
// 0044ed23  68dc4e7800           push 0x784edc
// 0044ed28  8d4c241c             lea ecx, [esp + 0x1c]
// 0044ed2c  ff1598e67700         call dword ptr [0x77e698]
// 0044ed32  8d442418             lea eax, [esp + 0x18]
// 0044ed36  50                   push eax
// 0044ed37  8d4c2438             lea ecx, [esp + 0x38]
// 0044ed3b  c744246800000000     mov dword ptr [esp + 0x68], 0
// 0044ed43  e87837fbff           call 0x4024c0
// 0044ed48  6864f38300           push 0x83f364
// 0044ed4d  8d4c2438             lea ecx, [esp + 0x38]
// 0044ed51  51                   push ecx
// 0044ed52  c744243c784e7800     mov dword ptr [esp + 0x3c], 0x784e78
// 0044ed5a  e83f1e1e00           call 0x630b9e
// 0044ed5f  8bd8                 mov ebx, eax
// 0044ed61  8d4c2470             lea ecx, [esp + 0x70]
// 0044ed65  895c2414             mov dword ptr [esp + 0x14], ebx
// 0044ed69  e842a1feff           call 0x438eb0
// 0044ed6e  8b03                 mov eax, dword ptr [ebx]
// 0044ed70  80781500             cmp byte ptr [eax + 0x15], 0
// 0044ed74  7405                 je 0x44ed7b
// 0044ed76  8b7b08               mov edi, dword ptr [ebx + 8]
// 0044ed79  eb18                 jmp 0x44ed93
// 0044ed7b  8b5308               mov edx, dword ptr [ebx + 8]
// 0044ed7e  807a1500             cmp byte ptr [edx + 0x15], 0
// 0044ed82  7404                 je 0x44ed88
// 0044ed84  8bf8                 mov edi, eax
// 0044ed86  eb0b                 jmp 0x44ed93
// 0044ed88  8b4c2474             mov ecx, dword ptr [esp + 0x74]
// 0044ed8c  3bcb                 cmp ecx, ebx
// 0044ed8e  8b7908               mov edi, dword ptr [ecx + 8]
// 0044ed91  756b                 jne 0x44edfe
// 0044ed93  807f1500             cmp byte ptr [edi + 0x15], 0
// 0044ed97  8b7304               mov esi, dword ptr [ebx + 4]
// 0044ed9a  7503                 jne 0x44ed9f
// 0044ed9c  897704               mov dword ptr [edi + 4], esi
// 0044ed9f  8b4504               mov eax, dword ptr [ebp + 4]
// 0044eda2  395804               cmp dword ptr [eax + 4], ebx
// 0044eda5  7505                 jne 0x44edac
// 0044eda7  897804               mov dword ptr [eax + 4], edi
// 0044edaa  eb0b                 jmp 0x44edb7
// 0044edac  391e                 cmp dword ptr [esi], ebx
// 0044edae  7504                 jne 0x44edb4
// 0044edb0  893e                 mov dword ptr [esi], edi
// 0044edb2  eb03                 jmp 0x44edb7
// 0044edb4  897e08               mov dword ptr [esi + 8], edi
// 0044edb7  8b5d04               mov ebx, dword ptr [ebp + 4]
// 0044edba  8b03                 mov eax, dword ptr [ebx]
// 0044edbc  3b442414             cmp eax, dword ptr [esp + 0x14]
// 0044edc0  7515                 jne 0x44edd7
// 0044edc2  807f1500             cmp byte ptr [edi + 0x15], 0
// 0044edc6  7404                 je 0x44edcc
// 0044edc8  8bc6                 mov eax, esi
// 0044edca  eb09                 jmp 0x44edd5
// 0044edcc  57                   push edi
// 0044edcd  e83e040a00           call 0x4ef210
// 0044edd2  83c404               add esp, 4
// 0044edd5  8903                 mov dword ptr [ebx], eax
// 0044edd7  8b5d04               mov ebx, dword ptr [ebp + 4]
// 0044edda  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0044edde  394b08               cmp dword ptr [ebx + 8], ecx
// 0044ede1  7572                 jne 0x44ee55
// 0044ede3  807f1500             cmp byte ptr [edi + 0x15], 0
// 0044ede7  7407                 je 0x44edf0
// 0044ede9  8bc6                 mov eax, esi
// 0044edeb  894308               mov dword ptr [ebx + 8], eax
// 0044edee  eb65                 jmp 0x44ee55
// 0044edf0  57                   push edi
// 0044edf1  e81a3e0f00           call 0x542c10
// 0044edf6  83c404               add esp, 4
// 0044edf9  894308               mov dword ptr [ebx + 8], eax
// 0044edfc  eb57                 jmp 0x44ee55
// 0044edfe  894804               mov dword ptr [eax + 4], ecx
// 0044ee01  8b13                 mov edx, dword ptr [ebx]
// 0044ee03  8911                 mov dword ptr [ecx], edx
// 0044ee05  3b4b08               cmp ecx, dword ptr [ebx + 8]
// 0044ee08  7504                 jne 0x44ee0e
// 0044ee0a  8bf1                 mov esi, ecx
// 0044ee0c  eb1a                 jmp 0x44ee28
// 0044ee0e  807f1500             cmp byte ptr [edi + 0x15], 0
// 0044ee12  8b7104               mov esi, dword ptr [ecx + 4]
// 0044ee15  7503                 jne 0x44ee1a
// 0044ee17  897704               mov dword ptr [edi + 4], esi
// 0044ee1a  893e                 mov dword ptr [esi], edi
// 0044ee1c  8b4308               mov eax, dword ptr [ebx + 8]
// 0044ee1f  894108               mov dword ptr [ecx + 8], eax
// 0044ee22  8b5308               mov edx, dword ptr [ebx + 8]
// 0044ee25  894a04               mov dword ptr [edx + 4], ecx
// 0044ee28  8b4504               mov eax, dword ptr [ebp + 4]
// 0044ee2b  395804               cmp dword ptr [eax + 4], ebx
// 0044ee2e  7505                 jne 0x44ee35
// 0044ee30  894804               mov dword ptr [eax + 4], ecx
// 0044ee33  eb0e                 jmp 0x44ee43
// 0044ee35  8b4304               mov eax, dword ptr [ebx + 4]
// 0044ee38  3918                 cmp dword ptr [eax], ebx
// 0044ee3a  7504                 jne 0x44ee40
// 0044ee3c  8908                 mov dword ptr [eax], ecx
// 0044ee3e  eb03                 jmp 0x44ee43
// 0044ee40  894808               mov dword ptr [eax + 8], ecx
// 0044ee43  8b4304               mov eax, dword ptr [ebx + 4]
// 0044ee46  894104               mov dword ptr [ecx + 4], eax
// 0044ee49  8a5314               mov dl, byte ptr [ebx + 0x14]
// 0044ee4c  8a4114               mov al, byte ptr [ecx + 0x14]
// 0044ee4f  885114               mov byte ptr [ecx + 0x14], dl
// 0044ee52  884314               mov byte ptr [ebx + 0x14], al
// 0044ee55  8b442414             mov eax, dword ptr [esp + 0x14]
// 0044ee59  b301                 mov bl, 1
// 0044ee5b  385814               cmp byte ptr [eax + 0x14], bl
// 0044ee5e  0f85f2000000         jne 0x44ef56
// 0044ee64  8b4d04               mov ecx, dword ptr [ebp + 4]
// 0044ee67  3b7904               cmp edi, dword ptr [ecx + 4]
// 0044ee6a  0f84e3000000         je 0x44ef53
// 0044ee70  385f14               cmp byte ptr [edi + 0x14], bl
// 0044ee73  0f85da000000         jne 0x44ef53
// 0044ee79  8b06                 mov eax, dword ptr [esi]
// 0044ee7b  3bf8                 cmp edi, eax
// 0044ee7d  7563                 jne 0x44eee2
// 0044ee7f  8b4608               mov eax, dword ptr [esi + 8]
// 0044ee82  80781400             cmp byte ptr [eax + 0x14], 0
// 0044ee86  7512                 jne 0x44ee9a
// 0044ee88  885814               mov byte ptr [eax + 0x14], bl
// 0044ee8b  56                   push esi
// 0044ee8c  8bcd                 mov ecx, ebp
// 0044ee8e  c6461400             mov byte ptr [esi + 0x14], 0
// 0044ee92  e849e61100           call 0x56d4e0
// 0044ee97  8b4608               mov eax, dword ptr [esi + 8]
// 0044ee9a  80781500             cmp byte ptr [eax + 0x15], 0
// 0044ee9e  7572                 jne 0x44ef12
// 0044eea0  8b10                 mov edx, dword ptr [eax]
// 0044eea2  385a14               cmp byte ptr [edx + 0x14], bl
// 0044eea5  7508                 jne 0x44eeaf
// 0044eea7  8b4808               mov ecx, dword ptr [eax + 8]
// 0044eeaa  385914               cmp byte ptr [ecx + 0x14], bl
// 0044eead  745f                 je 0x44ef0e
// 0044eeaf  8b4808               mov ecx, dword ptr [eax + 8]
// 0044eeb2  385914               cmp byte ptr [ecx + 0x14], bl
// 0044eeb5  7512                 jne 0x44eec9
// 0044eeb7  885a14               mov byte ptr [edx + 0x14], bl
// 0044eeba  50                   push eax
// 0044eebb  8bcd                 mov ecx, ebp
// 0044eebd  c6401400             mov byte ptr [eax + 0x14], 0
// 0044eec1  e85a5c1b00           call 0x604b20
// 0044eec6  8b4608               mov eax, dword ptr [esi + 8]
// 0044eec9  8a4e14               mov cl, byte ptr [esi + 0x14]
// 0044eecc  884814               mov byte ptr [eax + 0x14], cl
// 0044eecf  885e14               mov byte ptr [esi + 0x14], bl
// 0044eed2  8b5008               mov edx, dword ptr [eax + 8]
// 0044eed5  56                   push esi
// 0044eed6  8bcd                 mov ecx, ebp
// 0044eed8  885a14               mov byte ptr [edx + 0x14], bl
// 0044eedb  e800e61100           call 0x56d4e0
// 0044eee0  eb71                 jmp 0x44ef53
// 0044eee2  80781400             cmp byte ptr [eax + 0x14], 0
// 0044eee6  7511                 jne 0x44eef9
// 0044eee8  885814               mov byte ptr [eax + 0x14], bl
// 0044eeeb  56                   push esi
// 0044eeec  8bcd                 mov ecx, ebp
// 0044eeee  c6461400             mov byte ptr [esi + 0x14], 0
// 0044eef2  e8295c1b00           call 0x604b20
// 0044eef7  8b06                 mov eax, dword ptr [esi]
// 0044eef9  80781500             cmp byte ptr [eax + 0x15], 0
// 0044eefd  7513                 jne 0x44ef12
// 0044eeff  8b5008               mov edx, dword ptr [eax + 8]
// 0044ef02  385a14               cmp byte ptr [edx + 0x14], bl
// 0044ef05  751e                 jne 0x44ef25
// 0044ef07  8b08                 mov ecx, dword ptr [eax]
// 0044ef09  385914               cmp byte ptr [ecx + 0x14], bl
// 0044ef0c  7517                 jne 0x44ef25
// 0044ef0e  c6401400             mov byte ptr [eax + 0x14], 0
// 0044ef12  8b5504               mov edx, dword ptr [ebp + 4]
// 0044ef15  8bfe                 mov edi, esi
// 0044ef17  3b7a04               cmp edi, dword ptr [edx + 4]
// 0044ef1a  8b7604               mov esi, dword ptr [esi + 4]
// 0044ef1d  0f854dffffff         jne 0x44ee70
// 0044ef23  eb2e                 jmp 0x44ef53
// 0044ef25  8b08                 mov ecx, dword ptr [eax]
// 0044ef27  385914               cmp byte ptr [ecx + 0x14], bl
// 0044ef2a  7511                 jne 0x44ef3d
// 0044ef2c  885a14               mov byte ptr [edx + 0x14], bl
// 0044ef2f  50                   push eax
// 0044ef30  8bcd                 mov ecx, ebp
// 0044ef32  c6401400             mov byte ptr [eax + 0x14], 0
// 0044ef36  e8a5e51100           call 0x56d4e0
// 0044ef3b  8b06                 mov eax, dword ptr [esi]
// 0044ef3d  8a4e14               mov cl, byte ptr [esi + 0x14]
// 0044ef40  884814               mov byte ptr [eax + 0x14], cl
// 0044ef43  885e14               mov byte ptr [esi + 0x14], bl
// 0044ef46  8b10                 mov edx, dword ptr [eax]
// 0044ef48  56                   push esi
// 0044ef49  8bcd                 mov ecx, ebp
// 0044ef4b  885a14               mov byte ptr [edx + 0x14], bl
// 0044ef4e  e8cd5b1b00           call 0x604b20
// 0044ef53  885f14               mov byte ptr [edi + 0x14], bl
// 0044ef56  8b442414             mov eax, dword ptr [esp + 0x14]
// 0044ef5a  50                   push eax
// 0044ef5b  e8020d1e00           call 0x62fc62
// 0044ef60  8b4508               mov eax, dword ptr [ebp + 8]
// 0044ef63  83c404               add esp, 4
// 0044ef66  85c0                 test eax, eax
// 0044ef68  7606                 jbe 0x44ef70
// 0044ef6a  83c0ff               add eax, -1
// 0044ef6d  894508               mov dword ptr [ebp + 8], eax
// 0044ef70  8b44246c             mov eax, dword ptr [esp + 0x6c]
// 0044ef74  8b4c2470             mov ecx, dword ptr [esp + 0x70]
// 0044ef78  8b542474             mov edx, dword ptr [esp + 0x74]
// 0044ef7c  8908                 mov dword ptr [eax], ecx
// 0044ef7e  895004               mov dword ptr [eax + 4], edx
// 0044ef81  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 0044ef85  64890d00000000       mov dword ptr fs:[0], ecx
// 0044ef8c  59                   pop ecx
// 0044ef8d  5f                   pop edi
// 0044ef8e  5e                   pop esi
// 0044ef8f  5d                   pop ebp
// 0044ef90  5b                   pop ebx
// 0044ef91  83c454               add esp, 0x54
// 0044ef94  c20c00               ret 0xc
// standard library set<pod8> (function ?erase@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE?AViterator@12@V312@@Z)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
