// from server: 100% by auto
// roc 2012-06 004ae780  unit: VerbBinderJob  size: 113 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004ae780
//
// 004ae780  55                   push ebp
// 004ae781  8bec                 mov ebp, esp
// 004ae783  6aff                 push -1
// 004ae785  681047aa00           push 0xaa4710
// 004ae78a  64a100000000         mov eax, dword ptr fs:[0]
// 004ae790  50                   push eax
// 004ae791  64892500000000       mov dword ptr fs:[0], esp
// 004ae798  83ec08               sub esp, 8
// 004ae79b  53                   push ebx
// 004ae79c  56                   push esi
// 004ae79d  57                   push edi
// 004ae79e  8bf1                 mov esi, ecx
// 004ae7a0  8965f0               mov dword ptr [ebp - 0x10], esp
// 004ae7a3  8975ec               mov dword ptr [ebp - 0x14], esi
// 004ae7a6  e835890b00           call 0x5670e0
// 004ae7ab  894604               mov dword ptr [esi + 4], eax
// 004ae7ae  c6401901             mov byte ptr [eax + 0x19], 1
// 004ae7b2  8b4604               mov eax, dword ptr [esi + 4]
// 004ae7b5  894004               mov dword ptr [eax + 4], eax
// 004ae7b8  8b4604               mov eax, dword ptr [esi + 4]
// 004ae7bb  8900                 mov dword ptr [eax], eax
// 004ae7bd  8b4604               mov eax, dword ptr [esi + 4]
// 004ae7c0  894008               mov dword ptr [eax + 8], eax
// 004ae7c3  8b4508               mov eax, dword ptr [ebp + 8]
// 004ae7c6  50                   push eax
// 004ae7c7  8bce                 mov ecx, esi
// 004ae7c9  c7460800000000       mov dword ptr [esi + 8], 0
// 004ae7d0  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004ae7d7  e824feffff           call 0x4ae600
// 004ae7dc  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004ae7df  5f                   pop edi
// 004ae7e0  8bc6                 mov eax, esi
// 004ae7e2  5e                   pop esi
// 004ae7e3  64890d00000000       mov dword ptr fs:[0], ecx
// 004ae7ea  5b                   pop ebx
// 004ae7eb  8be5                 mov esp, ebp
// 004ae7ed  5d                   pop ebp
// 004ae7ee  c20400               ret 4
// library ogre-1.6.4/OgreAlignedAllocator.cpp (function ??0?$_Tree@V?$_Tmap_traits@IUGpuLogicalIndexUse@Ogre@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUGpuLogicalIndexUse@Ogre@@@std@@@4@$0A@@std@@@std@@QAE@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAlignedAllocator.cpp
