// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
void* __stdcall make_value_005d78f0();
void* func_005d78f0() {
    static void* value = make_value_005d78f0();
    return value;
}
