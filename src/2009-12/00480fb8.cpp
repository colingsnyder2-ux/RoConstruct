// roc 2009-12 00480fb8  unit: RBX::AdornRbxGfx  size: 232 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00480fb8
//
// 00480fb8  6a00                 push 0
// 00480fba  6a00                 push 0
// 00480fbc  e8b7383700           call 0x7f4878
// 00480fc1  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00480fc4  8bcb                 mov ecx, ebx
// 00480fc6  2bc8                 sub ecx, eax
// 00480fc8  c1f903               sar ecx, 3
// 00480fcb  3bcf                 cmp ecx, edi
// 00480fcd  7374                 jae 0x481043
// 00480fcf  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 00480fd2  8b11                 mov edx, dword ptr [ecx]
// 00480fd4  8b4904               mov ecx, dword ptr [ecx + 4]
// 00480fd7  894dec               mov dword ptr [ebp - 0x14], ecx
// 00480fda  8d0cfd00000000       lea ecx, [edi*8]
// 00480fe1  894d14               mov dword ptr [ebp + 0x14], ecx
// 00480fe4  03c8                 add ecx, eax
// 00480fe6  51                   push ecx
// 00480fe7  53                   push ebx
// 00480fe8  50                   push eax
// 00480fe9  8bce                 mov ecx, esi
// 00480feb  8955e8               mov dword ptr [ebp - 0x18], edx
// 00480fee  e80dc70f00           call 0x57d700
// 00480ff3  8b4610               mov eax, dword ptr [esi + 0x10]
// 00480ff6  8bc8                 mov ecx, eax
// 00480ff8  2b4d0c               sub ecx, dword ptr [ebp + 0xc]
// 00480ffb  8d55e8               lea edx, [ebp - 0x18]
// 00480ffe  c1f903               sar ecx, 3
// 00481001  52                   push edx
// 00481002  2bf9                 sub edi, ecx
// 00481004  57                   push edi
// 00481005  50                   push eax
// 00481006  8bce                 mov ecx, esi
// 00481008  c745fc02000000       mov dword ptr [ebp - 4], 2
// 0048100f  e81cf6ffff           call 0x480630
// 00481014  8b4514               mov eax, dword ptr [ebp + 0x14]
// 00481017  014610               add dword ptr [esi + 0x10], eax
// 0048101a  8b7610               mov esi, dword ptr [esi + 0x10]
// 0048101d  8d55e8               lea edx, [ebp - 0x18]
// 00481020  52                   push edx
// 00481021  2bf0                 sub esi, eax
// 00481023  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00481026  56                   push esi
// 00481027  50                   push eax
// 00481028  e8b3b22f00           call 0x77c2e0
// 0048102d  83c40c               add esp, 0xc
// 00481030  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00481033  64890d00000000       mov dword ptr fs:[0], ecx
// 0048103a  5f                   pop edi
// 0048103b  5e                   pop esi
// 0048103c  5b                   pop ebx
// 0048103d  8be5                 mov esp, ebp
// 0048103f  5d                   pop ebp
// 00481040  c21000               ret 0x10
// 00481043  8b4514               mov eax, dword ptr [ebp + 0x14]
// 00481046  8b08                 mov ecx, dword ptr [eax]
// 00481048  8b5004               mov edx, dword ptr [eax + 4]
// 0048104b  8d04fd00000000       lea eax, [edi*8]
// 00481052  53                   push ebx
// 00481053  8bfb                 mov edi, ebx
// 00481055  2bf8                 sub edi, eax
// 00481057  53                   push ebx
// 00481058  894de8               mov dword ptr [ebp - 0x18], ecx
// 0048105b  57                   push edi
// 0048105c  8bce                 mov ecx, esi
// 0048105e  8955ec               mov dword ptr [ebp - 0x14], edx
// 00481061  894514               mov dword ptr [ebp + 0x14], eax
// 00481064  e897c60f00           call 0x57d700
// 00481069  53                   push ebx
// 0048106a  894610               mov dword ptr [esi + 0x10], eax
// 0048106d  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00481070  57                   push edi
// 00481071  50                   push eax
// 00481072  e859b50f00           call 0x57c5d0
// 00481077  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0048107a  8b5514               mov edx, dword ptr [ebp + 0x14]
// 0048107d  8d4de8               lea ecx, [ebp - 0x18]
// 00481080  51                   push ecx
// 00481081  03d0                 add edx, eax
// 00481083  52                   push edx
// 00481084  50                   push eax
// 00481085  e856b22f00           call 0x77c2e0
// 0048108a  83c418               add esp, 0x18
// 0048108d  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00481090  5f                   pop edi
// 00481091  5e                   pop esi
// 00481092  64890d00000000       mov dword ptr fs:[0], ecx
// 00481099  5b                   pop ebx
// 0048109a  8be5                 mov esp, ebp
// 0048109c  5d                   pop ebp
// 0048109d  c21000               ret 0x10
// standard library vector<pod8> (function __catch$?_Insert_n@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEXV?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@IABUE@@@Z$2)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
