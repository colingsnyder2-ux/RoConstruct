// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
void* __stdcall make_value_004c44c0();
void* func_004c44c0() {
    static void* value = make_value_004c44c0();
    return value;
}
