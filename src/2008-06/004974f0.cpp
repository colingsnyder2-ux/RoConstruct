// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

extern char instanceType;
extern char playerType;
extern "C" void* __cdecl castObject(void*, long, void*, void*, int);

struct Control
{
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Shared
{
    void* object;
    Control* control;
    ~Shared();
};

inline Shared::~Shared()
{
    Control* p = control;
    if (p)
    {
        if (_InterlockedDecrement(&p->strong) == 0)
        {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

struct Player
{
    char padding[0x1c8];
    short x;
    short y;
    short z;
    short w;
};

struct Vector
{
    float x;
    float y;
    float z;
    float w;
    Vector(double, double, double, double);
};

inline Vector::Vector(double a, double b, double c, double d)
    : x(static_cast<float>(a)),
      y(static_cast<float>(b)),
      z(static_cast<float>(c)),
      w(static_cast<float>(d))
{
}

struct Output
{
    void set(const Vector&);
};

void __stdcall func_004974f0(Shared value, Output* output)
{
    Player* player = static_cast<Player*>(
        castObject(value.object, 0, &instanceType, &playerType, 0));

    if (player)
    {
        Vector vector(player->x, player->y, player->z, player->w);
        output->set(vector);
    }
}
