// from server: 100% by auto
// roc 2010-06 00705210  unit: RBX::VInstance::?$NonFactoryProduct  size: 208 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00705210
//
// 00705210  83ec08               sub esp, 8
// 00705213  53                   push ebx
// 00705214  55                   push ebp
// 00705215  56                   push esi
// 00705216  8bf1                 mov esi, ecx
// 00705218  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0070521b  57                   push edi
// 0070521c  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0070521f  8bcb                 mov ecx, ebx
// 00705221  2bcf                 sub ecx, edi
// 00705223  b8398ee338           mov eax, 0x38e38e39
// 00705228  f7e9                 imul ecx
// 0070522a  c1fa03               sar edx, 3
// 0070522d  8bc2                 mov eax, edx
// 0070522f  c1e81f               shr eax, 0x1f
// 00705232  03c2                 add eax, edx
// 00705234  7504                 jne 0x70523a
// 00705236  33ff                 xor edi, edi
// 00705238  eb35                 jmp 0x70526f
// 0070523a  3bfb                 cmp edi, ebx
// 0070523c  7606                 jbe 0x705244
// 0070523e  ff150ca99e00         call dword ptr [0x9ea90c]
// 00705244  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00705248  8b06                 mov eax, dword ptr [esi]
// 0070524a  85c9                 test ecx, ecx
// 0070524c  7404                 je 0x705252
// 0070524e  3bc8                 cmp ecx, eax
// 00705250  7406                 je 0x705258
// 00705252  ff150ca99e00         call dword ptr [0x9ea90c]
// 00705258  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0070525c  2bcf                 sub ecx, edi
// 0070525e  b8398ee338           mov eax, 0x38e38e39
// 00705263  f7e9                 imul ecx
// 00705265  c1fa03               sar edx, 3
// 00705268  8bfa                 mov edi, edx
// 0070526a  c1ef1f               shr edi, 0x1f
// 0070526d  03fa                 add edi, edx
// 0070526f  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00705273  8b542424             mov edx, dword ptr [esp + 0x24]
// 00705277  8b442420             mov eax, dword ptr [esp + 0x20]
// 0070527b  51                   push ecx
// 0070527c  6a01                 push 1
// 0070527e  52                   push edx
// 0070527f  50                   push eax
// 00705280  8bce                 mov ecx, esi
// 00705282  e809fbffff           call 0x704d90
// 00705287  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0070528a  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 0070528d  7606                 jbe 0x705295
// 0070528f  ff150ca99e00         call dword ptr [0x9ea90c]
// 00705295  8b36                 mov esi, dword ptr [esi]
// 00705297  8bee                 mov ebp, esi
// 00705299  895c2414             mov dword ptr [esp + 0x14], ebx
// 0070529d  85f6                 test esi, esi
// 0070529f  751b                 jne 0x7052bc
// 007052a1  ff150ca99e00         call dword ptr [0x9ea90c]
// 007052a7  33c0                 xor eax, eax
// 007052a9  8d0cff               lea ecx, [edi + edi*8]
// 007052ac  8d3c8b               lea edi, [ebx + ecx*4]
// 007052af  3b7810               cmp edi, dword ptr [eax + 0x10]
// 007052b2  7713                 ja 0x7052c7
// 007052b4  85f6                 test esi, esi
// 007052b6  7408                 je 0x7052c0
// 007052b8  8b36                 mov esi, dword ptr [esi]
// 007052ba  eb06                 jmp 0x7052c2
// 007052bc  8b06                 mov eax, dword ptr [esi]
// 007052be  ebe9                 jmp 0x7052a9
// 007052c0  33f6                 xor esi, esi
// 007052c2  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 007052c5  7306                 jae 0x7052cd
// 007052c7  ff150ca99e00         call dword ptr [0x9ea90c]
// 007052cd  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007052d1  897804               mov dword ptr [eax + 4], edi
// 007052d4  5f                   pop edi
// 007052d5  5e                   pop esi
// 007052d6  8928                 mov dword ptr [eax], ebp
// 007052d8  5d                   pop ebp
// 007052d9  5b                   pop ebx
// 007052da  83c408               add esp, 8
// 007052dd  c21000               ret 0x10
// standard library vector<pod36> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod36>
struct E { int v[9]; };
#include <vector>
template class std::vector<E>;
