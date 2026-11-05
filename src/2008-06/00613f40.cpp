// from server: 100% by king_originala
extern int counter;

struct S {
    char padding[0x90];
    int id;
    void assignId();
};

void S::assignId()
{
    int value = ++counter;
    if (value == 0x7fffffff)
        counter = value = 1;
    id = value;
}
