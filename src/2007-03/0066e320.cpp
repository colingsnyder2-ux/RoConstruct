// from server: 100% by auto
// roc 2007-03 0066e320  unit: seg_00660000  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0066e320
//
// 0066e320  56                   push esi
// 0066e321  57                   push edi
// 0066e322  8bf1                 mov esi, ecx
// 0066e324  e8a903fbff           call 0x61e6d2
// 0066e329  8bf8                 mov edi, eax
// 0066e32b  8b06                 mov eax, dword ptr [esi]
// 0066e32d  8b903c010000         mov edx, dword ptr [eax + 0x13c]
// 0066e333  8bce                 mov ecx, esi
// 0066e335  ffd2                 call edx
// 0066e337  8bc7                 mov eax, edi
// 0066e339  5f                   pop edi
// 0066e33a  5e                   pop esi
// 0066e33b  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?OnMDINext@CXTPTabClientWnd@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
