// from server: 100% by colin
struct Selection {
    char pad[0xf0];
    void* field;
    void func_00533fd0();
};

extern "C" void __cdecl func_005be3f0(void*, int, int);

void Selection::func_00533fd0()
{
    void* p = field;
    if (p != 0)
        func_005be3f0(p, 2, 0);
}
