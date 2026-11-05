// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
void* __stdcall make_value_004c02e0();
void* func_004c02e0() {
    static void* value = make_value_004c02e0();
    return value;
}
