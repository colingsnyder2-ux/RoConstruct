// from server: 100% by auto
// roc 2012-06 00404370  unit: RBX::Soundscape::VSoundChannel::?$FactoryProduct::Creator  size: 94 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00404370
//
// 00404370  803d3064e10000       cmp byte ptr [0xe16430], 0
// 00404377  56                   push esi
// 00404378  8bf1                 mov esi, ecx
// 0040437a  7527                 jne 0x4043a3
// 0040437c  686836b400           push 0xb43668
// 00404381  ff15ac21b200         call dword ptr [0xb221ac]
// 00404387  85c0                 test eax, eax
// 00404389  7411                 je 0x40439c
// 0040438b  685836b400           push 0xb43658
// 00404390  50                   push eax
// 00404391  ff15b021b200         call dword ptr [0xb221b0]
// 00404397  a32c64e100           mov dword ptr [0xe1642c], eax
// 0040439c  c6053064e10001       mov byte ptr [0xe16430], 1
// 004043a3  a12c64e100           mov eax, dword ptr [0xe1642c]
// 004043a8  8b542408             mov edx, dword ptr [esp + 8]
// 004043ac  85c0                 test eax, eax
// 004043ae  7410                 je 0x4043c0
// 004043b0  8b4e04               mov ecx, dword ptr [esi + 4]
// 004043b3  6a00                 push 0
// 004043b5  51                   push ecx
// 004043b6  8b0e                 mov ecx, dword ptr [esi]
// 004043b8  52                   push edx
// 004043b9  51                   push ecx
// 004043ba  ffd0                 call eax
// 004043bc  5e                   pop esi
// 004043bd  c20400               ret 4
// 004043c0  8b06                 mov eax, dword ptr [esi]
// 004043c2  52                   push edx
// 004043c3  50                   push eax
// 004043c4  ff150020b200         call dword ptr [0xb22000]
// 004043ca  5e                   pop esi
// 004043cb  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxsettingsstore.cpp (function ?DeleteSubKey@CRegKey@ATL@@QAEJPBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxsettingsstore.cpp
