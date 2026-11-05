// from server: 100% by auto
// roc 2009-06 004784b0  unit: Ogre::RbxMeshLoader  size: 181 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004784b0
//
// 004784b0  51                   push ecx
// 004784b1  8b442414             mov eax, dword ptr [esp + 0x14]
// 004784b5  53                   push ebx
// 004784b6  8b1dace98900         mov ebx, dword ptr [0x89e9ac]
// 004784bc  56                   push esi
// 004784bd  57                   push edi
// 004784be  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 004784c2  8b7714               mov esi, dword ptr [edi + 0x14]
// 004784c5  894c240c             mov dword ptr [esp + 0xc], ecx
// 004784c9  8b0f                 mov ecx, dword ptr [edi]
// 004784cb  85c0                 test eax, eax
// 004784cd  7404                 je 0x4784d3
// 004784cf  3bc1                 cmp eax, ecx
// 004784d1  7406                 je 0x4784d9
// 004784d3  ffd3                 call ebx
// 004784d5  8b442420             mov eax, dword ptr [esp + 0x20]
// 004784d9  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004784dd  3bce                 cmp ecx, esi
// 004784df  7479                 je 0x47855a
// 004784e1  55                   push ebp
// 004784e2  8be8                 mov ebp, eax
// 004784e4  8bf1                 mov esi, ecx
// 004784e6  85c0                 test eax, eax
// 004784e8  7577                 jne 0x478561
// 004784ea  ffd3                 call ebx
// 004784ec  8b442424             mov eax, dword ptr [esp + 0x24]
// 004784f0  33c9                 xor ecx, ecx
// 004784f2  3b7114               cmp esi, dword ptr [ecx + 0x14]
// 004784f5  7506                 jne 0x4784fd
// 004784f7  ffd3                 call ebx
// 004784f9  8b442424             mov eax, dword ptr [esp + 0x24]
// 004784fd  8b36                 mov esi, dword ptr [esi]
// 004784ff  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00478503  397c2410             cmp dword ptr [esp + 0x10], edi
// 00478507  7534                 jne 0x47853d
// 00478509  85c9                 test ecx, ecx
// 0047850b  7404                 je 0x478511
// 0047850d  3bc8                 cmp ecx, eax
// 0047850f  740a                 je 0x47851b
// 00478511  ffd3                 call ebx
// 00478513  8b442424             mov eax, dword ptr [esp + 0x24]
// 00478517  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0047851b  8b542428             mov edx, dword ptr [esp + 0x28]
// 0047851f  3954241c             cmp dword ptr [esp + 0x1c], edx
// 00478523  7434                 je 0x478559
// 00478525  85c9                 test ecx, ecx
// 00478527  7404                 je 0x47852d
// 00478529  3bcd                 cmp ecx, ebp
// 0047852b  740a                 je 0x478537
// 0047852d  ffd3                 call ebx
// 0047852f  8b442424             mov eax, dword ptr [esp + 0x24]
// 00478533  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00478537  3974241c             cmp dword ptr [esp + 0x1c], esi
// 0047853b  741c                 je 0x478559
// 0047853d  8b542428             mov edx, dword ptr [esp + 0x28]
// 00478541  6a00                 push 0
// 00478543  6a01                 push 1
// 00478545  56                   push esi
// 00478546  55                   push ebp
// 00478547  52                   push edx
// 00478548  50                   push eax
// 00478549  8b442434             mov eax, dword ptr [esp + 0x34]
// 0047854d  57                   push edi
// 0047854e  50                   push eax
// 0047854f  51                   push ecx
// 00478550  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 00478554  e857feffff           call 0x4783b0
// 00478559  5d                   pop ebp
// 0047855a  5f                   pop edi
// 0047855b  5e                   pop esi
// 0047855c  5b                   pop ebx
// 0047855d  59                   pop ecx
// 0047855e  c21400               ret 0x14
// 00478561  8b08                 mov ecx, dword ptr [eax]
// 00478563  eb8d                 jmp 0x4784f2
// standard library list<ptr> (function ?splice@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXV?$_Const_iterator@$00@12@AAV12@0@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
