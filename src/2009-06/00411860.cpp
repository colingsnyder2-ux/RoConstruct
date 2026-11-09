// from server: 100% by auto
// roc 2009-06 00411860  unit: std::logic_error  size: 184 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00411860
//
// 00411860  8b442404             mov eax, dword ptr [esp + 4]
// 00411864  83ec10               sub esp, 0x10
// 00411867  56                   push esi
// 00411868  8bf1                 mov esi, ecx
// 0041186a  c70601000000         mov dword ptr [esi], 1
// 00411870  c7460400000000       mov dword ptr [esi + 4], 0
// 00411877  8b08                 mov ecx, dword ptr [eax]
// 00411879  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0041187d  57                   push edi
// 0041187e  85c9                 test ecx, ecx
// 00411880  745e                 je 0x4118e0
// 00411882  83f9ff               cmp ecx, -1
// 00411885  7459                 je 0x4118e0
// 00411887  83f9fe               cmp ecx, -2
// 0041188a  7454                 je 0x4118e0
// 0041188c  8b10                 mov edx, dword ptr [eax]
// 0041188e  8b7804               mov edi, dword ptr [eax + 4]
// 00411891  85d2                 test edx, edx
// 00411893  7508                 jne 0x41189d
// 00411895  81ff00000080         cmp edi, 0x80000000
// 0041189b  7443                 je 0x4118e0
// 0041189d  83faff               cmp edx, -1
// 004118a0  7508                 jne 0x4118aa
// 004118a2  81ffffffff7f         cmp edi, 0x7fffffff
// 004118a8  7436                 je 0x4118e0
// 004118aa  83fafe               cmp edx, -2
// 004118ad  7508                 jne 0x4118b7
// 004118af  81ffffffff7f         cmp edi, 0x7fffffff
// 004118b5  7429                 je 0x4118e0
// 004118b7  53                   push ebx
// 004118b8  8b5804               mov ebx, dword ptr [eax + 4]
// 004118bb  6a14                 push 0x14
// 004118bd  680060d71d           push 0x1dd76000
// 004118c2  6a00                 push 0
// 004118c4  51                   push ecx
// 004118c5  8bfa                 mov edi, edx
// 004118c7  e874833000           call 0x719c40
// 004118cc  03c7                 add eax, edi
// 004118ce  13d3                 adc edx, ebx
// 004118d0  5b                   pop ebx
// 004118d1  8906                 mov dword ptr [esi], eax
// 004118d3  5f                   pop edi
// 004118d4  895604               mov dword ptr [esi + 4], edx
// 004118d7  8bc6                 mov eax, esi
// 004118d9  5e                   pop esi
// 004118da  83c410               add esp, 0x10
// 004118dd  c20800               ret 8
// 004118e0  8b5004               mov edx, dword ptr [eax + 4]
// 004118e3  894c241c             mov dword ptr [esp + 0x1c], ecx
// 004118e7  8b08                 mov ecx, dword ptr [eax]
// 004118e9  894c2408             mov dword ptr [esp + 8], ecx
// 004118ed  8d44241c             lea eax, [esp + 0x1c]
// 004118f1  50                   push eax
// 004118f2  8d4c2414             lea ecx, [esp + 0x14]
// 004118f6  51                   push ecx
// 004118f7  8d4c2410             lea ecx, [esp + 0x10]
// 004118fb  89542414             mov dword ptr [esp + 0x14], edx
// 004118ff  e85cfdffff           call 0x411660
// 00411904  8b10                 mov edx, dword ptr [eax]
// 00411906  8916                 mov dword ptr [esi], edx
// 00411908  8b4004               mov eax, dword ptr [eax + 4]
// 0041190b  894604               mov dword ptr [esi + 4], eax
// 0041190e  5f                   pop edi
// 0041190f  8bc6                 mov eax, esi
// 00411911  5e                   pop esi
// 00411912  83c410               add esp, 0x10
// 00411915  c20800               ret 8
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??0?$counted_time_rep@Vmillisec_posix_time_system_config@posix_time@boost@@@date_time@boost@@QAE@ABVdate@gregorian@2@ABVtime_duration@posix_time@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
