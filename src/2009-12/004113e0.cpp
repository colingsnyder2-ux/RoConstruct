// from server: 100% by auto
// roc 2009-12 004113e0  unit: CChildFrame  size: 184 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004113e0
//
// 004113e0  8b442404             mov eax, dword ptr [esp + 4]
// 004113e4  83ec10               sub esp, 0x10
// 004113e7  56                   push esi
// 004113e8  8bf1                 mov esi, ecx
// 004113ea  c70601000000         mov dword ptr [esi], 1
// 004113f0  c7460400000000       mov dword ptr [esi + 4], 0
// 004113f7  8b08                 mov ecx, dword ptr [eax]
// 004113f9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004113fd  57                   push edi
// 004113fe  85c9                 test ecx, ecx
// 00411400  745e                 je 0x411460
// 00411402  83f9ff               cmp ecx, -1
// 00411405  7459                 je 0x411460
// 00411407  83f9fe               cmp ecx, -2
// 0041140a  7454                 je 0x411460
// 0041140c  8b10                 mov edx, dword ptr [eax]
// 0041140e  8b7804               mov edi, dword ptr [eax + 4]
// 00411411  85d2                 test edx, edx
// 00411413  7508                 jne 0x41141d
// 00411415  81ff00000080         cmp edi, 0x80000000
// 0041141b  7443                 je 0x411460
// 0041141d  83faff               cmp edx, -1
// 00411420  7508                 jne 0x41142a
// 00411422  81ffffffff7f         cmp edi, 0x7fffffff
// 00411428  7436                 je 0x411460
// 0041142a  83fafe               cmp edx, -2
// 0041142d  7508                 jne 0x411437
// 0041142f  81ffffffff7f         cmp edi, 0x7fffffff
// 00411435  7429                 je 0x411460
// 00411437  53                   push ebx
// 00411438  8b5804               mov ebx, dword ptr [eax + 4]
// 0041143b  6a14                 push 0x14
// 0041143d  680060d71d           push 0x1dd76000
// 00411442  6a00                 push 0
// 00411444  51                   push ecx
// 00411445  8bfa                 mov edi, edx
// 00411447  e824363e00           call 0x7f4a70
// 0041144c  03c7                 add eax, edi
// 0041144e  13d3                 adc edx, ebx
// 00411450  5b                   pop ebx
// 00411451  8906                 mov dword ptr [esi], eax
// 00411453  5f                   pop edi
// 00411454  895604               mov dword ptr [esi + 4], edx
// 00411457  8bc6                 mov eax, esi
// 00411459  5e                   pop esi
// 0041145a  83c410               add esp, 0x10
// 0041145d  c20800               ret 8
// 00411460  8b5004               mov edx, dword ptr [eax + 4]
// 00411463  894c241c             mov dword ptr [esp + 0x1c], ecx
// 00411467  8b08                 mov ecx, dword ptr [eax]
// 00411469  894c2408             mov dword ptr [esp + 8], ecx
// 0041146d  8d44241c             lea eax, [esp + 0x1c]
// 00411471  50                   push eax
// 00411472  8d4c2414             lea ecx, [esp + 0x14]
// 00411476  51                   push ecx
// 00411477  8d4c2410             lea ecx, [esp + 0x10]
// 0041147b  89542414             mov dword ptr [esp + 0x14], edx
// 0041147f  e87cfdffff           call 0x411200
// 00411484  8b10                 mov edx, dword ptr [eax]
// 00411486  8916                 mov dword ptr [esi], edx
// 00411488  8b4004               mov eax, dword ptr [eax + 4]
// 0041148b  894604               mov dword ptr [esi + 4], eax
// 0041148e  5f                   pop edi
// 0041148f  8bc6                 mov eax, esi
// 00411491  5e                   pop esi
// 00411492  83c410               add esp, 0x10
// 00411495  c20800               ret 8
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??0?$counted_time_rep@Vmillisec_posix_time_system_config@posix_time@boost@@@date_time@boost@@QAE@ABVdate@gregorian@2@ABVtime_duration@posix_time@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
