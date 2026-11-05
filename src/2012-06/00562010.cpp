// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
void* __stdcall make_value_00562010();
void* func_00562010() {
    static void* value = make_value_00562010();
    return value;
}
