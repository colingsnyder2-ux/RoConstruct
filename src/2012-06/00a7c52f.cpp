// from server: 68% by colin
// roc-flags: /O2 /Ob2 /Oy- /hotpatch /GS- /EHsc /MD
extern "C" void __stdcall helper_00a7c52f(int); extern "C" __declspec(dllimport) void target_00a7c52f();
void func_00a7c52f() { helper_00a7c52f(1); target_00a7c52f(); }
