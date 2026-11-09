// from server: 100% by colin

// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) void* get_value_00a23b60();
extern void* stored_00a23b60;
void func_00a23b60() { stored_00a23b60 = get_value_00a23b60(); }
