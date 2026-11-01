// from server: 100% by king_originala
struct S {
    unsigned long data[0x190 / 4];

    void initialize(void *, void *, void *);
    S(void *, void *, void *, void *, void *);
};

S::S(void *a, void *b, void *c, void *d, void *e)
{
    initialize(a, b, c);
    data[0x188 / 4] = (unsigned long)e;
    data[0x000 / 4] = 0x0084bffc;
    data[0x010 / 4] = 0x0084bfec;
    data[0x014 / 4] = 0x0084bfe4;
    data[0x020 / 4] = 0x0084bfdc;
    data[0x024 / 4] = 0x0084bfcc;
    data[0x044 / 4] = 0x0084bfbc;
    data[0x064 / 4] = 0x0084bfac;
    data[0x084 / 4] = 0x0084bf9c;
    data[0x0a4 / 4] = 0x0084bf8c;
    data[0x0c4 / 4] = 0x0084bf7c;
    data[0x130 / 4] = 0x0084bf74;
    data[0x18c / 4] = (unsigned long)d;
}
