// from server: 71% by atomic.potato
struct Vec2 { float x; float y; };

extern "C" Vec2* __cdecl sub_53b3a0();

void __cdecl sub_497dc0(Vec2* a, Vec2* b, Vec2* c)
{
    Vec2* v = sub_53b3a0();
    b->x = v->x;
    b->y = v->y;
    c->x += a->x;
    c->y += a->y;
}
