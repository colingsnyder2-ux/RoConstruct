// from server: 100% by colin

// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) void* get_value_00a2fb70();
extern void* stored_00a2fb70;
void func_00a2fb70() { stored_00a2fb70 = get_value_00a2fb70(); }
