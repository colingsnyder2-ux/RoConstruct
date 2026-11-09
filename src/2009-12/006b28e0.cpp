// from server: 46% by atomic.potato
struct DropperTool
{
    float x;
    unsigned short y;
    void f(void *, const DropperTool *);
};

void DropperTool::f(void *out, const DropperTool *value)
{
    struct Result
    {
        float x;
        unsigned short y;
    };

    Result *r = (Result *)out;
    r->x = value->x + x;
    r->y = (unsigned short)(value->y + y);
}
