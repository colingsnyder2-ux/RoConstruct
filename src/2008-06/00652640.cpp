// from server: 100% by auto
// roc 2008-06 00652640  unit: RBX::ScoreHud  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00652640
//
// 00652640  83ec14               sub esp, 0x14
// 00652643  56                   push esi
// 00652644  8bf1                 mov esi, ecx
// 00652646  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 0065264a  57                   push edi
// 0065264b  7521                 jne 0x65266e
// 0065264d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00652651  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00652654  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00652658  50                   push eax
// 00652659  51                   push ecx
// 0065265a  6a01                 push 1
// 0065265c  57                   push edi
// 0065265d  8bce                 mov ecx, esi
// 0065265f  e8dcf4ffff           call 0x651b40
// 00652664  8bc7                 mov eax, edi
// 00652666  5f                   pop edi
// 00652667  5e                   pop esi
// 00652668  83c414               add esp, 0x14
// 0065266b  c21000               ret 0x10
// 0065266e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00652672  8b5618               mov edx, dword ptr [esi + 0x18]
// 00652675  8b3a                 mov edi, dword ptr [edx]
// 00652677  8b06                 mov eax, dword ptr [esi]
// 00652679  53                   push ebx
// 0065267a  8b1d90288000         mov ebx, dword ptr [0x802890]
// 00652680  85c9                 test ecx, ecx
// 00652682  7404                 je 0x652688
// 00652684  3bc8                 cmp ecx, eax
// 00652686  7406                 je 0x65268e
// 00652688  ffd3                 call ebx
// 0065268a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0065268e  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00652692  3bc7                 cmp eax, edi
// 00652694  752a                 jne 0x6526c0
// 00652696  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0065269a  8b0f                 mov ecx, dword ptr [edi]
// 0065269c  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 0065269f  0f834b010000         jae 0x6527f0
// 006526a5  57                   push edi
// 006526a6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 006526aa  50                   push eax
// 006526ab  6a01                 push 1
// 006526ad  57                   push edi
// 006526ae  8bce                 mov ecx, esi
// 006526b0  e88bf4ffff           call 0x651b40
// 006526b5  5b                   pop ebx
// 006526b6  8bc7                 mov eax, edi
// 006526b8  5f                   pop edi
// 006526b9  5e                   pop esi
// 006526ba  83c414               add esp, 0x14
// 006526bd  c21000               ret 0x10
// 006526c0  8b7e18               mov edi, dword ptr [esi + 0x18]
// 006526c3  8b16                 mov edx, dword ptr [esi]
// 006526c5  85c9                 test ecx, ecx
// 006526c7  7404                 je 0x6526cd
// 006526c9  3bca                 cmp ecx, edx
// 006526cb  740a                 je 0x6526d7
// 006526cd  ffd3                 call ebx
// 006526cf  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006526d3  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006526d7  3bc7                 cmp eax, edi
// 006526d9  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 006526dd  752c                 jne 0x65270b
// 006526df  8b5618               mov edx, dword ptr [esi + 0x18]
// 006526e2  8b4208               mov eax, dword ptr [edx + 8]
// 006526e5  8b480c               mov ecx, dword ptr [eax + 0xc]
// 006526e8  3b0f                 cmp ecx, dword ptr [edi]
// 006526ea  0f8300010000         jae 0x6527f0
// 006526f0  57                   push edi
// 006526f1  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 006526f5  50                   push eax
// 006526f6  6a00                 push 0
// 006526f8  57                   push edi
// 006526f9  8bce                 mov ecx, esi
// 006526fb  e840f4ffff           call 0x651b40
// 00652700  5b                   pop ebx
// 00652701  8bc7                 mov eax, edi
// 00652703  5f                   pop edi
// 00652704  5e                   pop esi
// 00652705  83c414               add esp, 0x14
// 00652708  c21000               ret 0x10
// 0065270b  8b17                 mov edx, dword ptr [edi]
// 0065270d  39500c               cmp dword ptr [eax + 0xc], edx
// 00652710  7663                 jbe 0x652775
// 00652712  894c240c             mov dword ptr [esp + 0xc], ecx
// 00652716  8d4c240c             lea ecx, [esp + 0xc]
// 0065271a  89442410             mov dword ptr [esp + 0x10], eax
// 0065271e  e8bd5fdeff           call 0x4386e0
// 00652723  8b17                 mov edx, dword ptr [edi]
// 00652725  8b442410             mov eax, dword ptr [esp + 0x10]
// 00652729  39500c               cmp dword ptr [eax + 0xc], edx
// 0065272c  733c                 jae 0x65276a
// 0065272e  8b5008               mov edx, dword ptr [eax + 8]
// 00652731  807a2900             cmp byte ptr [edx + 0x29], 0
// 00652735  57                   push edi
// 00652736  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0065273a  8bce                 mov ecx, esi
// 0065273c  7414                 je 0x652752
// 0065273e  50                   push eax
// 0065273f  6a00                 push 0
// 00652741  57                   push edi
// 00652742  e8f9f3ffff           call 0x651b40
// 00652747  5b                   pop ebx
// 00652748  8bc7                 mov eax, edi
// 0065274a  5f                   pop edi
// 0065274b  5e                   pop esi
// 0065274c  83c414               add esp, 0x14
// 0065274f  c21000               ret 0x10
// 00652752  8b442430             mov eax, dword ptr [esp + 0x30]
// 00652756  50                   push eax
// 00652757  6a01                 push 1
// 00652759  57                   push edi
// 0065275a  e8e1f3ffff           call 0x651b40
// 0065275f  5b                   pop ebx
// 00652760  8bc7                 mov eax, edi
// 00652762  5f                   pop edi
// 00652763  5e                   pop esi
// 00652764  83c414               add esp, 0x14
// 00652767  c21000               ret 0x10
// 0065276a  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0065276e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00652772  39500c               cmp dword ptr [eax + 0xc], edx
// 00652775  7379                 jae 0x6527f0
// 00652777  8b16                 mov edx, dword ptr [esi]
// 00652779  894c240c             mov dword ptr [esp + 0xc], ecx
// 0065277d  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00652780  894c2418             mov dword ptr [esp + 0x18], ecx
// 00652784  8d4c240c             lea ecx, [esp + 0xc]
// 00652788  89442410             mov dword ptr [esp + 0x10], eax
// 0065278c  89542414             mov dword ptr [esp + 0x14], edx
// 00652790  e8db5fdeff           call 0x438770
// 00652795  8d442414             lea eax, [esp + 0x14]
// 00652799  50                   push eax
// 0065279a  8d4c2410             lea ecx, [esp + 0x10]
// 0065279e  e8fda4f9ff           call 0x5ecca0
// 006527a3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006527a7  84c0                 test al, al
// 006527a9  7507                 jne 0x6527b2
// 006527ab  8b17                 mov edx, dword ptr [edi]
// 006527ad  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 006527b0  733e                 jae 0x6527f0
// 006527b2  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006527b6  8b5008               mov edx, dword ptr [eax + 8]
// 006527b9  807a2900             cmp byte ptr [edx + 0x29], 0
// 006527bd  57                   push edi
// 006527be  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 006527c2  7416                 je 0x6527da
// 006527c4  50                   push eax
// 006527c5  6a00                 push 0
// 006527c7  57                   push edi
// 006527c8  8bce                 mov ecx, esi
// 006527ca  e871f3ffff           call 0x651b40
// 006527cf  5b                   pop ebx
// 006527d0  8bc7                 mov eax, edi
// 006527d2  5f                   pop edi
// 006527d3  5e                   pop esi
// 006527d4  83c414               add esp, 0x14
// 006527d7  c21000               ret 0x10
// 006527da  51                   push ecx
// 006527db  6a01                 push 1
// 006527dd  57                   push edi
// 006527de  8bce                 mov ecx, esi
// 006527e0  e85bf3ffff           call 0x651b40
// 006527e5  5b                   pop ebx
// 006527e6  8bc7                 mov eax, edi
// 006527e8  5f                   pop edi
// 006527e9  5e                   pop esi
// 006527ea  83c414               add esp, 0x14
// 006527ed  c21000               ret 0x10
// 006527f0  57                   push edi
// 006527f1  8d442418             lea eax, [esp + 0x18]
// 006527f5  50                   push eax
// 006527f6  8bce                 mov ecx, esi
// 006527f8  e863f6ffff           call 0x651e60
// 006527fd  8b10                 mov edx, dword ptr [eax]
// 006527ff  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00652803  5b                   pop ebx
// 00652804  8911                 mov dword ptr [ecx], edx
// 00652806  8b4004               mov eax, dword ptr [eax + 4]
// 00652809  5f                   pop edi
// 0065280a  894104               mov dword ptr [ecx + 4], eax
// 0065280d  8bc1                 mov eax, ecx
// 0065280f  5e                   pop esi
// 00652810  83c414               add esp, 0x14
// 00652813  c21000               ret 0x10
// standard library map_ptr<pod24> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod24>
struct E { int v[6]; };
#include <map>
struct K; template class std::map<K*, E>;
