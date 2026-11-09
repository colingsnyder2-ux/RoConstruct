// from server: 100% by auto
// roc 2007-08 00584370  unit: RBX::VHat::?$FactoryProduct  size: 185 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00584370
//
// 00584370  83ec0c               sub esp, 0xc
// 00584373  55                   push ebp
// 00584374  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 00584378  56                   push esi
// 00584379  57                   push edi
// 0058437a  8bf9                 mov edi, ecx
// 0058437c  8b7704               mov esi, dword ptr [edi + 4]
// 0058437f  8b4604               mov eax, dword ptr [esi + 4]
// 00584382  80781500             cmp byte ptr [eax + 0x15], 0
// 00584386  b101                 mov cl, 1
// 00584388  884c240c             mov byte ptr [esp + 0xc], cl
// 0058438c  7520                 jne 0x5843ae
// 0058438e  8b5500               mov edx, dword ptr [ebp]
// 00584391  3b500c               cmp edx, dword ptr [eax + 0xc]
// 00584394  8bf0                 mov esi, eax
// 00584396  0f9cc1               setl cl
// 00584399  84c9                 test cl, cl
// 0058439b  884c240c             mov byte ptr [esp + 0xc], cl
// 0058439f  7404                 je 0x5843a5
// 005843a1  8b00                 mov eax, dword ptr [eax]
// 005843a3  eb03                 jmp 0x5843a8
// 005843a5  8b4008               mov eax, dword ptr [eax + 8]
// 005843a8  80781500             cmp byte ptr [eax + 0x15], 0
// 005843ac  74e3                 je 0x584391
// 005843ae  84c9                 test cl, cl
// 005843b0  8bd6                 mov edx, esi
// 005843b2  89542414             mov dword ptr [esp + 0x14], edx
// 005843b6  897c2410             mov dword ptr [esp + 0x10], edi
// 005843ba  743d                 je 0x5843f9
// 005843bc  8b4704               mov eax, dword ptr [edi + 4]
// 005843bf  3b30                 cmp esi, dword ptr [eax]
// 005843c1  8d4c2410             lea ecx, [esp + 0x10]
// 005843c5  7529                 jne 0x5843f0
// 005843c7  55                   push ebp
// 005843c8  56                   push esi
// 005843c9  6a01                 push 1
// 005843cb  51                   push ecx
// 005843cc  8bcf                 mov ecx, edi
// 005843ce  e85df6ffff           call 0x583a30
// 005843d3  8bc8                 mov ecx, eax
// 005843d5  8b11                 mov edx, dword ptr [ecx]
// 005843d7  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005843db  8b4904               mov ecx, dword ptr [ecx + 4]
// 005843de  5f                   pop edi
// 005843df  5e                   pop esi
// 005843e0  8910                 mov dword ptr [eax], edx
// 005843e2  894804               mov dword ptr [eax + 4], ecx
// 005843e5  c6400801             mov byte ptr [eax + 8], 1
// 005843e9  5d                   pop ebp
// 005843ea  83c40c               add esp, 0xc
// 005843ed  c20800               ret 8
// 005843f0  e83baef6ff           call 0x4ef230
// 005843f5  8b542414             mov edx, dword ptr [esp + 0x14]
// 005843f9  8b420c               mov eax, dword ptr [edx + 0xc]
// 005843fc  3b4500               cmp eax, dword ptr [ebp]
// 005843ff  7d0e                 jge 0x58440f
// 00584401  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00584405  55                   push ebp
// 00584406  56                   push esi
// 00584407  51                   push ecx
// 00584408  8d54241c             lea edx, [esp + 0x1c]
// 0058440c  52                   push edx
// 0058440d  ebbd                 jmp 0x5843cc
// 0058440f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00584413  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00584417  5f                   pop edi
// 00584418  5e                   pop esi
// 00584419  8908                 mov dword ptr [eax], ecx
// 0058441b  895004               mov dword ptr [eax + 4], edx
// 0058441e  c6400800             mov byte ptr [eax + 8], 0
// 00584422  5d                   pop ebp
// 00584423  83c40c               add esp, 0xc
// 00584426  c20800               ret 8
// standard library map_int<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBHPAUT@@@2@@Z)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;
