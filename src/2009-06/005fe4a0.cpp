// from server: 100% by auto
// roc 2009-06 005fe4a0  unit: RBX::VInstance::?$NonFactoryProduct  size: 211 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005fe4a0
//
// 005fe4a0  64a100000000         mov eax, dword ptr fs:[0]
// 005fe4a6  6aff                 push -1
// 005fe4a8  6868688600           push 0x866868
// 005fe4ad  50                   push eax
// 005fe4ae  64892500000000       mov dword ptr fs:[0], esp
// 005fe4b5  83ec28               sub esp, 0x28
// 005fe4b8  53                   push ebx
// 005fe4b9  55                   push ebp
// 005fe4ba  8b6c2440             mov ebp, dword ptr [esp + 0x40]
// 005fe4be  56                   push esi
// 005fe4bf  55                   push ebp
// 005fe4c0  8bf1                 mov esi, ecx
// 005fe4c2  e8e9eafcff           call 0x5ccfb0
// 005fe4c7  8bd8                 mov ebx, eax
// 005fe4c9  85f6                 test esi, esi
// 005fe4cb  7506                 jne 0x5fe4d3
// 005fe4cd  ff15ace98900         call dword ptr [0x89e9ac]
// 005fe4d3  8b4618               mov eax, dword ptr [esi + 0x18]
// 005fe4d6  57                   push edi
// 005fe4d7  8b3e                 mov edi, dword ptr [esi]
// 005fe4d9  89442414             mov dword ptr [esp + 0x14], eax
// 005fe4dd  85ff                 test edi, edi
// 005fe4df  7404                 je 0x5fe4e5
// 005fe4e1  3bff                 cmp edi, edi
// 005fe4e3  7406                 je 0x5fe4eb
// 005fe4e5  ff15ace98900         call dword ptr [0x89e9ac]
// 005fe4eb  3b5c2414             cmp ebx, dword ptr [esp + 0x14]
// 005fe4ef  7412                 je 0x5fe503
// 005fe4f1  8d4b0c               lea ecx, [ebx + 0xc]
// 005fe4f4  51                   push ecx
// 005fe4f5  55                   push ebp
// 005fe4f6  ff15e0e48900         call dword ptr [0x89e4e0]
// 005fe4fc  83c408               add esp, 8
// 005fe4ff  84c0                 test al, al
// 005fe501  743f                 je 0x5fe542
// 005fe503  55                   push ebp
// 005fe504  8d4c241c             lea ecx, [esp + 0x1c]
// 005fe508  ff15b8e48900         call dword ptr [0x89e4b8]
// 005fe50e  33c0                 xor eax, eax
// 005fe510  89442434             mov dword ptr [esp + 0x34], eax
// 005fe514  8d542418             lea edx, [esp + 0x18]
// 005fe518  52                   push edx
// 005fe519  53                   push ebx
// 005fe51a  89442448             mov dword ptr [esp + 0x48], eax
// 005fe51e  57                   push edi
// 005fe51f  8d44241c             lea eax, [esp + 0x1c]
// 005fe523  50                   push eax
// 005fe524  8bce                 mov ecx, esi
// 005fe526  e815f4ffff           call 0x5fd940
// 005fe52b  8b38                 mov edi, dword ptr [eax]
// 005fe52d  8b5804               mov ebx, dword ptr [eax + 4]
// 005fe530  8d4c2418             lea ecx, [esp + 0x18]
// 005fe534  c7442440ffffffff     mov dword ptr [esp + 0x40], 0xffffffff
// 005fe53c  ff15c4e48900         call dword ptr [0x89e4c4]
// 005fe542  85ff                 test edi, edi
// 005fe544  7529                 jne 0x5fe56f
// 005fe546  ff15ace98900         call dword ptr [0x89e9ac]
// 005fe54c  3b5f18               cmp ebx, dword ptr [edi + 0x18]
// 005fe54f  5f                   pop edi
// 005fe550  7506                 jne 0x5fe558
// 005fe552  ff15ace98900         call dword ptr [0x89e9ac]
// 005fe558  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 005fe55c  5e                   pop esi
// 005fe55d  5d                   pop ebp
// 005fe55e  8d4328               lea eax, [ebx + 0x28]
// 005fe561  5b                   pop ebx
// 005fe562  64890d00000000       mov dword ptr fs:[0], ecx
// 005fe569  83c434               add esp, 0x34
// 005fe56c  c20400               ret 4
// 005fe56f  8b3f                 mov edi, dword ptr [edi]
// 005fe571  ebd9                 jmp 0x5fe54c
// standard library map_str<ptr> (function ??A?$map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@@std@@QAEAAPAUT@@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
