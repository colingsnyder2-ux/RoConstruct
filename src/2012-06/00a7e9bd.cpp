// from server: 68% by colin
// roc-flags: /O2 /Ob2 /Oy- /hotpatch /GS- /EHsc /MD
extern "C" void __stdcall helper_00a7e9bd(int); extern "C" __declspec(dllimport) void target_00a7e9bd();
void func_00a7e9bd() { helper_00a7e9bd(1); target_00a7e9bd(); }
