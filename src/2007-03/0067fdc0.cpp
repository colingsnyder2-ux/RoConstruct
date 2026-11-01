// from server: 100% by auto
// roc 2007-03 0067fdc0  unit: seg_00670000  size: 113 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0067fdc0
//
// 0067fdc0  837c240400           cmp dword ptr [esp + 4], 0
// 0067fdc5  56                   push esi
// 0067fdc6  8bf1                 mov esi, ecx
// 0067fdc8  7437                 je 0x67fe01
// 0067fdca  833d941e8c0000       cmp dword ptr [0x8c1e94], 0
// 0067fdd1  755a                 jne 0x67fe2d
// 0067fdd3  833d981e8c0000       cmp dword ptr [0x8c1e98], 0
// 0067fdda  7551                 jne 0x67fe2d
// 0067fddc  ff1584d27700         call dword ptr [0x77d284]
// 0067fde2  50                   push eax
// 0067fde3  6a00                 push 0
// 0067fde5  6810fd6700           push 0x67fd10
// 0067fdea  6a07                 push 7
// 0067fdec  ff15f0ee7700         call dword ptr [0x77eef0]
// 0067fdf2  8935981e8c00         mov dword ptr [0x8c1e98], esi
// 0067fdf8  a3941e8c00           mov dword ptr [0x8c1e94], eax
// 0067fdfd  5e                   pop esi
// 0067fdfe  c20400               ret 4
// 0067fe01  a1941e8c00           mov eax, dword ptr [0x8c1e94]
// 0067fe06  85c0                 test eax, eax
// 0067fe08  7423                 je 0x67fe2d
// 0067fe0a  3935981e8c00         cmp dword ptr [0x8c1e98], esi
// 0067fe10  751b                 jne 0x67fe2d
// 0067fe12  50                   push eax
// 0067fe13  ff15ecee7700         call dword ptr [0x77eeec]
// 0067fe19  c705941e8c0000000000 mov dword ptr [0x8c1e94], 0
// 0067fe23  c705981e8c0000000000 mov dword ptr [0x8c1e98], 0
// 0067fe2d  5e                   pop esi
// 0067fe2e  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPToolTipContext.cpp (function ?HookMouseMove@CXTPToolTipContextToolTip@@IAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPToolTipContext.cpp
