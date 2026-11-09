// from server: 100% by auto
// roc 2009-12 006ae5f0  unit: RBX::Accoutrement  size: 169 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006ae5f0
//
// 006ae5f0  83ec18               sub esp, 0x18
// 006ae5f3  53                   push ebx
// 006ae5f4  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 006ae5f8  56                   push esi
// 006ae5f9  8bf1                 mov esi, ecx
// 006ae5fb  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 006ae5fe  57                   push edi
// 006ae5ff  8b7e10               mov edi, dword ptr [esi + 0x10]
// 006ae602  8bc7                 mov eax, edi
// 006ae604  2bc1                 sub eax, ecx
// 006ae606  c1f802               sar eax, 2
// 006ae609  3bd8                 cmp ebx, eax
// 006ae60b  762f                 jbe 0x6ae63c
// 006ae60d  3bcf                 cmp ecx, edi
// 006ae60f  7606                 jbe 0x6ae617
// 006ae611  ff1560b79800         call dword ptr [0x98b760]
// 006ae617  8b5610               mov edx, dword ptr [esi + 0x10]
// 006ae61a  2b560c               sub edx, dword ptr [esi + 0xc]
// 006ae61d  8b06                 mov eax, dword ptr [esi]
// 006ae61f  8d4c242c             lea ecx, [esp + 0x2c]
// 006ae623  51                   push ecx
// 006ae624  c1fa02               sar edx, 2
// 006ae627  2bda                 sub ebx, edx
// 006ae629  53                   push ebx
// 006ae62a  57                   push edi
// 006ae62b  50                   push eax
// 006ae62c  8bce                 mov ecx, esi
// 006ae62e  e8bde5e4ff           call 0x4fcbf0
// 006ae633  5f                   pop edi
// 006ae634  5e                   pop esi
// 006ae635  5b                   pop ebx
// 006ae636  83c418               add esp, 0x18
// 006ae639  c20800               ret 8
// 006ae63c  7352                 jae 0x6ae690
// 006ae63e  3bcf                 cmp ecx, edi
// 006ae640  7606                 jbe 0x6ae648
// 006ae642  ff1560b79800         call dword ptr [0x98b760]
// 006ae648  8b06                 mov eax, dword ptr [esi]
// 006ae64a  55                   push ebp
// 006ae64b  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 006ae64e  89442418             mov dword ptr [esp + 0x18], eax
// 006ae652  3b6e10               cmp ebp, dword ptr [esi + 0x10]
// 006ae655  7606                 jbe 0x6ae65d
// 006ae657  ff1560b79800         call dword ptr [0x98b760]
// 006ae65d  8b0e                 mov ecx, dword ptr [esi]
// 006ae65f  53                   push ebx
// 006ae660  8d542424             lea edx, [esp + 0x24]
// 006ae664  894c2414             mov dword ptr [esp + 0x14], ecx
// 006ae668  52                   push edx
// 006ae669  8d4c2418             lea ecx, [esp + 0x18]
// 006ae66d  896c241c             mov dword ptr [esp + 0x1c], ebp
// 006ae671  e80a54d8ff           call 0x433a80
// 006ae676  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 006ae67a  8b5004               mov edx, dword ptr [eax + 4]
// 006ae67d  8b00                 mov eax, dword ptr [eax]
// 006ae67f  57                   push edi
// 006ae680  51                   push ecx
// 006ae681  52                   push edx
// 006ae682  50                   push eax
// 006ae683  8d4c2428             lea ecx, [esp + 0x28]
// 006ae687  51                   push ecx
// 006ae688  8bce                 mov ecx, esi
// 006ae68a  e831f8ffff           call 0x6adec0
// 006ae68f  5d                   pop ebp
// 006ae690  5f                   pop edi
// 006ae691  5e                   pop esi
// 006ae692  5b                   pop ebx
// 006ae693  83c418               add esp, 0x18
// 006ae696  c20800               ret 8
// standard library vector<ptr> (function ?resize@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXIPAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
