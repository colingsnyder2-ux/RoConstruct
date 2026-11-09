// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
void* __stdcall make_value_006d0a00();
void* func_006d0a00() {
    static void* value = make_value_006d0a00();
    return value;
}
