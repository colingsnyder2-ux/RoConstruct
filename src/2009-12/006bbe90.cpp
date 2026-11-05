// from server: 61% by atomic.potato
typedef const char *LPCSTR;

extern "C" void *basic_string_ctor(void *, LPCSTR);

struct Decal
{
    void * __cdecl f(void *, void *, const char *);
};

void *Decal::f(void *, void *, const char *value)
{
    void *result = 0;
    const char *text = *value ? "true" : "false";
    basic_string_ctor(&result, text);
    return (void *)value;
}
