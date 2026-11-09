// from server: 100% by colin
extern "C" void __cdecl func_0062ff26(void*);

struct ScintillaView {
    char pad[0xb8];
    void* field_b8;
    void* field_bc;
    void* field_c0;
    void method(int, int);
};

void ScintillaView::method(int, int)
{
    if (field_b8 != 0) {
        func_0062ff26(field_b8);
        field_b8 = 0;
    }
    field_c0 = 0;
    field_bc = 0;
}
