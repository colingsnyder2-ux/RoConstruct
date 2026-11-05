// from server: 100% by colin

// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) void* get_value_00a24890();
extern void* stored_00a24890;
void func_00a24890() { stored_00a24890 = get_value_00a24890(); }
