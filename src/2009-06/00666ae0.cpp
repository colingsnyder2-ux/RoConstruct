// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
void* __stdcall make_value_00666ae0();
void* func_00666ae0() {
    static void* value = make_value_00666ae0();
    return value;
}
