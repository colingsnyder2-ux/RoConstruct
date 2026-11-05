// from server: 100% by auto
// roc 2007-08 004335a0  unit: RBX::CMarshalWindow  size: 185 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004335a0
//
// 004335a0  83ec0c               sub esp, 0xc
// 004335a3  55                   push ebp
// 004335a4  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 004335a8  56                   push esi
// 004335a9  57                   push edi
// 004335aa  8bf9                 mov edi, ecx
// 004335ac  8b7704               mov esi, dword ptr [edi + 4]
// 004335af  8b4604               mov eax, dword ptr [esi + 4]
// 004335b2  80781500             cmp byte ptr [eax + 0x15], 0
// 004335b6  b101                 mov cl, 1
// 004335b8  884c240c             mov byte ptr [esp + 0xc], cl
// 004335bc  7520                 jne 0x4335de
// 004335be  8b5500               mov edx, dword ptr [ebp]
// 004335c1  3b500c               cmp edx, dword ptr [eax + 0xc]
// 004335c4  8bf0                 mov esi, eax
// 004335c6  0f92c1               setb cl
// 004335c9  84c9                 test cl, cl
// 004335cb  884c240c             mov byte ptr [esp + 0xc], cl
// 004335cf  7404                 je 0x4335d5
// 004335d1  8b00                 mov eax, dword ptr [eax]
// 004335d3  eb03                 jmp 0x4335d8
// 004335d5  8b4008               mov eax, dword ptr [eax + 8]
// 004335d8  80781500             cmp byte ptr [eax + 0x15], 0
// 004335dc  74e3                 je 0x4335c1
// 004335de  84c9                 test cl, cl
// 004335e0  8bd6                 mov edx, esi
// 004335e2  89542414             mov dword ptr [esp + 0x14], edx
// 004335e6  897c2410             mov dword ptr [esp + 0x10], edi
// 004335ea  743d                 je 0x433629
// 004335ec  8b4704               mov eax, dword ptr [edi + 4]
// 004335ef  3b30                 cmp esi, dword ptr [eax]
// 004335f1  8d4c2410             lea ecx, [esp + 0x10]
// 004335f5  7529                 jne 0x433620
// 004335f7  55                   push ebp
// 004335f8  56                   push esi
// 004335f9  6a01                 push 1
// 004335fb  51                   push ecx
// 004335fc  8bcf                 mov ecx, edi
// 004335fe  e8adfdffff           call 0x4333b0
// 00433603  8bc8                 mov ecx, eax
// 00433605  8b11                 mov edx, dword ptr [ecx]
// 00433607  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0043360b  8b4904               mov ecx, dword ptr [ecx + 4]
// 0043360e  5f                   pop edi
// 0043360f  5e                   pop esi
// 00433610  8910                 mov dword ptr [eax], edx
// 00433612  894804               mov dword ptr [eax + 4], ecx
// 00433615  c6400801             mov byte ptr [eax + 8], 1
// 00433619  5d                   pop ebp
// 0043361a  83c40c               add esp, 0xc
// 0043361d  c20800               ret 8
// 00433620  e80bbc0b00           call 0x4ef230
// 00433625  8b542414             mov edx, dword ptr [esp + 0x14]
// 00433629  8b420c               mov eax, dword ptr [edx + 0xc]
// 0043362c  3b4500               cmp eax, dword ptr [ebp]
// 0043362f  730e                 jae 0x43363f
// 00433631  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00433635  55                   push ebp
// 00433636  56                   push esi
// 00433637  51                   push ecx
// 00433638  8d54241c             lea edx, [esp + 0x1c]
// 0043363c  52                   push edx
// 0043363d  ebbd                 jmp 0x4335fc
// 0043363f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00433643  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00433647  5f                   pop edi
// 00433648  5e                   pop esi
// 00433649  8908                 mov dword ptr [eax], ecx
// 0043364b  895004               mov dword ptr [eax + 4], edx
// 0043364e  c6400800             mov byte ptr [eax + 8], 0
// 00433652  5d                   pop ebp
// 00433653  83c40c               add esp, 0xc
// 00433656  c20800               ret 8
// standard library map_ptr<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@PAUT@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@PAUT@@@std@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PAUK@@PAUT@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@PAUT@@@std@@@4@$0A@@std@@@std@@_N@2@ABU?$pair@QAUK@@PAUT@@@2@@Z)

// stl: map_ptr<ptr>
struct T; typedef T* E;
#include <map>
struct K; template class std::map<K*, E>;
