// from server: 100% by auto
// roc 2008-06 005888f0  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 123 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005888f0
//
// 005888f0  83ec08               sub esp, 8
// 005888f3  8b442410             mov eax, dword ptr [esp + 0x10]
// 005888f7  53                   push ebx
// 005888f8  8b1d90288000         mov ebx, dword ptr [0x802890]
// 005888fe  56                   push esi
// 005888ff  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00588903  57                   push edi
// 00588904  8bf9                 mov edi, ecx
// 00588906  8944240c             mov dword ptr [esp + 0xc], eax
// 0058890a  85c0                 test eax, eax
// 0058890c  750a                 jne 0x588918
// 0058890e  ffd3                 call ebx
// 00588910  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00588914  85c0                 test eax, eax
// 00588916  7404                 je 0x58891c
// 00588918  8b00                 mov eax, dword ptr [eax]
// 0058891a  eb02                 jmp 0x58891e
// 0058891c  33c0                 xor eax, eax
// 0058891e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00588922  3b4814               cmp ecx, dword ptr [eax + 0x14]
// 00588925  7502                 jne 0x588929
// 00588927  ffd3                 call ebx
// 00588929  8b542420             mov edx, dword ptr [esp + 0x20]
// 0058892d  8b02                 mov eax, dword ptr [edx]
// 0058892f  89442420             mov dword ptr [esp + 0x20], eax
// 00588933  3b7714               cmp esi, dword ptr [edi + 0x14]
// 00588936  741b                 je 0x588953
// 00588938  8b4e04               mov ecx, dword ptr [esi + 4]
// 0058893b  8b16                 mov edx, dword ptr [esi]
// 0058893d  8911                 mov dword ptr [ecx], edx
// 0058893f  8b06                 mov eax, dword ptr [esi]
// 00588941  8b4e04               mov ecx, dword ptr [esi + 4]
// 00588944  56                   push esi
// 00588945  894804               mov dword ptr [eax + 4], ecx
// 00588948  e82d7d1100           call 0x6a067a
// 0058894d  83c404               add esp, 4
// 00588950  ff4f18               dec dword ptr [edi + 0x18]
// 00588953  8b0f                 mov ecx, dword ptr [edi]
// 00588955  8b442418             mov eax, dword ptr [esp + 0x18]
// 00588959  8b542420             mov edx, dword ptr [esp + 0x20]
// 0058895d  5f                   pop edi
// 0058895e  5e                   pop esi
// 0058895f  895004               mov dword ptr [eax + 4], edx
// 00588962  8908                 mov dword ptr [eax], ecx
// 00588964  5b                   pop ebx
// 00588965  83c408               add esp, 8
// 00588968  c20c00               ret 0xc
// standard library list<ptr> (function ?erase@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Iterator@$00@12@V?$_Const_iterator@$00@12@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
