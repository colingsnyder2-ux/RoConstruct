// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
void* __stdcall make_value_005d1d70();
void* func_005d1d70() {
    static void* value = make_value_005d1d70();
    return value;
}
