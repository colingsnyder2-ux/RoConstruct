// from server: 100% by king_originala
struct Ball {
    char padding[0xB8];
    int values[1];
    void set(int index, int value);
};

struct Descriptor {
    void* get();
};

struct Part {
    char padding[0x228];
    Ball ball;
    void setShouldRender(int index);
    int* f(int index);
    void notify(void* value);
};

struct S {
    Part* part;
    int index;
    void set(int value);
};

void S::set(int value)
{
    if (value != part->ball.values[index]) {
        part->ball.set(index, value);
        part->setShouldRender(index);
        part->notify(reinterpret_cast<Descriptor*>(part->f(index))->get());
    }
}
