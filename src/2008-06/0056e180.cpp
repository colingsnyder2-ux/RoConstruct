// from server: 100% by king_originala
struct String;
String* __cdecl formatFloat(String* result, const float& value);

struct Getter;

struct GetterTable
{
    void* slots[2];
    float (__thiscall *get)(Getter*, void*);
};

struct Getter
{
    GetterTable* table;
};

struct Descriptor
{
    char padding[24];
    Getter* getter;

    String* getString(String* result, void* object);
};

String* Descriptor::getString(String* result, void* object)
{
    volatile int state = 0;
    reinterpret_cast<float&>(object) = getter->table->get(getter, object);
    formatFloat(result, reinterpret_cast<const float&>(object));
    return result;
}
