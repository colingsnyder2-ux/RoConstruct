// from server: 100% by king_originala
extern "C" void *__cdecl runtime_cast(void *, int, const void *, const void *, int);
extern "C" __declspec(noreturn) void __cdecl raise_exception(void *, const void *);

extern unsigned char source_type;
extern unsigned char destination_type;
extern unsigned char exception_type;
extern const char bad_cast_message[];

extern void *(__thiscall *construct_bad_cast)(void *, const char *);

struct Descriptor
{
    unsigned char reserved[0x38];
    void (__thiscall *function)(void *);
    int displacement;
    int table_offset;

    void invoke(void *, void *);
};

void Descriptor::invoke(void *object, void *)
{
    void *converted = runtime_cast(object, 0, &source_type, &destination_type, 0);
    if (!converted)
    {
        unsigned char exception[12];
        construct_bad_cast(exception, bad_cast_message);
        raise_exception(exception, &exception_type);
    }

    char *base = static_cast<char *>(converted);
    int *table = *reinterpret_cast<int **>(base + 0x134);
    int adjustment = *reinterpret_cast<int *>(
        reinterpret_cast<char *>(table) + table_offset);
    function(base + 0x134 + adjustment + displacement);
}
