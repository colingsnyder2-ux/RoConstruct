// from server: 100% by king_originala
typedef void (__thiscall *Function)(void*);

struct Object {
    char padding[0x134];
    char* table;
};

struct Descriptor {
    Function function;
    int adjustment;
    int tableOffset;
    int unused;
    Object* object;
};

void __cdecl invoke(Descriptor* descriptor)
{
    Object* object = descriptor->object;
    int displacement = *reinterpret_cast<int*>(
        object->table + descriptor->tableOffset);
    displacement += descriptor->adjustment;
    descriptor->function(
        reinterpret_cast<char*>(object) + 0x134 + displacement);
}
