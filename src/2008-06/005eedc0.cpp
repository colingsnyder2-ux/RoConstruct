// from server: 100% by EspClaude
// roc-lang: cpp
struct Surface {
    void* part;
    int id;
    void g(int a, int b);
};

struct Surfaces {
    Surface Top, Bottom, Left, Right, Front, Back;
    Surface& operator[](int id)
    {
        switch (id) {
        case 4: return Bottom;
        case 2: return Back;
        case 5: return Front;
        case 0: return Right;
        case 3: return Left;
        default: return Top;
        }
    }
};

struct S_func_00598de0 {
    char pad0[500];
    int m_x;
    Surfaces& f();
};

void __stdcall target(char* p, int a, int b)
{
    S_func_00598de0* object =
        p ? reinterpret_cast<S_func_00598de0*>(p - 20) : 0;
    Surfaces& surfaces = object->f();
    surfaces[3].g(a, b);
}
