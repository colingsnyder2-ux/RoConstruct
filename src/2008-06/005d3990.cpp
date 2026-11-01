// from server: 100% by king_originala
struct Object
{
    void notify(void*);
};

typedef void (__thiscall *Callback)(void*, void*);

struct S
{
    int reserved;
    void* property;
    int valueOffset;
    int valueIndex;
    Callback callback;
    int callbackOffset;
    int callbackIndex;

    void f(void*, const bool*);
};

void S::f(void* p, const bool* value)
{
    char* base = p ? (char*)p - 20 : 0;
    int table = *(int*)(base + 0x134);
    int offset = *(int*)(table + valueIndex);
    offset += valueOffset;
    bool* destination = (bool*)(base + 0x134 + offset);

    if (*destination != *value)
    {
        *destination = *value;
        if (callback)
        {
            int callbackTable = *(int*)(base + 0x134);
            int adjustment = *(int*)(callbackTable + callbackIndex);
            adjustment += callbackOffset;
            callback(base + 0x134 + adjustment, property);
        }
        ((Object*)base)->notify(property);
    }
}
