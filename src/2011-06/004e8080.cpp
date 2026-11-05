// from server: 76% by atomic.potato
struct PhysicsSenderJob
{
    char padding[0x1f0];
    float field_1f0;
    void *Function_004e8080(void *arg1, void *arg2);
};

extern "C" void *__cdecl Function_007fddb0(double, void *, void *);

void *PhysicsSenderJob::Function_004e8080(void *arg1, void *arg2)
{
    double value = field_1f0;
    Function_007fddb0(value, arg2, arg1);
    return arg2;
}
