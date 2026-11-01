// from server: 100% by tester
// roc 2012-06 0099bdc0  unit: CXTPImageManagerIconSet  size: 76 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0099bdc0
//
// 0099bdc0  837c241000           cmp dword ptr [esp + 0x10], 0
// 0099bdc5  56                   push esi
// 0099bdc6  8b742408             mov esi, dword ptr [esp + 8]
// 0099bdca  57                   push edi
// 0099bdcb  8bf9                 mov edi, ecx
// 0099bdcd  7426                 je 0x99bdf5
// 0099bdcf  6a0e                 push 0xe
// 0099bdd1  56                   push esi
// 0099bdd2  e8856cfeff           call 0x982a5c
// 0099bdd7  85c0                 test eax, eax
// 0099bdd9  741a                 je 0x99bdf5
// 0099bddb  6a01                 push 1
// 0099bddd  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0099bde1  8b542414             mov edx, dword ptr [esp + 0x14]
// 0099bde5  51                   push ecx
// 0099bde6  52                   push edx
// 0099bde7  56                   push esi
// 0099bde8  50                   push eax
// 0099bde9  8bcf                 mov ecx, edi
// 0099bdeb  e880f5ffff           call 0x99b370
// 0099bdf0  5f                   pop edi
// 0099bdf1  5e                   pop esi
// 0099bdf2  c21000               ret 0x10
// 0099bdf5  6a03                 push 3
// 0099bdf7  56                   push esi
// 0099bdf8  e85f6cfeff           call 0x982a5c
// 0099bdfd  85c0                 test eax, eax
// 0099bdff  7404                 je 0x99be05
// 0099be01  6a00                 push 0
// 0099be03  ebd8                 jmp 0x99bddd
// 0099be05  5f                   pop edi
// 0099be06  33c0                 xor eax, eax
// 0099be08  5e                   pop esi
// 0099be09  c21000               ret 0x10
// library xtp-15.2.1-shared-mfc/Source\Common\XTPImageManager.cpp (function ?CreateIconFromResource@CXTPImageManagerIconHandle@@QAEHPBDVCSize@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Common/XTPImageManager.cpp
