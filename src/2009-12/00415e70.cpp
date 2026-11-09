// from server: 100% by atomic.potato
struct TypeInfo
{
    bool operator==(const TypeInfo& other) const;
};

extern "C" bool (__thiscall *imported_type_info_compare)(TypeInfo*, const TypeInfo*);

struct PasteVerb
{
    bool f();
};

bool PasteVerb::f()
{
    TypeInfo* value = *(TypeInfo**)this;
    return imported_type_info_compare((TypeInfo*)0x00B03434, *((const TypeInfo**)((char*)value + 8)));
}
