// from server: 100% by auto
// roc 2007-08 004ef230  unit: RBX::Render::SceneManager  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004ef230
//
// 004ef230  56                   push esi
// 004ef231  8bf1                 mov esi, ecx
// 004ef233  833e00               cmp dword ptr [esi], 0
// 004ef236  57                   push edi
// 004ef237  8b3dd8e67700         mov edi, dword ptr [0x77e6d8]
// 004ef23d  7502                 jne 0x4ef241
// 004ef23f  ffd7                 call edi
// 004ef241  8b4604               mov eax, dword ptr [esi + 4]
// 004ef244  80781500             cmp byte ptr [eax + 0x15], 0
// 004ef248  7411                 je 0x4ef25b
// 004ef24a  8b4008               mov eax, dword ptr [eax + 8]
// 004ef24d  894604               mov dword ptr [esi + 4], eax
// 004ef250  80781500             cmp byte ptr [eax + 0x15], 0
// 004ef254  745b                 je 0x4ef2b1
// 004ef256  ffd7                 call edi
// 004ef258  5f                   pop edi
// 004ef259  5e                   pop esi
// 004ef25a  c3                   ret 
// 004ef25b  8b08                 mov ecx, dword ptr [eax]
// 004ef25d  80791500             cmp byte ptr [ecx + 0x15], 0
// 004ef261  751e                 jne 0x4ef281
// 004ef263  8b4108               mov eax, dword ptr [ecx + 8]
// 004ef266  80781500             cmp byte ptr [eax + 0x15], 0
// 004ef26a  750f                 jne 0x4ef27b
// 004ef26c  8d642400             lea esp, [esp]
// 004ef270  8bc8                 mov ecx, eax
// 004ef272  8b4108               mov eax, dword ptr [ecx + 8]
// 004ef275  80781500             cmp byte ptr [eax + 0x15], 0
// 004ef279  74f5                 je 0x4ef270
// 004ef27b  5f                   pop edi
// 004ef27c  894e04               mov dword ptr [esi + 4], ecx
// 004ef27f  5e                   pop esi
// 004ef280  c3                   ret 
// 004ef281  8b4004               mov eax, dword ptr [eax + 4]
// 004ef284  80781500             cmp byte ptr [eax + 0x15], 0
// 004ef288  751b                 jne 0x4ef2a5
// 004ef28a  8d9b00000000         lea ebx, [ebx]
// 004ef290  8b4e04               mov ecx, dword ptr [esi + 4]
// 004ef293  3b08                 cmp ecx, dword ptr [eax]
// 004ef295  750e                 jne 0x4ef2a5
// 004ef297  894604               mov dword ptr [esi + 4], eax
// 004ef29a  8bd0                 mov edx, eax
// 004ef29c  8b4204               mov eax, dword ptr [edx + 4]
// 004ef29f  80781500             cmp byte ptr [eax + 0x15], 0
// 004ef2a3  74eb                 je 0x4ef290
// 004ef2a5  8b4e04               mov ecx, dword ptr [esi + 4]
// 004ef2a8  80791500             cmp byte ptr [ecx + 0x15], 0
// 004ef2ac  75a8                 jne 0x4ef256
// 004ef2ae  894604               mov dword ptr [esi + 4], eax
// 004ef2b1  5f                   pop edi
// 004ef2b2  5e                   pop esi
// 004ef2b3  c3                   ret 
// standard library map_int<ptr> (function ?_Dec@const_iterator@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@QAEXXZ)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;
