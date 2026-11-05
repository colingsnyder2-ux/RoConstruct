// from server: 100% by king_originala
void __cdecl operator delete(void *);

struct Primary {
    virtual ~Primary();
};

struct Secondary {
    virtual ~Secondary();
};

struct Base : Primary, Secondary {
    unsigned int reserved[5];
    virtual ~Base();
};

struct Owned {
    ~Owned();
};

struct S : Base {
    Owned *owned;
    virtual ~S();
};

S::~S()
{
    delete owned;
}
