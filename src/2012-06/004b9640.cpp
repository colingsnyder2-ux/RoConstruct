// from server: 100% by auto
// roc 2012-06 004b9640  unit: Ogre::VResource::?$SharedPtr  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004b9640
//
// 004b9640  56                   push esi
// 004b9641  8bf1                 mov esi, ecx
// 004b9643  8b460c               mov eax, dword ptr [esi + 0xc]
// 004b9646  83e800               sub eax, 0
// 004b9649  57                   push edi
// 004b964a  8b3d042eb200         mov edi, dword ptr [0xb22e04]
// 004b9650  7445                 je 0x4b9697
// 004b9652  83e801               sub eax, 1
// 004b9655  741a                 je 0x4b9671
// 004b9657  83e801               sub eax, 1
// 004b965a  754a                 jne 0x4b96a6
// 004b965c  8b4604               mov eax, dword ptr [esi + 4]
// 004b965f  50                   push eax
// 004b9660  ffd7                 call edi
// 004b9662  8b4e08               mov ecx, dword ptr [esi + 8]
// 004b9665  83c404               add esp, 4
// 004b9668  51                   push ecx
// 004b9669  ffd7                 call edi
// 004b966b  83c404               add esp, 4
// 004b966e  5f                   pop edi
// 004b966f  5e                   pop esi
// 004b9670  c3                   ret 
// 004b9671  837e0400             cmp dword ptr [esi + 4], 0
// 004b9675  742f                 je 0x4b96a6
// 004b9677  8b4e04               mov ecx, dword ptr [esi + 4]
// 004b967a  8b11                 mov edx, dword ptr [ecx]
// 004b967c  8b02                 mov eax, dword ptr [edx]
// 004b967e  6a00                 push 0
// 004b9680  ffd0                 call eax
// 004b9682  8b4e04               mov ecx, dword ptr [esi + 4]
// 004b9685  51                   push ecx
// 004b9686  ffd7                 call edi
// 004b9688  8b4e08               mov ecx, dword ptr [esi + 8]
// 004b968b  83c404               add esp, 4
// 004b968e  51                   push ecx
// 004b968f  ffd7                 call edi
// 004b9691  83c404               add esp, 4
// 004b9694  5f                   pop edi
// 004b9695  5e                   pop esi
// 004b9696  c3                   ret 
// 004b9697  8b4e04               mov ecx, dword ptr [esi + 4]
// 004b969a  85c9                 test ecx, ecx
// 004b969c  7408                 je 0x4b96a6
// 004b969e  8b11                 mov edx, dword ptr [ecx]
// 004b96a0  8b02                 mov eax, dword ptr [edx]
// 004b96a2  6a01                 push 1
// 004b96a4  ffd0                 call eax
// 004b96a6  8b4e08               mov ecx, dword ptr [esi + 8]
// 004b96a9  51                   push ecx
// 004b96aa  ffd7                 call edi
// 004b96ac  83c404               add esp, 4
// 004b96af  5f                   pop edi
// 004b96b0  5e                   pop esi
// 004b96b1  c3                   ret 
// library ogre-1.7.0/OgreCompositionPass.cpp (function ?destroy@?$SharedPtr@VResource@Ogre@@@Ogre@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: ogre-1.7.0 OgreCompositionPass.cpp
