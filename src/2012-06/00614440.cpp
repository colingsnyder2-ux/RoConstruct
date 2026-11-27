// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE /fp:fast
int __stdcall f(int a, float* b) { return (a == 0 && b[1] > b[0]) ? 1 : 0; }

