// from server: 100% by EspClaude
// roc-flags: /O1 /GS- /EHsc /MD /Oy- /hotpatch
extern "C" int __stdcall helper(int);
extern "C" int (__stdcall *pfn_0081ce41)(int, float);
extern "C" int __stdcall func_0081ce41(int a, float b) { helper(1); return pfn_0081ce41(a, b); }
