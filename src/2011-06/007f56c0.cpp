// from server: 64% by atomic.potato
struct ContactStage
{
    int field08;
    void f(int);
};

extern "C" void call_007b4ad0(int, int);
extern "C" void call_007a1d00(int, int);

void ContactStage::f(int value)
{
    call_007b4ad0(field08, value);
    call_007a1d00(value, (int)this);
}
