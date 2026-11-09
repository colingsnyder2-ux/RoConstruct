// from server: 100% by auto
// roc 2010-06 004740f0  unit: CRobloxScriptReviewPaneView  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004740f0
//
// 004740f0  83ec08               sub esp, 8
// 004740f3  53                   push ebx
// 004740f4  55                   push ebp
// 004740f5  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 004740fb  56                   push esi
// 004740fc  8bf1                 mov esi, ecx
// 004740fe  8b4618               mov eax, dword ptr [esi + 0x18]
// 00474101  8b18                 mov ebx, dword ptr [eax]
// 00474103  8b06                 mov eax, dword ptr [esi]
// 00474105  57                   push edi
// 00474106  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0047410a  85ff                 test edi, edi
// 0047410c  7404                 je 0x474112
// 0047410e  3bf8                 cmp edi, eax
// 00474110  7406                 je 0x474118
// 00474112  ffd5                 call ebp
// 00474114  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00474118  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0047411c  7562                 jne 0x474180
// 0047411e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00474122  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00474125  8b06                 mov eax, dword ptr [esi]
// 00474127  85c9                 test ecx, ecx
// 00474129  7404                 je 0x47412f
// 0047412b  3bc8                 cmp ecx, eax
// 0047412d  7406                 je 0x474135
// 0047412f  ffd5                 call ebp
// 00474131  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00474135  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 00474139  7545                 jne 0x474180
// 0047413b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0047413e  8b5104               mov edx, dword ptr [ecx + 4]
// 00474141  52                   push edx
// 00474142  8bce                 mov ecx, esi
// 00474144  e8d77d1e00           call 0x65bf20
// 00474149  8b4618               mov eax, dword ptr [esi + 0x18]
// 0047414c  894004               mov dword ptr [eax + 4], eax
// 0047414f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00474152  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00474159  8900                 mov dword ptr [eax], eax
// 0047415b  8b4618               mov eax, dword ptr [esi + 0x18]
// 0047415e  894008               mov dword ptr [eax + 8], eax
// 00474161  8b4618               mov eax, dword ptr [esi + 0x18]
// 00474164  8b16                 mov edx, dword ptr [esi]
// 00474166  8b08                 mov ecx, dword ptr [eax]
// 00474168  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0047416c  5f                   pop edi
// 0047416d  5e                   pop esi
// 0047416e  5d                   pop ebp
// 0047416f  894804               mov dword ptr [eax + 4], ecx
// 00474172  8910                 mov dword ptr [eax], edx
// 00474174  5b                   pop ebx
// 00474175  83c408               add esp, 8
// 00474178  c21400               ret 0x14
// 0047417b  eb03                 jmp 0x474180
// 0047417d  8d4900               lea ecx, [ecx]
// 00474180  85ff                 test edi, edi
// 00474182  7406                 je 0x47418a
// 00474184  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00474188  7406                 je 0x474190
// 0047418a  ffd5                 call ebp
// 0047418c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00474190  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00474194  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00474198  741d                 je 0x4741b7
// 0047419a  8d4c2420             lea ecx, [esp + 0x20]
// 0047419e  e80db31e00           call 0x65f4b0
// 004741a3  53                   push ebx
// 004741a4  57                   push edi
// 004741a5  8d442418             lea eax, [esp + 0x18]
// 004741a9  50                   push eax
// 004741aa  8bce                 mov ecx, esi
// 004741ac  e82ffbffff           call 0x473ce0
// 004741b1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004741b5  ebc9                 jmp 0x474180
// 004741b7  8b36                 mov esi, dword ptr [esi]
// 004741b9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004741bd  5f                   pop edi
// 004741be  8930                 mov dword ptr [eax], esi
// 004741c0  5e                   pop esi
// 004741c1  5d                   pop ebp
// 004741c2  895804               mov dword ptr [eax + 4], ebx
// 004741c5  5b                   pop ebx
// 004741c6  83c408               add esp, 8
// 004741c9  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
