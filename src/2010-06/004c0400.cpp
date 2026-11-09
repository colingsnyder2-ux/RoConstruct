// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
void* __stdcall make_value_004c0400();
void* func_004c0400() {
    static void* value = make_value_004c0400();
    return value;
}
