// from server: 36% by atomic.potato
extern "C" int __cdecl sub_495f40(void *);
extern "C" void *__cdecl sub_983b6a(int);
extern "C" int __cdecl type_info_equal(void *, void *);

struct TToolVerb
{
    void *field_0c;
    int f();
};

int TToolVerb::f()
{
    int value = sub_495f40(*(void **)((char *)field_0c + 0xac4));
    if (value)
    {
        void *converted = sub_983b6a(value);
        return type_info_equal((void *)0xdec97c, converted);
    }
    return 0;
}
