// from server: 100% by colin

// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) void* get_value_009d9300();
extern void* stored_009d9300;
void func_009d9300() { stored_009d9300 = get_value_009d9300(); }
