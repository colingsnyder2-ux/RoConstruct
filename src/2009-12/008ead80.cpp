// from server: 100% by auto
// roc 2009-12 008ead80  unit: CXTPScrollBase  size: 125 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008ead80
//
// 008ead80  8b442404             mov eax, dword ptr [esp + 4]
// 008ead84  56                   push esi
// 008ead85  8bf1                 mov esi, ecx
// 008ead87  837e5c00             cmp dword ptr [esi + 0x5c], 0
// 008ead8b  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008ead8f  57                   push edi
// 008ead90  8bf9                 mov edi, ecx
// 008ead92  7502                 jne 0x8ead96
// 008ead94  8bf8                 mov edi, eax
// 008ead96  51                   push ecx
// 008ead97  50                   push eax
// 008ead98  8d4648               lea eax, [esi + 0x48]
// 008ead9b  50                   push eax
// 008ead9c  ff155cca9800         call dword ptr [0x98ca5c]
// 008eada2  85c0                 test eax, eax
// 008eada4  7505                 jne 0x8eadab
// 008eada6  5f                   pop edi
// 008eada7  5e                   pop esi
// 008eada8  c20800               ret 8
// 008eadab  3b7e28               cmp edi, dword ptr [esi + 0x28]
// 008eadae  7d0a                 jge 0x8eadba
// 008eadb0  5f                   pop edi
// 008eadb1  b83c000000           mov eax, 0x3c
// 008eadb6  5e                   pop esi
// 008eadb7  c20800               ret 8
// 008eadba  8b463c               mov eax, dword ptr [esi + 0x3c]
// 008eadbd  85c0                 test eax, eax
// 008eadbf  7e0e                 jle 0x8eadcf
// 008eadc1  3bf8                 cmp edi, eax
// 008eadc3  7e0a                 jle 0x8eadcf
// 008eadc5  5f                   pop edi
// 008eadc6  b841000000           mov eax, 0x41
// 008eadcb  5e                   pop esi
// 008eadcc  c20800               ret 8
// 008eadcf  3b7e2c               cmp edi, dword ptr [esi + 0x2c]
// 008eadd2  7c0a                 jl 0x8eadde
// 008eadd4  5f                   pop edi
// 008eadd5  b83d000000           mov eax, 0x3d
// 008eadda  5e                   pop esi
// 008eaddb  c20800               ret 8
// 008eadde  3b7e38               cmp edi, dword ptr [esi + 0x38]
// 008eade1  7d0a                 jge 0x8eaded
// 008eade3  5f                   pop edi
// 008eade4  b83e000000           mov eax, 0x3e
// 008eade9  5e                   pop esi
// 008eadea  c20800               ret 8
// 008eaded  33c0                 xor eax, eax
// 008eadef  3b7e34               cmp edi, dword ptr [esi + 0x34]
// 008eadf2  5f                   pop edi
// 008eadf3  0f9cc0               setl al
// 008eadf6  5e                   pop esi
// 008eadf7  83c03f               add eax, 0x3f
// 008eadfa  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPScrollBase.cpp (function ?HitTestScrollBar@CXTPScrollBase@@QBEHUtagPOINT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPScrollBase.cpp
