// from server: 100% by auto
// roc 2009-12 0047aae0  unit: RBX::LDraw2Lua::LDraw2RobloxColorMap  size: 510 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0047aae0
//
// 0047aae0  64a100000000         mov eax, dword ptr fs:[0]
// 0047aae6  6aff                 push -1
// 0047aae8  6812699500           push 0x956912
// 0047aaed  50                   push eax
// 0047aaee  64892500000000       mov dword ptr fs:[0], esp
// 0047aaf5  83ec44               sub esp, 0x44
// 0047aaf8  57                   push edi
// 0047aaf9  8bf9                 mov edi, ecx
// 0047aafb  817f1cfeffff07       cmp dword ptr [edi + 0x1c], 0x7fffffe
// 0047ab02  7259                 jb 0x47ab5d
// 0047ab04  6800f59900           push 0x99f500
// 0047ab09  8d4c2408             lea ecx, [esp + 8]
// 0047ab0d  ff15f4b69800         call dword ptr [0x98b6f4]
// 0047ab13  8d4c2420             lea ecx, [esp + 0x20]
// 0047ab17  c744245000000000     mov dword ptr [esp + 0x50], 0
// 0047ab1f  ff1554b79800         call dword ptr [0x98b754]
// 0047ab25  8d442404             lea eax, [esp + 4]
// 0047ab29  50                   push eax
// 0047ab2a  8d4c2430             lea ecx, [esp + 0x30]
// 0047ab2e  c644245401           mov byte ptr [esp + 0x54], 1
// 0047ab33  c744242484f49900     mov dword ptr [esp + 0x24], 0x99f484
// 0047ab3b  ff15f0b69800         call dword ptr [0x98b6f0]
// 0047ab41  68e4efa800           push 0xa8efe4
// 0047ab46  8d4c2424             lea ecx, [esp + 0x24]
// 0047ab4a  51                   push ecx
// 0047ab4b  c644245800           mov byte ptr [esp + 0x58], 0
// 0047ab50  c744242890f49900     mov dword ptr [esp + 0x28], 0x99f490
// 0047ab58  e81b9d3700           call 0x7f4878
// 0047ab5d  8b542464             mov edx, dword ptr [esp + 0x64]
// 0047ab61  8b4718               mov eax, dword ptr [edi + 0x18]
// 0047ab64  53                   push ebx
// 0047ab65  55                   push ebp
// 0047ab66  56                   push esi
// 0047ab67  8b74246c             mov esi, dword ptr [esp + 0x6c]
// 0047ab6b  6a00                 push 0
// 0047ab6d  52                   push edx
// 0047ab6e  50                   push eax
// 0047ab6f  56                   push esi
// 0047ab70  50                   push eax
// 0047ab71  e8cafeffff           call 0x47aa40
// 0047ab76  8be8                 mov ebp, eax
// 0047ab78  8b4718               mov eax, dword ptr [edi + 0x18]
// 0047ab7b  bb01000000           mov ebx, 1
// 0047ab80  015f1c               add dword ptr [edi + 0x1c], ebx
// 0047ab83  3bf0                 cmp esi, eax
// 0047ab85  7510                 jne 0x47ab97
// 0047ab87  896804               mov dword ptr [eax + 4], ebp
// 0047ab8a  8b4718               mov eax, dword ptr [edi + 0x18]
// 0047ab8d  8928                 mov dword ptr [eax], ebp
// 0047ab8f  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 0047ab92  896908               mov dword ptr [ecx + 8], ebp
// 0047ab95  eb22                 jmp 0x47abb9
// 0047ab97  807c246800           cmp byte ptr [esp + 0x68], 0
// 0047ab9c  740d                 je 0x47abab
// 0047ab9e  892e                 mov dword ptr [esi], ebp
// 0047aba0  8b4718               mov eax, dword ptr [edi + 0x18]
// 0047aba3  3b30                 cmp esi, dword ptr [eax]
// 0047aba5  7512                 jne 0x47abb9
// 0047aba7  8928                 mov dword ptr [eax], ebp
// 0047aba9  eb0e                 jmp 0x47abb9
// 0047abab  896e08               mov dword ptr [esi + 8], ebp
// 0047abae  8b4718               mov eax, dword ptr [edi + 0x18]
// 0047abb1  3b7008               cmp esi, dword ptr [eax + 8]
// 0047abb4  7503                 jne 0x47abb9
// 0047abb6  896808               mov dword ptr [eax + 8], ebp
// 0047abb9  8b5504               mov edx, dword ptr [ebp + 4]
// 0047abbc  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 0047abc0  8d4504               lea eax, [ebp + 4]
// 0047abc3  8bf5                 mov esi, ebp
// 0047abc5  0f85ea000000         jne 0x47acb5
// 0047abcb  eb03                 jmp 0x47abd0
// 0047abcd  8d4900               lea ecx, [ecx]
// 0047abd0  8b08                 mov ecx, dword ptr [eax]
// 0047abd2  8b5104               mov edx, dword ptr [ecx + 4]
// 0047abd5  3b0a                 cmp ecx, dword ptr [edx]
// 0047abd7  7551                 jne 0x47ac2a
// 0047abd9  8b5208               mov edx, dword ptr [edx + 8]
// 0047abdc  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 0047abe0  7519                 jne 0x47abfb
// 0047abe2  88592c               mov byte ptr [ecx + 0x2c], bl
// 0047abe5  885a2c               mov byte ptr [edx + 0x2c], bl
// 0047abe8  8b10                 mov edx, dword ptr [eax]
// 0047abea  8b4a04               mov ecx, dword ptr [edx + 4]
// 0047abed  c6412c00             mov byte ptr [ecx + 0x2c], 0
// 0047abf1  8b10                 mov edx, dword ptr [eax]
// 0047abf3  8b7204               mov esi, dword ptr [edx + 4]
// 0047abf6  e9aa000000           jmp 0x47aca5
// 0047abfb  3b7108               cmp esi, dword ptr [ecx + 8]
// 0047abfe  750a                 jne 0x47ac0a
// 0047ac00  8bf1                 mov esi, ecx
// 0047ac02  56                   push esi
// 0047ac03  8bcf                 mov ecx, edi
// 0047ac05  e876fdffff           call 0x47a980
// 0047ac0a  8b4604               mov eax, dword ptr [esi + 4]
// 0047ac0d  88582c               mov byte ptr [eax + 0x2c], bl
// 0047ac10  8b4e04               mov ecx, dword ptr [esi + 4]
// 0047ac13  8b5104               mov edx, dword ptr [ecx + 4]
// 0047ac16  c6422c00             mov byte ptr [edx + 0x2c], 0
// 0047ac1a  8b4604               mov eax, dword ptr [esi + 4]
// 0047ac1d  8b4804               mov ecx, dword ptr [eax + 4]
// 0047ac20  51                   push ecx
// 0047ac21  8bcf                 mov ecx, edi
// 0047ac23  e868242300           call 0x6ad090
// 0047ac28  eb7b                 jmp 0x47aca5
// 0047ac2a  8b12                 mov edx, dword ptr [edx]
// 0047ac2c  807a2c00             cmp byte ptr [edx + 0x2c], 0
// 0047ac30  7516                 jne 0x47ac48
// 0047ac32  88592c               mov byte ptr [ecx + 0x2c], bl
// 0047ac35  885a2c               mov byte ptr [edx + 0x2c], bl
// 0047ac38  8b10                 mov edx, dword ptr [eax]
// 0047ac3a  8b4a04               mov ecx, dword ptr [edx + 4]
// 0047ac3d  c6412c00             mov byte ptr [ecx + 0x2c], 0
// 0047ac41  8b10                 mov edx, dword ptr [eax]
// 0047ac43  8b7204               mov esi, dword ptr [edx + 4]
// 0047ac46  eb5d                 jmp 0x47aca5
// 0047ac48  3b31                 cmp esi, dword ptr [ecx]
// 0047ac4a  750a                 jne 0x47ac56
// 0047ac4c  8bf1                 mov esi, ecx
// 0047ac4e  56                   push esi
// 0047ac4f  8bcf                 mov ecx, edi
// 0047ac51  e83a242300           call 0x6ad090
// 0047ac56  8b4604               mov eax, dword ptr [esi + 4]
// 0047ac59  88582c               mov byte ptr [eax + 0x2c], bl
// 0047ac5c  8b4e04               mov ecx, dword ptr [esi + 4]
// 0047ac5f  8b5104               mov edx, dword ptr [ecx + 4]
// 0047ac62  c6422c00             mov byte ptr [edx + 0x2c], 0
// 0047ac66  8b4604               mov eax, dword ptr [esi + 4]
// 0047ac69  8b4004               mov eax, dword ptr [eax + 4]
// 0047ac6c  8b4808               mov ecx, dword ptr [eax + 8]
// 0047ac6f  8b11                 mov edx, dword ptr [ecx]
// 0047ac71  895008               mov dword ptr [eax + 8], edx
// 0047ac74  8b11                 mov edx, dword ptr [ecx]
// 0047ac76  807a2d00             cmp byte ptr [edx + 0x2d], 0
// 0047ac7a  7503                 jne 0x47ac7f
// 0047ac7c  894204               mov dword ptr [edx + 4], eax
// 0047ac7f  8b5004               mov edx, dword ptr [eax + 4]
// 0047ac82  895104               mov dword ptr [ecx + 4], edx
// 0047ac85  8b5718               mov edx, dword ptr [edi + 0x18]
// 0047ac88  3b4204               cmp eax, dword ptr [edx + 4]
// 0047ac8b  7505                 jne 0x47ac92
// 0047ac8d  894a04               mov dword ptr [edx + 4], ecx
// 0047ac90  eb0e                 jmp 0x47aca0
// 0047ac92  8b5004               mov edx, dword ptr [eax + 4]
// 0047ac95  3b02                 cmp eax, dword ptr [edx]
// 0047ac97  7504                 jne 0x47ac9d
// 0047ac99  890a                 mov dword ptr [edx], ecx
// 0047ac9b  eb03                 jmp 0x47aca0
// 0047ac9d  894a08               mov dword ptr [edx + 8], ecx
// 0047aca0  8901                 mov dword ptr [ecx], eax
// 0047aca2  894804               mov dword ptr [eax + 4], ecx
// 0047aca5  8b4e04               mov ecx, dword ptr [esi + 4]
// 0047aca8  80792c00             cmp byte ptr [ecx + 0x2c], 0
// 0047acac  8d4604               lea eax, [esi + 4]
// 0047acaf  0f841bffffff         je 0x47abd0
// 0047acb5  8b5718               mov edx, dword ptr [edi + 0x18]
// 0047acb8  8b4204               mov eax, dword ptr [edx + 4]
// 0047acbb  88582c               mov byte ptr [eax + 0x2c], bl
// 0047acbe  8b442464             mov eax, dword ptr [esp + 0x64]
// 0047acc2  8b0f                 mov ecx, dword ptr [edi]
// 0047acc4  5e                   pop esi
// 0047acc5  896804               mov dword ptr [eax + 4], ebp
// 0047acc8  5d                   pop ebp
// 0047acc9  8908                 mov dword ptr [eax], ecx
// 0047accb  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 0047accf  5b                   pop ebx
// 0047acd0  5f                   pop edi
// 0047acd1  64890d00000000       mov dword ptr fs:[0], ecx
// 0047acd8  83c450               add esp, 0x50
// 0047acdb  c21000               ret 0x10
// standard library map_int<string> (function ?_Insert@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@IAE?AViterator@12@_NPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@2@ABU?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
