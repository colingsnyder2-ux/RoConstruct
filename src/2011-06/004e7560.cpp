// from server: 100% by Yeetserama
// roc 2011-06 004e7560  unit: RBX::VHint::?$FactoryProduct::Creator  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004e7560
//
// 004e7560  56                   push esi
// 004e7561  8bf1                 mov esi, ecx
// 004e7563  e8d8fcffff           call 0x4e7240
// 004e7568  84c0                 test al, al
// 004e756a  7528                 jne 0x4e7594
// 004e756c  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004e7570  6a02                 push 2
// 004e7572  8d44240c             lea eax, [esp + 0xc]
// 004e7576  50                   push eax
// 004e7577  51                   push ecx
// 004e7578  e823580000           call 0x4ecda0
// 004e757d  83c40c               add esp, 0xc
// 004e7580  6a01                 push 1
// 004e7582  6a10                 push 0x10
// 004e7584  8d542410             lea edx, [esp + 0x10]
// 004e7588  52                   push edx
// 004e7589  8bce                 mov ecx, esi
// 004e758b  e8405a0000           call 0x4ecfd0
// 004e7590  5e                   pop esi
// 004e7591  c20400               ret 4
// 004e7594  8b442408             mov eax, dword ptr [esp + 8]
// 004e7598  6a01                 push 1
// 004e759a  6a10                 push 0x10
// 004e759c  50                   push eax
// 004e759d  8bce                 mov ecx, esi
// 004e759f  e82c5a0000           call 0x4ecfd0
// 004e75a4  5e                   pop esi
// 004e75a5  c20400               ret 4
// copied from an identical function in another client (function ??$Write@G@BitStream@RakNet@@QAEXABG@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 FullyConnectedMesh2.cpp