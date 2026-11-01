// from server: 100% by auto
// roc 2009-12 00487520  unit: Ogre::GfxClustererPart  size: 562 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00487520
//
// 00487520  83ec14               sub esp, 0x14
// 00487523  56                   push esi
// 00487524  8bf1                 mov esi, ecx
// 00487526  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 0048752a  57                   push edi
// 0048752b  7521                 jne 0x48754e
// 0048752d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00487531  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00487534  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00487538  50                   push eax
// 00487539  51                   push ecx
// 0048753a  6a01                 push 1
// 0048753c  57                   push edi
// 0048753d  8bce                 mov ecx, esi
// 0048753f  e87cefffff           call 0x4864c0
// 00487544  8bc7                 mov eax, edi
// 00487546  5f                   pop edi
// 00487547  5e                   pop esi
// 00487548  83c414               add esp, 0x14
// 0048754b  c21000               ret 0x10
// 0048754e  8b442424             mov eax, dword ptr [esp + 0x24]
// 00487552  8b5618               mov edx, dword ptr [esi + 0x18]
// 00487555  8b3a                 mov edi, dword ptr [edx]
// 00487557  8b0e                 mov ecx, dword ptr [esi]
// 00487559  53                   push ebx
// 0048755a  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 00487560  85c0                 test eax, eax
// 00487562  7404                 je 0x487568
// 00487564  3bc1                 cmp eax, ecx
// 00487566  7406                 je 0x48756e
// 00487568  ffd3                 call ebx
// 0048756a  8b442428             mov eax, dword ptr [esp + 0x28]
// 0048756e  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 00487572  55                   push ebp
// 00487573  3bd7                 cmp edx, edi
// 00487575  753a                 jne 0x4875b1
// 00487577  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 0048757b  83c20c               add edx, 0xc
// 0048757e  52                   push edx
// 0048757f  57                   push edi
// 00487580  ff15d8b59800         call dword ptr [0x98b5d8]
// 00487586  83c408               add esp, 8
// 00487589  84c0                 test al, al
// 0048758b  0f849a010000         je 0x48772b
// 00487591  8b442430             mov eax, dword ptr [esp + 0x30]
// 00487595  57                   push edi
// 00487596  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0048759a  50                   push eax
// 0048759b  6a01                 push 1
// 0048759d  57                   push edi
// 0048759e  8bce                 mov ecx, esi
// 004875a0  e81befffff           call 0x4864c0
// 004875a5  5d                   pop ebp
// 004875a6  5b                   pop ebx
// 004875a7  8bc7                 mov eax, edi
// 004875a9  5f                   pop edi
// 004875aa  5e                   pop esi
// 004875ab  83c414               add esp, 0x14
// 004875ae  c21000               ret 0x10
// 004875b1  8b7e18               mov edi, dword ptr [esi + 0x18]
// 004875b4  8b0e                 mov ecx, dword ptr [esi]
// 004875b6  85c0                 test eax, eax
// 004875b8  7404                 je 0x4875be
// 004875ba  3bc1                 cmp eax, ecx
// 004875bc  7406                 je 0x4875c4
// 004875be  ffd3                 call ebx
// 004875c0  8b542430             mov edx, dword ptr [esp + 0x30]
// 004875c4  3bd7                 cmp edx, edi
// 004875c6  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 004875ca  753e                 jne 0x48760a
// 004875cc  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 004875cf  8b4108               mov eax, dword ptr [ecx + 8]
// 004875d2  83c00c               add eax, 0xc
// 004875d5  57                   push edi
// 004875d6  50                   push eax
// 004875d7  ff15d8b59800         call dword ptr [0x98b5d8]
// 004875dd  83c408               add esp, 8
// 004875e0  84c0                 test al, al
// 004875e2  0f8443010000         je 0x48772b
// 004875e8  8b5618               mov edx, dword ptr [esi + 0x18]
// 004875eb  8b4208               mov eax, dword ptr [edx + 8]
// 004875ee  57                   push edi
// 004875ef  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 004875f3  50                   push eax
// 004875f4  6a00                 push 0
// 004875f6  57                   push edi
// 004875f7  8bce                 mov ecx, esi
// 004875f9  e8c2eeffff           call 0x4864c0
// 004875fe  5d                   pop ebp
// 004875ff  5b                   pop ebx
// 00487600  8bc7                 mov eax, edi
// 00487602  5f                   pop edi
// 00487603  5e                   pop esi
// 00487604  83c414               add esp, 0x14
// 00487607  c21000               ret 0x10
// 0048760a  8b2dd8b59800         mov ebp, dword ptr [0x98b5d8]
// 00487610  83c20c               add edx, 0xc
// 00487613  52                   push edx
// 00487614  57                   push edi
// 00487615  ffd5                 call ebp
// 00487617  83c408               add esp, 8
// 0048761a  84c0                 test al, al
// 0048761c  746c                 je 0x48768a
// 0048761e  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00487622  8b542430             mov edx, dword ptr [esp + 0x30]
// 00487626  894c2410             mov dword ptr [esp + 0x10], ecx
// 0048762a  8d4c2410             lea ecx, [esp + 0x10]
// 0048762e  89542414             mov dword ptr [esp + 0x14], edx
// 00487632  e849e1ffff           call 0x485780
// 00487637  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 0048763b  57                   push edi
// 0048763c  8d430c               lea eax, [ebx + 0xc]
// 0048763f  50                   push eax
// 00487640  8d4e08               lea ecx, [esi + 8]
// 00487643  e80832ffff           call 0x47a850
// 00487648  84c0                 test al, al
// 0048764a  743e                 je 0x48768a
// 0048764c  8b4b08               mov ecx, dword ptr [ebx + 8]
// 0048764f  80794500             cmp byte ptr [ecx + 0x45], 0
// 00487653  57                   push edi
// 00487654  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00487658  8bce                 mov ecx, esi
// 0048765a  7415                 je 0x487671
// 0048765c  53                   push ebx
// 0048765d  6a00                 push 0
// 0048765f  57                   push edi
// 00487660  e85beeffff           call 0x4864c0
// 00487665  5d                   pop ebp
// 00487666  5b                   pop ebx
// 00487667  8bc7                 mov eax, edi
// 00487669  5f                   pop edi
// 0048766a  5e                   pop esi
// 0048766b  83c414               add esp, 0x14
// 0048766e  c21000               ret 0x10
// 00487671  8b542434             mov edx, dword ptr [esp + 0x34]
// 00487675  52                   push edx
// 00487676  6a01                 push 1
// 00487678  57                   push edi
// 00487679  e842eeffff           call 0x4864c0
// 0048767e  5d                   pop ebp
// 0048767f  5b                   pop ebx
// 00487680  8bc7                 mov eax, edi
// 00487682  5f                   pop edi
// 00487683  5e                   pop esi
// 00487684  83c414               add esp, 0x14
// 00487687  c21000               ret 0x10
// 0048768a  8b442430             mov eax, dword ptr [esp + 0x30]
// 0048768e  83c00c               add eax, 0xc
// 00487691  57                   push edi
// 00487692  50                   push eax
// 00487693  ffd5                 call ebp
// 00487695  83c408               add esp, 8
// 00487698  84c0                 test al, al
// 0048769a  0f848b000000         je 0x48772b
// 004876a0  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 004876a4  8b542430             mov edx, dword ptr [esp + 0x30]
// 004876a8  8b4618               mov eax, dword ptr [esi + 0x18]
// 004876ab  894c2410             mov dword ptr [esp + 0x10], ecx
// 004876af  8b0e                 mov ecx, dword ptr [esi]
// 004876b1  894c2418             mov dword ptr [esp + 0x18], ecx
// 004876b5  8d4c2410             lea ecx, [esp + 0x10]
// 004876b9  89542414             mov dword ptr [esp + 0x14], edx
// 004876bd  8944241c             mov dword ptr [esp + 0x1c], eax
// 004876c1  e85ac3f8ff           call 0x413a20
// 004876c6  8d542418             lea edx, [esp + 0x18]
// 004876ca  52                   push edx
// 004876cb  8d4c2414             lea ecx, [esp + 0x14]
// 004876cf  e88c4c1400           call 0x5cc360
// 004876d4  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 004876d8  84c0                 test al, al
// 004876da  7511                 jne 0x4876ed
// 004876dc  8d430c               lea eax, [ebx + 0xc]
// 004876df  50                   push eax
// 004876e0  57                   push edi
// 004876e1  8d4e08               lea ecx, [esi + 8]
// 004876e4  e86731ffff           call 0x47a850
// 004876e9  84c0                 test al, al
// 004876eb  743e                 je 0x48772b
// 004876ed  8b442430             mov eax, dword ptr [esp + 0x30]
// 004876f1  8b4808               mov ecx, dword ptr [eax + 8]
// 004876f4  80794500             cmp byte ptr [ecx + 0x45], 0
// 004876f8  57                   push edi
// 004876f9  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 004876fd  8bce                 mov ecx, esi
// 004876ff  7415                 je 0x487716
// 00487701  50                   push eax
// 00487702  6a00                 push 0
// 00487704  57                   push edi
// 00487705  e8b6edffff           call 0x4864c0
// 0048770a  5d                   pop ebp
// 0048770b  5b                   pop ebx
// 0048770c  8bc7                 mov eax, edi
// 0048770e  5f                   pop edi
// 0048770f  5e                   pop esi
// 00487710  83c414               add esp, 0x14
// 00487713  c21000               ret 0x10
// 00487716  53                   push ebx
// 00487717  6a01                 push 1
// 00487719  57                   push edi
// 0048771a  e8a1edffff           call 0x4864c0
// 0048771f  5d                   pop ebp
// 00487720  5b                   pop ebx
// 00487721  8bc7                 mov eax, edi
// 00487723  5f                   pop edi
// 00487724  5e                   pop esi
// 00487725  83c414               add esp, 0x14
// 00487728  c21000               ret 0x10
// 0048772b  57                   push edi
// 0048772c  8d54241c             lea edx, [esp + 0x1c]
// 00487730  52                   push edx
// 00487731  8bce                 mov ecx, esi
// 00487733  e898f2ffff           call 0x4869d0
// 00487738  8b10                 mov edx, dword ptr [eax]
// 0048773a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0048773e  5d                   pop ebp
// 0048773f  5b                   pop ebx
// 00487740  8911                 mov dword ptr [ecx], edx
// 00487742  8b4004               mov eax, dword ptr [eax + 4]
// 00487745  5f                   pop edi
// 00487746  894104               mov dword ptr [ecx + 4], eax
// 00487749  8bc1                 mov eax, ecx
// 0048774b  5e                   pop esi
// 0048774c  83c414               add esp, 0x14
// 0048774f  c21000               ret 0x10
// standard library map_str<string> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@2@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
