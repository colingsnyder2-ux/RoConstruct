// from server: 76% by atomic.potato
extern "C" void initialize_004151e0(void*);
extern "C" void render_007fddb0(void*, void*, void*, double);

struct ViewUpdateJob_0046b260 {
    void* update(void*, void*);
};

double g_00a6f1b8;

void* ViewUpdateJob_0046b260::update(void* a, void* b)
{
    initialize_004151e0(this);
    render_007fddb0(this, b, a, g_00a6f1b8);
    return b;
}
