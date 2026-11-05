// from server: 100% by atomic.potato
extern "C" void __cdecl sub_007adce0();
extern "C" void __cdecl sub_0080a058(void *);

struct ManualGlueJoint {
    int value;
    char padding[24];
    int other;
    ManualGlueJoint *f(int);
};

ManualGlueJoint *ManualGlueJoint::f(int flag)
{
    value = 0xAA5F4C;
    other = 0xAA5F2C;
    sub_007adce0();
    if (flag & 1)
        sub_0080a058(this);
    return this;
}
