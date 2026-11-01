// from server: 100% by auto
// roc 2007-03 0060ae40  unit: seg_00600000  size: 518 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0060ae40
//
// 0060ae40  83ec0c               sub esp, 0xc
// 0060ae43  56                   push esi
// 0060ae44  8bf1                 mov esi, ecx
// 0060ae46  837e0800             cmp dword ptr [esi + 8], 0
// 0060ae4a  57                   push edi
// 0060ae4b  7521                 jne 0x60ae6e
// 0060ae4d  8b442424             mov eax, dword ptr [esp + 0x24]
// 0060ae51  8b4e04               mov ecx, dword ptr [esi + 4]
// 0060ae54  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0060ae58  50                   push eax
// 0060ae59  51                   push ecx
// 0060ae5a  6a01                 push 1
// 0060ae5c  57                   push edi
// 0060ae5d  8bce                 mov ecx, esi
// 0060ae5f  e89cedffff           call 0x609c00
// 0060ae64  8bc7                 mov eax, edi
// 0060ae66  5f                   pop edi
// 0060ae67  5e                   pop esi
// 0060ae68  83c40c               add esp, 0xc
// 0060ae6b  c21000               ret 0x10
// 0060ae6e  8b5604               mov edx, dword ptr [esi + 4]
// 0060ae71  8b3a                 mov edi, dword ptr [edx]
// 0060ae73  55                   push ebp
// 0060ae74  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 0060ae78  85ed                 test ebp, ebp
// 0060ae7a  7404                 je 0x60ae80
// 0060ae7c  3bee                 cmp ebp, esi
// 0060ae7e  7406                 je 0x60ae86
// 0060ae80  ff1544e97700         call dword ptr [0x77e944]
// 0060ae86  53                   push ebx
// 0060ae87  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 0060ae8b  3bdf                 cmp ebx, edi
// 0060ae8d  7536                 jne 0x60aec5
// 0060ae8f  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0060ae93  8d430c               lea eax, [ebx + 0xc]
// 0060ae96  50                   push eax
// 0060ae97  57                   push edi
// 0060ae98  ff15e0e67700         call dword ptr [0x77e6e0]
// 0060ae9e  83c408               add esp, 8
// 0060aea1  84c0                 test al, al
// 0060aea3  0f8476010000         je 0x60b01f
// 0060aea9  57                   push edi
// 0060aeaa  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0060aeae  53                   push ebx
// 0060aeaf  6a01                 push 1
// 0060aeb1  57                   push edi
// 0060aeb2  8bce                 mov ecx, esi
// 0060aeb4  e847edffff           call 0x609c00
// 0060aeb9  5b                   pop ebx
// 0060aeba  5d                   pop ebp
// 0060aebb  8bc7                 mov eax, edi
// 0060aebd  5f                   pop edi
// 0060aebe  5e                   pop esi
// 0060aebf  83c40c               add esp, 0xc
// 0060aec2  c21000               ret 0x10
// 0060aec5  85ed                 test ebp, ebp
// 0060aec7  8b7e04               mov edi, dword ptr [esi + 4]
// 0060aeca  7404                 je 0x60aed0
// 0060aecc  3bee                 cmp ebp, esi
// 0060aece  7406                 je 0x60aed6
// 0060aed0  ff1544e97700         call dword ptr [0x77e944]
// 0060aed6  3bdf                 cmp ebx, edi
// 0060aed8  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0060aedc  753e                 jne 0x60af1c
// 0060aede  8b4e04               mov ecx, dword ptr [esi + 4]
// 0060aee1  8b4108               mov eax, dword ptr [ecx + 8]
// 0060aee4  83c00c               add eax, 0xc
// 0060aee7  57                   push edi
// 0060aee8  50                   push eax
// 0060aee9  ff15e0e67700         call dword ptr [0x77e6e0]
// 0060aeef  83c408               add esp, 8
// 0060aef2  84c0                 test al, al
// 0060aef4  0f8425010000         je 0x60b01f
// 0060aefa  8b5604               mov edx, dword ptr [esi + 4]
// 0060aefd  8b4208               mov eax, dword ptr [edx + 8]
// 0060af00  57                   push edi
// 0060af01  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0060af05  50                   push eax
// 0060af06  6a00                 push 0
// 0060af08  57                   push edi
// 0060af09  8bce                 mov ecx, esi
// 0060af0b  e8f0ecffff           call 0x609c00
// 0060af10  5b                   pop ebx
// 0060af11  5d                   pop ebp
// 0060af12  8bc7                 mov eax, edi
// 0060af14  5f                   pop edi
// 0060af15  5e                   pop esi
// 0060af16  83c40c               add esp, 0xc
// 0060af19  c21000               ret 0x10
// 0060af1c  8d430c               lea eax, [ebx + 0xc]
// 0060af1f  50                   push eax
// 0060af20  57                   push edi
// 0060af21  ff15e0e67700         call dword ptr [0x77e6e0]
// 0060af27  83c408               add esp, 8
// 0060af2a  84c0                 test al, al
// 0060af2c  7463                 je 0x60af91
// 0060af2e  8d4c2424             lea ecx, [esp + 0x24]
// 0060af32  896c2424             mov dword ptr [esp + 0x24], ebp
// 0060af36  895c2428             mov dword ptr [esp + 0x28], ebx
// 0060af3a  e8f1ceffff           call 0x607e30
// 0060af3f  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0060af43  83c10c               add ecx, 0xc
// 0060af46  57                   push edi
// 0060af47  51                   push ecx
// 0060af48  8bce                 mov ecx, esi
// 0060af4a  e86195e3ff           call 0x4444b0
// 0060af4f  84c0                 test al, al
// 0060af51  743e                 je 0x60af91
// 0060af53  8b442428             mov eax, dword ptr [esp + 0x28]
// 0060af57  8b5008               mov edx, dword ptr [eax + 8]
// 0060af5a  807a3500             cmp byte ptr [edx + 0x35], 0
// 0060af5e  57                   push edi
// 0060af5f  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0060af63  8bce                 mov ecx, esi
// 0060af65  7415                 je 0x60af7c
// 0060af67  50                   push eax
// 0060af68  6a00                 push 0
// 0060af6a  57                   push edi
// 0060af6b  e890ecffff           call 0x609c00
// 0060af70  5b                   pop ebx
// 0060af71  5d                   pop ebp
// 0060af72  8bc7                 mov eax, edi
// 0060af74  5f                   pop edi
// 0060af75  5e                   pop esi
// 0060af76  83c40c               add esp, 0xc
// 0060af79  c21000               ret 0x10
// 0060af7c  53                   push ebx
// 0060af7d  6a01                 push 1
// 0060af7f  57                   push edi
// 0060af80  e87becffff           call 0x609c00
// 0060af85  5b                   pop ebx
// 0060af86  5d                   pop ebp
// 0060af87  8bc7                 mov eax, edi
// 0060af89  5f                   pop edi
// 0060af8a  5e                   pop esi
// 0060af8b  83c40c               add esp, 0xc
// 0060af8e  c21000               ret 0x10
// 0060af91  8d430c               lea eax, [ebx + 0xc]
// 0060af94  57                   push edi
// 0060af95  50                   push eax
// 0060af96  ff15e0e67700         call dword ptr [0x77e6e0]
// 0060af9c  83c408               add esp, 8
// 0060af9f  84c0                 test al, al
// 0060afa1  747c                 je 0x60b01f
// 0060afa3  8b4604               mov eax, dword ptr [esi + 4]
// 0060afa6  8d4c2424             lea ecx, [esp + 0x24]
// 0060afaa  896c2424             mov dword ptr [esp + 0x24], ebp
// 0060afae  895c2428             mov dword ptr [esp + 0x28], ebx
// 0060afb2  89442414             mov dword ptr [esp + 0x14], eax
// 0060afb6  89742410             mov dword ptr [esp + 0x10], esi
// 0060afba  e84124ecff           call 0x4cd400
// 0060afbf  8d4c2410             lea ecx, [esp + 0x10]
// 0060afc3  51                   push ecx
// 0060afc4  8d4c2428             lea ecx, [esp + 0x28]
// 0060afc8  e8930ce4ff           call 0x44bc60
// 0060afcd  84c0                 test al, al
// 0060afcf  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 0060afd3  7510                 jne 0x60afe5
// 0060afd5  8d550c               lea edx, [ebp + 0xc]
// 0060afd8  52                   push edx
// 0060afd9  57                   push edi
// 0060afda  8bce                 mov ecx, esi
// 0060afdc  e8cf94e3ff           call 0x4444b0
// 0060afe1  84c0                 test al, al
// 0060afe3  743a                 je 0x60b01f
// 0060afe5  8b4308               mov eax, dword ptr [ebx + 8]
// 0060afe8  80783500             cmp byte ptr [eax + 0x35], 0
// 0060afec  57                   push edi
// 0060afed  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0060aff1  8bce                 mov ecx, esi
// 0060aff3  7415                 je 0x60b00a
// 0060aff5  53                   push ebx
// 0060aff6  6a00                 push 0
// 0060aff8  57                   push edi
// 0060aff9  e802ecffff           call 0x609c00
// 0060affe  5b                   pop ebx
// 0060afff  5d                   pop ebp
// 0060b000  8bc7                 mov eax, edi
// 0060b002  5f                   pop edi
// 0060b003  5e                   pop esi
// 0060b004  83c40c               add esp, 0xc
// 0060b007  c21000               ret 0x10
// 0060b00a  55                   push ebp
// 0060b00b  6a01                 push 1
// 0060b00d  57                   push edi
// 0060b00e  e8edebffff           call 0x609c00
// 0060b013  5b                   pop ebx
// 0060b014  5d                   pop ebp
// 0060b015  8bc7                 mov eax, edi
// 0060b017  5f                   pop edi
// 0060b018  5e                   pop esi
// 0060b019  83c40c               add esp, 0xc
// 0060b01c  c21000               ret 0x10
// 0060b01f  57                   push edi
// 0060b020  8d4c2414             lea ecx, [esp + 0x14]
// 0060b024  51                   push ecx
// 0060b025  8bce                 mov ecx, esi
// 0060b027  e8b4f4ffff           call 0x60a4e0
// 0060b02c  8b10                 mov edx, dword ptr [eax]
// 0060b02e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0060b032  5b                   pop ebx
// 0060b033  5d                   pop ebp
// 0060b034  8911                 mov dword ptr [ecx], edx
// 0060b036  8b4004               mov eax, dword ptr [eax + 4]
// 0060b039  5f                   pop edi
// 0060b03a  894104               mov dword ptr [ecx + 4], eax
// 0060b03d  8bc1                 mov eax, ecx
// 0060b03f  5e                   pop esi
// 0060b040  83c40c               add esp, 0xc
// 0060b043  c21000               ret 0x10
// standard library map_str<pod12> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@V312@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod12>
struct E { int v[3]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
