// from server: 53% by atomic.potato
extern "C" void __cdecl sub_00655480(const char *, void *, int);

struct InstanceLocksmith
{
    int f();
};

int InstanceLocksmith::f()
{
    int value = 0;
    sub_00655480("D$ VP", this, value);
    return (int)this;
}
