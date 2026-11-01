// from server: 100% by auto
// roc 2009-12 0097ce10  unit: seg_00970000  size: 381 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097ce10
//
// 0097ce10  56                   push esi
// 0097ce11  8b3538ca9800         mov esi, dword ptr [0x98ca38]
// 0097ce17  6a1e                 push 0x1e
// 0097ce19  33c9                 xor ecx, ecx
// 0097ce1b  6a2b                 push 0x2b
// 0097ce1d  51                   push ecx
// 0097ce1e  51                   push ecx
// 0097ce1f  b819000000           mov eax, 0x19
// 0097ce24  6830bbb900           push 0xb9bb30
// 0097ce29  a328bbb900           mov dword ptr [0xb9bb28], eax
// 0097ce2e  890d2cbbb900         mov dword ptr [0xb9bb2c], ecx
// 0097ce34  ffd6                 call esi
// 0097ce36  6a4c                 push 0x4c
// 0097ce38  6a3c                 push 0x3c
// 0097ce3a  6a21                 push 0x21
// 0097ce3c  6a1e                 push 0x1e
// 0097ce3e  33c0                 xor eax, eax
// 0097ce40  b919000000           mov ecx, 0x19
// 0097ce45  6848bbb900           push 0xb9bb48
// 0097ce4a  a340bbb900           mov dword ptr [0xb9bb40], eax
// 0097ce4f  890d44bbb900         mov dword ptr [0xb9bb44], ecx
// 0097ce55  ffd6                 call esi
// 0097ce57  6a1e                 push 0x1e
// 0097ce59  6a56                 push 0x56
// 0097ce5b  6a00                 push 0
// 0097ce5d  6a2b                 push 0x2b
// 0097ce5f  b819000000           mov eax, 0x19
// 0097ce64  b93f000000           mov ecx, 0x3f
// 0097ce69  6860bbb900           push 0xb9bb60
// 0097ce6e  a358bbb900           mov dword ptr [0xb9bb58], eax
// 0097ce73  890d5cbbb900         mov dword ptr [0xb9bb5c], ecx
// 0097ce79  ffd6                 call esi
// 0097ce7b  6a4c                 push 0x4c
// 0097ce7d  6a1e                 push 0x1e
// 0097ce7f  6a21                 push 0x21
// 0097ce81  6a00                 push 0
// 0097ce83  b83f000000           mov eax, 0x3f
// 0097ce88  b919000000           mov ecx, 0x19
// 0097ce8d  6878bbb900           push 0xb9bb78
// 0097ce92  a370bbb900           mov dword ptr [0xb9bb70], eax
// 0097ce97  890d74bbb900         mov dword ptr [0xb9bb74], ecx
// 0097ce9d  ffd6                 call esi
// 0097ce9f  6a6a                 push 0x6a
// 0097cea1  6a2b                 push 0x2b
// 0097cea3  33c9                 xor ecx, ecx
// 0097cea5  6a4c                 push 0x4c
// 0097cea7  51                   push ecx
// 0097cea8  b819000000           mov eax, 0x19
// 0097cead  6890bbb900           push 0xb9bb90
// 0097ceb2  a388bbb900           mov dword ptr [0xb9bb88], eax
// 0097ceb7  890d8cbbb900         mov dword ptr [0xb9bb8c], ecx
// 0097cebd  ffd6                 call esi
// 0097cebf  6a4c                 push 0x4c
// 0097cec1  6a78                 push 0x78
// 0097cec3  6a21                 push 0x21
// 0097cec5  6a5a                 push 0x5a
// 0097cec7  33c0                 xor eax, eax
// 0097cec9  b919000000           mov ecx, 0x19
// 0097cece  68a8bbb900           push 0xb9bba8
// 0097ced3  a3a0bbb900           mov dword ptr [0xb9bba0], eax
// 0097ced8  890da4bbb900         mov dword ptr [0xb9bba4], ecx
// 0097cede  ffd6                 call esi
// 0097cee0  6a6a                 push 0x6a
// 0097cee2  6a56                 push 0x56
// 0097cee4  6a4c                 push 0x4c
// 0097cee6  6a2b                 push 0x2b
// 0097cee8  b819000000           mov eax, 0x19
// 0097ceed  b93f000000           mov ecx, 0x3f
// 0097cef2  68c0bbb900           push 0xb9bbc0
// 0097cef7  a3b8bbb900           mov dword ptr [0xb9bbb8], eax
// 0097cefc  890dbcbbb900         mov dword ptr [0xb9bbbc], ecx
// 0097cf02  ffd6                 call esi
// 0097cf04  6a4c                 push 0x4c
// 0097cf06  6a5a                 push 0x5a
// 0097cf08  6a21                 push 0x21
// 0097cf0a  b83f000000           mov eax, 0x3f
// 0097cf0f  b919000000           mov ecx, 0x19
// 0097cf14  6a3c                 push 0x3c
// 0097cf16  a3d0bbb900           mov dword ptr [0xb9bbd0], eax
// 0097cf1b  890dd4bbb900         mov dword ptr [0xb9bbd4], ecx
// 0097cf21  68d8bbb900           push 0xb9bbd8
// 0097cf26  ffd6                 call esi
// 0097cf28  6a21                 push 0x21
// 0097cf2a  6a77                 push 0x77
// 0097cf2c  6a00                 push 0
// 0097cf2e  b81e000000           mov eax, 0x1e
// 0097cf33  6a56                 push 0x56
// 0097cf35  8bc8                 mov ecx, eax
// 0097cf37  68f0bbb900           push 0xb9bbf0
// 0097cf3c  a3e8bbb900           mov dword ptr [0xb9bbe8], eax
// 0097cf41  890decbbb900         mov dword ptr [0xb9bbec], ecx
// 0097cf47  ffd6                 call esi
// 0097cf49  6a6d                 push 0x6d
// 0097cf4b  6a77                 push 0x77
// 0097cf4d  6a4c                 push 0x4c
// 0097cf4f  b81e000000           mov eax, 0x1e
// 0097cf54  6a56                 push 0x56
// 0097cf56  8bc8                 mov ecx, eax
// 0097cf58  6808bcb900           push 0xb9bc08
// 0097cf5d  a300bcb900           mov dword ptr [0xb9bc00], eax
// 0097cf62  890d04bcb900         mov dword ptr [0xb9bc04], ecx
// 0097cf68  ffd6                 call esi
// 0097cf6a  6a2b                 push 0x2b
// 0097cf6c  6a2b                 push 0x2b
// 0097cf6e  6a00                 push 0
// 0097cf70  b819000000           mov eax, 0x19
// 0097cf75  6a00                 push 0
// 0097cf77  8bc8                 mov ecx, eax
// 0097cf79  6820bcb900           push 0xb9bc20
// 0097cf7e  a318bcb900           mov dword ptr [0xb9bc18], eax
// 0097cf83  890d1cbcb900         mov dword ptr [0xb9bc1c], ecx
// 0097cf89  ffd6                 call esi
// 0097cf8b  5e                   pop esi
// 0097cf8c  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneContext.cpp (function ??__EarrSpritesStyckerWidbey@@YAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneContext.cpp
