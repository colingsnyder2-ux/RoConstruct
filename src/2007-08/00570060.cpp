// from server: 74% by colin
extern "C" int __cdecl string_less(const void* a, const void* b);

struct StringRef
{
    char pad[4];
    char* data;
};

int __cdecl compare_strings(const StringRef* a, const StringRef* b)
{
    const char* x = a->data + 4;
    const char* y = b->data + 4;
    return string_less(y, x);
}
