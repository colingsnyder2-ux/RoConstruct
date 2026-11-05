// from server: 68% by colin
// roc-flags: /O2 /Ob2 /Oy- /hotpatch /GS- /EHsc /MD
extern "C" void __stdcall helper_00a7cae2(int); extern "C" __declspec(dllimport) void target_00a7cae2();
void func_00a7cae2() { helper_00a7cae2(1); target_00a7cae2(); }
