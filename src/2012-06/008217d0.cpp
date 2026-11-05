// from server: 100% by tester
struct S {
    void* f();
};

extern "C" int __cdecl sub_972290(unsigned char, const char*);

void* S::f()
{
    if (*(unsigned char*)0xe580b3 != 0)
    {
        if (*(int*)0xe275dc != 0x29a)
        {
            char (*fp)(const char*, const char*, int) = *(char (**)(const char*, const char*, int))0xe5809c;
            if (fp != 0)
            {
                if (fp((const char*)0xb440b8, (const char*)0xb42fa8, 0xfd))
                    return (void*)0xe27da0;
            }
            sub_972290(*(unsigned char*)0xe580b3, (const char*)0xb44040);
        }
    }
    return (void*)0xe27da0;
}
