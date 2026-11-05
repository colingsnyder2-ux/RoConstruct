// from server: 74% by atomic.potato
typedef float float32;

struct ServiceProvider
{
    void f();
};

extern float g_9cf454;
extern float g_9cf450;

void ServiceProvider::f()
{
    volatile float32* a0 = (volatile float32*)((char*)this + 0xa0);
    volatile float32* a4 = (volatile float32*)((char*)this + 0xa4);
    *a0 = g_9cf454;
    *a4 = g_9cf450;
    *(int*)((char*)this + 0xa8) = 0;
}
