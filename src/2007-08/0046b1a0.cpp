// from server: 33% by colin
struct LuaObjectWriter
{
    void* vtable;
    char pad0[0x6c];
    void* field70;
    void construct();
};

extern "C" void __stdcall sub_77e6ac(void*);

void LuaObjectWriter::construct()
{
    vtable = (void*)0x7961b4;
    field70 = 0;
    sub_77e6ac(&field70);
    vtable = (void*)0x7961a8;
}
