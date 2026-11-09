// from server: 100% by atomic.potato
struct Point
{
    float x;
    float y;
};

extern "C" Point *GetPoint();

struct DxUserInput
{
    void f();
    float pad0[41];
    float x;
    float y;
};

void DxUserInput::f()
{
    Point *p = GetPoint();
    x = p->x;
    y = p->y;
}
