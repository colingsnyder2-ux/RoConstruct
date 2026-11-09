// from server: 63% by atomic.potato
struct Accoutrement
{
    int f();
};

extern "C" Accoutrement *singleton();
extern "C" int getDescriptor(void *);

int Accoutrement::f()
{
    Accoutrement *p = singleton();
    return *reinterpret_cast<int *>(getDescriptor(reinterpret_cast<char *>(p) + 0xc8));
}
