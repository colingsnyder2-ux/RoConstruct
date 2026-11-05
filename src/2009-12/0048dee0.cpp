// from server: 100% by auto
// roc 2009-12 0048dee0  unit: Ogre::VertexStreamer  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0048dee0
//
// 0048dee0  83ec08               sub esp, 8
// 0048dee3  56                   push esi
// 0048dee4  8bf1                 mov esi, ecx
// 0048dee6  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0048dee9  57                   push edi
// 0048deea  85c9                 test ecx, ecx
// 0048deec  7504                 jne 0x48def2
// 0048deee  33c0                 xor eax, eax
// 0048def0  eb08                 jmp 0x48defa
// 0048def2  8b4614               mov eax, dword ptr [esi + 0x14]
// 0048def5  2bc1                 sub eax, ecx
// 0048def7  c1f804               sar eax, 4
// 0048defa  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0048defd  8bd7                 mov edx, edi
// 0048deff  2bd1                 sub edx, ecx
// 0048df01  c1fa04               sar edx, 4
// 0048df04  3bd0                 cmp edx, eax
// 0048df06  7331                 jae 0x48df39
// 0048df08  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0048df0c  c644240800           mov byte ptr [esp + 8], 0
// 0048df11  8b442408             mov eax, dword ptr [esp + 8]
// 0048df15  50                   push eax
// 0048df16  8b442418             mov eax, dword ptr [esp + 0x18]
// 0048df1a  51                   push ecx
// 0048df1b  8d5608               lea edx, [esi + 8]
// 0048df1e  52                   push edx
// 0048df1f  50                   push eax
// 0048df20  6a01                 push 1
// 0048df22  57                   push edi
// 0048df23  e808eaffff           call 0x48c930
// 0048df28  83c418               add esp, 0x18
// 0048df2b  83c710               add edi, 0x10
// 0048df2e  897e10               mov dword ptr [esi + 0x10], edi
// 0048df31  5f                   pop edi
// 0048df32  5e                   pop esi
// 0048df33  83c408               add esp, 8
// 0048df36  c20400               ret 4
// 0048df39  3bcf                 cmp ecx, edi
// 0048df3b  7606                 jbe 0x48df43
// 0048df3d  ff1560b79800         call dword ptr [0x98b760]
// 0048df43  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0048df47  8b06                 mov eax, dword ptr [esi]
// 0048df49  51                   push ecx
// 0048df4a  57                   push edi
// 0048df4b  50                   push eax
// 0048df4c  8d542414             lea edx, [esp + 0x14]
// 0048df50  52                   push edx
// 0048df51  8bce                 mov ecx, esi
// 0048df53  e8a8fcffff           call 0x48dc00
// 0048df58  5f                   pop edi
// 0048df59  5e                   pop esi
// 0048df5a  83c408               add esp, 8
// 0048df5d  c20400               ret 4
// standard library vector<pod16> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
