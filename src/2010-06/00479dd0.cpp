// from server: 67% by atomic.potato
struct Vec2 {
    float x;
    float y;
};

extern "C" Vec2* __cdecl get_zero_vec();

void add_vec2(Vec2* a, Vec2* b, Vec2* out)
{
    Vec2* z = get_zero_vec();
    out->x = z->x;
    out->y = z->y;
    b->x += a->x;
    b->y += a->y;
}
