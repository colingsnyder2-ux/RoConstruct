// from server: 65% by atomic.potato
typedef int BOOL;

struct TypeInfo
{
    BOOL operator==(const TypeInfo& other) const;
};

extern "C" TypeInfo* GetTypeInfo(void*);
extern "C" void* MakeTypeInfo(void*);
extern "C" void DispatchTypeInfo(void*, void*);

struct TToolVerb
{
    char pad[12];
    void* field_0c;
    BOOL f();
};

BOOL TToolVerb::f()
{
    void* value = *(void**)((char*)field_0c + 0xAC4);
    TypeInfo* info = GetTypeInfo(value);
    if (!info)
        return 0;
    void* converted = MakeTypeInfo(info);
    DispatchTypeInfo((void*)0x00DEC558, converted);
    return 1;
}
