// from server: 24% by colin
struct Binder {
    char pad[0x58];
    void* field_58;
    void* field_5c;
    void* field_60;
    void destroy();
};

extern "C" void __stdcall sub_62fc62(void*);
extern "C" void __stdcall sub_630502(void*);
extern "C" void __stdcall sub_44efc0(void*, void*, void*, void*, void*);

void Binder::destroy()
{
    void* p = field_5c;
    void* v = *(void**)p;
    sub_44efc0(&field_58, &field_58, v, p, &field_58);
    sub_62fc62(field_5c);
    field_5c = 0;
    field_60 = 0;
    sub_630502(this);
}
