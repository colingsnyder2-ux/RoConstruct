// from server: 100% by auto
// roc 2010-06 006042b0  unit: RBX::$$A6AXABVHeartbeat::?$signal::slot  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006042b0
//
// 006042b0  83ec08               sub esp, 8
// 006042b3  53                   push ebx
// 006042b4  55                   push ebp
// 006042b5  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 006042bb  56                   push esi
// 006042bc  8bf1                 mov esi, ecx
// 006042be  8b4618               mov eax, dword ptr [esi + 0x18]
// 006042c1  8b18                 mov ebx, dword ptr [eax]
// 006042c3  8b06                 mov eax, dword ptr [esi]
// 006042c5  57                   push edi
// 006042c6  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006042ca  85ff                 test edi, edi
// 006042cc  7404                 je 0x6042d2
// 006042ce  3bf8                 cmp edi, eax
// 006042d0  7406                 je 0x6042d8
// 006042d2  ffd5                 call ebp
// 006042d4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006042d8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 006042dc  7562                 jne 0x604340
// 006042de  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006042e2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 006042e5  8b06                 mov eax, dword ptr [esi]
// 006042e7  85c9                 test ecx, ecx
// 006042e9  7404                 je 0x6042ef
// 006042eb  3bc8                 cmp ecx, eax
// 006042ed  7406                 je 0x6042f5
// 006042ef  ffd5                 call ebp
// 006042f1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006042f5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 006042f9  7545                 jne 0x604340
// 006042fb  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006042fe  8b5104               mov edx, dword ptr [ecx + 4]
// 00604301  52                   push edx
// 00604302  8bce                 mov ecx, esi
// 00604304  e8b7faffff           call 0x603dc0
// 00604309  8b4618               mov eax, dword ptr [esi + 0x18]
// 0060430c  894004               mov dword ptr [eax + 4], eax
// 0060430f  8b4618               mov eax, dword ptr [esi + 0x18]
// 00604312  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00604319  8900                 mov dword ptr [eax], eax
// 0060431b  8b4618               mov eax, dword ptr [esi + 0x18]
// 0060431e  894008               mov dword ptr [eax + 8], eax
// 00604321  8b4618               mov eax, dword ptr [esi + 0x18]
// 00604324  8b16                 mov edx, dword ptr [esi]
// 00604326  8b08                 mov ecx, dword ptr [eax]
// 00604328  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0060432c  5f                   pop edi
// 0060432d  5e                   pop esi
// 0060432e  5d                   pop ebp
// 0060432f  894804               mov dword ptr [eax + 4], ecx
// 00604332  8910                 mov dword ptr [eax], edx
// 00604334  5b                   pop ebx
// 00604335  83c408               add esp, 8
// 00604338  c21400               ret 0x14
// 0060433b  eb03                 jmp 0x604340
// 0060433d  8d4900               lea ecx, [ecx]
// 00604340  85ff                 test edi, edi
// 00604342  7406                 je 0x60434a
// 00604344  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00604348  7406                 je 0x604350
// 0060434a  ffd5                 call ebp
// 0060434c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00604350  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00604354  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00604358  741d                 je 0x604377
// 0060435a  8d4c2420             lea ecx, [esp + 0x20]
// 0060435e  e84db21600           call 0x76f5b0
// 00604363  53                   push ebx
// 00604364  57                   push edi
// 00604365  8d442418             lea eax, [esp + 0x18]
// 00604369  50                   push eax
// 0060436a  8bce                 mov ecx, esi
// 0060436c  e85ff7ffff           call 0x603ad0
// 00604371  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00604375  ebc9                 jmp 0x604340
// 00604377  8b36                 mov esi, dword ptr [esi]
// 00604379  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0060437d  5f                   pop edi
// 0060437e  8930                 mov dword ptr [eax], esi
// 00604380  5e                   pop esi
// 00604381  5d                   pop ebp
// 00604382  895804               mov dword ptr [eax + 4], ebx
// 00604385  5b                   pop ebx
// 00604386  83c408               add esp, 8
// 00604389  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
