// from server: 100% by auto
// roc 2010-06 004116b0  unit: CChildFrame  size: 184 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004116b0
//
// 004116b0  8b442404             mov eax, dword ptr [esp + 4]
// 004116b4  83ec10               sub esp, 0x10
// 004116b7  56                   push esi
// 004116b8  8bf1                 mov esi, ecx
// 004116ba  c70601000000         mov dword ptr [esi], 1
// 004116c0  c7460400000000       mov dword ptr [esi + 4], 0
// 004116c7  8b08                 mov ecx, dword ptr [eax]
// 004116c9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004116cd  57                   push edi
// 004116ce  85c9                 test ecx, ecx
// 004116d0  745e                 je 0x411730
// 004116d2  83f9ff               cmp ecx, -1
// 004116d5  7459                 je 0x411730
// 004116d7  83f9fe               cmp ecx, -2
// 004116da  7454                 je 0x411730
// 004116dc  8b10                 mov edx, dword ptr [eax]
// 004116de  8b7804               mov edi, dword ptr [eax + 4]
// 004116e1  85d2                 test edx, edx
// 004116e3  7508                 jne 0x4116ed
// 004116e5  81ff00000080         cmp edi, 0x80000000
// 004116eb  7443                 je 0x411730
// 004116ed  83faff               cmp edx, -1
// 004116f0  7508                 jne 0x4116fa
// 004116f2  81ffffffff7f         cmp edi, 0x7fffffff
// 004116f8  7436                 je 0x411730
// 004116fa  83fafe               cmp edx, -2
// 004116fd  7508                 jne 0x411707
// 004116ff  81ffffffff7f         cmp edi, 0x7fffffff
// 00411705  7429                 je 0x411730
// 00411707  53                   push ebx
// 00411708  8b5804               mov ebx, dword ptr [eax + 4]
// 0041170b  6a14                 push 0x14
// 0041170d  680060d71d           push 0x1dd76000
// 00411712  6a00                 push 0
// 00411714  51                   push ecx
// 00411715  8bfa                 mov edi, edx
// 00411717  e894743900           call 0x7a8bb0
// 0041171c  03c7                 add eax, edi
// 0041171e  13d3                 adc edx, ebx
// 00411720  5b                   pop ebx
// 00411721  8906                 mov dword ptr [esi], eax
// 00411723  5f                   pop edi
// 00411724  895604               mov dword ptr [esi + 4], edx
// 00411727  8bc6                 mov eax, esi
// 00411729  5e                   pop esi
// 0041172a  83c410               add esp, 0x10
// 0041172d  c20800               ret 8
// 00411730  8b5004               mov edx, dword ptr [eax + 4]
// 00411733  894c241c             mov dword ptr [esp + 0x1c], ecx
// 00411737  8b08                 mov ecx, dword ptr [eax]
// 00411739  894c2408             mov dword ptr [esp + 8], ecx
// 0041173d  8d44241c             lea eax, [esp + 0x1c]
// 00411741  50                   push eax
// 00411742  8d4c2414             lea ecx, [esp + 0x14]
// 00411746  51                   push ecx
// 00411747  8d4c2410             lea ecx, [esp + 0x10]
// 0041174b  89542414             mov dword ptr [esp + 0x14], edx
// 0041174f  e88cfdffff           call 0x4114e0
// 00411754  8b10                 mov edx, dword ptr [eax]
// 00411756  8916                 mov dword ptr [esi], edx
// 00411758  8b4004               mov eax, dword ptr [eax + 4]
// 0041175b  894604               mov dword ptr [esi + 4], eax
// 0041175e  5f                   pop edi
// 0041175f  8bc6                 mov eax, esi
// 00411761  5e                   pop esi
// 00411762  83c410               add esp, 0x10
// 00411765  c20800               ret 8
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??0?$counted_time_rep@Vmillisec_posix_time_system_config@posix_time@boost@@@date_time@boost@@QAE@ABVdate@gregorian@2@ABVtime_duration@posix_time@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
