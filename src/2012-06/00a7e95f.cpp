// from server: 68% by colin
// roc-flags: /O2 /Ob2 /Oy- /hotpatch /GS- /EHsc /MD
extern "C" void __stdcall helper_00a7e95f(int); extern "C" __declspec(dllimport) void target_00a7e95f();
void func_00a7e95f() { helper_00a7e95f(1); target_00a7e95f(); }
