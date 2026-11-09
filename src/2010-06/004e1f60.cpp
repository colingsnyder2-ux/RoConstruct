// from server: 71% by atomic.potato
struct Ray
{
    char pad0[4];
    char pad1[4];
    char pad2[4];
    char pad3[4];
    char pad4[4];
    char pad5[4];
    char pad6[4];
    char pad7[4];
    char pad8[4];
    char pad9[4];
    char pad10[4];
    char pad11[4];
    char pad12[4];
    char pad13[4];
    char pad14[4];
    char pad15[4];
    Ray* __cdecl func(const void* a, unsigned short b);
};

extern "C" void __cdecl sub_4e0f70(void*, const void*);
extern "C" void __cdecl reverse_copy(const char*, char*, unsigned int);
extern "C" char __cdecl sub_4dd500(void);
extern "C" void __cdecl sub_4dd450(Ray*, const void*, int, int);

Ray* Ray::func(const void* a, unsigned short b)
{
    sub_4e0f70(this, a);
    unsigned int c = b;
    if (sub_4dd500())
    {
        char buf[16];
        reverse_copy((const char*)&c, buf, 2);
        sub_4dd450(this, buf, 0x10, 1);
    }
    else
    {
        sub_4dd450(this, &c, 0x10, 1);
    }
    return this;
}
