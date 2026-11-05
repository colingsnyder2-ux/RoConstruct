// roc 2012-06 00a7bdc5  unit: CXTIconHandle  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a7bdc5
//
// 00a7bdc5  8bff                 mov edi, edi
// 00a7bdc7  55                   push ebp
// 00a7bdc8  8bec                 mov ebp, esp
// 00a7bdca  8bc1                 mov eax, ecx
// 00a7bdcc  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00a7bdcf  894804               mov dword ptr [eax + 4], ecx
// 00a7bdd2  c70054bbc200         mov dword ptr [eax], 0xc2bb54
// 00a7bdd8  33c9                 xor ecx, ecx
// 00a7bdda  c7401402000000       mov dword ptr [eax + 0x14], 2
// 00a7bde1  89480c               mov dword ptr [eax + 0xc], ecx
// 00a7bde4  894810               mov dword ptr [eax + 0x10], ecx
// 00a7bde7  66894818             mov word ptr [eax + 0x18], cx
// 00a7bdeb  6689481a             mov word ptr [eax + 0x1a], cx
// 00a7bdef  894008               mov dword ptr [eax + 8], eax
// 00a7bdf2  5d                   pop ebp
// 00a7bdf3  c20400               ret 4
// copied from an identical function in another client (function ??0CAtlStringMgr@ATL@@QAE@PAUIAtlMemMgr@1@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-archive: msvc-atlmfc-rtm atls.lib/f:/dd/vctools/vc7libs/ship/atlmfc/src/atl/atls/staticrelease/obj1r/i386/atlstr.obj