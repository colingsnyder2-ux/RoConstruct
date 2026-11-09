// from server: 100% by atomic.potato
struct Vec3 { int x; int y; int z; };

extern "C" Vec3* __cdecl sub_0062e740();

struct GuiObject
{
    int a0;
    int a1;
    int a2;
    int a3;
    int a4;
    int a5;
    GuiObject* assign(const Vec3* v);
};

GuiObject* GuiObject::assign(const Vec3* v)
{
    a0 = v->x;
    a1 = v->y;
    a2 = v->z;
    Vec3* r = sub_0062e740();
    a3 = r->x;
    a4 = r->y;
    a5 = r->z;
    return this;
}
