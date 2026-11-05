// from server: 100% by auto
// roc 2011-06 009c6600  unit: seg_009c0000  size: 144 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 009c6600
//
// 009c6600  0f57c0               xorps xmm0, xmm0
// 009c6603  56                   push esi
// 009c6604  8bf1                 mov esi, ecx
// 009c6606  f30f1106             movss dword ptr [esi], xmm0
// 009c660a  f30f114604           movss dword ptr [esi + 4], xmm0
// 009c660f  f30f114608           movss dword ptr [esi + 8], xmm0
// 009c6614  f30f11460c           movss dword ptr [esi + 0xc], xmm0
// 009c6619  f30f114610           movss dword ptr [esi + 0x10], xmm0
// 009c661e  f30f114614           movss dword ptr [esi + 0x14], xmm0
// 009c6623  f30f114618           movss dword ptr [esi + 0x18], xmm0
// 009c6628  f30f11461c           movss dword ptr [esi + 0x1c], xmm0
// 009c662d  f30f114620           movss dword ptr [esi + 0x20], xmm0
// 009c6632  f30f100530eca600     movss xmm0, dword ptr [0xa6ec30]
// 009c663a  f30f114624           movss dword ptr [esi + 0x24], xmm0
// 009c663f  f30f10053827a900     movss xmm0, dword ptr [0xa92738]
// 009c6647  f30f114628           movss dword ptr [esi + 0x28], xmm0
// 009c664c  c6462c00             mov byte ptr [esi + 0x2c], 0
// 009c6650  e86b94b7ff           call 0x53fac0
// 009c6655  d900                 fld dword ptr [eax]
// 009c6657  f30f1005143ba600     movss xmm0, dword ptr [0xa63b14]
// 009c665f  d95e3c               fstp dword ptr [esi + 0x3c]
// 009c6662  d94004               fld dword ptr [eax + 4]
// 009c6665  d95e40               fstp dword ptr [esi + 0x40]
// 009c6668  d94008               fld dword ptr [eax + 8]
// 009c666b  b001                 mov al, 1
// 009c666d  d95e44               fstp dword ptr [esi + 0x44]
// 009c6670  f30f114630           movss dword ptr [esi + 0x30], xmm0
// 009c6675  0f57c0               xorps xmm0, xmm0
// 009c6678  884649               mov byte ptr [esi + 0x49], al
// 009c667b  88464a               mov byte ptr [esi + 0x4a], al
// 009c667e  c6464800             mov byte ptr [esi + 0x48], 0
// 009c6682  f30f114634           movss dword ptr [esi + 0x34], xmm0
// 009c6687  f30f114638           movss dword ptr [esi + 0x38], xmm0
// 009c668c  8bc6                 mov eax, esi
// 009c668e  5e                   pop esi
// 009c668f  c3                   ret 
// library rbx2016-g3d/GLight.cpp (function ??0GLight@G3D@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d GLight.cpp
