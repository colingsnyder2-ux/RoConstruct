// from server: 100% by auto
// roc 2007-03 00686800  unit: seg_00680000  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00686800
//
// 00686800  56                   push esi
// 00686801  57                   push edi
// 00686802  8bf9                 mov edi, ecx
// 00686804  8b470c               mov eax, dword ptr [edi + 0xc]
// 00686807  85c0                 test eax, eax
// 00686809  7423                 je 0x68682e
// 0068680b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0068680f  8b5104               mov edx, dword ptr [ecx + 4]
// 00686812  8b09                 mov ecx, dword ptr [ecx]
// 00686814  6a00                 push 0
// 00686816  52                   push edx
// 00686817  51                   push ecx
// 00686818  ffd0                 call eax
// 0068681a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0068681e  50                   push eax
// 0068681f  56                   push esi
// 00686820  8bcf                 mov ecx, edi
// 00686822  e839feffff           call 0x686660
// 00686827  5f                   pop edi
// 00686828  8bc6                 mov eax, esi
// 0068682a  5e                   pop esi
// 0068682b  c20800               ret 8
// 0068682e  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00686832  33c0                 xor eax, eax
// 00686834  50                   push eax
// 00686835  56                   push esi
// 00686836  8bcf                 mov ecx, edi
// 00686838  e823feffff           call 0x686660
// 0068683d  5f                   pop edi
// 0068683e  8bc6                 mov eax, esi
// 00686840  5e                   pop esi
// 00686841  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?GetScreenArea@CXTPMultiMonitor@@QAE?AVCRect@@ABUtagPOINT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
