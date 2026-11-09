// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
void* __stdcall make_value_005e62a0();
void* func_005e62a0() {
    static void* value = make_value_005e62a0();
    return value;
}
