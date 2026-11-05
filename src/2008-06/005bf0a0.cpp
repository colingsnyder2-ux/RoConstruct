// from server: 100% by king_originala
struct String {
    unsigned int proxy;
    union {
        char buffer[16];
        char* pointer;
    } data;
    unsigned int length;
    unsigned int capacity;
};

extern int* __cdecl convert(void* result, const char* text);

bool __cdecl parse(const String* text, int* result)
{
    const char* chars = text->capacity >= 16
        ? text->data.pointer
        : text->data.buffer;
    *result = *convert(&text, chars);
    return true;
}
