// from server: 40% by atomic.potato
extern "C" void __stdcall string_copy(void*, void*);

struct Pants
{
    char pad[0x98];
    struct String
    {
        char data[0x1c];
    } value;
    Pants();
};

Pants::Pants()
{
    String* source = reinterpret_cast<String*>(reinterpret_cast<char*>(this) + 0x98);
    string_copy(reinterpret_cast<void*>(this), source);
}
