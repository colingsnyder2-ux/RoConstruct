// from server: 100% by auto
// roc 2010-06 008236f0  unit: PAVCXTPCommandBar::?$CArray  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008236f0
//
// 008236f0  56                   push esi
// 008236f1  8bf1                 mov esi, ecx
// 008236f3  57                   push edi
// 008236f4  8d7e08               lea edi, [esi + 8]
// 008236f7  8bcf                 mov ecx, edi
// 008236f9  c706984ea600         mov dword ptr [esi], 0xa64e98
// 008236ff  e82c51faff           call 0x7c8830
// 00823704  c707684ea600         mov dword ptr [edi], 0xa64e68
// 0082370a  8d7e2c               lea edi, [esi + 0x2c]
// 0082370d  8bcf                 mov ecx, edi
// 0082370f  e8dcf8ffff           call 0x822ff0
// 00823714  33c0                 xor eax, eax
// 00823716  c707804ea600         mov dword ptr [edi], 0xa64e80
// 0082371c  6a01                 push 1
// 0082371e  8bce                 mov ecx, esi
// 00823720  89461c               mov dword ptr [esi + 0x1c], eax
// 00823723  894604               mov dword ptr [esi + 4], eax
// 00823726  894624               mov dword ptr [esi + 0x24], eax
// 00823729  894628               mov dword ptr [esi + 0x28], eax
// 0082372c  894620               mov dword ptr [esi + 0x20], eax
// 0082372f  894640               mov dword ptr [esi + 0x40], eax
// 00823732  894644               mov dword ptr [esi + 0x44], eax
// 00823735  e8c6feffff           call 0x823600
// 0082373a  5f                   pop edi
// 0082373b  8bc6                 mov eax, esi
// 0082373d  5e                   pop esi
// 0082373e  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\CommandBars\XTPMouseManager.cpp (function ??0CXTPMouseManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/CommandBars/XTPMouseManager.cpp
