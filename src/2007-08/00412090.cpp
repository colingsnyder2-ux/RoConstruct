// from server: 29% by colin
extern "C" __declspec(dllimport) void* __stdcall SafeArrayCreate(unsigned short, unsigned int, void*);
extern "C" __declspec(dllimport) void __stdcall SafeArrayLock(void*);
extern "C" __declspec(dllimport) void __stdcall SafeArrayUnlock(void*);
extern "C" __declspec(dllimport) void __stdcall _invalid_parameter_noinfo(void);

struct Inner {
    char pad[8];
};

struct Outer {
    Inner* begin;
    Inner* end;
    int count();
    void* make(int idx);
};

int Outer::count()
{
    return 0;
}

void* Outer::make(int idx)
{
    return 0;
}

void* func_00412090(Outer* self)
{
    int n;
    void* sa;
    int i;
    Inner* p;

    n = 0;
    if (self->begin != 0)
        n = (int)(((char*)self->end - (char*)self->begin) >> 3);

    sa = SafeArrayCreate(0xc, 1, &n);
    if (sa != 0)
        SafeArrayLock(sa);

    i = 0;
    while (i < self->count())
    {
        if (self->begin == 0 || i >= (int)(((char*)self->end - (char*)self->begin) >> 3))
            _invalid_parameter_noinfo();

        p = self->begin + i;
        self->make(i);
        i++;
    }

    SafeArrayUnlock(sa);
    return sa;
}
