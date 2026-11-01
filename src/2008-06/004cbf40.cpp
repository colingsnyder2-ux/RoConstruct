// from server: 100% by king_originala
extern "C" void __cdecl transfer(char*, char*, char*, char*);

struct Prefix {
    unsigned long reserved;
    char* data;
    unsigned long padding;
};

struct S {
    unsigned long reserved;
    void update(char*);
    long assign(char*);
};

struct Owner : Prefix, S {
};

void S::update(char* value)
{
    char* third = static_cast<Owner*>(this)->data;
    char* second = static_cast<Owner*>(this)->data;
    char* first = static_cast<Owner*>(this)->data + 0x60;
    char* destination = value ? value + 0x60 : 0;

    transfer(destination, first, second + 0x64, third + 0x68);
    assign(value);
}
