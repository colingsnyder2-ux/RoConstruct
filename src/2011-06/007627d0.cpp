// from server: 100% by auto
// roc 2011-06 007627d0  unit: seg_00760000  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007627d0
//
// 007627d0  8b442408             mov eax, dword ptr [esp + 8]
// 007627d4  56                   push esi
// 007627d5  57                   push edi
// 007627d6  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 007627da  8bcf                 mov ecx, edi
// 007627dc  e8cff9ffff           call 0x7621b0
// 007627e1  8bf0                 mov esi, eax
// 007627e3  8b4608               mov eax, dword ptr [esi + 8]
// 007627e6  83c0fd               add eax, -3
// 007627e9  83f804               cmp eax, 4
// 007627ec  7733                 ja 0x762821
// 007627ee  ff248528287600       jmp dword ptr [eax*4 + 0x762828]
// 007627f5  8b06                 mov eax, dword ptr [esi]
// 007627f7  8b400c               mov eax, dword ptr [eax + 0xc]
// 007627fa  5f                   pop edi
// 007627fb  5e                   pop esi
// 007627fc  c3                   ret 
// 007627fd  8b0e                 mov ecx, dword ptr [esi]
// 007627ff  8b4110               mov eax, dword ptr [ecx + 0x10]
// 00762802  5f                   pop edi
// 00762803  5e                   pop esi
// 00762804  c3                   ret 
// 00762805  8b16                 mov edx, dword ptr [esi]
// 00762807  52                   push edx
// 00762808  e8b3730700           call 0x7d9bc0
// 0076280d  83c404               add esp, 4
// 00762810  5f                   pop edi
// 00762811  5e                   pop esi
// 00762812  c3                   ret 
// 00762813  56                   push esi
// 00762814  57                   push edi
// 00762815  e8a64c0700           call 0x7d74c0
// 0076281a  83c408               add esp, 8
// 0076281d  85c0                 test eax, eax
// 0076281f  75d4                 jne 0x7627f5
// 00762821  5f                   pop edi
// 00762822  33c0                 xor eax, eax
// 00762824  5e                   pop esi
// 00762825  c3                   ret 
// 00762826  8bff                 mov edi, edi
// 00762828  1328                 adc ebp, dword ptr [eax]
// 0076282a  7600                 jbe 0x76282c
// 0076282c  f5                   cmc 
// 0076282d  27                   daa 
// 0076282e  7600                 jbe 0x762830
// 00762830  0528760021           add eax, 0x21007628
// 00762835  287600               sub byte ptr [esi], dh
// 00762838  fd                   std 
// 00762839  27                   daa 
// 0076283a  7600                 jbe 0x76283c
// library lua-5.1/lapi.c (function _lua_objlen)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
