// from server: 100% by colin
// roc 2007-08 00465360  unit: DxUserInput  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00465360

struct Vec2 { float x; float y; };

extern "C" Vec2* __cdecl sub_501570();

void __cdecl sub_465360(Vec2* a, Vec2* b, Vec2* c)
{
    Vec2* src = sub_501570();
    b->x = src->x;
    b->y = src->y;
    c->x += a->x;
    c->y += a->y;
}
