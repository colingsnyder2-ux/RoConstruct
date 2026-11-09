// from server: 28% by atomic.potato
struct TypeInfo
{
    bool operator==(const TypeInfo& other) const;
};

struct BadCast
{
    char pad[8];
};

extern "C" bool (__thiscall *type_info_compare)(TypeInfo*, const TypeInfo*);
extern "C" void (__thiscall *bad_cast_ctor)(BadCast*, const char*);
extern "C" void (__stdcall *throw_bad_cast)(BadCast*);

struct PasteVerb
{
    void f();
};

void PasteVerb::f()
{
    TypeInfo* value = *(TypeInfo**)this;
    if (value != 0)
    {
        TypeInfo* t = *(TypeInfo**)value;
        if (t != 0)
        {
            t = (TypeInfo*)(*(void***)t)[1];
        }
        else
        {
            t = (TypeInfo*)0x00B0030C;
        }
        if (type_info_compare(t, (const TypeInfo*)0x00B033DC))
        {
            if ((char*)value + 8 != 0)
            {
                return;
            }
        }
    }
    BadCast bc;
    bad_cast_ctor(&bc, "bad cast");
    throw_bad_cast(&bc);
}
