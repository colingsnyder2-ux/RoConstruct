// from server: 100% by king_originala
struct Object {
    void set(int);
};

struct CRobloxWnd {
    char padding[0x84];
    Object* object;

    void start();
    void finish();
    void f(int);
};

void CRobloxWnd::f(int)
{
    if (object)
        object->set(0);
    start();
    finish();
}
