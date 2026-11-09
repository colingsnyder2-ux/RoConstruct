// from server: 100% by auto
// roc 2007-08 00726e20  unit: boost::thread_resource_error  size: 96 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00726e20
//
// 00726e20  83ec08               sub esp, 8
// 00726e23  53                   push ebx
// 00726e24  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 00726e28  85db                 test ebx, ebx
// 00726e2a  55                   push ebp
// 00726e2b  56                   push esi
// 00726e2c  8b742420             mov esi, dword ptr [esp + 0x20]
// 00726e30  57                   push edi
// 00726e31  8bf9                 mov edi, ecx
// 00726e33  895c2410             mov dword ptr [esp + 0x10], ebx
// 00726e37  7506                 jne 0x726e3f
// 00726e39  ff15d8e67700         call dword ptr [0x77e6d8]
// 00726e3f  3b7304               cmp esi, dword ptr [ebx + 4]
// 00726e42  7506                 jne 0x726e4a
// 00726e44  ff15d8e67700         call dword ptr [0x77e6d8]
// 00726e4a  3b7704               cmp esi, dword ptr [edi + 4]
// 00726e4d  8b2e                 mov ebp, dword ptr [esi]
// 00726e4f  741c                 je 0x726e6d
// 00726e51  8b4604               mov eax, dword ptr [esi + 4]
// 00726e54  8bcd                 mov ecx, ebp
// 00726e56  8908                 mov dword ptr [eax], ecx
// 00726e58  8b16                 mov edx, dword ptr [esi]
// 00726e5a  8b4604               mov eax, dword ptr [esi + 4]
// 00726e5d  56                   push esi
// 00726e5e  894204               mov dword ptr [edx + 4], eax
// 00726e61  e8fc8df0ff           call 0x62fc62
// 00726e66  83c404               add esp, 4
// 00726e69  834708ff             add dword ptr [edi + 8], -1
// 00726e6d  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00726e71  5f                   pop edi
// 00726e72  5e                   pop esi
// 00726e73  896804               mov dword ptr [eax + 4], ebp
// 00726e76  5d                   pop ebp
// 00726e77  8918                 mov dword ptr [eax], ebx
// 00726e79  5b                   pop ebx
// 00726e7a  83c408               add esp, 8
// 00726e7d  c20c00               ret 0xc
// standard library list<ptr> (function ?erase@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Iterator@$00@12@V312@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
