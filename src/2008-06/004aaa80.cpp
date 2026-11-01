// from server: 100% by king_originala
extern "C" void (__cdecl* _invalid_parameter_noinfo)();

struct Getter {
    void** vtable;
};

struct Values {
    char padding[0xdc];
    int* begin;
    int* volatile end;
};

struct EnumPropDescriptor {
    char padding[0x1c];
    Getter* getter;
    Values* values;

    int convert(void* argument);
};

int EnumPropDescriptor::convert(void* argument)
{
    unsigned int index =
        reinterpret_cast<unsigned int (__thiscall*)(Getter*, void*)>(
            getter->vtable[2])(getter, argument);

    Values* table = values;
    if (index < static_cast<unsigned int>(table->end - table->begin)) {
        if (index >= static_cast<unsigned int>(table->end - table->begin))
            _invalid_parameter_noinfo();

        return table->begin[index];
    }

    return -1;
}
