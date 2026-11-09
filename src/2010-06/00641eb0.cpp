// from server: 100% by auto
// roc 2010-06 00641eb0  unit: RBX::VInstance::?$NonFactoryProduct  size: 181 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00641eb0
//
// 00641eb0  51                   push ecx
// 00641eb1  8b442414             mov eax, dword ptr [esp + 0x14]
// 00641eb5  53                   push ebx
// 00641eb6  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 00641ebc  56                   push esi
// 00641ebd  57                   push edi
// 00641ebe  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00641ec2  8b7714               mov esi, dword ptr [edi + 0x14]
// 00641ec5  894c240c             mov dword ptr [esp + 0xc], ecx
// 00641ec9  8b0f                 mov ecx, dword ptr [edi]
// 00641ecb  85c0                 test eax, eax
// 00641ecd  7404                 je 0x641ed3
// 00641ecf  3bc1                 cmp eax, ecx
// 00641ed1  7406                 je 0x641ed9
// 00641ed3  ffd3                 call ebx
// 00641ed5  8b442420             mov eax, dword ptr [esp + 0x20]
// 00641ed9  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00641edd  3bce                 cmp ecx, esi
// 00641edf  7479                 je 0x641f5a
// 00641ee1  55                   push ebp
// 00641ee2  8be8                 mov ebp, eax
// 00641ee4  8bf1                 mov esi, ecx
// 00641ee6  85c0                 test eax, eax
// 00641ee8  7577                 jne 0x641f61
// 00641eea  ffd3                 call ebx
// 00641eec  8b442424             mov eax, dword ptr [esp + 0x24]
// 00641ef0  33c9                 xor ecx, ecx
// 00641ef2  3b7114               cmp esi, dword ptr [ecx + 0x14]
// 00641ef5  7506                 jne 0x641efd
// 00641ef7  ffd3                 call ebx
// 00641ef9  8b442424             mov eax, dword ptr [esp + 0x24]
// 00641efd  8b36                 mov esi, dword ptr [esi]
// 00641eff  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00641f03  397c2410             cmp dword ptr [esp + 0x10], edi
// 00641f07  7534                 jne 0x641f3d
// 00641f09  85c9                 test ecx, ecx
// 00641f0b  7404                 je 0x641f11
// 00641f0d  3bc8                 cmp ecx, eax
// 00641f0f  740a                 je 0x641f1b
// 00641f11  ffd3                 call ebx
// 00641f13  8b442424             mov eax, dword ptr [esp + 0x24]
// 00641f17  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00641f1b  8b542428             mov edx, dword ptr [esp + 0x28]
// 00641f1f  3954241c             cmp dword ptr [esp + 0x1c], edx
// 00641f23  7434                 je 0x641f59
// 00641f25  85c9                 test ecx, ecx
// 00641f27  7404                 je 0x641f2d
// 00641f29  3bcd                 cmp ecx, ebp
// 00641f2b  740a                 je 0x641f37
// 00641f2d  ffd3                 call ebx
// 00641f2f  8b442424             mov eax, dword ptr [esp + 0x24]
// 00641f33  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00641f37  3974241c             cmp dword ptr [esp + 0x1c], esi
// 00641f3b  741c                 je 0x641f59
// 00641f3d  8b542428             mov edx, dword ptr [esp + 0x28]
// 00641f41  6a00                 push 0
// 00641f43  6a01                 push 1
// 00641f45  56                   push esi
// 00641f46  55                   push ebp
// 00641f47  52                   push edx
// 00641f48  50                   push eax
// 00641f49  8b442434             mov eax, dword ptr [esp + 0x34]
// 00641f4d  57                   push edi
// 00641f4e  50                   push eax
// 00641f4f  51                   push ecx
// 00641f50  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 00641f54  e857fdffff           call 0x641cb0
// 00641f59  5d                   pop ebp
// 00641f5a  5f                   pop edi
// 00641f5b  5e                   pop esi
// 00641f5c  5b                   pop ebx
// 00641f5d  59                   pop ecx
// 00641f5e  c21400               ret 0x14
// 00641f61  8b08                 mov ecx, dword ptr [eax]
// 00641f63  eb8d                 jmp 0x641ef2
// standard library list<ptr> (function ?splice@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXV?$_Const_iterator@$00@12@AAV12@0@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
