// from server: 43% by atomic.potato
struct DxUserInput {
    float x;
    float y;
};

void f(float* a, DxUserInput* b)
{
    a[0] += b->x;
    a[1] += b->y;
}
