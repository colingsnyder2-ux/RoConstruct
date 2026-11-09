// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
void* __stdcall make_value_004b9ad0();
void* func_004b9ad0() {
    static void* value = make_value_004b9ad0();
    return value;
}
