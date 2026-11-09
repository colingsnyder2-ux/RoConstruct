// from server: 100% by colin
// Analog for 00553340: builds the result from a wrapped value (ctor 005534a0)
// and a flag accessor (005c72e0); result ctor 00553480 takes both.
struct Flag {
    void* f(int);
};

struct Temporary {
    int value;
    Temporary(int);
};

struct S {
    int value;
    S(int, void*);
};

#pragma optimize("gy", off)
S reconstruct(int value, unsigned char flag)
{
    Flag flagObject;
    return S(Temporary(value).value, flagObject.f(flag));
}
