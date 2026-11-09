// from server: 100% by auto
// roc 2009-12 004bb480  unit: Ogre::RbxCullableSceneNode  size: 169 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004bb480
//
// 004bb480  83ec18               sub esp, 0x18
// 004bb483  53                   push ebx
// 004bb484  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 004bb488  56                   push esi
// 004bb489  8bf1                 mov esi, ecx
// 004bb48b  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004bb48e  57                   push edi
// 004bb48f  8b7e10               mov edi, dword ptr [esi + 0x10]
// 004bb492  8bc7                 mov eax, edi
// 004bb494  2bc1                 sub eax, ecx
// 004bb496  c1f802               sar eax, 2
// 004bb499  3bd8                 cmp ebx, eax
// 004bb49b  762f                 jbe 0x4bb4cc
// 004bb49d  3bcf                 cmp ecx, edi
// 004bb49f  7606                 jbe 0x4bb4a7
// 004bb4a1  ff1560b79800         call dword ptr [0x98b760]
// 004bb4a7  8b5610               mov edx, dword ptr [esi + 0x10]
// 004bb4aa  2b560c               sub edx, dword ptr [esi + 0xc]
// 004bb4ad  8b06                 mov eax, dword ptr [esi]
// 004bb4af  8d4c242c             lea ecx, [esp + 0x2c]
// 004bb4b3  51                   push ecx
// 004bb4b4  c1fa02               sar edx, 2
// 004bb4b7  2bda                 sub ebx, edx
// 004bb4b9  53                   push ebx
// 004bb4ba  57                   push edi
// 004bb4bb  50                   push eax
// 004bb4bc  8bce                 mov ecx, esi
// 004bb4be  e8ddc2fcff           call 0x4877a0
// 004bb4c3  5f                   pop edi
// 004bb4c4  5e                   pop esi
// 004bb4c5  5b                   pop ebx
// 004bb4c6  83c418               add esp, 0x18
// 004bb4c9  c20800               ret 8
// 004bb4cc  7352                 jae 0x4bb520
// 004bb4ce  3bcf                 cmp ecx, edi
// 004bb4d0  7606                 jbe 0x4bb4d8
// 004bb4d2  ff1560b79800         call dword ptr [0x98b760]
// 004bb4d8  8b06                 mov eax, dword ptr [esi]
// 004bb4da  55                   push ebp
// 004bb4db  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 004bb4de  89442418             mov dword ptr [esp + 0x18], eax
// 004bb4e2  3b6e10               cmp ebp, dword ptr [esi + 0x10]
// 004bb4e5  7606                 jbe 0x4bb4ed
// 004bb4e7  ff1560b79800         call dword ptr [0x98b760]
// 004bb4ed  8b0e                 mov ecx, dword ptr [esi]
// 004bb4ef  53                   push ebx
// 004bb4f0  8d542424             lea edx, [esp + 0x24]
// 004bb4f4  894c2414             mov dword ptr [esp + 0x14], ecx
// 004bb4f8  52                   push edx
// 004bb4f9  8d4c2418             lea ecx, [esp + 0x18]
// 004bb4fd  896c241c             mov dword ptr [esp + 0x1c], ebp
// 004bb501  e87a85f7ff           call 0x433a80
// 004bb506  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004bb50a  8b5004               mov edx, dword ptr [eax + 4]
// 004bb50d  8b00                 mov eax, dword ptr [eax]
// 004bb50f  57                   push edi
// 004bb510  51                   push ecx
// 004bb511  52                   push edx
// 004bb512  50                   push eax
// 004bb513  8d4c2428             lea ecx, [esp + 0x28]
// 004bb517  51                   push ecx
// 004bb518  8bce                 mov ecx, esi
// 004bb51a  e82137ffff           call 0x4aec40
// 004bb51f  5d                   pop ebp
// 004bb520  5f                   pop edi
// 004bb521  5e                   pop esi
// 004bb522  5b                   pop ebx
// 004bb523  83c418               add esp, 0x18
// 004bb526  c20800               ret 8
// standard library vector<ptr> (function ?resize@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXIPAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
