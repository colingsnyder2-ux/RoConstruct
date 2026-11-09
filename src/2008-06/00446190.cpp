// from server: 100% by auto
// roc 2008-06 00446190  unit: RBX::Reflection::M::?$TypedPropertyDescriptor  size: 250 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00446190
//
// 00446190  6aff                 push -1
// 00446192  68793f7c00           push 0x7c3f79
// 00446197  64a100000000         mov eax, dword ptr fs:[0]
// 0044619d  50                   push eax
// 0044619e  64892500000000       mov dword ptr fs:[0], esp
// 004461a5  83ec10               sub esp, 0x10
// 004461a8  53                   push ebx
// 004461a9  55                   push ebp
// 004461aa  56                   push esi
// 004461ab  57                   push edi
// 004461ac  8bf1                 mov esi, ecx
// 004461ae  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 004461b1  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 004461b4  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 004461b8  8bcb                 mov ecx, ebx
// 004461ba  2bcd                 sub ecx, ebp
// 004461bc  b893244992           mov eax, 0x92492493
// 004461c1  f7e9                 imul ecx
// 004461c3  03d1                 add edx, ecx
// 004461c5  c1fa04               sar edx, 4
// 004461c8  8bc2                 mov eax, edx
// 004461ca  c1e81f               shr eax, 0x1f
// 004461cd  03c2                 add eax, edx
// 004461cf  c744242800000000     mov dword ptr [esp + 0x28], 0
// 004461d7  3bf8                 cmp edi, eax
// 004461d9  7638                 jbe 0x446213
// 004461db  3beb                 cmp ebp, ebx
// 004461dd  7606                 jbe 0x4461e5
// 004461df  ff1590288000         call dword ptr [0x802890]
// 004461e5  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 004461e8  2b4e0c               sub ecx, dword ptr [esi + 0xc]
// 004461eb  8b2e                 mov ebp, dword ptr [esi]
// 004461ed  8d442434             lea eax, [esp + 0x34]
// 004461f1  50                   push eax
// 004461f2  b893244992           mov eax, 0x92492493
// 004461f7  f7e9                 imul ecx
// 004461f9  03d1                 add edx, ecx
// 004461fb  c1fa04               sar edx, 4
// 004461fe  8bca                 mov ecx, edx
// 00446200  c1e91f               shr ecx, 0x1f
// 00446203  03ca                 add ecx, edx
// 00446205  2bf9                 sub edi, ecx
// 00446207  57                   push edi
// 00446208  53                   push ebx
// 00446209  55                   push ebp
// 0044620a  8bce                 mov ecx, esi
// 0044620c  e86f32feff           call 0x429480
// 00446211  eb50                 jmp 0x446263
// 00446213  734e                 jae 0x446263
// 00446215  3beb                 cmp ebp, ebx
// 00446217  7606                 jbe 0x44621f
// 00446219  ff1590288000         call dword ptr [0x802890]
// 0044621f  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 00446222  8b16                 mov edx, dword ptr [esi]
// 00446224  89542418             mov dword ptr [esp + 0x18], edx
// 00446228  3b6e10               cmp ebp, dword ptr [esi + 0x10]
// 0044622b  7606                 jbe 0x446233
// 0044622d  ff1590288000         call dword ptr [0x802890]
// 00446233  8b06                 mov eax, dword ptr [esi]
// 00446235  57                   push edi
// 00446236  8d4c2414             lea ecx, [esp + 0x14]
// 0044623a  89442414             mov dword ptr [esp + 0x14], eax
// 0044623e  896c2418             mov dword ptr [esp + 0x18], ebp
// 00446242  e8091cfeff           call 0x427e50
// 00446247  8b442418             mov eax, dword ptr [esp + 0x18]
// 0044624b  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0044624f  8b542410             mov edx, dword ptr [esp + 0x10]
// 00446253  53                   push ebx
// 00446254  50                   push eax
// 00446255  51                   push ecx
// 00446256  52                   push edx
// 00446257  8d442428             lea eax, [esp + 0x28]
// 0044625b  50                   push eax
// 0044625c  8bce                 mov ecx, esi
// 0044625e  e8bdfdffff           call 0x446020
// 00446263  8d4c2434             lea ecx, [esp + 0x34]
// 00446267  c7442428ffffffff     mov dword ptr [esp + 0x28], 0xffffffff
// 0044626f  ff1568248000         call dword ptr [0x802468]
// 00446275  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00446279  5f                   pop edi
// 0044627a  5e                   pop esi
// 0044627b  5d                   pop ebp
// 0044627c  5b                   pop ebx
// 0044627d  64890d00000000       mov dword ptr fs:[0], ecx
// 00446284  83c41c               add esp, 0x1c
// 00446287  c22000               ret 0x20
// standard library vector<string> (function ?resize@?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAEXIV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
