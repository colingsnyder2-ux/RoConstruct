// from server: 100% by king_originala
struct Vec2 {
    float x;
    float y;
};

extern const Vec2& __cdecl zeroVector();

void __cdecl func_004692f0(const Vec2* input, Vec2* first, Vec2* second)
{
    const Vec2& zero = zeroVector();
    first->x = zero.x;
    first->y = zero.y;
    second->x = input->x + second->x;
    second->y = input->y + second->y;
}
