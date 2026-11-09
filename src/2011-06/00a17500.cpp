// from server: 100% by colin

// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) void* get_value_00a17500();
extern void* stored_00a17500;
void func_00a17500() { stored_00a17500 = get_value_00a17500(); }
