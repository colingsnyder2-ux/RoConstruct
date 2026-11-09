// from server: 100% by auto
// roc 2009-12 007c93c0  unit: RBX::ScoreHud  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007c93c0
//
// 007c93c0  83ec14               sub esp, 0x14
// 007c93c3  56                   push esi
// 007c93c4  8bf1                 mov esi, ecx
// 007c93c6  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 007c93ca  57                   push edi
// 007c93cb  7521                 jne 0x7c93ee
// 007c93cd  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007c93d1  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007c93d4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007c93d8  50                   push eax
// 007c93d9  51                   push ecx
// 007c93da  6a01                 push 1
// 007c93dc  57                   push edi
// 007c93dd  8bce                 mov ecx, esi
// 007c93df  e87ce9ffff           call 0x7c7d60
// 007c93e4  8bc7                 mov eax, edi
// 007c93e6  5f                   pop edi
// 007c93e7  5e                   pop esi
// 007c93e8  83c414               add esp, 0x14
// 007c93eb  c21000               ret 0x10
// 007c93ee  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007c93f2  8b5618               mov edx, dword ptr [esi + 0x18]
// 007c93f5  8b3a                 mov edi, dword ptr [edx]
// 007c93f7  8b06                 mov eax, dword ptr [esi]
// 007c93f9  53                   push ebx
// 007c93fa  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 007c9400  85c9                 test ecx, ecx
// 007c9402  7404                 je 0x7c9408
// 007c9404  3bc8                 cmp ecx, eax
// 007c9406  7406                 je 0x7c940e
// 007c9408  ffd3                 call ebx
// 007c940a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007c940e  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007c9412  3bc7                 cmp eax, edi
// 007c9414  752a                 jne 0x7c9440
// 007c9416  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 007c941a  8b0f                 mov ecx, dword ptr [edi]
// 007c941c  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 007c941f  0f834b010000         jae 0x7c9570
// 007c9425  57                   push edi
// 007c9426  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 007c942a  50                   push eax
// 007c942b  6a01                 push 1
// 007c942d  57                   push edi
// 007c942e  8bce                 mov ecx, esi
// 007c9430  e82be9ffff           call 0x7c7d60
// 007c9435  5b                   pop ebx
// 007c9436  8bc7                 mov eax, edi
// 007c9438  5f                   pop edi
// 007c9439  5e                   pop esi
// 007c943a  83c414               add esp, 0x14
// 007c943d  c21000               ret 0x10
// 007c9440  8b7e18               mov edi, dword ptr [esi + 0x18]
// 007c9443  8b16                 mov edx, dword ptr [esi]
// 007c9445  85c9                 test ecx, ecx
// 007c9447  7404                 je 0x7c944d
// 007c9449  3bca                 cmp ecx, edx
// 007c944b  740a                 je 0x7c9457
// 007c944d  ffd3                 call ebx
// 007c944f  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007c9453  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007c9457  3bc7                 cmp eax, edi
// 007c9459  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 007c945d  752c                 jne 0x7c948b
// 007c945f  8b5618               mov edx, dword ptr [esi + 0x18]
// 007c9462  8b4208               mov eax, dword ptr [edx + 8]
// 007c9465  8b480c               mov ecx, dword ptr [eax + 0xc]
// 007c9468  3b0f                 cmp ecx, dword ptr [edi]
// 007c946a  0f8300010000         jae 0x7c9570
// 007c9470  57                   push edi
// 007c9471  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 007c9475  50                   push eax
// 007c9476  6a00                 push 0
// 007c9478  57                   push edi
// 007c9479  8bce                 mov ecx, esi
// 007c947b  e8e0e8ffff           call 0x7c7d60
// 007c9480  5b                   pop ebx
// 007c9481  8bc7                 mov eax, edi
// 007c9483  5f                   pop edi
// 007c9484  5e                   pop esi
// 007c9485  83c414               add esp, 0x14
// 007c9488  c21000               ret 0x10
// 007c948b  8b17                 mov edx, dword ptr [edi]
// 007c948d  39500c               cmp dword ptr [eax + 0xc], edx
// 007c9490  7663                 jbe 0x7c94f5
// 007c9492  894c240c             mov dword ptr [esp + 0xc], ecx
// 007c9496  8d4c240c             lea ecx, [esp + 0xc]
// 007c949a  89442410             mov dword ptr [esp + 0x10], eax
// 007c949e  e8bda3d4ff           call 0x513860
// 007c94a3  8b17                 mov edx, dword ptr [edi]
// 007c94a5  8b442410             mov eax, dword ptr [esp + 0x10]
// 007c94a9  39500c               cmp dword ptr [eax + 0xc], edx
// 007c94ac  733c                 jae 0x7c94ea
// 007c94ae  8b5008               mov edx, dword ptr [eax + 8]
// 007c94b1  807a3100             cmp byte ptr [edx + 0x31], 0
// 007c94b5  57                   push edi
// 007c94b6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 007c94ba  8bce                 mov ecx, esi
// 007c94bc  7414                 je 0x7c94d2
// 007c94be  50                   push eax
// 007c94bf  6a00                 push 0
// 007c94c1  57                   push edi
// 007c94c2  e899e8ffff           call 0x7c7d60
// 007c94c7  5b                   pop ebx
// 007c94c8  8bc7                 mov eax, edi
// 007c94ca  5f                   pop edi
// 007c94cb  5e                   pop esi
// 007c94cc  83c414               add esp, 0x14
// 007c94cf  c21000               ret 0x10
// 007c94d2  8b442430             mov eax, dword ptr [esp + 0x30]
// 007c94d6  50                   push eax
// 007c94d7  6a01                 push 1
// 007c94d9  57                   push edi
// 007c94da  e881e8ffff           call 0x7c7d60
// 007c94df  5b                   pop ebx
// 007c94e0  8bc7                 mov eax, edi
// 007c94e2  5f                   pop edi
// 007c94e3  5e                   pop esi
// 007c94e4  83c414               add esp, 0x14
// 007c94e7  c21000               ret 0x10
// 007c94ea  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007c94ee  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007c94f2  39500c               cmp dword ptr [eax + 0xc], edx
// 007c94f5  7379                 jae 0x7c9570
// 007c94f7  8b16                 mov edx, dword ptr [esi]
// 007c94f9  894c240c             mov dword ptr [esp + 0xc], ecx
// 007c94fd  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007c9500  894c2418             mov dword ptr [esp + 0x18], ecx
// 007c9504  8d4c240c             lea ecx, [esp + 0xc]
// 007c9508  89442410             mov dword ptr [esp + 0x10], eax
// 007c950c  89542414             mov dword ptr [esp + 0x14], edx
// 007c9510  e8dba3d4ff           call 0x5138f0
// 007c9515  8d442414             lea eax, [esp + 0x14]
// 007c9519  50                   push eax
// 007c951a  8d4c2410             lea ecx, [esp + 0x10]
// 007c951e  e83d2ee0ff           call 0x5cc360
// 007c9523  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007c9527  84c0                 test al, al
// 007c9529  7507                 jne 0x7c9532
// 007c952b  8b17                 mov edx, dword ptr [edi]
// 007c952d  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 007c9530  733e                 jae 0x7c9570
// 007c9532  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007c9536  8b5008               mov edx, dword ptr [eax + 8]
// 007c9539  807a3100             cmp byte ptr [edx + 0x31], 0
// 007c953d  57                   push edi
// 007c953e  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 007c9542  7416                 je 0x7c955a
// 007c9544  50                   push eax
// 007c9545  6a00                 push 0
// 007c9547  57                   push edi
// 007c9548  8bce                 mov ecx, esi
// 007c954a  e811e8ffff           call 0x7c7d60
// 007c954f  5b                   pop ebx
// 007c9550  8bc7                 mov eax, edi
// 007c9552  5f                   pop edi
// 007c9553  5e                   pop esi
// 007c9554  83c414               add esp, 0x14
// 007c9557  c21000               ret 0x10
// 007c955a  51                   push ecx
// 007c955b  6a01                 push 1
// 007c955d  57                   push edi
// 007c955e  8bce                 mov ecx, esi
// 007c9560  e8fbe7ffff           call 0x7c7d60
// 007c9565  5b                   pop ebx
// 007c9566  8bc7                 mov eax, edi
// 007c9568  5f                   pop edi
// 007c9569  5e                   pop esi
// 007c956a  83c414               add esp, 0x14
// 007c956d  c21000               ret 0x10
// 007c9570  57                   push edi
// 007c9571  8d442418             lea eax, [esp + 0x18]
// 007c9575  50                   push eax
// 007c9576  8bce                 mov ecx, esi
// 007c9578  e8e3f2ffff           call 0x7c8860
// 007c957d  8b10                 mov edx, dword ptr [eax]
// 007c957f  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007c9583  5b                   pop ebx
// 007c9584  8911                 mov dword ptr [ecx], edx
// 007c9586  8b4004               mov eax, dword ptr [eax + 4]
// 007c9589  5f                   pop edi
// 007c958a  894104               mov dword ptr [ecx + 4], eax
// 007c958d  8bc1                 mov eax, ecx
// 007c958f  5e                   pop esi
// 007c9590  83c414               add esp, 0x14
// 007c9593  c21000               ret 0x10
// standard library map_ptr<pod32> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod32>
struct E { int v[8]; };
#include <map>
struct K; template class std::map<K*, E>;
