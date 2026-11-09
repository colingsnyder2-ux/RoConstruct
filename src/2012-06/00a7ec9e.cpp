// from server: 68% by colin
// roc-flags: /O2 /Ob2 /Oy- /hotpatch /GS- /EHsc /MD
extern "C" void __stdcall helper_00a7ec9e(int); extern "C" __declspec(dllimport) void target_00a7ec9e();
void func_00a7ec9e() { helper_00a7ec9e(1); target_00a7ec9e(); }
