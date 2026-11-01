// from server: 100% by king_originala
struct Element {
    char data[24];
};

struct S {
    Element* data;
    int count;
    Element* f();
};

#pragma optimize("", off)
Element* S::f()
{
    do {} while (0);
    do {} while (0);
    return data + (count - 1);
}
#pragma optimize("", on)
