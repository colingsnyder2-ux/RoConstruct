// from server: 100% by king_originala
struct Object {
    void release();
};

struct S {
    Object* first();
    Object* second();
    Object* third();
    Object* fourth();
    Object* fifth();
};

void __stdcall f(S* s)
{
    Object* p = s->first();
    if (p)
        p->release();

    p = s->second();
    if (p)
        p->release();

    p = s->third();
    if (p)
        p->release();

    p = s->fourth();
    if (p)
        p->release();

    p = s->fifth();
    if (p)
        p->release();
}
