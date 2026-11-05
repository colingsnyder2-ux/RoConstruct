// from server: 100% by colin

// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) void* get_value_009cf1f0();
extern void* stored_009cf1f0;
void func_009cf1f0() { stored_009cf1f0 = get_value_009cf1f0(); }
