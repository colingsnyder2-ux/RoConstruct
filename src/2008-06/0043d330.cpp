// from server: 100% by king_originala
struct Primary {
    virtual ~Primary();
    char storage[0x1C];
};

struct Secondary {
    virtual ~Secondary();
    char storage[0xFC];
};

struct Tertiary {
    virtual ~Tertiary();
};

struct Base : Primary, Secondary, Tertiary {
    Base(int, int);
    virtual ~Base();
    void SetCheckBoxStyle(int);
};

struct S : Base {
    S(int, int);
    virtual ~S();
};

S::S(int a, int b) : Base(a, b) {
    SetCheckBoxStyle(1);
}
