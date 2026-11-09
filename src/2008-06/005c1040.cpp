// from server: 100% by king_originala
typedef unsigned int size_t;

extern "C" void* (__cdecl *malloc)(size_t);

inline void* __cdecl operator new(size_t size)
{
    return malloc(size);
}

void __cdecl operator delete(void*);

struct Explosion {
    unsigned char storage[0x41c];
    Explosion(int);
};

struct Creator {
    Explosion* object;
    void* control;
    Creator(Explosion*, int);
};

Creator __cdecl createExplosion()
{
    volatile int control = 0;
    *reinterpret_cast<volatile unsigned char*>(&control) = 0;
    return Creator(new Explosion(1), control);
}
