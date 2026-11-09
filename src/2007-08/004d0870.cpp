// from server: 100% by auto
// roc 2007-08 004d0870  unit: RBX::View::PartChunk  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004d0870
//
// 004d0870  56                   push esi
// 004d0871  8bf1                 mov esi, ecx
// 004d0873  833e00               cmp dword ptr [esi], 0
// 004d0876  57                   push edi
// 004d0877  8b3dd8e67700         mov edi, dword ptr [0x77e6d8]
// 004d087d  7502                 jne 0x4d0881
// 004d087f  ffd7                 call edi
// 004d0881  8b4604               mov eax, dword ptr [esi + 4]
// 004d0884  80782100             cmp byte ptr [eax + 0x21], 0
// 004d0888  7405                 je 0x4d088f
// 004d088a  ffd7                 call edi
// 004d088c  5f                   pop edi
// 004d088d  5e                   pop esi
// 004d088e  c3                   ret 
// 004d088f  8b4808               mov ecx, dword ptr [eax + 8]
// 004d0892  80792100             cmp byte ptr [ecx + 0x21], 0
// 004d0896  7518                 jne 0x4d08b0
// 004d0898  8b01                 mov eax, dword ptr [ecx]
// 004d089a  80782100             cmp byte ptr [eax + 0x21], 0
// 004d089e  750a                 jne 0x4d08aa
// 004d08a0  8bc8                 mov ecx, eax
// 004d08a2  8b01                 mov eax, dword ptr [ecx]
// 004d08a4  80782100             cmp byte ptr [eax + 0x21], 0
// 004d08a8  74f6                 je 0x4d08a0
// 004d08aa  5f                   pop edi
// 004d08ab  894e04               mov dword ptr [esi + 4], ecx
// 004d08ae  5e                   pop esi
// 004d08af  c3                   ret 
// 004d08b0  8b4004               mov eax, dword ptr [eax + 4]
// 004d08b3  80782100             cmp byte ptr [eax + 0x21], 0
// 004d08b7  751d                 jne 0x4d08d6
// 004d08b9  8da42400000000       lea esp, [esp]
// 004d08c0  8b4e04               mov ecx, dword ptr [esi + 4]
// 004d08c3  3b4808               cmp ecx, dword ptr [eax + 8]
// 004d08c6  750e                 jne 0x4d08d6
// 004d08c8  894604               mov dword ptr [esi + 4], eax
// 004d08cb  8bd0                 mov edx, eax
// 004d08cd  8b4204               mov eax, dword ptr [edx + 4]
// 004d08d0  80782100             cmp byte ptr [eax + 0x21], 0
// 004d08d4  74ea                 je 0x4d08c0
// 004d08d6  5f                   pop edi
// 004d08d7  894604               mov dword ptr [esi + 4], eax
// 004d08da  5e                   pop esi
// 004d08db  c3                   ret 
// standard library set<pod20> (function ?_Inc@const_iterator@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
