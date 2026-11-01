// from server: 100% by auto
// roc 2009-12 00881d90  unit: CXTPOffice2007Theme  size: 133 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00881d90
//
// 00881d90  83ec10               sub esp, 0x10
// 00881d93  8b442420             mov eax, dword ptr [esp + 0x20]
// 00881d97  53                   push ebx
// 00881d98  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 00881d9c  55                   push ebp
// 00881d9d  bd03000000           mov ebp, 3
// 00881da2  56                   push esi
// 00881da3  83c0fd               add eax, -3
// 00881da6  83c3fd               add ebx, -3
// 00881da9  57                   push edi
// 00881daa  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00881dae  894c2414             mov dword ptr [esp + 0x14], ecx
// 00881db2  89442418             mov dword ptr [esp + 0x18], eax
// 00881db6  896c2410             mov dword ptr [esp + 0x10], ebp
// 00881dba  85ed                 test ebp, ebp
// 00881dbc  7e41                 jle 0x881dff
// 00881dbe  8b742418             mov esi, dword ptr [esp + 0x18]
// 00881dc2  68ffffff00           push 0xffffff
// 00881dc7  6a02                 push 2
// 00881dc9  6a02                 push 2
// 00881dcb  8d4301               lea eax, [ebx + 1]
// 00881dce  50                   push eax
// 00881dcf  8d4e01               lea ecx, [esi + 1]
// 00881dd2  51                   push ecx
// 00881dd3  8bcf                 mov ecx, edi
// 00881dd5  e8bc460a00           call 0x926496
// 00881dda  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00881dde  6a27                 push 0x27
// 00881de0  e85bb8f7ff           call 0x7fd640
// 00881de5  50                   push eax
// 00881de6  6a02                 push 2
// 00881de8  6a02                 push 2
// 00881dea  53                   push ebx
// 00881deb  56                   push esi
// 00881dec  8bcf                 mov ecx, edi
// 00881dee  e8a3460a00           call 0x926496
// 00881df3  83ee04               sub esi, 4
// 00881df6  83ed01               sub ebp, 1
// 00881df9  75c7                 jne 0x881dc2
// 00881dfb  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 00881dff  4d                   dec ebp
// 00881e00  83eb04               sub ebx, 4
// 00881e03  896c2410             mov dword ptr [esp + 0x10], ebp
// 00881e07  85ed                 test ebp, ebp
// 00881e09  7fb3                 jg 0x881dbe
// 00881e0b  5f                   pop edi
// 00881e0c  5e                   pop esi
// 00881e0d  5d                   pop ebp
// 00881e0e  5b                   pop ebx
// 00881e0f  83c410               add esp, 0x10
// 00881e12  c21400               ret 0x14
// library xtp-15.2.1/Source\CommandBars\XTPResourceTheme.cpp (function ?DrawStatusBarGripper@CXTPResourceTheme@@MAEXPAVCDC@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPResourceTheme.cpp
