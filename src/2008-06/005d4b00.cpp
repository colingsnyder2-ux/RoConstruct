// from server: 100% by king_originala
struct Item {
    void update();
};

struct S {
    Item* first();
    Item* second();
    Item* third();
    Item* fourth();
    Item* fifth();
    void update();
};

void S::update()
{
    Item* p = first();
    if (p)
        p->update();

    p = second();
    if (p)
        p->update();

    p = third();
    if (p)
        p->update();

    p = fourth();
    if (p)
        p->update();

    p = fifth();
    if (p)
        p->update();
}
