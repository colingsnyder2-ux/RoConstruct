// from server: 68% by atomic.potato
struct S
{
    void f();
    char data[0x194];
};

extern "C" void sub_664370(void*);

void S::f()
{
    sub_664370(data + 0x188);
    sub_664370(data + 0x190);
}
