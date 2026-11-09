// from server: 92% by colin
// from server: 82% by king_originala
#pragma optimize("", off)

struct Reference {
    void update(void* p, int flag);
};

struct S {
    unsigned char reserved[12];
    Reference reference;

    void __cdecl f(void* p);
};

void S::f(void* p)
{
    void* saved = p;
    try {
        reference.update(saved, 0);
    }
    catch (...) {
        reference.update(saved, 1);
        throw;
    }
}
