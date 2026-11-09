// from server: 100% by auto
// roc 2011-06 0040b300  unit: VAuthoringSettings::?$FactoryProduct  size: 184 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0040b300
//
// 0040b300  8b442404             mov eax, dword ptr [esp + 4]
// 0040b304  83ec10               sub esp, 0x10
// 0040b307  56                   push esi
// 0040b308  8bf1                 mov esi, ecx
// 0040b30a  c70601000000         mov dword ptr [esi], 1
// 0040b310  c7460400000000       mov dword ptr [esi + 4], 0
// 0040b317  8b08                 mov ecx, dword ptr [eax]
// 0040b319  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0040b31d  57                   push edi
// 0040b31e  85c9                 test ecx, ecx
// 0040b320  745e                 je 0x40b380
// 0040b322  83f9ff               cmp ecx, -1
// 0040b325  7459                 je 0x40b380
// 0040b327  83f9fe               cmp ecx, -2
// 0040b32a  7454                 je 0x40b380
// 0040b32c  8b10                 mov edx, dword ptr [eax]
// 0040b32e  8b7804               mov edi, dword ptr [eax + 4]
// 0040b331  85d2                 test edx, edx
// 0040b333  7508                 jne 0x40b33d
// 0040b335  81ff00000080         cmp edi, 0x80000000
// 0040b33b  7443                 je 0x40b380
// 0040b33d  83faff               cmp edx, -1
// 0040b340  7508                 jne 0x40b34a
// 0040b342  81ffffffff7f         cmp edi, 0x7fffffff
// 0040b348  7436                 je 0x40b380
// 0040b34a  83fafe               cmp edx, -2
// 0040b34d  7508                 jne 0x40b357
// 0040b34f  81ffffffff7f         cmp edi, 0x7fffffff
// 0040b355  7429                 je 0x40b380
// 0040b357  53                   push ebx
// 0040b358  8b5804               mov ebx, dword ptr [eax + 4]
// 0040b35b  6a14                 push 0x14
// 0040b35d  680060d71d           push 0x1dd76000
// 0040b362  6a00                 push 0
// 0040b364  51                   push ecx
// 0040b365  8bfa                 mov edi, edx
// 0040b367  e844ff3f00           call 0x80b2b0
// 0040b36c  03c7                 add eax, edi
// 0040b36e  13d3                 adc edx, ebx
// 0040b370  5b                   pop ebx
// 0040b371  8906                 mov dword ptr [esi], eax
// 0040b373  5f                   pop edi
// 0040b374  895604               mov dword ptr [esi + 4], edx
// 0040b377  8bc6                 mov eax, esi
// 0040b379  5e                   pop esi
// 0040b37a  83c410               add esp, 0x10
// 0040b37d  c20800               ret 8
// 0040b380  8b5004               mov edx, dword ptr [eax + 4]
// 0040b383  894c241c             mov dword ptr [esp + 0x1c], ecx
// 0040b387  8b08                 mov ecx, dword ptr [eax]
// 0040b389  894c2408             mov dword ptr [esp + 8], ecx
// 0040b38d  8d44241c             lea eax, [esp + 0x1c]
// 0040b391  50                   push eax
// 0040b392  8d4c2414             lea ecx, [esp + 0x14]
// 0040b396  51                   push ecx
// 0040b397  8d4c2410             lea ecx, [esp + 0x10]
// 0040b39b  89542414             mov dword ptr [esp + 0x14], edx
// 0040b39f  e88cfcffff           call 0x40b030
// 0040b3a4  8b10                 mov edx, dword ptr [eax]
// 0040b3a6  8916                 mov dword ptr [esi], edx
// 0040b3a8  8b4004               mov eax, dword ptr [eax + 4]
// 0040b3ab  894604               mov dword ptr [esi + 4], eax
// 0040b3ae  5f                   pop edi
// 0040b3af  8bc6                 mov eax, esi
// 0040b3b1  5e                   pop esi
// 0040b3b2  83c410               add esp, 0x10
// 0040b3b5  c20800               ret 8
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??0?$counted_time_rep@Vmillisec_posix_time_system_config@posix_time@boost@@@date_time@boost@@QAE@ABVdate@gregorian@2@ABVtime_duration@posix_time@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
