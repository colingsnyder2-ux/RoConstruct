// from server: 100% by auto
// roc 2009-12 00491000  unit: Ogre::RbxEntity  size: 219 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00491000
//
// 00491000  55                   push ebp
// 00491001  8bec                 mov ebp, esp
// 00491003  6aff                 push -1
// 00491005  6830009300           push 0x930030
// 0049100a  64a100000000         mov eax, dword ptr fs:[0]
// 00491010  50                   push eax
// 00491011  64892500000000       mov dword ptr fs:[0], esp
// 00491018  83ec10               sub esp, 0x10
// 0049101b  8b5508               mov edx, dword ptr [ebp + 8]
// 0049101e  53                   push ebx
// 0049101f  56                   push esi
// 00491020  57                   push edi
// 00491021  8965f0               mov dword ptr [ebp - 0x10], esp
// 00491024  8bf1                 mov esi, ecx
// 00491026  81faffffff1f         cmp edx, 0x1fffffff
// 0049102c  7605                 jbe 0x491033
// 0049102e  e82d11fbff           call 0x442160
// 00491033  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00491036  85c9                 test ecx, ecx
// 00491038  7504                 jne 0x49103e
// 0049103a  33c0                 xor eax, eax
// 0049103c  eb08                 jmp 0x491046
// 0049103e  8b4614               mov eax, dword ptr [esi + 0x14]
// 00491041  2bc1                 sub eax, ecx
// 00491043  c1f803               sar eax, 3
// 00491046  3bc2                 cmp eax, edx
// 00491048  737e                 jae 0x4910c8
// 0049104a  6a00                 push 0
// 0049104c  52                   push edx
// 0049104d  e87eaa0e00           call 0x57bad0
// 00491052  8bd8                 mov ebx, eax
// 00491054  8b4610               mov eax, dword ptr [esi + 0x10]
// 00491057  83c408               add esp, 8
// 0049105a  895de4               mov dword ptr [ebp - 0x1c], ebx
// 0049105d  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00491064  8945e8               mov dword ptr [ebp - 0x18], eax
// 00491067  39460c               cmp dword ptr [esi + 0xc], eax
// 0049106a  7606                 jbe 0x491072
// 0049106c  ff1560b79800         call dword ptr [0x98b760]
// 00491072  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00491075  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 00491078  7606                 jbe 0x491080
// 0049107a  ff1560b79800         call dword ptr [0x98b760]
// 00491080  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00491083  c645ec00             mov byte ptr [ebp - 0x14], 0
// 00491087  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 0049108a  50                   push eax
// 0049108b  8b45e8               mov eax, dword ptr [ebp - 0x18]
// 0049108e  51                   push ecx
// 0049108f  8d5608               lea edx, [esi + 8]
// 00491092  52                   push edx
// 00491093  53                   push ebx
// 00491094  50                   push eax
// 00491095  57                   push edi
// 00491096  e8859c0100           call 0x4aad20
// 0049109b  8b460c               mov eax, dword ptr [esi + 0xc]
// 0049109e  8b7e10               mov edi, dword ptr [esi + 0x10]
// 004910a1  2bf8                 sub edi, eax
// 004910a3  83c418               add esp, 0x18
// 004910a6  c1ff03               sar edi, 3
// 004910a9  85c0                 test eax, eax
// 004910ab  7409                 je 0x4910b6
// 004910ad  50                   push eax
// 004910ae  e8a7273600           call 0x7f385a
// 004910b3  83c404               add esp, 4
// 004910b6  8b4d08               mov ecx, dword ptr [ebp + 8]
// 004910b9  8d14cb               lea edx, [ebx + ecx*8]
// 004910bc  8d04fb               lea eax, [ebx + edi*8]
// 004910bf  895614               mov dword ptr [esi + 0x14], edx
// 004910c2  894610               mov dword ptr [esi + 0x10], eax
// 004910c5  895e0c               mov dword ptr [esi + 0xc], ebx
// 004910c8  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004910cb  5f                   pop edi
// 004910cc  5e                   pop esi
// 004910cd  64890d00000000       mov dword ptr fs:[0], ecx
// 004910d4  5b                   pop ebx
// 004910d5  8be5                 mov esp, ebp
// 004910d7  5d                   pop ebp
// 004910d8  c20400               ret 4
// standard library vector<pod8> (function ?reserve@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXI@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
