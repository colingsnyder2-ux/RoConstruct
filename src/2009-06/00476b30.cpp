// from server: 100% by auto
// roc 2009-06 00476b30  unit: Ogre::RbxMeshLoader  size: 123 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00476b30
//
// 00476b30  83ec08               sub esp, 8
// 00476b33  8b442410             mov eax, dword ptr [esp + 0x10]
// 00476b37  53                   push ebx
// 00476b38  8b1dace98900         mov ebx, dword ptr [0x89e9ac]
// 00476b3e  56                   push esi
// 00476b3f  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00476b43  57                   push edi
// 00476b44  8bf9                 mov edi, ecx
// 00476b46  8944240c             mov dword ptr [esp + 0xc], eax
// 00476b4a  85c0                 test eax, eax
// 00476b4c  750a                 jne 0x476b58
// 00476b4e  ffd3                 call ebx
// 00476b50  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00476b54  85c0                 test eax, eax
// 00476b56  7404                 je 0x476b5c
// 00476b58  8b00                 mov eax, dword ptr [eax]
// 00476b5a  eb02                 jmp 0x476b5e
// 00476b5c  33c0                 xor eax, eax
// 00476b5e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00476b62  3b4814               cmp ecx, dword ptr [eax + 0x14]
// 00476b65  7502                 jne 0x476b69
// 00476b67  ffd3                 call ebx
// 00476b69  8b542420             mov edx, dword ptr [esp + 0x20]
// 00476b6d  8b02                 mov eax, dword ptr [edx]
// 00476b6f  89442420             mov dword ptr [esp + 0x20], eax
// 00476b73  3b7714               cmp esi, dword ptr [edi + 0x14]
// 00476b76  741b                 je 0x476b93
// 00476b78  8b4e04               mov ecx, dword ptr [esi + 4]
// 00476b7b  8b16                 mov edx, dword ptr [esi]
// 00476b7d  8911                 mov dword ptr [ecx], edx
// 00476b7f  8b06                 mov eax, dword ptr [esi]
// 00476b81  8b4e04               mov ecx, dword ptr [esi + 4]
// 00476b84  56                   push esi
// 00476b85  894804               mov dword ptr [eax + 4], ecx
// 00476b88  e8a51e2a00           call 0x718a32
// 00476b8d  83c404               add esp, 4
// 00476b90  ff4f18               dec dword ptr [edi + 0x18]
// 00476b93  8b0f                 mov ecx, dword ptr [edi]
// 00476b95  8b442418             mov eax, dword ptr [esp + 0x18]
// 00476b99  8b542420             mov edx, dword ptr [esp + 0x20]
// 00476b9d  5f                   pop edi
// 00476b9e  5e                   pop esi
// 00476b9f  895004               mov dword ptr [eax + 4], edx
// 00476ba2  8908                 mov dword ptr [eax], ecx
// 00476ba4  5b                   pop ebx
// 00476ba5  83c408               add esp, 8
// 00476ba8  c20c00               ret 0xc
// standard library list<ptr> (function ?erase@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Iterator@$00@12@V?$_Const_iterator@$00@12@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
