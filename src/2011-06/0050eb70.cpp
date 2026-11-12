// from server: 100% by auto
// roc 2011-06 0050eb70  unit: RBX::Network::VMarker::?$EventDesc  size: 110 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0050eb70
//
// 0050eb70  56                   push esi
// 0050eb71  8b742410             mov esi, dword ptr [esp + 0x10]
// 0050eb75  8d46fe               lea eax, [esi - 2]
// 0050eb78  83f80e               cmp eax, 0xe
// 0050eb7b  7758                 ja 0x50ebd5
// 0050eb7d  55                   push ebp
// 0050eb7e  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 0050eb82  57                   push edi
// 0050eb83  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0050eb87  8bcf                 mov ecx, edi
// 0050eb89  8bc5                 mov eax, ebp
// 0050eb8b  eb03                 jmp 0x50eb90
// 0050eb8d  8d4900               lea ecx, [ecx]
// 0050eb90  99                   cdq 
// 0050eb91  f7fe                 idiv esi
// 0050eb93  85d2                 test edx, edx
// 0050eb95  7d02                 jge 0x50eb99
// 0050eb97  f7da                 neg edx
// 0050eb99  8a9228cfa700         mov dl, byte ptr [edx + 0xa7cf28]
// 0050eb9f  8811                 mov byte ptr [ecx], dl
// 0050eba1  41                   inc ecx
// 0050eba2  85c0                 test eax, eax
// 0050eba4  75ea                 jne 0x50eb90
// 0050eba6  85ed                 test ebp, ebp
// 0050eba8  7d09                 jge 0x50ebb3
// 0050ebaa  83fe0a               cmp esi, 0xa
// 0050ebad  7504                 jne 0x50ebb3
// 0050ebaf  c6012d               mov byte ptr [ecx], 0x2d
// 0050ebb2  41                   inc ecx
// 0050ebb3  c60100               mov byte ptr [ecx], 0
// 0050ebb6  49                   dec ecx
// 0050ebb7  8bc7                 mov eax, edi
// 0050ebb9  3bf9                 cmp edi, ecx
// 0050ebbb  7312                 jae 0x50ebcf
// 0050ebbd  53                   push ebx
// 0050ebbe  8bff                 mov edi, edi
// 0050ebc0  8a19                 mov bl, byte ptr [ecx]
// 0050ebc2  8a10                 mov dl, byte ptr [eax]
// 0050ebc4  8818                 mov byte ptr [eax], bl
// 0050ebc6  8811                 mov byte ptr [ecx], dl
// 0050ebc8  40                   inc eax
// 0050ebc9  49                   dec ecx
// 0050ebca  3bc1                 cmp eax, ecx
// 0050ebcc  72f2                 jb 0x50ebc0
// 0050ebce  5b                   pop ebx
// 0050ebcf  8bc7                 mov eax, edi
// 0050ebd1  5f                   pop edi
// 0050ebd2  5d                   pop ebp
// 0050ebd3  5e                   pop esi
// 0050ebd4  c3                   ret 
// 0050ebd5  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0050ebd9  c60000               mov byte ptr [eax], 0
// 0050ebdc  5e                   pop esi
// 0050ebdd  c3                   ret 
// library openrbx-raknet/RakNetTypes.cpp (function ?my_itoa@@YAPADHPADH@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakNetTypes.cpp
