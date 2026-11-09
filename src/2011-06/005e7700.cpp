// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
void* __stdcall make_value_005e7700();
void* func_005e7700() {
    static void* value = make_value_005e7700();
    return value;
}
