// from server: 100% by auto
// roc 2010-06 0076f9b0  unit: RBX::ScoreHud  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0076f9b0
//
// 0076f9b0  6aff                 push -1
// 0076f9b2  6858a29900           push 0x99a258
// 0076f9b7  64a100000000         mov eax, dword ptr fs:[0]
// 0076f9bd  50                   push eax
// 0076f9be  64892500000000       mov dword ptr fs:[0], esp
// 0076f9c5  51                   push ecx
// 0076f9c6  56                   push esi
// 0076f9c7  8bf1                 mov esi, ecx
// 0076f9c9  6a04                 push 4
// 0076f9cb  89742408             mov dword ptr [esp + 8], esi
// 0076f9cf  e8cc7f0300           call 0x7a79a0
// 0076f9d4  83c404               add esp, 4
// 0076f9d7  85c0                 test eax, eax
// 0076f9d9  7404                 je 0x76f9df
// 0076f9db  8930                 mov dword ptr [eax], esi
// 0076f9dd  eb02                 jmp 0x76f9e1
// 0076f9df  33c0                 xor eax, eax
// 0076f9e1  8906                 mov dword ptr [esi], eax
// 0076f9e3  8bce                 mov ecx, esi
// 0076f9e5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0076f9ed  e82e81f7ff           call 0x6e7b20
// 0076f9f2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0076f9f6  894618               mov dword ptr [esi + 0x18], eax
// 0076f9f9  c6403101             mov byte ptr [eax + 0x31], 1
// 0076f9fd  8b4618               mov eax, dword ptr [esi + 0x18]
// 0076fa00  894004               mov dword ptr [eax + 4], eax
// 0076fa03  8b4618               mov eax, dword ptr [esi + 0x18]
// 0076fa06  8900                 mov dword ptr [eax], eax
// 0076fa08  8b4618               mov eax, dword ptr [esi + 0x18]
// 0076fa0b  894008               mov dword ptr [eax + 8], eax
// 0076fa0e  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0076fa15  8bc6                 mov eax, esi
// 0076fa17  5e                   pop esi
// 0076fa18  64890d00000000       mov dword ptr fs:[0], ecx
// 0076fa1f  83c410               add esp, 0x10
// 0076fa22  c20800               ret 8
// standard library set<pod36> (function ??0?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE@ABU?$less@UE@@@1@ABV?$allocator@UE@@@1@@Z)

// stl: set<pod36>
struct E { int v[9]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
