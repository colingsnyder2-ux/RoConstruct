// from server: 57% by atomic.potato
extern "C" int __stdcall DeleteFileA(const char*);

struct Seg {
    unsigned char padC0[0xc0];
    void* object;
    unsigned char padD8[0x10];
    unsigned int value;
    unsigned char flag;
    int f();
};

int Seg::f()
{
    flag = 1;
    if (value < 0x10)
        return DeleteFileA((const char*)((char*)object + 0xc0));
    return DeleteFileA((const char*)object);
}
