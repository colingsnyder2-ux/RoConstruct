// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
void* __stdcall make_value_004f4f10();
void* func_004f4f10() {
    static void* value = make_value_004f4f10();
    return value;
}
