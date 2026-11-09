// from server: 100% by auto
// roc 2009-12 004aafa0  unit: Ogre::RbxSceneUpdater  size: 123 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004aafa0
//
// 004aafa0  83ec08               sub esp, 8
// 004aafa3  8b442410             mov eax, dword ptr [esp + 0x10]
// 004aafa7  53                   push ebx
// 004aafa8  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 004aafae  56                   push esi
// 004aafaf  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 004aafb3  57                   push edi
// 004aafb4  8bf9                 mov edi, ecx
// 004aafb6  8944240c             mov dword ptr [esp + 0xc], eax
// 004aafba  85c0                 test eax, eax
// 004aafbc  750a                 jne 0x4aafc8
// 004aafbe  ffd3                 call ebx
// 004aafc0  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004aafc4  85c0                 test eax, eax
// 004aafc6  7404                 je 0x4aafcc
// 004aafc8  8b00                 mov eax, dword ptr [eax]
// 004aafca  eb02                 jmp 0x4aafce
// 004aafcc  33c0                 xor eax, eax
// 004aafce  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004aafd2  3b4814               cmp ecx, dword ptr [eax + 0x14]
// 004aafd5  7502                 jne 0x4aafd9
// 004aafd7  ffd3                 call ebx
// 004aafd9  8b542420             mov edx, dword ptr [esp + 0x20]
// 004aafdd  8b02                 mov eax, dword ptr [edx]
// 004aafdf  89442420             mov dword ptr [esp + 0x20], eax
// 004aafe3  3b7714               cmp esi, dword ptr [edi + 0x14]
// 004aafe6  741b                 je 0x4ab003
// 004aafe8  8b4e04               mov ecx, dword ptr [esi + 4]
// 004aafeb  8b16                 mov edx, dword ptr [esi]
// 004aafed  8911                 mov dword ptr [ecx], edx
// 004aafef  8b06                 mov eax, dword ptr [esi]
// 004aaff1  8b4e04               mov ecx, dword ptr [esi + 4]
// 004aaff4  56                   push esi
// 004aaff5  894804               mov dword ptr [eax + 4], ecx
// 004aaff8  e85d883400           call 0x7f385a
// 004aaffd  83c404               add esp, 4
// 004ab000  ff4f18               dec dword ptr [edi + 0x18]
// 004ab003  8b0f                 mov ecx, dword ptr [edi]
// 004ab005  8b442418             mov eax, dword ptr [esp + 0x18]
// 004ab009  8b542420             mov edx, dword ptr [esp + 0x20]
// 004ab00d  5f                   pop edi
// 004ab00e  5e                   pop esi
// 004ab00f  895004               mov dword ptr [eax + 4], edx
// 004ab012  8908                 mov dword ptr [eax], ecx
// 004ab014  5b                   pop ebx
// 004ab015  83c408               add esp, 8
// 004ab018  c20c00               ret 0xc
// standard library list<ptr> (function ?erase@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Iterator@$00@12@V?$_Const_iterator@$00@12@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
