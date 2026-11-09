// from server: 100% by auto
// roc 2008-06 004ddf10  unit: RBX::RenderBase::Mesh::Level  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004ddf10
//
// 004ddf10  83ec08               sub esp, 8
// 004ddf13  56                   push esi
// 004ddf14  8bf1                 mov esi, ecx
// 004ddf16  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004ddf19  57                   push edi
// 004ddf1a  85c9                 test ecx, ecx
// 004ddf1c  7504                 jne 0x4ddf22
// 004ddf1e  33c0                 xor eax, eax
// 004ddf20  eb07                 jmp 0x4ddf29
// 004ddf22  8b4614               mov eax, dword ptr [esi + 0x14]
// 004ddf25  2bc1                 sub eax, ecx
// 004ddf27  d1f8                 sar eax, 1
// 004ddf29  8b7e10               mov edi, dword ptr [esi + 0x10]
// 004ddf2c  8bd7                 mov edx, edi
// 004ddf2e  2bd1                 sub edx, ecx
// 004ddf30  d1fa                 sar edx, 1
// 004ddf32  3bd0                 cmp edx, eax
// 004ddf34  7318                 jae 0x4ddf4e
// 004ddf36  8b442414             mov eax, dword ptr [esp + 0x14]
// 004ddf3a  668b08               mov cx, word ptr [eax]
// 004ddf3d  66890f               mov word ptr [edi], cx
// 004ddf40  83c702               add edi, 2
// 004ddf43  897e10               mov dword ptr [esi + 0x10], edi
// 004ddf46  5f                   pop edi
// 004ddf47  5e                   pop esi
// 004ddf48  83c408               add esp, 8
// 004ddf4b  c20400               ret 4
// 004ddf4e  3bcf                 cmp ecx, edi
// 004ddf50  7606                 jbe 0x4ddf58
// 004ddf52  ff1590288000         call dword ptr [0x802890]
// 004ddf58  8b542414             mov edx, dword ptr [esp + 0x14]
// 004ddf5c  8b06                 mov eax, dword ptr [esi]
// 004ddf5e  52                   push edx
// 004ddf5f  57                   push edi
// 004ddf60  50                   push eax
// 004ddf61  8d442414             lea eax, [esp + 0x14]
// 004ddf65  50                   push eax
// 004ddf66  8bce                 mov ecx, esi
// 004ddf68  e873f9ffff           call 0x4dd8e0
// 004ddf6d  5f                   pop edi
// 004ddf6e  5e                   pop esi
// 004ddf6f  83c408               add esp, 8
// 004ddf72  c20400               ret 4
// standard library vector<short> (function ?push_back@?$vector@FV?$allocator@F@std@@@std@@QAEXABF@Z)

// stl: vector<short>
typedef short E;
#include <vector>
template class std::vector<E>;
