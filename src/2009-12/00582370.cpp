// from server: 100% by auto
// roc 2009-12 00582370  unit: Ogre::RbxSceneUpdater  size: 181 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00582370
//
// 00582370  51                   push ecx
// 00582371  8b442414             mov eax, dword ptr [esp + 0x14]
// 00582375  53                   push ebx
// 00582376  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 0058237c  56                   push esi
// 0058237d  57                   push edi
// 0058237e  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00582382  8b7714               mov esi, dword ptr [edi + 0x14]
// 00582385  894c240c             mov dword ptr [esp + 0xc], ecx
// 00582389  8b0f                 mov ecx, dword ptr [edi]
// 0058238b  85c0                 test eax, eax
// 0058238d  7404                 je 0x582393
// 0058238f  3bc1                 cmp eax, ecx
// 00582391  7406                 je 0x582399
// 00582393  ffd3                 call ebx
// 00582395  8b442420             mov eax, dword ptr [esp + 0x20]
// 00582399  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0058239d  3bce                 cmp ecx, esi
// 0058239f  7479                 je 0x58241a
// 005823a1  55                   push ebp
// 005823a2  8be8                 mov ebp, eax
// 005823a4  8bf1                 mov esi, ecx
// 005823a6  85c0                 test eax, eax
// 005823a8  7577                 jne 0x582421
// 005823aa  ffd3                 call ebx
// 005823ac  8b442424             mov eax, dword ptr [esp + 0x24]
// 005823b0  33c9                 xor ecx, ecx
// 005823b2  3b7114               cmp esi, dword ptr [ecx + 0x14]
// 005823b5  7506                 jne 0x5823bd
// 005823b7  ffd3                 call ebx
// 005823b9  8b442424             mov eax, dword ptr [esp + 0x24]
// 005823bd  8b36                 mov esi, dword ptr [esi]
// 005823bf  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005823c3  397c2410             cmp dword ptr [esp + 0x10], edi
// 005823c7  7534                 jne 0x5823fd
// 005823c9  85c9                 test ecx, ecx
// 005823cb  7404                 je 0x5823d1
// 005823cd  3bc8                 cmp ecx, eax
// 005823cf  740a                 je 0x5823db
// 005823d1  ffd3                 call ebx
// 005823d3  8b442424             mov eax, dword ptr [esp + 0x24]
// 005823d7  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005823db  8b542428             mov edx, dword ptr [esp + 0x28]
// 005823df  3954241c             cmp dword ptr [esp + 0x1c], edx
// 005823e3  7434                 je 0x582419
// 005823e5  85c9                 test ecx, ecx
// 005823e7  7404                 je 0x5823ed
// 005823e9  3bcd                 cmp ecx, ebp
// 005823eb  740a                 je 0x5823f7
// 005823ed  ffd3                 call ebx
// 005823ef  8b442424             mov eax, dword ptr [esp + 0x24]
// 005823f3  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005823f7  3974241c             cmp dword ptr [esp + 0x1c], esi
// 005823fb  741c                 je 0x582419
// 005823fd  8b542428             mov edx, dword ptr [esp + 0x28]
// 00582401  6a00                 push 0
// 00582403  6a01                 push 1
// 00582405  56                   push esi
// 00582406  55                   push ebp
// 00582407  52                   push edx
// 00582408  50                   push eax
// 00582409  8b442434             mov eax, dword ptr [esp + 0x34]
// 0058240d  57                   push edi
// 0058240e  50                   push eax
// 0058240f  51                   push ecx
// 00582410  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 00582414  e8e7feffff           call 0x582300
// 00582419  5d                   pop ebp
// 0058241a  5f                   pop edi
// 0058241b  5e                   pop esi
// 0058241c  5b                   pop ebx
// 0058241d  59                   pop ecx
// 0058241e  c21400               ret 0x14
// 00582421  8b08                 mov ecx, dword ptr [eax]
// 00582423  eb8d                 jmp 0x5823b2
// standard library list<ptr> (function ?splice@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXV?$_Const_iterator@$00@12@AAV12@0@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
