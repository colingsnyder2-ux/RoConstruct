// from server: 100% by auto
// roc 2010-06 00738260  unit: seg_00730000  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00738260
//
// 00738260  53                   push ebx
// 00738261  55                   push ebp
// 00738262  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 00738268  56                   push esi
// 00738269  8bf1                 mov esi, ecx
// 0073826b  8b06                 mov eax, dword ptr [esi]
// 0073826d  57                   push edi
// 0073826e  85c0                 test eax, eax
// 00738270  7508                 jne 0x73827a
// 00738272  ffd5                 call ebp
// 00738274  8b06                 mov eax, dword ptr [esi]
// 00738276  85c0                 test eax, eax
// 00738278  7404                 je 0x73827e
// 0073827a  8b18                 mov ebx, dword ptr [eax]
// 0073827c  eb02                 jmp 0x738280
// 0073827e  33db                 xor ebx, ebx
// 00738280  85c0                 test eax, eax
// 00738282  7404                 je 0x738288
// 00738284  8b10                 mov edx, dword ptr [eax]
// 00738286  eb02                 jmp 0x73828a
// 00738288  33d2                 xor edx, edx
// 0073828a  8b521c               mov edx, dword ptr [edx + 0x1c]
// 0073828d  8b4e04               mov ecx, dword ptr [esi + 4]
// 00738290  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00738294  035318               add edx, dword ptr [ebx + 0x18]
// 00738297  03cf                 add ecx, edi
// 00738299  3bca                 cmp ecx, edx
// 0073829b  770f                 ja 0x7382ac
// 0073829d  85c0                 test eax, eax
// 0073829f  7404                 je 0x7382a5
// 007382a1  8b00                 mov eax, dword ptr [eax]
// 007382a3  eb02                 jmp 0x7382a7
// 007382a5  33c0                 xor eax, eax
// 007382a7  3b4818               cmp ecx, dword ptr [eax + 0x18]
// 007382aa  7302                 jae 0x7382ae
// 007382ac  ffd5                 call ebp
// 007382ae  017e04               add dword ptr [esi + 4], edi
// 007382b1  5f                   pop edi
// 007382b2  8bc6                 mov eax, esi
// 007382b4  5e                   pop esi
// 007382b5  5d                   pop ebp
// 007382b6  5b                   pop ebx
// 007382b7  c20400               ret 4
// standard library deque<ptr> (function ??Y?$_Deque_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@$00@std@@QAEAAV01@H@Z)

// stl: deque<ptr>
struct T; typedef T* E;
#include <deque>
template class std::deque<E>;
