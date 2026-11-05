// from server: 100% by auto
// roc 2011-06 00762ed0  unit: seg_00760000  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00762ed0
//
// 00762ed0  8b442408             mov eax, dword ptr [esp + 8]
// 00762ed4  53                   push ebx
// 00762ed5  56                   push esi
// 00762ed6  57                   push edi
// 00762ed7  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00762edb  8bcf                 mov ecx, edi
// 00762edd  e8cef2ffff           call 0x7621b0
// 00762ee2  8b7708               mov esi, dword ptr [edi + 8]
// 00762ee5  8bd8                 mov ebx, eax
// 00762ee7  8b442418             mov eax, dword ptr [esp + 0x18]
// 00762eeb  8b0b                 mov ecx, dword ptr [ebx]
// 00762eed  50                   push eax
// 00762eee  51                   push ecx
// 00762eef  57                   push edi
// 00762ef0  83ee10               sub esi, 0x10
// 00762ef3  e8d86b0700           call 0x7d9ad0
// 00762ef8  8b16                 mov edx, dword ptr [esi]
// 00762efa  8910                 mov dword ptr [eax], edx
// 00762efc  8b4e04               mov ecx, dword ptr [esi + 4]
// 00762eff  894804               mov dword ptr [eax + 4], ecx
// 00762f02  8b5608               mov edx, dword ptr [esi + 8]
// 00762f05  895008               mov dword ptr [eax + 8], edx
// 00762f08  8b4708               mov eax, dword ptr [edi + 8]
// 00762f0b  b904000000           mov ecx, 4
// 00762f10  83c40c               add esp, 0xc
// 00762f13  3948f8               cmp dword ptr [eax - 8], ecx
// 00762f16  7c1a                 jl 0x762f32
// 00762f18  8b40f0               mov eax, dword ptr [eax - 0x10]
// 00762f1b  f6400503             test byte ptr [eax + 5], 3
// 00762f1f  7411                 je 0x762f32
// 00762f21  8b1b                 mov ebx, dword ptr [ebx]
// 00762f23  844b05               test byte ptr [ebx + 5], cl
// 00762f26  740a                 je 0x762f32
// 00762f28  53                   push ebx
// 00762f29  57                   push edi
// 00762f2a  e8a1430700           call 0x7d72d0
// 00762f2f  83c408               add esp, 8
// 00762f32  834708f0             add dword ptr [edi + 8], -0x10
// 00762f36  5f                   pop edi
// 00762f37  5e                   pop esi
// 00762f38  5b                   pop ebx
// 00762f39  c3                   ret 
// library lua-5.1/lapi.c (function _lua_rawseti)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
