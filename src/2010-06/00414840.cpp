// from server: 100% by auto
// roc 2010-06 00414840  unit: CopyVerb  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00414840
//
// 00414840  83ec08               sub esp, 8
// 00414843  53                   push ebx
// 00414844  55                   push ebp
// 00414845  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 0041484b  56                   push esi
// 0041484c  8bf1                 mov esi, ecx
// 0041484e  8b4618               mov eax, dword ptr [esi + 0x18]
// 00414851  8b18                 mov ebx, dword ptr [eax]
// 00414853  8b06                 mov eax, dword ptr [esi]
// 00414855  57                   push edi
// 00414856  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0041485a  85ff                 test edi, edi
// 0041485c  7404                 je 0x414862
// 0041485e  3bf8                 cmp edi, eax
// 00414860  7406                 je 0x414868
// 00414862  ffd5                 call ebp
// 00414864  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00414868  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0041486c  7562                 jne 0x4148d0
// 0041486e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00414872  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 00414875  8b06                 mov eax, dword ptr [esi]
// 00414877  85c9                 test ecx, ecx
// 00414879  7404                 je 0x41487f
// 0041487b  3bc8                 cmp ecx, eax
// 0041487d  7406                 je 0x414885
// 0041487f  ffd5                 call ebp
// 00414881  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00414885  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 00414889  7545                 jne 0x4148d0
// 0041488b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0041488e  8b5104               mov edx, dword ptr [ecx + 4]
// 00414891  52                   push edx
// 00414892  8bce                 mov ecx, esi
// 00414894  e897fdffff           call 0x414630
// 00414899  8b4618               mov eax, dword ptr [esi + 0x18]
// 0041489c  894004               mov dword ptr [eax + 4], eax
// 0041489f  8b4618               mov eax, dword ptr [esi + 0x18]
// 004148a2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 004148a9  8900                 mov dword ptr [eax], eax
// 004148ab  8b4618               mov eax, dword ptr [esi + 0x18]
// 004148ae  894008               mov dword ptr [eax + 8], eax
// 004148b1  8b4618               mov eax, dword ptr [esi + 0x18]
// 004148b4  8b16                 mov edx, dword ptr [esi]
// 004148b6  8b08                 mov ecx, dword ptr [eax]
// 004148b8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004148bc  5f                   pop edi
// 004148bd  5e                   pop esi
// 004148be  5d                   pop ebp
// 004148bf  894804               mov dword ptr [eax + 4], ecx
// 004148c2  8910                 mov dword ptr [eax], edx
// 004148c4  5b                   pop ebx
// 004148c5  83c408               add esp, 8
// 004148c8  c21400               ret 0x14
// 004148cb  eb03                 jmp 0x4148d0
// 004148cd  8d4900               lea ecx, [ecx]
// 004148d0  85ff                 test edi, edi
// 004148d2  7406                 je 0x4148da
// 004148d4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 004148d8  7406                 je 0x4148e0
// 004148da  ffd5                 call ebp
// 004148dc  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004148e0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004148e4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 004148e8  741d                 je 0x414907
// 004148ea  8d4c2420             lea ecx, [esp + 0x20]
// 004148ee  e84df3ffff           call 0x413c40
// 004148f3  53                   push ebx
// 004148f4  57                   push edi
// 004148f5  8d442418             lea eax, [esp + 0x18]
// 004148f9  50                   push eax
// 004148fa  8bce                 mov ecx, esi
// 004148fc  e8bff9ffff           call 0x4142c0
// 00414901  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00414905  ebc9                 jmp 0x4148d0
// 00414907  8b36                 mov esi, dword ptr [esi]
// 00414909  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0041490d  5f                   pop edi
// 0041490e  8930                 mov dword ptr [eax], esi
// 00414910  5e                   pop esi
// 00414911  5d                   pop ebp
// 00414912  895804               mov dword ptr [eax + 4], ebx
// 00414915  5b                   pop ebx
// 00414916  83c408               add esp, 8
// 00414919  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
