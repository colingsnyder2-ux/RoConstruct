// from server: 100% by colin

// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) void* get_value_00a24dc0();
extern void* stored_00a24dc0;
void func_00a24dc0() { stored_00a24dc0 = get_value_00a24dc0(); }
