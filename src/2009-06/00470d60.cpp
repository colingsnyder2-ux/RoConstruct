// from server: 100% by auto
// roc 2009-06 00470d60  unit: RBX::LDraw2Lua::LDraw2RobloxColorMap  size: 169 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00470d60
//
// 00470d60  8b542404             mov edx, dword ptr [esp + 4]
// 00470d64  83ec10               sub esp, 0x10
// 00470d67  53                   push ebx
// 00470d68  55                   push ebp
// 00470d69  57                   push edi
// 00470d6a  8bf9                 mov edi, ecx
// 00470d6c  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 00470d6f  8b4104               mov eax, dword ptr [ecx + 4]
// 00470d72  80781500             cmp byte ptr [eax + 0x15], 0
// 00470d76  8bd9                 mov ebx, ecx
// 00470d78  751a                 jne 0x470d94
// 00470d7a  8b0a                 mov ecx, dword ptr [edx]
// 00470d7c  8d642400             lea esp, [esp]
// 00470d80  39480c               cmp dword ptr [eax + 0xc], ecx
// 00470d83  7d05                 jge 0x470d8a
// 00470d85  8b4008               mov eax, dword ptr [eax + 8]
// 00470d88  eb04                 jmp 0x470d8e
// 00470d8a  8bd8                 mov ebx, eax
// 00470d8c  8b00                 mov eax, dword ptr [eax]
// 00470d8e  80781500             cmp byte ptr [eax + 0x15], 0
// 00470d92  74ec                 je 0x470d80
// 00470d94  8b4718               mov eax, dword ptr [edi + 0x18]
// 00470d97  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 00470d9d  56                   push esi
// 00470d9e  8b37                 mov esi, dword ptr [edi]
// 00470da0  89442414             mov dword ptr [esp + 0x14], eax
// 00470da4  85f6                 test esi, esi
// 00470da6  7404                 je 0x470dac
// 00470da8  3bf6                 cmp esi, esi
// 00470daa  740c                 je 0x470db8
// 00470dac  ffd5                 call ebp
// 00470dae  8b542424             mov edx, dword ptr [esp + 0x24]
// 00470db2  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 00470db8  3b5c2414             cmp ebx, dword ptr [esp + 0x14]
// 00470dbc  7407                 je 0x470dc5
// 00470dbe  8b0a                 mov ecx, dword ptr [edx]
// 00470dc0  3b4b0c               cmp ecx, dword ptr [ebx + 0xc]
// 00470dc3  7d26                 jge 0x470deb
// 00470dc5  8b12                 mov edx, dword ptr [edx]
// 00470dc7  8d442410             lea eax, [esp + 0x10]
// 00470dcb  50                   push eax
// 00470dcc  53                   push ebx
// 00470dcd  56                   push esi
// 00470dce  8d4c2424             lea ecx, [esp + 0x24]
// 00470dd2  51                   push ecx
// 00470dd3  8bcf                 mov ecx, edi
// 00470dd5  89542420             mov dword ptr [esp + 0x20], edx
// 00470dd9  c744242400000000     mov dword ptr [esp + 0x24], 0
// 00470de1  e85afbffff           call 0x470940
// 00470de6  8b30                 mov esi, dword ptr [eax]
// 00470de8  8b5804               mov ebx, dword ptr [eax + 4]
// 00470deb  85f6                 test esi, esi
// 00470ded  7516                 jne 0x470e05
// 00470def  ffd5                 call ebp
// 00470df1  3b5e18               cmp ebx, dword ptr [esi + 0x18]
// 00470df4  5e                   pop esi
// 00470df5  7502                 jne 0x470df9
// 00470df7  ffd5                 call ebp
// 00470df9  5f                   pop edi
// 00470dfa  5d                   pop ebp
// 00470dfb  8d4310               lea eax, [ebx + 0x10]
// 00470dfe  5b                   pop ebx
// 00470dff  83c410               add esp, 0x10
// 00470e02  c20400               ret 4
// 00470e05  8b36                 mov esi, dword ptr [esi]
// 00470e07  ebe8                 jmp 0x470df1
// standard library map_int<ptr> (function ??A?$map@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@@std@@QAEAAPAUT@@ABH@Z)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;
