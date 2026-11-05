// from server: 68% by colin
// roc-flags: /O2 /Ob2 /Oy- /hotpatch /GS- /EHsc /MD
extern "C" void __stdcall helper_00a7f600(int); extern "C" __declspec(dllimport) void target_00a7f600();
void func_00a7f600() { helper_00a7f600(1); target_00a7f600(); }
