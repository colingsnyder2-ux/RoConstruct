// from server: 100% by auto
// roc 2008-06 00516330  unit: G3D::BinaryInput  size: 167 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00516330
//
// 00516330  83ec18               sub esp, 0x18
// 00516333  53                   push ebx
// 00516334  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 00516338  56                   push esi
// 00516339  8bf1                 mov esi, ecx
// 0051633b  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0051633e  57                   push edi
// 0051633f  8b7e10               mov edi, dword ptr [esi + 0x10]
// 00516342  8bc7                 mov eax, edi
// 00516344  2bc1                 sub eax, ecx
// 00516346  d1f8                 sar eax, 1
// 00516348  3bd8                 cmp ebx, eax
// 0051634a  762e                 jbe 0x51637a
// 0051634c  3bcf                 cmp ecx, edi
// 0051634e  7606                 jbe 0x516356
// 00516350  ff1590288000         call dword ptr [0x802890]
// 00516356  8b5610               mov edx, dword ptr [esi + 0x10]
// 00516359  2b560c               sub edx, dword ptr [esi + 0xc]
// 0051635c  8b06                 mov eax, dword ptr [esi]
// 0051635e  8d4c242c             lea ecx, [esp + 0x2c]
// 00516362  51                   push ecx
// 00516363  d1fa                 sar edx, 1
// 00516365  2bda                 sub ebx, edx
// 00516367  53                   push ebx
// 00516368  57                   push edi
// 00516369  50                   push eax
// 0051636a  8bce                 mov ecx, esi
// 0051636c  e80f71fcff           call 0x4dd480
// 00516371  5f                   pop edi
// 00516372  5e                   pop esi
// 00516373  5b                   pop ebx
// 00516374  83c418               add esp, 0x18
// 00516377  c20800               ret 8
// 0051637a  7352                 jae 0x5163ce
// 0051637c  3bcf                 cmp ecx, edi
// 0051637e  7606                 jbe 0x516386
// 00516380  ff1590288000         call dword ptr [0x802890]
// 00516386  8b06                 mov eax, dword ptr [esi]
// 00516388  55                   push ebp
// 00516389  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 0051638c  89442418             mov dword ptr [esp + 0x18], eax
// 00516390  3b6e10               cmp ebp, dword ptr [esi + 0x10]
// 00516393  7606                 jbe 0x51639b
// 00516395  ff1590288000         call dword ptr [0x802890]
// 0051639b  8b0e                 mov ecx, dword ptr [esi]
// 0051639d  53                   push ebx
// 0051639e  8d542424             lea edx, [esp + 0x24]
// 005163a2  894c2414             mov dword ptr [esp + 0x14], ecx
// 005163a6  52                   push edx
// 005163a7  8d4c2418             lea ecx, [esp + 0x18]
// 005163ab  896c241c             mov dword ptr [esp + 0x1c], ebp
// 005163af  e8ac65fcff           call 0x4dc960
// 005163b4  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 005163b8  8b5004               mov edx, dword ptr [eax + 4]
// 005163bb  8b00                 mov eax, dword ptr [eax]
// 005163bd  57                   push edi
// 005163be  51                   push ecx
// 005163bf  52                   push edx
// 005163c0  50                   push eax
// 005163c1  8d4c2428             lea ecx, [esp + 0x28]
// 005163c5  51                   push ecx
// 005163c6  8bce                 mov ecx, esi
// 005163c8  e873fcffff           call 0x516040
// 005163cd  5d                   pop ebp
// 005163ce  5f                   pop edi
// 005163cf  5e                   pop esi
// 005163d0  5b                   pop ebx
// 005163d1  83c418               add esp, 0x18
// 005163d4  c20800               ret 8
// standard library vector<short> (function ?resize@?$vector@FV?$allocator@F@std@@@std@@QAEXIF@Z)

// stl: vector<short>
typedef short E;
#include <vector>
template class std::vector<E>;
