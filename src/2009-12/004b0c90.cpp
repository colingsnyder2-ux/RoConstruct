// from server: 100% by auto
// roc 2009-12 004b0c90  unit: Ogre::RbxTextureCompositorSceneManager  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004b0c90
//
// 004b0c90  83ec14               sub esp, 0x14
// 004b0c93  53                   push ebx
// 004b0c94  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 004b0c98  55                   push ebp
// 004b0c99  56                   push esi
// 004b0c9a  8be9                 mov ebp, ecx
// 004b0c9c  57                   push edi
// 004b0c9d  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 004b0ca0  8b7704               mov esi, dword ptr [edi + 4]
// 004b0ca3  807e6900             cmp byte ptr [esi + 0x69], 0
// 004b0ca7  b001                 mov al, 1
// 004b0ca9  88442410             mov byte ptr [esp + 0x10], al
// 004b0cad  7526                 jne 0x4b0cd5
// 004b0caf  90                   nop 
// 004b0cb0  8d460c               lea eax, [esi + 0xc]
// 004b0cb3  50                   push eax
// 004b0cb4  53                   push ebx
// 004b0cb5  8bfe                 mov edi, esi
// 004b0cb7  ff15d8b59800         call dword ptr [0x98b5d8]
// 004b0cbd  83c408               add esp, 8
// 004b0cc0  88442410             mov byte ptr [esp + 0x10], al
// 004b0cc4  84c0                 test al, al
// 004b0cc6  7404                 je 0x4b0ccc
// 004b0cc8  8b36                 mov esi, dword ptr [esi]
// 004b0cca  eb03                 jmp 0x4b0ccf
// 004b0ccc  8b7608               mov esi, dword ptr [esi + 8]
// 004b0ccf  807e6900             cmp byte ptr [esi + 0x69], 0
// 004b0cd3  74db                 je 0x4b0cb0
// 004b0cd5  8b7500               mov esi, dword ptr [ebp]
// 004b0cd8  897c2418             mov dword ptr [esp + 0x18], edi
// 004b0cdc  89742414             mov dword ptr [esp + 0x14], esi
// 004b0ce0  84c0                 test al, al
// 004b0ce2  7458                 je 0x4b0d3c
// 004b0ce4  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 004b0ce7  8b11                 mov edx, dword ptr [ecx]
// 004b0ce9  89542420             mov dword ptr [esp + 0x20], edx
// 004b0ced  85f6                 test esi, esi
// 004b0cef  7404                 je 0x4b0cf5
// 004b0cf1  3bf6                 cmp esi, esi
// 004b0cf3  7406                 je 0x4b0cfb
// 004b0cf5  ff1560b79800         call dword ptr [0x98b760]
// 004b0cfb  3b7c2420             cmp edi, dword ptr [esp + 0x20]
// 004b0cff  752e                 jne 0x4b0d2f
// 004b0d01  53                   push ebx
// 004b0d02  57                   push edi
// 004b0d03  6a01                 push 1
// 004b0d05  8d442428             lea eax, [esp + 0x28]
// 004b0d09  50                   push eax
// 004b0d0a  8bcd                 mov ecx, ebp
// 004b0d0c  e8dffcffff           call 0x4b09f0
// 004b0d11  5f                   pop edi
// 004b0d12  8bc8                 mov ecx, eax
// 004b0d14  8b11                 mov edx, dword ptr [ecx]
// 004b0d16  8b442424             mov eax, dword ptr [esp + 0x24]
// 004b0d1a  8b4904               mov ecx, dword ptr [ecx + 4]
// 004b0d1d  5e                   pop esi
// 004b0d1e  5d                   pop ebp
// 004b0d1f  8910                 mov dword ptr [eax], edx
// 004b0d21  894804               mov dword ptr [eax + 4], ecx
// 004b0d24  c6400801             mov byte ptr [eax + 8], 1
// 004b0d28  5b                   pop ebx
// 004b0d29  83c414               add esp, 0x14
// 004b0d2c  c20800               ret 8
// 004b0d2f  8d4c2414             lea ecx, [esp + 0x14]
// 004b0d33  e868d4ffff           call 0x4ae1a0
// 004b0d38  8b742414             mov esi, dword ptr [esp + 0x14]
// 004b0d3c  8b542418             mov edx, dword ptr [esp + 0x18]
// 004b0d40  83c20c               add edx, 0xc
// 004b0d43  53                   push ebx
// 004b0d44  52                   push edx
// 004b0d45  ff15d8b59800         call dword ptr [0x98b5d8]
// 004b0d4b  83c408               add esp, 8
// 004b0d4e  84c0                 test al, al
// 004b0d50  740e                 je 0x4b0d60
// 004b0d52  8b442410             mov eax, dword ptr [esp + 0x10]
// 004b0d56  53                   push ebx
// 004b0d57  57                   push edi
// 004b0d58  50                   push eax
// 004b0d59  8d4c2428             lea ecx, [esp + 0x28]
// 004b0d5d  51                   push ecx
// 004b0d5e  ebaa                 jmp 0x4b0d0a
// 004b0d60  8b442428             mov eax, dword ptr [esp + 0x28]
// 004b0d64  8b542418             mov edx, dword ptr [esp + 0x18]
// 004b0d68  5f                   pop edi
// 004b0d69  8930                 mov dword ptr [eax], esi
// 004b0d6b  5e                   pop esi
// 004b0d6c  5d                   pop ebp
// 004b0d6d  895004               mov dword ptr [eax + 4], edx
// 004b0d70  c6400800             mov byte ptr [eax + 8], 0
// 004b0d74  5b                   pop ebx
// 004b0d75  83c414               add esp, 0x14
// 004b0d78  c20800               ret 8
// standard library map_str<pod64> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod64>
struct E { int v[16]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
