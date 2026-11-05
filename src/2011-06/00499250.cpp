// from server: 82% by atomic.potato
extern "C" void destroy_string(void *);
extern "C" void __cdecl release_object(void *);

struct UData
{
    void *value;
    void *string;
    void f();
};

void UData::f()
{
    void *p = string;
    if (p != 0)
    {
        destroy_string((char *)p + 12);
        release_object(p);
    }
}
