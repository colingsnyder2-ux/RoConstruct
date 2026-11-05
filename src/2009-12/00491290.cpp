// from server: 100% by auto
// roc 2009-12 00491290  unit: Ogre::RbxEntity  size: 163 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00491290
//
// 00491290  83ec18               sub esp, 0x18
// 00491293  53                   push ebx
// 00491294  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 00491298  56                   push esi
// 00491299  8bf1                 mov esi, ecx
// 0049129b  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0049129e  57                   push edi
// 0049129f  8b7e10               mov edi, dword ptr [esi + 0x10]
// 004912a2  8bc7                 mov eax, edi
// 004912a4  2bc1                 sub eax, ecx
// 004912a6  3bd8                 cmp ebx, eax
// 004912a8  762c                 jbe 0x4912d6
// 004912aa  3bcf                 cmp ecx, edi
// 004912ac  7606                 jbe 0x4912b4
// 004912ae  ff1560b79800         call dword ptr [0x98b760]
// 004912b4  8b560c               mov edx, dword ptr [esi + 0xc]
// 004912b7  2b5610               sub edx, dword ptr [esi + 0x10]
// 004912ba  8b06                 mov eax, dword ptr [esi]
// 004912bc  8d4c242c             lea ecx, [esp + 0x2c]
// 004912c0  51                   push ecx
// 004912c1  03d3                 add edx, ebx
// 004912c3  52                   push edx
// 004912c4  57                   push edi
// 004912c5  50                   push eax
// 004912c6  8bce                 mov ecx, esi
// 004912c8  e833feffff           call 0x491100
// 004912cd  5f                   pop edi
// 004912ce  5e                   pop esi
// 004912cf  5b                   pop ebx
// 004912d0  83c418               add esp, 0x18
// 004912d3  c20800               ret 8
// 004912d6  7352                 jae 0x49132a
// 004912d8  3bcf                 cmp ecx, edi
// 004912da  7606                 jbe 0x4912e2
// 004912dc  ff1560b79800         call dword ptr [0x98b760]
// 004912e2  8b06                 mov eax, dword ptr [esi]
// 004912e4  55                   push ebp
// 004912e5  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 004912e8  89442418             mov dword ptr [esp + 0x18], eax
// 004912ec  3b6e10               cmp ebp, dword ptr [esi + 0x10]
// 004912ef  7606                 jbe 0x4912f7
// 004912f1  ff1560b79800         call dword ptr [0x98b760]
// 004912f7  8b0e                 mov ecx, dword ptr [esi]
// 004912f9  53                   push ebx
// 004912fa  8d542424             lea edx, [esp + 0x24]
// 004912fe  894c2414             mov dword ptr [esp + 0x14], ecx
// 00491302  52                   push edx
// 00491303  8d4c2418             lea ecx, [esp + 0x18]
// 00491307  896c241c             mov dword ptr [esp + 0x1c], ebp
// 0049130b  e830f7ffff           call 0x490a40
// 00491310  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00491314  8b5004               mov edx, dword ptr [eax + 4]
// 00491317  8b00                 mov eax, dword ptr [eax]
// 00491319  57                   push edi
// 0049131a  51                   push ecx
// 0049131b  52                   push edx
// 0049131c  50                   push eax
// 0049131d  8d4c2428             lea ecx, [esp + 0x28]
// 00491321  51                   push ecx
// 00491322  8bce                 mov ecx, esi
// 00491324  e8f7fbffff           call 0x490f20
// 00491329  5d                   pop ebp
// 0049132a  5f                   pop edi
// 0049132b  5e                   pop esi
// 0049132c  5b                   pop ebx
// 0049132d  83c418               add esp, 0x18
// 00491330  c20800               ret 8
// standard library vector<char> (function ?resize@?$vector@DV?$allocator@D@std@@@std@@QAEXID@Z)

// stl: vector<char>
typedef char E;
#include <vector>
template class std::vector<E>;
