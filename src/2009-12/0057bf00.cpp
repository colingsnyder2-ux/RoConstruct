// from server: 100% by auto
// roc 2009-12 0057bf00  unit: RBX::VCylinderMesh::?$FactoryProduct::Creator  size: 154 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0057bf00
//
// 0057bf00  64a100000000         mov eax, dword ptr fs:[0]
// 0057bf06  8b542404             mov edx, dword ptr [esp + 4]
// 0057bf0a  6aff                 push -1
// 0057bf0c  6812699500           push 0x956912
// 0057bf11  50                   push eax
// 0057bf12  64892500000000       mov dword ptr fs:[0], esp
// 0057bf19  8b4118               mov eax, dword ptr [ecx + 0x18]
// 0057bf1c  83ec44               sub esp, 0x44
// 0057bf1f  56                   push esi
// 0057bf20  beffffff1f           mov esi, 0x1fffffff
// 0057bf25  2bf0                 sub esi, eax
// 0057bf27  3bf2                 cmp esi, edx
// 0057bf29  5e                   pop esi
// 0057bf2a  7358                 jae 0x57bf84
// 0057bf2c  6884389a00           push 0x9a3884
// 0057bf31  8d4c2404             lea ecx, [esp + 4]
// 0057bf35  ff15f4b69800         call dword ptr [0x98b6f4]
// 0057bf3b  8d4c241c             lea ecx, [esp + 0x1c]
// 0057bf3f  c744244c00000000     mov dword ptr [esp + 0x4c], 0
// 0057bf47  ff1554b79800         call dword ptr [0x98b754]
// 0057bf4d  8d0424               lea eax, [esp]
// 0057bf50  50                   push eax
// 0057bf51  8d4c242c             lea ecx, [esp + 0x2c]
// 0057bf55  c644245001           mov byte ptr [esp + 0x50], 1
// 0057bf5a  c744242084f49900     mov dword ptr [esp + 0x20], 0x99f484
// 0057bf62  ff15f0b69800         call dword ptr [0x98b6f0]
// 0057bf68  68e4efa800           push 0xa8efe4
// 0057bf6d  8d4c2420             lea ecx, [esp + 0x20]
// 0057bf71  51                   push ecx
// 0057bf72  c644245400           mov byte ptr [esp + 0x54], 0
// 0057bf77  c744242490f49900     mov dword ptr [esp + 0x24], 0x99f490
// 0057bf7f  e8f4882700           call 0x7f4878
// 0057bf84  03c2                 add eax, edx
// 0057bf86  894118               mov dword ptr [ecx + 0x18], eax
// 0057bf89  8b4c2444             mov ecx, dword ptr [esp + 0x44]
// 0057bf8d  64890d00000000       mov dword ptr fs:[0], ecx
// 0057bf94  83c450               add esp, 0x50
// 0057bf97  c20400               ret 4
// standard library list<double> (function ?_Incsize@?$list@NV?$allocator@N@std@@@std@@IAEXI@Z)

// stl: list<double>
typedef double E;
#include <list>
template class std::list<E>;
