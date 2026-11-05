// from server: 100% by auto
// roc 2010-06 00446900  unit: RBX::Reflection::M::?$TypedPropertyDescriptor  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00446900
//
// 00446900  83ec14               sub esp, 0x14
// 00446903  56                   push esi
// 00446904  8bf1                 mov esi, ecx
// 00446906  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 0044690a  57                   push edi
// 0044690b  7521                 jne 0x44692e
// 0044690d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00446911  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00446914  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00446918  50                   push eax
// 00446919  51                   push ecx
// 0044691a  6a01                 push 1
// 0044691c  57                   push edi
// 0044691d  8bce                 mov ecx, esi
// 0044691f  e80c473400           call 0x78b030
// 00446924  8bc7                 mov eax, edi
// 00446926  5f                   pop edi
// 00446927  5e                   pop esi
// 00446928  83c414               add esp, 0x14
// 0044692b  c21000               ret 0x10
// 0044692e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00446932  8b5618               mov edx, dword ptr [esi + 0x18]
// 00446935  8b3a                 mov edi, dword ptr [edx]
// 00446937  8b06                 mov eax, dword ptr [esi]
// 00446939  53                   push ebx
// 0044693a  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 00446940  85c9                 test ecx, ecx
// 00446942  7404                 je 0x446948
// 00446944  3bc8                 cmp ecx, eax
// 00446946  7406                 je 0x44694e
// 00446948  ffd3                 call ebx
// 0044694a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0044694e  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00446952  3bc7                 cmp eax, edi
// 00446954  752a                 jne 0x446980
// 00446956  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0044695a  8b0f                 mov ecx, dword ptr [edi]
// 0044695c  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 0044695f  0f834b010000         jae 0x446ab0
// 00446965  57                   push edi
// 00446966  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0044696a  50                   push eax
// 0044696b  6a01                 push 1
// 0044696d  57                   push edi
// 0044696e  8bce                 mov ecx, esi
// 00446970  e8bb463400           call 0x78b030
// 00446975  5b                   pop ebx
// 00446976  8bc7                 mov eax, edi
// 00446978  5f                   pop edi
// 00446979  5e                   pop esi
// 0044697a  83c414               add esp, 0x14
// 0044697d  c21000               ret 0x10
// 00446980  8b7e18               mov edi, dword ptr [esi + 0x18]
// 00446983  8b16                 mov edx, dword ptr [esi]
// 00446985  85c9                 test ecx, ecx
// 00446987  7404                 je 0x44698d
// 00446989  3bca                 cmp ecx, edx
// 0044698b  740a                 je 0x446997
// 0044698d  ffd3                 call ebx
// 0044698f  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00446993  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00446997  3bc7                 cmp eax, edi
// 00446999  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0044699d  752c                 jne 0x4469cb
// 0044699f  8b5618               mov edx, dword ptr [esi + 0x18]
// 004469a2  8b4208               mov eax, dword ptr [edx + 8]
// 004469a5  8b480c               mov ecx, dword ptr [eax + 0xc]
// 004469a8  3b0f                 cmp ecx, dword ptr [edi]
// 004469aa  0f8300010000         jae 0x446ab0
// 004469b0  57                   push edi
// 004469b1  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 004469b5  50                   push eax
// 004469b6  6a00                 push 0
// 004469b8  57                   push edi
// 004469b9  8bce                 mov ecx, esi
// 004469bb  e870463400           call 0x78b030
// 004469c0  5b                   pop ebx
// 004469c1  8bc7                 mov eax, edi
// 004469c3  5f                   pop edi
// 004469c4  5e                   pop esi
// 004469c5  83c414               add esp, 0x14
// 004469c8  c21000               ret 0x10
// 004469cb  8b17                 mov edx, dword ptr [edi]
// 004469cd  39500c               cmp dword ptr [eax + 0xc], edx
// 004469d0  7663                 jbe 0x446a35
// 004469d2  894c240c             mov dword ptr [esp + 0xc], ecx
// 004469d6  8d4c240c             lea ecx, [esp + 0xc]
// 004469da  89442410             mov dword ptr [esp + 0x10], eax
// 004469de  e85d322c00           call 0x709c40
// 004469e3  8b17                 mov edx, dword ptr [edi]
// 004469e5  8b442410             mov eax, dword ptr [esp + 0x10]
// 004469e9  39500c               cmp dword ptr [eax + 0xc], edx
// 004469ec  733c                 jae 0x446a2a
// 004469ee  8b5008               mov edx, dword ptr [eax + 8]
// 004469f1  807a1500             cmp byte ptr [edx + 0x15], 0
// 004469f5  57                   push edi
// 004469f6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 004469fa  8bce                 mov ecx, esi
// 004469fc  7414                 je 0x446a12
// 004469fe  50                   push eax
// 004469ff  6a00                 push 0
// 00446a01  57                   push edi
// 00446a02  e829463400           call 0x78b030
// 00446a07  5b                   pop ebx
// 00446a08  8bc7                 mov eax, edi
// 00446a0a  5f                   pop edi
// 00446a0b  5e                   pop esi
// 00446a0c  83c414               add esp, 0x14
// 00446a0f  c21000               ret 0x10
// 00446a12  8b442430             mov eax, dword ptr [esp + 0x30]
// 00446a16  50                   push eax
// 00446a17  6a01                 push 1
// 00446a19  57                   push edi
// 00446a1a  e811463400           call 0x78b030
// 00446a1f  5b                   pop ebx
// 00446a20  8bc7                 mov eax, edi
// 00446a22  5f                   pop edi
// 00446a23  5e                   pop esi
// 00446a24  83c414               add esp, 0x14
// 00446a27  c21000               ret 0x10
// 00446a2a  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00446a2e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00446a32  39500c               cmp dword ptr [eax + 0xc], edx
// 00446a35  7379                 jae 0x446ab0
// 00446a37  8b16                 mov edx, dword ptr [esi]
// 00446a39  894c240c             mov dword ptr [esp + 0xc], ecx
// 00446a3d  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00446a40  894c2418             mov dword ptr [esp + 0x18], ecx
// 00446a44  8d4c240c             lea ecx, [esp + 0xc]
// 00446a48  89442410             mov dword ptr [esp + 0x10], eax
// 00446a4c  89542414             mov dword ptr [esp + 0x14], edx
// 00446a50  e88b0f2a00           call 0x6e79e0
// 00446a55  8d442414             lea eax, [esp + 0x14]
// 00446a59  50                   push eax
// 00446a5a  8d4c2410             lea ecx, [esp + 0x10]
// 00446a5e  e81d050200           call 0x466f80
// 00446a63  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00446a67  84c0                 test al, al
// 00446a69  7507                 jne 0x446a72
// 00446a6b  8b17                 mov edx, dword ptr [edi]
// 00446a6d  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 00446a70  733e                 jae 0x446ab0
// 00446a72  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00446a76  8b5008               mov edx, dword ptr [eax + 8]
// 00446a79  807a1500             cmp byte ptr [edx + 0x15], 0
// 00446a7d  57                   push edi
// 00446a7e  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00446a82  7416                 je 0x446a9a
// 00446a84  50                   push eax
// 00446a85  6a00                 push 0
// 00446a87  57                   push edi
// 00446a88  8bce                 mov ecx, esi
// 00446a8a  e8a1453400           call 0x78b030
// 00446a8f  5b                   pop ebx
// 00446a90  8bc7                 mov eax, edi
// 00446a92  5f                   pop edi
// 00446a93  5e                   pop esi
// 00446a94  83c414               add esp, 0x14
// 00446a97  c21000               ret 0x10
// 00446a9a  51                   push ecx
// 00446a9b  6a01                 push 1
// 00446a9d  57                   push edi
// 00446a9e  8bce                 mov ecx, esi
// 00446aa0  e88b453400           call 0x78b030
// 00446aa5  5b                   pop ebx
// 00446aa6  8bc7                 mov eax, edi
// 00446aa8  5f                   pop edi
// 00446aa9  5e                   pop esi
// 00446aaa  83c414               add esp, 0x14
// 00446aad  c21000               ret 0x10
// 00446ab0  57                   push edi
// 00446ab1  8d442418             lea eax, [esp + 0x18]
// 00446ab5  50                   push eax
// 00446ab6  8bce                 mov ecx, esi
// 00446ab8  e813f9ffff           call 0x4463d0
// 00446abd  8b10                 mov edx, dword ptr [eax]
// 00446abf  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00446ac3  5b                   pop ebx
// 00446ac4  8911                 mov dword ptr [ecx], edx
// 00446ac6  8b4004               mov eax, dword ptr [eax + 4]
// 00446ac9  5f                   pop edi
// 00446aca  894104               mov dword ptr [ecx + 4], eax
// 00446acd  8bc1                 mov eax, ecx
// 00446acf  5e                   pop esi
// 00446ad0  83c414               add esp, 0x14
// 00446ad3  c21000               ret 0x10
// standard library map_ptr<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@PAUT@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@PAUT@@@std@@@4@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@QAUK@@PAUT@@@2@@Z)

// stl: map_ptr<ptr>
struct T; typedef T* E;
#include <map>
struct K; template class std::map<K*, E>;
