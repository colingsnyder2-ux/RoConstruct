// from server: 43% by atomic.potato
struct Vector2
{
    float x;
    float y;
};

void AddVector2(Vector2* a, Vector2* b)
{
    a->x += b->x;
    a->y += b->y;
}
