// from server: 100% by atomic.potato
extern "C" void __cdecl sub_006a067a(int);

struct PhysicsSender
{
    int value;
    int reserved0;
    int reserved1;
    unsigned int count;

    void f();
};

void PhysicsSender::f()
{
    if (count > 0)
        sub_006a067a(value);
}
