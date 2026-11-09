// from server: 100% by atomic.potato
extern "C" void __cdecl sub_007f385a(int);

struct PhysicsSender_Job
{
    char pad[16];
    int unk10;
    int unk14;
    void f();
};

void PhysicsSender_Job::f()
{
    if (unk10 != 0)
        sub_007f385a(unk14);
}
