// from server: 100% by auto
// roc 2009-12 004777c0  unit: VCContent::?$CComObject  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004777c0
//
// 004777c0  6aff                 push -1
// 004777c2  68d8c59300           push 0x93c5d8
// 004777c7  64a100000000         mov eax, dword ptr fs:[0]
// 004777cd  50                   push eax
// 004777ce  64892500000000       mov dword ptr fs:[0], esp
// 004777d5  51                   push ecx
// 004777d6  56                   push esi
// 004777d7  8bf1                 mov esi, ecx
// 004777d9  6a04                 push 4
// 004777db  89742408             mov dword ptr [esp + 8], esi
// 004777df  e87cc03700           call 0x7f3860
// 004777e4  83c404               add esp, 4
// 004777e7  85c0                 test eax, eax
// 004777e9  7404                 je 0x4777ef
// 004777eb  8930                 mov dword ptr [eax], esi
// 004777ed  eb02                 jmp 0x4777f1
// 004777ef  33c0                 xor eax, eax
// 004777f1  8906                 mov dword ptr [esi], eax
// 004777f3  8bce                 mov ecx, esi
// 004777f5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004777fd  e88e712c00           call 0x73e990
// 00477802  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00477806  894618               mov dword ptr [esi + 0x18], eax
// 00477809  c6403101             mov byte ptr [eax + 0x31], 1
// 0047780d  8b4618               mov eax, dword ptr [esi + 0x18]
// 00477810  894004               mov dword ptr [eax + 4], eax
// 00477813  8b4618               mov eax, dword ptr [esi + 0x18]
// 00477816  8900                 mov dword ptr [eax], eax
// 00477818  8b4618               mov eax, dword ptr [esi + 0x18]
// 0047781b  894008               mov dword ptr [eax + 8], eax
// 0047781e  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 00477825  8bc6                 mov eax, esi
// 00477827  5e                   pop esi
// 00477828  64890d00000000       mov dword ptr fs:[0], ecx
// 0047782f  83c410               add esp, 0x10
// 00477832  c20800               ret 8
// standard library set<pod36> (function ??0?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@QAE@ABU?$less@UE@@@1@ABV?$allocator@UE@@@1@@Z)

// stl: set<pod36>
struct E { int v[9]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
