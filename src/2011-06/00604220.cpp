// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
void* __stdcall make_value_00604220();
void* func_00604220() {
    static void* value = make_value_00604220();
    return value;
}
