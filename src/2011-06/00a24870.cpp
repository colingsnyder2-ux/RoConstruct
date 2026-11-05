// from server: 100% by colin

// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) void* get_value_00a24870();
extern void* stored_00a24870;
void func_00a24870() { stored_00a24870 = get_value_00a24870(); }
