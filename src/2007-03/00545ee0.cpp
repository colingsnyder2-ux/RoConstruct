// from server: 100% by auto
// roc 2007-03 00545ee0  unit: seg_00540000  size: 105 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00545ee0
//
// 00545ee0  83ec08               sub esp, 8
// 00545ee3  53                   push ebx
// 00545ee4  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 00545ee8  85db                 test ebx, ebx
// 00545eea  55                   push ebp
// 00545eeb  56                   push esi
// 00545eec  8b742420             mov esi, dword ptr [esp + 0x20]
// 00545ef0  57                   push edi
// 00545ef1  8bf9                 mov edi, ecx
// 00545ef3  895c2410             mov dword ptr [esp + 0x10], ebx
// 00545ef7  7506                 jne 0x545eff
// 00545ef9  ff1544e97700         call dword ptr [0x77e944]
// 00545eff  3b7304               cmp esi, dword ptr [ebx + 4]
// 00545f02  7506                 jne 0x545f0a
// 00545f04  ff1544e97700         call dword ptr [0x77e944]
// 00545f0a  3b7704               cmp esi, dword ptr [edi + 4]
// 00545f0d  8b2e                 mov ebp, dword ptr [esi]
// 00545f0f  7425                 je 0x545f36
// 00545f11  8b4604               mov eax, dword ptr [esi + 4]
// 00545f14  8bcd                 mov ecx, ebp
// 00545f16  8908                 mov dword ptr [eax], ecx
// 00545f18  8b16                 mov edx, dword ptr [esi]
// 00545f1a  8b4604               mov eax, dword ptr [esi + 4]
// 00545f1d  8d4e08               lea ecx, [esi + 8]
// 00545f20  894204               mov dword ptr [edx + 4], eax
// 00545f23  ff158ce77700         call dword ptr [0x77e78c]
// 00545f29  56                   push esi
// 00545f2a  e8c1810d00           call 0x61e0f0
// 00545f2f  83c404               add esp, 4
// 00545f32  834708ff             add dword ptr [edi + 8], -1
// 00545f36  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00545f3a  5f                   pop edi
// 00545f3b  5e                   pop esi
// 00545f3c  896804               mov dword ptr [eax + 4], ebp
// 00545f3f  5d                   pop ebp
// 00545f40  8918                 mov dword ptr [eax], ebx
// 00545f42  5b                   pop ebx
// 00545f43  83c408               add esp, 8
// 00545f46  c20c00               ret 0xc
// standard library list<string> (function ?erase@?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE?AV?$_Iterator@$00@12@V312@@Z)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
