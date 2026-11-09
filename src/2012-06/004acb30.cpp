// from server: 43% by atomic.potato
struct DxUserInput
{
    float x;
    float y;
};

void AddInput(DxUserInput* a, DxUserInput* b)
{
    a->x += b->x;
    a->y += b->y;
}
