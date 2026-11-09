// from server: 100% by auto
// roc 2010-06 0075b560  unit: RBX::ParallelRampPoly  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0075b560
//
// 0075b560  56                   push esi
// 0075b561  8bf1                 mov esi, ecx
// 0075b563  833e00               cmp dword ptr [esi], 0
// 0075b566  57                   push edi
// 0075b567  8b3d0ca99e00         mov edi, dword ptr [0x9ea90c]
// 0075b56d  7502                 jne 0x75b571
// 0075b56f  ffd7                 call edi
// 0075b571  8b4604               mov eax, dword ptr [esi + 4]
// 0075b574  80781d00             cmp byte ptr [eax + 0x1d], 0
// 0075b578  7411                 je 0x75b58b
// 0075b57a  8b4008               mov eax, dword ptr [eax + 8]
// 0075b57d  894604               mov dword ptr [esi + 4], eax
// 0075b580  80781d00             cmp byte ptr [eax + 0x1d], 0
// 0075b584  745b                 je 0x75b5e1
// 0075b586  ffd7                 call edi
// 0075b588  5f                   pop edi
// 0075b589  5e                   pop esi
// 0075b58a  c3                   ret 
// 0075b58b  8b08                 mov ecx, dword ptr [eax]
// 0075b58d  80791d00             cmp byte ptr [ecx + 0x1d], 0
// 0075b591  751e                 jne 0x75b5b1
// 0075b593  8b4108               mov eax, dword ptr [ecx + 8]
// 0075b596  80781d00             cmp byte ptr [eax + 0x1d], 0
// 0075b59a  750f                 jne 0x75b5ab
// 0075b59c  8d642400             lea esp, [esp]
// 0075b5a0  8bc8                 mov ecx, eax
// 0075b5a2  8b4108               mov eax, dword ptr [ecx + 8]
// 0075b5a5  80781d00             cmp byte ptr [eax + 0x1d], 0
// 0075b5a9  74f5                 je 0x75b5a0
// 0075b5ab  5f                   pop edi
// 0075b5ac  894e04               mov dword ptr [esi + 4], ecx
// 0075b5af  5e                   pop esi
// 0075b5b0  c3                   ret 
// 0075b5b1  8b4004               mov eax, dword ptr [eax + 4]
// 0075b5b4  80781d00             cmp byte ptr [eax + 0x1d], 0
// 0075b5b8  751b                 jne 0x75b5d5
// 0075b5ba  8d9b00000000         lea ebx, [ebx]
// 0075b5c0  8b4e04               mov ecx, dword ptr [esi + 4]
// 0075b5c3  3b08                 cmp ecx, dword ptr [eax]
// 0075b5c5  750e                 jne 0x75b5d5
// 0075b5c7  894604               mov dword ptr [esi + 4], eax
// 0075b5ca  8bd0                 mov edx, eax
// 0075b5cc  8b4204               mov eax, dword ptr [edx + 4]
// 0075b5cf  80781d00             cmp byte ptr [eax + 0x1d], 0
// 0075b5d3  74eb                 je 0x75b5c0
// 0075b5d5  8b4e04               mov ecx, dword ptr [esi + 4]
// 0075b5d8  80791d00             cmp byte ptr [ecx + 0x1d], 0
// 0075b5dc  75a8                 jne 0x75b586
// 0075b5de  894604               mov dword ptr [esi + 4], eax
// 0075b5e1  5f                   pop edi
// 0075b5e2  5e                   pop esi
// 0075b5e3  c3                   ret 
// standard library map_int<pod12> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HUE@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUE@@@std@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<pod12>
struct E { int v[3]; };
#include <map>
template class std::map<int, E>;
