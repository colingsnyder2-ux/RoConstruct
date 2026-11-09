// from server: 100% by auto
// roc 2012-06 0050c860  unit: Ogre::RbxSpatialHashedSceneNode::?3??_findVisibleObjects::NodeVisiter  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0050c860
//
// 0050c860  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0050c864  8bc1                 mov eax, ecx
// 0050c866  85c9                 test ecx, ecx
// 0050c868  7d02                 jge 0x50c86c
// 0050c86a  f7d8                 neg eax
// 0050c86c  f30f101540c4b400     movss xmm2, dword ptr [0xb4c440]
// 0050c874  f30f104c2404         movss xmm1, dword ptr [esp + 4]
// 0050c87a  0f28c2               movaps xmm0, xmm2
// 0050c87d  8d4900               lea ecx, [ecx]
// 0050c880  a801                 test al, 1
// 0050c882  7404                 je 0x50c888
// 0050c884  f30f59c1             mulss xmm0, xmm1
// 0050c888  d1e8                 shr eax, 1
// 0050c88a  740c                 je 0x50c898
// 0050c88c  0f28d9               movaps xmm3, xmm1
// 0050c88f  f30f59d9             mulss xmm3, xmm1
// 0050c893  0f28cb               movaps xmm1, xmm3
// 0050c896  ebe8                 jmp 0x50c880
// 0050c898  85c9                 test ecx, ecx
// 0050c89a  7d0f                 jge 0x50c8ab
// 0050c89c  f30f5ed0             divss xmm2, xmm0
// 0050c8a0  f30f11542408         movss dword ptr [esp + 8], xmm2
// 0050c8a6  d9442408             fld dword ptr [esp + 8]
// 0050c8aa  c3                   ret 
// 0050c8ab  f30f11442408         movss dword ptr [esp + 8], xmm0
// 0050c8b1  d9442408             fld dword ptr [esp + 8]
// 0050c8b5  c3                   ret 
// library rbx2016-g3d/Capsule.cpp (function ??$_Pow_int@M@@YAMMH@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Capsule.cpp
