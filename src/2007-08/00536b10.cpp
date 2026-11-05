// from server: 100% by auto
// roc 2007-08 00536b10  unit: boost::any::placeholder  size: 184 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00536b10
//
// 00536b10  8b442404             mov eax, dword ptr [esp + 4]
// 00536b14  83ec10               sub esp, 0x10
// 00536b17  56                   push esi
// 00536b18  8bf1                 mov esi, ecx
// 00536b1a  c70601000000         mov dword ptr [esi], 1
// 00536b20  c7460400000000       mov dword ptr [esi + 4], 0
// 00536b27  8b08                 mov ecx, dword ptr [eax]
// 00536b29  85c9                 test ecx, ecx
// 00536b2b  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00536b2f  57                   push edi
// 00536b30  745e                 je 0x536b90
// 00536b32  83f9ff               cmp ecx, -1
// 00536b35  7459                 je 0x536b90
// 00536b37  83f9fe               cmp ecx, -2
// 00536b3a  7454                 je 0x536b90
// 00536b3c  8b10                 mov edx, dword ptr [eax]
// 00536b3e  85d2                 test edx, edx
// 00536b40  8b7804               mov edi, dword ptr [eax + 4]
// 00536b43  7508                 jne 0x536b4d
// 00536b45  81ff00000080         cmp edi, 0x80000000
// 00536b4b  7443                 je 0x536b90
// 00536b4d  83faff               cmp edx, -1
// 00536b50  7508                 jne 0x536b5a
// 00536b52  81ffffffff7f         cmp edi, 0x7fffffff
// 00536b58  7436                 je 0x536b90
// 00536b5a  83fafe               cmp edx, -2
// 00536b5d  7508                 jne 0x536b67
// 00536b5f  81ffffffff7f         cmp edi, 0x7fffffff
// 00536b65  7429                 je 0x536b90
// 00536b67  53                   push ebx
// 00536b68  8b5804               mov ebx, dword ptr [eax + 4]
// 00536b6b  6a14                 push 0x14
// 00536b6d  680060d71d           push 0x1dd76000
// 00536b72  6a00                 push 0
// 00536b74  51                   push ecx
// 00536b75  8bfa                 mov edi, edx
// 00536b77  e8d4a00f00           call 0x630c50
// 00536b7c  03c7                 add eax, edi
// 00536b7e  13d3                 adc edx, ebx
// 00536b80  5b                   pop ebx
// 00536b81  8906                 mov dword ptr [esi], eax
// 00536b83  5f                   pop edi
// 00536b84  895604               mov dword ptr [esi + 4], edx
// 00536b87  8bc6                 mov eax, esi
// 00536b89  5e                   pop esi
// 00536b8a  83c410               add esp, 0x10
// 00536b8d  c20800               ret 8
// 00536b90  8b5004               mov edx, dword ptr [eax + 4]
// 00536b93  894c241c             mov dword ptr [esp + 0x1c], ecx
// 00536b97  8b08                 mov ecx, dword ptr [eax]
// 00536b99  894c2408             mov dword ptr [esp + 8], ecx
// 00536b9d  8d44241c             lea eax, [esp + 0x1c]
// 00536ba1  50                   push eax
// 00536ba2  8d4c2414             lea ecx, [esp + 0x14]
// 00536ba6  51                   push ecx
// 00536ba7  8d4c2410             lea ecx, [esp + 0x10]
// 00536bab  89542414             mov dword ptr [esp + 0x14], edx
// 00536baf  e87cf1ffff           call 0x535d30
// 00536bb4  8b10                 mov edx, dword ptr [eax]
// 00536bb6  8916                 mov dword ptr [esi], edx
// 00536bb8  8b4004               mov eax, dword ptr [eax + 4]
// 00536bbb  894604               mov dword ptr [esi + 4], eax
// 00536bbe  5f                   pop edi
// 00536bbf  8bc6                 mov eax, esi
// 00536bc1  5e                   pop esi
// 00536bc2  83c410               add esp, 0x10
// 00536bc5  c20800               ret 8
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??0?$counted_time_rep@Vmillisec_posix_time_system_config@posix_time@boost@@@date_time@boost@@QAE@ABVdate@gregorian@2@ABVtime_duration@posix_time@2@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
