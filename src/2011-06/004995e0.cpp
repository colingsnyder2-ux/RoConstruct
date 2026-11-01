// from server: 100% by auto
// roc 2011-06 004995e0  unit: VerbBinderJob  size: 113 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004995e0
//
// 004995e0  55                   push ebp
// 004995e1  8bec                 mov ebp, esp
// 004995e3  6aff                 push -1
// 004995e5  68d06a9d00           push 0x9d6ad0
// 004995ea  64a100000000         mov eax, dword ptr fs:[0]
// 004995f0  50                   push eax
// 004995f1  64892500000000       mov dword ptr fs:[0], esp
// 004995f8  83ec08               sub esp, 8
// 004995fb  53                   push ebx
// 004995fc  56                   push esi
// 004995fd  57                   push edi
// 004995fe  8bf1                 mov esi, ecx
// 00499600  8965f0               mov dword ptr [ebp - 0x10], esp
// 00499603  8975ec               mov dword ptr [ebp - 0x14], esi
// 00499606  e895d00500           call 0x4f66a0
// 0049960b  894604               mov dword ptr [esi + 4], eax
// 0049960e  c6401901             mov byte ptr [eax + 0x19], 1
// 00499612  8b4604               mov eax, dword ptr [esi + 4]
// 00499615  894004               mov dword ptr [eax + 4], eax
// 00499618  8b4604               mov eax, dword ptr [esi + 4]
// 0049961b  8900                 mov dword ptr [eax], eax
// 0049961d  8b4604               mov eax, dword ptr [esi + 4]
// 00499620  894008               mov dword ptr [eax + 8], eax
// 00499623  8b4508               mov eax, dword ptr [ebp + 8]
// 00499626  50                   push eax
// 00499627  8bce                 mov ecx, esi
// 00499629  c7460800000000       mov dword ptr [esi + 8], 0
// 00499630  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00499637  e824ffffff           call 0x499560
// 0049963c  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0049963f  5f                   pop edi
// 00499640  8bc6                 mov eax, esi
// 00499642  5e                   pop esi
// 00499643  64890d00000000       mov dword ptr fs:[0], ecx
// 0049964a  5b                   pop ebx
// 0049964b  8be5                 mov esp, ebp
// 0049964d  5d                   pop ebp
// 0049964e  c20400               ret 4
// library ogre-1.6.4/OgreAlignedAllocator.cpp (function ??0?$_Tree@V?$_Tmap_traits@IUGpuLogicalIndexUse@Ogre@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUGpuLogicalIndexUse@Ogre@@@std@@@4@$0A@@std@@@std@@QAE@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAlignedAllocator.cpp
