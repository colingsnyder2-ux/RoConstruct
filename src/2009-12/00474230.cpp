// from server: 71% by atomic.potato
struct Vec2 { float x; float y; };

extern "C" Vec2* __cdecl sub_5EBC60();

void __cdecl sub_474230(Vec2* a, Vec2* b, Vec2* c)
{
    Vec2* g = sub_5EBC60();
    b->x = g->x;
    b->y = g->y;
    c->x += a->x;
    c->y += a->y;
}
