// from server: 100% by auto
// roc 2009-12 00564cd0  unit: CXTPRichRender::XTextHost  size: 110 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00564cd0
//
// 00564cd0  56                   push esi
// 00564cd1  8b742410             mov esi, dword ptr [esp + 0x10]
// 00564cd5  8d46fe               lea eax, [esi - 2]
// 00564cd8  83f80e               cmp eax, 0xe
// 00564cdb  7758                 ja 0x564d35
// 00564cdd  55                   push ebp
// 00564cde  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 00564ce2  57                   push edi
// 00564ce3  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00564ce7  8bcf                 mov ecx, edi
// 00564ce9  8bc5                 mov eax, ebp
// 00564ceb  eb03                 jmp 0x564cf0
// 00564ced  8d4900               lea ecx, [ecx]
// 00564cf0  99                   cdq 
// 00564cf1  f7fe                 idiv esi
// 00564cf3  85d2                 test edx, edx
// 00564cf5  7d02                 jge 0x564cf9
// 00564cf7  f7da                 neg edx
// 00564cf9  8a9248039c00         mov dl, byte ptr [edx + 0x9c0348]
// 00564cff  8811                 mov byte ptr [ecx], dl
// 00564d01  41                   inc ecx
// 00564d02  85c0                 test eax, eax
// 00564d04  75ea                 jne 0x564cf0
// 00564d06  85ed                 test ebp, ebp
// 00564d08  7d09                 jge 0x564d13
// 00564d0a  83fe0a               cmp esi, 0xa
// 00564d0d  7504                 jne 0x564d13
// 00564d0f  c6012d               mov byte ptr [ecx], 0x2d
// 00564d12  41                   inc ecx
// 00564d13  c60100               mov byte ptr [ecx], 0
// 00564d16  49                   dec ecx
// 00564d17  8bc7                 mov eax, edi
// 00564d19  3bf9                 cmp edi, ecx
// 00564d1b  7312                 jae 0x564d2f
// 00564d1d  53                   push ebx
// 00564d1e  8bff                 mov edi, edi
// 00564d20  8a19                 mov bl, byte ptr [ecx]
// 00564d22  8a10                 mov dl, byte ptr [eax]
// 00564d24  8818                 mov byte ptr [eax], bl
// 00564d26  8811                 mov byte ptr [ecx], dl
// 00564d28  40                   inc eax
// 00564d29  49                   dec ecx
// 00564d2a  3bc1                 cmp eax, ecx
// 00564d2c  72f2                 jb 0x564d20
// 00564d2e  5b                   pop ebx
// 00564d2f  8bc7                 mov eax, edi
// 00564d31  5f                   pop edi
// 00564d32  5d                   pop ebp
// 00564d33  5e                   pop esi
// 00564d34  c3                   ret 
// 00564d35  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00564d39  c60000               mov byte ptr [eax], 0
// 00564d3c  5e                   pop esi
// 00564d3d  c3                   ret 
// library raknet-4.081/Itoa.cpp (function _Itoa)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 Itoa.cpp
