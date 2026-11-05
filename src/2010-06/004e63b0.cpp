// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
void* __stdcall make_value_004e63b0();
void* func_004e63b0() {
    static void* value = make_value_004e63b0();
    return value;
}
