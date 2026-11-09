// roc 2012-06 005a7e90  unit: RBX::Image  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005a7e90
//
// 005a7e90  56                   push esi
// 005a7e91  57                   push edi
// 005a7e92  8bf1                 mov esi, ecx
// 005a7e94  e827ffffff           call 0x5a7dc0
// 005a7e99  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005a7e9d  8b07                 mov eax, dword ptr [edi]
// 005a7e9f  3db804d900           cmp eax, 0xd904b8
// 005a7ea4  7433                 je 0x5a7ed9
// 005a7ea6  8b08                 mov ecx, dword ptr [eax]
// 005a7ea8  e8b310e7ff           call 0x418f60
// 005a7ead  8b07                 mov eax, dword ptr [edi]
// 005a7eaf  83780400             cmp dword ptr [eax + 4], 0
// 005a7eb3  7516                 jne 0x5a7ecb
// 005a7eb5  c706b804d900         mov dword ptr [esi], 0xd904b8
// 005a7ebb  8b07                 mov eax, dword ptr [edi]
// 005a7ebd  8b08                 mov ecx, dword ptr [eax]
// 005a7ebf  e8ac10e7ff           call 0x418f70
// 005a7ec4  5f                   pop edi
// 005a7ec5  8bc6                 mov eax, esi
// 005a7ec7  5e                   pop esi
// 005a7ec8  c20400               ret 4
// 005a7ecb  8906                 mov dword ptr [esi], eax
// 005a7ecd  ff4004               inc dword ptr [eax + 4]
// 005a7ed0  8b07                 mov eax, dword ptr [edi]
// 005a7ed2  8b08                 mov ecx, dword ptr [eax]
// 005a7ed4  e89710e7ff           call 0x418f70
// 005a7ed9  5f                   pop edi
// 005a7eda  8bc6                 mov eax, esi
// 005a7edc  5e                   pop esi
// 005a7edd  c20400               ret 4
// copied from an identical function in another client (function ??4RakString@RakNet@@QAEAAV01@ABV01@@Z)

// roc-cl: 30729
// roc-lang: cpp
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: raknet-4.081 RakString.cpp