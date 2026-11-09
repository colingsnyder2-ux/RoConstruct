// from server: 100% by auto
// roc 2008-06 0055d270  unit: RBX::MD5HasherImpl  size: 184 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0055d270
//
// 0055d270  8b442404             mov eax, dword ptr [esp + 4]
// 0055d274  83ec10               sub esp, 0x10
// 0055d277  56                   push esi
// 0055d278  8bf1                 mov esi, ecx
// 0055d27a  c70601000000         mov dword ptr [esi], 1
// 0055d280  c7460400000000       mov dword ptr [esi + 4], 0
// 0055d287  8b08                 mov ecx, dword ptr [eax]
// 0055d289  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0055d28d  57                   push edi
// 0055d28e  85c9                 test ecx, ecx
// 0055d290  745e                 je 0x55d2f0
// 0055d292  83f9ff               cmp ecx, -1
// 0055d295  7459                 je 0x55d2f0
// 0055d297  83f9fe               cmp ecx, -2
// 0055d29a  7454                 je 0x55d2f0
// 0055d29c  8b10                 mov edx, dword ptr [eax]
// 0055d29e  8b7804               mov edi, dword ptr [eax + 4]
// 0055d2a1  85d2                 test edx, edx
// 0055d2a3  7508                 jne 0x55d2ad
// 0055d2a5  81ff00000080         cmp edi, 0x80000000
// 0055d2ab  7443                 je 0x55d2f0
// 0055d2ad  83faff               cmp edx, -1
// 0055d2b0  7508                 jne 0x55d2ba
// 0055d2b2  81ffffffff7f         cmp edi, 0x7fffffff
// 0055d2b8  7436                 je 0x55d2f0
// 0055d2ba  83fafe               cmp edx, -2
// 0055d2bd  7508                 jne 0x55d2c7
// 0055d2bf  81ffffffff7f         cmp edi, 0x7fffffff
// 0055d2c5  7429                 je 0x55d2f0
// 0055d2c7  53                   push ebx
// 0055d2c8  8b5804               mov ebx, dword ptr [eax + 4]
// 0055d2cb  6a14                 push 0x14
// 0055d2cd  680060d71d           push 0x1dd76000
// 0055d2d2  6a00                 push 0
// 0055d2d4  51                   push ecx
// 0055d2d5  8bfa                 mov edi, edx
// 0055d2d7  e8f4431400           call 0x6a16d0
// 0055d2dc  03c7                 add eax, edi
// 0055d2de  13d3                 adc edx, ebx
// 0055d2e0  5b                   pop ebx
// 0055d2e1  8906                 mov dword ptr [esi], eax
// 0055d2e3  5f                   pop edi
// 0055d2e4  895604               mov dword ptr [esi + 4], edx
// 0055d2e7  8bc6                 mov eax, esi
// 0055d2e9  5e                   pop esi
// 0055d2ea  83c410               add esp, 0x10
// 0055d2ed  c20800               ret 8
// 0055d2f0  8b5004               mov edx, dword ptr [eax + 4]
// 0055d2f3  894c241c             mov dword ptr [esp + 0x1c], ecx
// 0055d2f7  8b08                 mov ecx, dword ptr [eax]
// 0055d2f9  894c2408             mov dword ptr [esp + 8], ecx
// 0055d2fd  8d44241c             lea eax, [esp + 0x1c]
// 0055d301  50                   push eax
// 0055d302  8d4c2414             lea ecx, [esp + 0x14]
// 0055d306  51                   push ecx
// 0055d307  8d4c2410             lea ecx, [esp + 0x10]
// 0055d30b  89542414             mov dword ptr [esp + 0x14], edx
// 0055d30f  e8acfaffff           call 0x55cdc0
// 0055d314  8b10                 mov edx, dword ptr [eax]
// 0055d316  8916                 mov dword ptr [esi], edx
// 0055d318  8b4004               mov eax, dword ptr [eax + 4]
// 0055d31b  894604               mov dword ptr [esi + 4], eax
// 0055d31e  5f                   pop edi
// 0055d31f  8bc6                 mov eax, esi
// 0055d321  5e                   pop esi
// 0055d322  83c410               add esp, 0x10
// 0055d325  c20800               ret 8
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??0?$counted_time_rep@Vmillisec_posix_time_system_config@posix_time@boost@@@date_time@boost@@QAE@ABVdate@gregorian@2@ABVtime_duration@posix_time@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
