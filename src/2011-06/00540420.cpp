// from server: 100% by auto
// roc 2011-06 00540420  unit: G3D::MemoryManager  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00540420
//
// 00540420  8b442404             mov eax, dword ptr [esp + 4]
// 00540424  f30f1005dc5ca700     movss xmm0, dword ptr [0xa75cdc]
// 0054042c  56                   push esi
// 0054042d  8bf1                 mov esi, ecx
// 0054042f  57                   push edi
// 00540430  8d5004               lea edx, [eax + 4]
// 00540433  2bf0                 sub esi, eax
// 00540435  bf03000000           mov edi, 3
// 0054043a  8d9b00000000         lea ebx, [ebx]
// 00540440  0f28c8               movaps xmm1, xmm0
// 00540443  f30f5c09             subss xmm1, dword ptr [ecx]
// 00540447  f30f114afc           movss dword ptr [edx - 4], xmm1
// 0054044c  0f28c8               movaps xmm1, xmm0
// 0054044f  f30f5c0c16           subss xmm1, dword ptr [esi + edx]
// 00540454  f30f110a             movss dword ptr [edx], xmm1
// 00540458  0f28c8               movaps xmm1, xmm0
// 0054045b  f30f5c4908           subss xmm1, dword ptr [ecx + 8]
// 00540460  f30f114a04           movss dword ptr [edx + 4], xmm1
// 00540465  83c10c               add ecx, 0xc
// 00540468  83c20c               add edx, 0xc
// 0054046b  83ef01               sub edi, 1
// 0054046e  75d0                 jne 0x540440
// 00540470  5f                   pop edi
// 00540471  5e                   pop esi
// 00540472  c20400               ret 4
// library rbx2016-g3d/Matrix3.cpp (function ??GMatrix3@G3D@@QBE?AV01@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Matrix3.cpp
