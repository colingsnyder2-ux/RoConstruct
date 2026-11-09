// from server: 100% by atomic.potato





struct S {
    int f0;
    int f4;
    int pad0[4];
    int f18;
    int f1c;
    int pad1[29];
    int f94;
    int f98;
    void init();
};

void __fastcall S_tail(S*);

void S::init() {
    f0 = 0xa4677c;
    f4 = 0xa46774;
    f18 = 0xa46768;
    f1c = 0xa4675c;
    f94 = 0xa4674c;
    f98 = 0xa46734;
    S_tail(this);
}
