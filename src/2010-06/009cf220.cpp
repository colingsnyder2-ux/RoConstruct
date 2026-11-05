// from server: 100% by colin

// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) void* get_value_009cf220();
extern void* stored_009cf220;
void func_009cf220() { stored_009cf220 = get_value_009cf220(); }
