// from server: 100% by auto
// roc 2009-12 00684080  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00684080
//
// 00684080  83ec08               sub esp, 8
// 00684083  53                   push ebx
// 00684084  55                   push ebp
// 00684085  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 0068408b  56                   push esi
// 0068408c  8bf1                 mov esi, ecx
// 0068408e  8b4618               mov eax, dword ptr [esi + 0x18]
// 00684091  8b18                 mov ebx, dword ptr [eax]
// 00684093  8b06                 mov eax, dword ptr [esi]
// 00684095  57                   push edi
// 00684096  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0068409a  85ff                 test edi, edi
// 0068409c  7404                 je 0x6840a2
// 0068409e  3bf8                 cmp edi, eax
// 006840a0  7406                 je 0x6840a8
// 006840a2  ffd5                 call ebp
// 006840a4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006840a8  395c2424             cmp dword ptr [esp + 0x24], ebx
// 006840ac  7562                 jne 0x684110
// 006840ae  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006840b2  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 006840b5  8b06                 mov eax, dword ptr [esi]
// 006840b7  85c9                 test ecx, ecx
// 006840b9  7404                 je 0x6840bf
// 006840bb  3bc8                 cmp ecx, eax
// 006840bd  7406                 je 0x6840c5
// 006840bf  ffd5                 call ebp
// 006840c1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006840c5  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 006840c9  7545                 jne 0x684110
// 006840cb  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006840ce  8b5104               mov edx, dword ptr [ecx + 4]
// 006840d1  52                   push edx
// 006840d2  8bce                 mov ecx, esi
// 006840d4  e867f1ffff           call 0x683240
// 006840d9  8b4618               mov eax, dword ptr [esi + 0x18]
// 006840dc  894004               mov dword ptr [eax + 4], eax
// 006840df  8b4618               mov eax, dword ptr [esi + 0x18]
// 006840e2  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 006840e9  8900                 mov dword ptr [eax], eax
// 006840eb  8b4618               mov eax, dword ptr [esi + 0x18]
// 006840ee  894008               mov dword ptr [eax + 8], eax
// 006840f1  8b4618               mov eax, dword ptr [esi + 0x18]
// 006840f4  8b16                 mov edx, dword ptr [esi]
// 006840f6  8b08                 mov ecx, dword ptr [eax]
// 006840f8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006840fc  5f                   pop edi
// 006840fd  5e                   pop esi
// 006840fe  5d                   pop ebp
// 006840ff  894804               mov dword ptr [eax + 4], ecx
// 00684102  8910                 mov dword ptr [eax], edx
// 00684104  5b                   pop ebx
// 00684105  83c408               add esp, 8
// 00684108  c21400               ret 0x14
// 0068410b  eb03                 jmp 0x684110
// 0068410d  8d4900               lea ecx, [ecx]
// 00684110  85ff                 test edi, edi
// 00684112  7406                 je 0x68411a
// 00684114  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 00684118  7406                 je 0x684120
// 0068411a  ffd5                 call ebp
// 0068411c  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00684120  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 00684124  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 00684128  741d                 je 0x684147
// 0068412a  8d4c2420             lea ecx, [esp + 0x20]
// 0068412e  e84d44ebff           call 0x538580
// 00684133  53                   push ebx
// 00684134  57                   push edi
// 00684135  8d442418             lea eax, [esp + 0x18]
// 00684139  50                   push eax
// 0068413a  8bce                 mov ecx, esi
// 0068413c  e83ff2ffff           call 0x683380
// 00684141  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00684145  ebc9                 jmp 0x684110
// 00684147  8b36                 mov esi, dword ptr [esi]
// 00684149  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0068414d  5f                   pop edi
// 0068414e  8930                 mov dword ptr [eax], esi
// 00684150  5e                   pop esi
// 00684151  5d                   pop ebp
// 00684152  895804               mov dword ptr [eax + 4], ebx
// 00684155  5b                   pop ebx
// 00684156  83c408               add esp, 8
// 00684159  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
