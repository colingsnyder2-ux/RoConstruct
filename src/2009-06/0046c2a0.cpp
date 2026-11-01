// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Vec2 {
    float x;
    float y;
};

extern const float scale;
extern void __cdecl helper(Vec2 *, Vec2 *, Vec2 *, void *, int, float);

void __cdecl update(Vec2 *a, Vec2 *b, Vec2 *c, void *context)
{
    float y = a->y + c->y;
    helper(a, b, c, context, 20, scale);
    b->y = 0.0f;
    c->y = y;
}