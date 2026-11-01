// from server: 100% by auto
// roc 2009-12 00722370  unit: boost::iostreams::DUoutput::V?$basic_null_device::?$stream_buffer  size: 154 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00722370
//
// 00722370  64a100000000         mov eax, dword ptr fs:[0]
// 00722376  8b542404             mov edx, dword ptr [esp + 4]
// 0072237a  6aff                 push -1
// 0072237c  6812699500           push 0x956912
// 00722381  50                   push eax
// 00722382  64892500000000       mov dword ptr fs:[0], esp
// 00722389  8b4118               mov eax, dword ptr [ecx + 0x18]
// 0072238c  83ec44               sub esp, 0x44
// 0072238f  56                   push esi
// 00722390  beffffff3f           mov esi, 0x3fffffff
// 00722395  2bf0                 sub esi, eax
// 00722397  3bf2                 cmp esi, edx
// 00722399  5e                   pop esi
// 0072239a  7358                 jae 0x7223f4
// 0072239c  6884389a00           push 0x9a3884
// 007223a1  8d4c2404             lea ecx, [esp + 4]
// 007223a5  ff15f4b69800         call dword ptr [0x98b6f4]
// 007223ab  8d4c241c             lea ecx, [esp + 0x1c]
// 007223af  c744244c00000000     mov dword ptr [esp + 0x4c], 0
// 007223b7  ff1554b79800         call dword ptr [0x98b754]
// 007223bd  8d0424               lea eax, [esp]
// 007223c0  50                   push eax
// 007223c1  8d4c242c             lea ecx, [esp + 0x2c]
// 007223c5  c644245001           mov byte ptr [esp + 0x50], 1
// 007223ca  c744242084f49900     mov dword ptr [esp + 0x20], 0x99f484
// 007223d2  ff15f0b69800         call dword ptr [0x98b6f0]
// 007223d8  68e4efa800           push 0xa8efe4
// 007223dd  8d4c2420             lea ecx, [esp + 0x20]
// 007223e1  51                   push ecx
// 007223e2  c644245400           mov byte ptr [esp + 0x54], 0
// 007223e7  c744242490f49900     mov dword ptr [esp + 0x24], 0x99f490
// 007223ef  e884240d00           call 0x7f4878
// 007223f4  03c2                 add eax, edx
// 007223f6  894118               mov dword ptr [ecx + 0x18], eax
// 007223f9  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 007223fd  64890d00000000       mov dword ptr fs:[0], ecx
// 00722404  83c450               add esp, 0x50
// 00722407  c20400               ret 4
// standard library list<ptr> (function ?_Incsize@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEXI@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
