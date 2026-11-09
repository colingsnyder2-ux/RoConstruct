// from server: 100% by auto
// roc 2010-06 008fe840  unit: Ogre::RbxSceneUpdater  size: 123 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008fe840
//
// 008fe840  83ec08               sub esp, 8
// 008fe843  8b442410             mov eax, dword ptr [esp + 0x10]
// 008fe847  53                   push ebx
// 008fe848  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 008fe84e  56                   push esi
// 008fe84f  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 008fe853  57                   push edi
// 008fe854  8bf9                 mov edi, ecx
// 008fe856  8944240c             mov dword ptr [esp + 0xc], eax
// 008fe85a  85c0                 test eax, eax
// 008fe85c  750a                 jne 0x8fe868
// 008fe85e  ffd3                 call ebx
// 008fe860  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008fe864  85c0                 test eax, eax
// 008fe866  7404                 je 0x8fe86c
// 008fe868  8b00                 mov eax, dword ptr [eax]
// 008fe86a  eb02                 jmp 0x8fe86e
// 008fe86c  33c0                 xor eax, eax
// 008fe86e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 008fe872  3b4814               cmp ecx, dword ptr [eax + 0x14]
// 008fe875  7502                 jne 0x8fe879
// 008fe877  ffd3                 call ebx
// 008fe879  8b542420             mov edx, dword ptr [esp + 0x20]
// 008fe87d  8b02                 mov eax, dword ptr [edx]
// 008fe87f  89442420             mov dword ptr [esp + 0x20], eax
// 008fe883  3b7714               cmp esi, dword ptr [edi + 0x14]
// 008fe886  741b                 je 0x8fe8a3
// 008fe888  8b4e04               mov ecx, dword ptr [esi + 4]
// 008fe88b  8b16                 mov edx, dword ptr [esi]
// 008fe88d  8911                 mov dword ptr [ecx], edx
// 008fe88f  8b06                 mov eax, dword ptr [esi]
// 008fe891  8b4e04               mov ecx, dword ptr [esi + 4]
// 008fe894  56                   push esi
// 008fe895  894804               mov dword ptr [eax + 4], ecx
// 008fe898  e8fd90eaff           call 0x7a799a
// 008fe89d  83c404               add esp, 4
// 008fe8a0  ff4f18               dec dword ptr [edi + 0x18]
// 008fe8a3  8b0f                 mov ecx, dword ptr [edi]
// 008fe8a5  8b442418             mov eax, dword ptr [esp + 0x18]
// 008fe8a9  8b542420             mov edx, dword ptr [esp + 0x20]
// 008fe8ad  5f                   pop edi
// 008fe8ae  5e                   pop esi
// 008fe8af  895004               mov dword ptr [eax + 4], edx
// 008fe8b2  8908                 mov dword ptr [eax], ecx
// 008fe8b4  5b                   pop ebx
// 008fe8b5  83c408               add esp, 8
// 008fe8b8  c20c00               ret 0xc
// standard library list<ptr> (function ?erase@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Iterator@$00@12@V?$_Const_iterator@$00@12@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
