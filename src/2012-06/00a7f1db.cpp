// from server: 68% by colin
// roc-flags: /O2 /Ob2 /Oy- /hotpatch /GS- /EHsc /MD
extern "C" void __stdcall helper_00a7f1db(int); extern "C" __declspec(dllimport) void target_00a7f1db();
void func_00a7f1db() { helper_00a7f1db(1); target_00a7f1db(); }
