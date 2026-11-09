// from server: 68% by atomic.potato
extern "C" int __stdcall DeleteFileA(const char *);

struct S
{
    unsigned char pad[200];
    unsigned int size;
    const char *path;

    void f();
};

void S::f()
{
    pad[0xc8] = 1;
    if (size < 0x10)
        DeleteFileA(path + 0xb0);
    else
        DeleteFileA(path);
}
