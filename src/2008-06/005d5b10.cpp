// from server: 100% by king_originala
struct StringData
{
    char data[28];
};

struct Value
{
    StringData text;
    unsigned long extra;
};

extern bool __cdecl valueChanged(const Value*, const Value*);

struct Object
{
    void notify(void*);
};

typedef StringData& (__thiscall *StringAssign)(
    StringData*, const StringData&);

extern StringAssign stringAssign;

typedef void (__thiscall *Callback)(void*, void*);

struct Property
{
    void* reserved;
    void* descriptor;
    int valueOffset;
    void* reserved2;
    Callback callback;
    int callbackOffset;

    void set(char*, const Value*);
};

void Property::set(char* instance, const Value* value)
{
    char* object = instance ? instance - 20 : 0;

    if (valueChanged(
            reinterpret_cast<Value*>(object + valueOffset), value))
    {
        Value* destination =
            reinterpret_cast<Value*>(object + valueOffset);

        stringAssign(&destination->text, value->text);
        destination->extra = value->extra;

        if (callback)
            callback(object + callbackOffset, descriptor);

        reinterpret_cast<Object*>(object)->notify(descriptor);
    }
}
