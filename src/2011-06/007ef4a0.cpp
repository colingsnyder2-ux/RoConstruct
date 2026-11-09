// from server: 83% by atomic.potato
struct S
{
    int value;
    char data[16];
    int state;
    S();
};

void func_0063f850(void *);

S::S()
{
    value = 0x00ABF0B8;
    func_0063f850((char *)this + 4);
    state = 0;
}
