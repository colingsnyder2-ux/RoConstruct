// from server: 100% by colin

// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) void* get_value_00a15f10();
extern void* stored_00a15f10;
void func_00a15f10() { stored_00a15f10 = get_value_00a15f10(); }
