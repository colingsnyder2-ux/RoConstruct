// from server: 61% by atomic.potato
struct EdgeStage
{
    int pad0;
    int pad4;
    int field8;
    void *f(unsigned int);
};

extern "C" void sub_917430(void *, EdgeStage *);
extern "C" void sub_96bbc0(int, unsigned int);

void *EdgeStage::f(unsigned int value)
{
    sub_917430((void *)value, this);
    sub_96bbc0(field8, value);
    return this;
}
