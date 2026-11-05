// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
void* __stdcall make_value_0048a520();
void* func_0048a520() {
    static void* value = make_value_0048a520();
    return value;
}
