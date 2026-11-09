// from server: 100% by auto
// roc 2011-06 00545300  unit: G3D::BinaryInput  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00545300
//
// 00545300  53                   push ebx
// 00545301  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00545305  56                   push esi
// 00545306  8bc3                 mov eax, ebx
// 00545308  57                   push edi
// 00545309  8bf1                 mov esi, ecx
// 0054530b  8d5001               lea edx, [eax + 1]
// 0054530e  8bff                 mov edi, edi
// 00545310  8a08                 mov cl, byte ptr [eax]
// 00545312  40                   inc eax
// 00545313  84c9                 test cl, cl
// 00545315  75f9                 jne 0x545310
// 00545317  8b4e38               mov ecx, dword ptr [esi + 0x38]
// 0054531a  2bc2                 sub eax, edx
// 0054531c  8d7801               lea edi, [eax + 1]
// 0054531f  8b4640               mov eax, dword ptr [esi + 0x40]
// 00545322  03c7                 add eax, edi
// 00545324  3bc8                 cmp ecx, eax
// 00545326  7c02                 jl 0x54532a
// 00545328  8bc1                 mov eax, ecx
// 0054532a  3b463c               cmp eax, dword ptr [esi + 0x3c]
// 0054532d  894638               mov dword ptr [esi + 0x38], eax
// 00545330  7e09                 jle 0x54533b
// 00545332  51                   push ecx
// 00545333  57                   push edi
// 00545334  8bce                 mov ecx, esi
// 00545336  e8f5fdffff           call 0x545130
// 0054533b  8b4634               mov eax, dword ptr [esi + 0x34]
// 0054533e  034640               add eax, dword ptr [esi + 0x40]
// 00545341  57                   push edi
// 00545342  53                   push ebx
// 00545343  50                   push eax
// 00545344  e89797ffff           call 0x53eae0
// 00545349  017e40               add dword ptr [esi + 0x40], edi
// 0054534c  83c40c               add esp, 0xc
// 0054534f  5f                   pop edi
// 00545350  5e                   pop esi
// 00545351  5b                   pop ebx
// 00545352  c20400               ret 4
// library rbx2016-g3d/BinaryOutput.cpp (function ?writeString@BinaryOutput@G3D@@QAEXPBD@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d BinaryOutput.cpp
