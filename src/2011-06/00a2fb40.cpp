// from server: 100% by colin

// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) void* get_value_00a2fb40();
extern void* stored_00a2fb40;
void func_00a2fb40() { stored_00a2fb40 = get_value_00a2fb40(); }
