// from server: 57% by atomic.potato
struct Ray {
    char pad0[4];
    int __cdecl f(int* p);
};

extern "C" void __cdecl reverse_copy(const char* source, char* destination, unsigned int count);
extern "C" int __cdecl sub_4DD500();
extern "C" int __cdecl sub_4DD450(int, int, int);

int Ray::f(int* p)
{
    int v;
    int tmp;
    v = *p;
    if (sub_4DD500())
    {
        reverse_copy((const char*)&v, (char*)&tmp, 4);
        return sub_4DD450(tmp, 0x20, 1);
    }
    return sub_4DD450(v, 0x20, 1);
}
