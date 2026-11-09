// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
void* __stdcall make_value_008ad5e0();
void* func_008ad5e0() {
    static void* value = make_value_008ad5e0();
    return value;
}
