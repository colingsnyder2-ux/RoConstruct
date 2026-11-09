// from server: 100% by auto
// roc 2010-06 00532590  unit: RBX::G3DTexture  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00532590
//
// 00532590  83ec08               sub esp, 8
// 00532593  53                   push ebx
// 00532594  55                   push ebp
// 00532595  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 0053259b  56                   push esi
// 0053259c  8bf1                 mov esi, ecx
// 0053259e  8b4618               mov eax, dword ptr [esi + 0x18]
// 005325a1  8b18                 mov ebx, dword ptr [eax]
// 005325a3  8b06                 mov eax, dword ptr [esi]
// 005325a5  57                   push edi
// 005325a6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005325aa  85ff                 test edi, edi
// 005325ac  7404                 je 0x5325b2
// 005325ae  3bf8                 cmp edi, eax
// 005325b0  7406                 je 0x5325b8
// 005325b2  ffd5                 call ebp
// 005325b4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005325b8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 005325bc  7562                 jne 0x532620
// 005325be  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005325c2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 005325c5  8b06                 mov eax, dword ptr [esi]
// 005325c7  85c9                 test ecx, ecx
// 005325c9  7404                 je 0x5325cf
// 005325cb  3bc8                 cmp ecx, eax
// 005325cd  7406                 je 0x5325d5
// 005325cf  ffd5                 call ebp
// 005325d1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005325d5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 005325d9  7545                 jne 0x532620
// 005325db  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005325de  8b5104               mov edx, dword ptr [ecx + 4]
// 005325e1  52                   push edx
// 005325e2  8bce                 mov ecx, esi
// 005325e4  e817f3ffff           call 0x531900
// 005325e9  8b4618               mov eax, dword ptr [esi + 0x18]
// 005325ec  894004               mov dword ptr [eax + 4], eax
// 005325ef  8b4618               mov eax, dword ptr [esi + 0x18]
// 005325f2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 005325f9  8900                 mov dword ptr [eax], eax
// 005325fb  8b4618               mov eax, dword ptr [esi + 0x18]
// 005325fe  894008               mov dword ptr [eax + 8], eax
// 00532601  8b4618               mov eax, dword ptr [esi + 0x18]
// 00532604  8b16                 mov edx, dword ptr [esi]
// 00532606  8b08                 mov ecx, dword ptr [eax]
// 00532608  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0053260c  5f                   pop edi
// 0053260d  5e                   pop esi
// 0053260e  5d                   pop ebp
// 0053260f  894804               mov dword ptr [eax + 4], ecx
// 00532612  8910                 mov dword ptr [eax], edx
// 00532614  5b                   pop ebx
// 00532615  83c408               add esp, 8
// 00532618  c21400               ret 0x14
// 0053261b  eb03                 jmp 0x532620
// 0053261d  8d4900               lea ecx, [ecx]
// 00532620  85ff                 test edi, edi
// 00532622  7406                 je 0x53262a
// 00532624  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00532628  7406                 je 0x532630
// 0053262a  ffd5                 call ebp
// 0053262c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00532630  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00532634  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00532638  741d                 je 0x532657
// 0053263a  8d4c2420             lea ecx, [esp + 0x20]
// 0053263e  e8bd8a0e00           call 0x61b100
// 00532643  53                   push ebx
// 00532644  57                   push edi
// 00532645  8d442418             lea eax, [esp + 0x18]
// 00532649  50                   push eax
// 0053264a  8bce                 mov ecx, esi
// 0053264c  e88fefffff           call 0x5315e0
// 00532651  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00532655  ebc9                 jmp 0x532620
// 00532657  8b36                 mov esi, dword ptr [esi]
// 00532659  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0053265d  5f                   pop edi
// 0053265e  8930                 mov dword ptr [eax], esi
// 00532660  5e                   pop esi
// 00532661  5d                   pop ebp
// 00532662  895804               mov dword ptr [eax + 4], ebx
// 00532665  5b                   pop ebx
// 00532666  83c408               add esp, 8
// 00532669  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
