// from server: 100% by colin

// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) void* get_value_009d92e0();
extern void* stored_009d92e0;
void func_009d92e0() { stored_009d92e0 = get_value_009d92e0(); }
