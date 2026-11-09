// from server: 100% by auto
// roc 2012-06 0062b840  unit: G3D::Sphere  size: 144 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062b840
//
// 0062b840  0f57c0               xorps xmm0, xmm0
// 0062b843  56                   push esi
// 0062b844  8bf1                 mov esi, ecx
// 0062b846  f30f1106             movss dword ptr [esi], xmm0
// 0062b84a  f30f114604           movss dword ptr [esi + 4], xmm0
// 0062b84f  f30f114608           movss dword ptr [esi + 8], xmm0
// 0062b854  f30f11460c           movss dword ptr [esi + 0xc], xmm0
// 0062b859  f30f114610           movss dword ptr [esi + 0x10], xmm0
// 0062b85e  f30f114614           movss dword ptr [esi + 0x14], xmm0
// 0062b863  f30f114618           movss dword ptr [esi + 0x18], xmm0
// 0062b868  f30f11461c           movss dword ptr [esi + 0x1c], xmm0
// 0062b86d  f30f114620           movss dword ptr [esi + 0x20], xmm0
// 0062b872  f30f1005b8abb500     movss xmm0, dword ptr [0xb5abb8]
// 0062b87a  f30f114624           movss dword ptr [esi + 0x24], xmm0
// 0062b87f  f30f10052039b800     movss xmm0, dword ptr [0xb83920]
// 0062b887  f30f114628           movss dword ptr [esi + 0x28], xmm0
// 0062b88c  c6462c00             mov byte ptr [esi + 0x2c], 0
// 0062b890  e80b040000           call 0x62bca0
// 0062b895  d900                 fld dword ptr [eax]
// 0062b897  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 0062b89f  d95e3c               fstp dword ptr [esi + 0x3c]
// 0062b8a2  d94004               fld dword ptr [eax + 4]
// 0062b8a5  d95e40               fstp dword ptr [esi + 0x40]
// 0062b8a8  d94008               fld dword ptr [eax + 8]
// 0062b8ab  b001                 mov al, 1
// 0062b8ad  d95e44               fstp dword ptr [esi + 0x44]
// 0062b8b0  f30f114630           movss dword ptr [esi + 0x30], xmm0
// 0062b8b5  0f57c0               xorps xmm0, xmm0
// 0062b8b8  884649               mov byte ptr [esi + 0x49], al
// 0062b8bb  88464a               mov byte ptr [esi + 0x4a], al
// 0062b8be  c6464800             mov byte ptr [esi + 0x48], 0
// 0062b8c2  f30f114634           movss dword ptr [esi + 0x34], xmm0
// 0062b8c7  f30f114638           movss dword ptr [esi + 0x38], xmm0
// 0062b8cc  8bc6                 mov eax, esi
// 0062b8ce  5e                   pop esi
// 0062b8cf  c3                   ret 
// library rbx2016-g3d/GLight.cpp (function ??0GLight@G3D@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d GLight.cpp
