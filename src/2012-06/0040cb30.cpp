// from server: 100% by auto
// roc 2012-06 0040cb30  unit: VAuthoringSettings::?$FactoryProduct  size: 184 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0040cb30
//
// 0040cb30  8b442404             mov eax, dword ptr [esp + 4]
// 0040cb34  83ec10               sub esp, 0x10
// 0040cb37  56                   push esi
// 0040cb38  8bf1                 mov esi, ecx
// 0040cb3a  c70601000000         mov dword ptr [esi], 1
// 0040cb40  c7460400000000       mov dword ptr [esi + 4], 0
// 0040cb47  8b08                 mov ecx, dword ptr [eax]
// 0040cb49  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0040cb4d  57                   push edi
// 0040cb4e  85c9                 test ecx, ecx
// 0040cb50  745e                 je 0x40cbb0
// 0040cb52  83f9ff               cmp ecx, -1
// 0040cb55  7459                 je 0x40cbb0
// 0040cb57  83f9fe               cmp ecx, -2
// 0040cb5a  7454                 je 0x40cbb0
// 0040cb5c  8b10                 mov edx, dword ptr [eax]
// 0040cb5e  8b7804               mov edi, dword ptr [eax + 4]
// 0040cb61  85d2                 test edx, edx
// 0040cb63  7508                 jne 0x40cb6d
// 0040cb65  81ff00000080         cmp edi, 0x80000000
// 0040cb6b  7443                 je 0x40cbb0
// 0040cb6d  83faff               cmp edx, -1
// 0040cb70  7508                 jne 0x40cb7a
// 0040cb72  81ffffffff7f         cmp edi, 0x7fffffff
// 0040cb78  7436                 je 0x40cbb0
// 0040cb7a  83fafe               cmp edx, -2
// 0040cb7d  7508                 jne 0x40cb87
// 0040cb7f  81ffffffff7f         cmp edi, 0x7fffffff
// 0040cb85  7429                 je 0x40cbb0
// 0040cb87  53                   push ebx
// 0040cb88  8b5804               mov ebx, dword ptr [eax + 4]
// 0040cb8b  6a14                 push 0x14
// 0040cb8d  680060d71d           push 0x1dd76000
// 0040cb92  6a00                 push 0
// 0040cb94  51                   push ecx
// 0040cb95  8bfa                 mov edi, edx
// 0040cb97  e8a4675700           call 0x983340
// 0040cb9c  03c7                 add eax, edi
// 0040cb9e  13d3                 adc edx, ebx
// 0040cba0  5b                   pop ebx
// 0040cba1  8906                 mov dword ptr [esi], eax
// 0040cba3  5f                   pop edi
// 0040cba4  895604               mov dword ptr [esi + 4], edx
// 0040cba7  8bc6                 mov eax, esi
// 0040cba9  5e                   pop esi
// 0040cbaa  83c410               add esp, 0x10
// 0040cbad  c20800               ret 8
// 0040cbb0  8b5004               mov edx, dword ptr [eax + 4]
// 0040cbb3  894c241c             mov dword ptr [esp + 0x1c], ecx
// 0040cbb7  8b08                 mov ecx, dword ptr [eax]
// 0040cbb9  894c2408             mov dword ptr [esp + 8], ecx
// 0040cbbd  8d44241c             lea eax, [esp + 0x1c]
// 0040cbc1  50                   push eax
// 0040cbc2  8d4c2414             lea ecx, [esp + 0x14]
// 0040cbc6  51                   push ecx
// 0040cbc7  8d4c2410             lea ecx, [esp + 0x10]
// 0040cbcb  89542414             mov dword ptr [esp + 0x14], edx
// 0040cbcf  e8ecfbffff           call 0x40c7c0
// 0040cbd4  8b10                 mov edx, dword ptr [eax]
// 0040cbd6  8916                 mov dword ptr [esi], edx
// 0040cbd8  8b4004               mov eax, dword ptr [eax + 4]
// 0040cbdb  894604               mov dword ptr [esi + 4], eax
// 0040cbde  5f                   pop edi
// 0040cbdf  8bc6                 mov eax, esi
// 0040cbe1  5e                   pop esi
// 0040cbe2  83c410               add esp, 0x10
// 0040cbe5  c20800               ret 8
// library boost-1.36.0/libs\thread\src\win32\thread.cpp (function ??0?$counted_time_rep@Vmillisec_posix_time_system_config@posix_time@boost@@@date_time@boost@@QAE@ABVdate@gregorian@2@ABVtime_duration@posix_time@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.36.0 libs/thread/src/win32/thread.cpp
