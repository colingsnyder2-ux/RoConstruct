// from server: 100% by colin

// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) void* get_value_00a2fb30();
extern void* stored_00a2fb30;
void func_00a2fb30() { stored_00a2fb30 = get_value_00a2fb30(); }
