// from server: 100% by auto
// roc 2012-06 004076b0  unit: VCApp::?$CComObject  size: 136 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004076b0
//
// 004076b0  51                   push ecx
// 004076b1  8b01                 mov eax, dword ptr [ecx]
// 004076b3  56                   push esi
// 004076b4  85c0                 test eax, eax
// 004076b6  750d                 jne 0x4076c5
// 004076b8  3944240c             cmp dword ptr [esp + 0xc], eax
// 004076bc  7573                 jne 0x407731
// 004076be  b001                 mov al, 1
// 004076c0  5e                   pop esi
// 004076c1  59                   pop ecx
// 004076c2  c20400               ret 4
// 004076c5  8b74240c             mov esi, dword ptr [esp + 0xc]
// 004076c9  85f6                 test esi, esi
// 004076cb  7464                 je 0x407731
// 004076cd  53                   push ebx
// 004076ce  8d542410             lea edx, [esp + 0x10]
// 004076d2  52                   push edx
// 004076d3  c744241400000000     mov dword ptr [esp + 0x14], 0
// 004076db  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 004076e3  8b08                 mov ecx, dword ptr [eax]
// 004076e5  68503ab400           push 0xb43a50
// 004076ea  50                   push eax
// 004076eb  8b01                 mov eax, dword ptr [ecx]
// 004076ed  ffd0                 call eax
// 004076ef  8b0e                 mov ecx, dword ptr [esi]
// 004076f1  8b01                 mov eax, dword ptr [ecx]
// 004076f3  8d542408             lea edx, [esp + 8]
// 004076f7  52                   push edx
// 004076f8  68503ab400           push 0xb43a50
// 004076fd  56                   push esi
// 004076fe  ffd0                 call eax
// 00407700  8b442408             mov eax, dword ptr [esp + 8]
// 00407704  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00407708  3bc8                 cmp ecx, eax
// 0040770a  0f94c3               sete bl
// 0040770d  85c0                 test eax, eax
// 0040770f  740c                 je 0x40771d
// 00407711  8b08                 mov ecx, dword ptr [eax]
// 00407713  8b5108               mov edx, dword ptr [ecx + 8]
// 00407716  50                   push eax
// 00407717  ffd2                 call edx
// 00407719  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0040771d  85c9                 test ecx, ecx
// 0040771f  7408                 je 0x407729
// 00407721  8b01                 mov eax, dword ptr [ecx]
// 00407723  51                   push ecx
// 00407724  8b4808               mov ecx, dword ptr [eax + 8]
// 00407727  ffd1                 call ecx
// 00407729  8ac3                 mov al, bl
// 0040772b  5b                   pop ebx
// 0040772c  5e                   pop esi
// 0040772d  59                   pop ecx
// 0040772e  c20400               ret 4
// 00407731  32c0                 xor al, al
// 00407733  5e                   pop esi
// 00407734  59                   pop ecx
// 00407735  c20400               ret 4
// library atl-9.0/atl.cpp (function ?IsEqualObject@?$CComPtrBase@UITypeInfo@@@ATL@@QAE_NPAUIUnknown@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
