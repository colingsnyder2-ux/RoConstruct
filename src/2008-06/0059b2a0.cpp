// from server: 100% by king_originala
struct Value {
    float x, y, z;
};

struct Reader {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual Value get(void* object) = 0;
};

struct S {
    char padding[24];
    Reader* reader;
    int equal(void* a, void* b);
};

#pragma float_control(precise, off, push)

int S::equal(void* a, void* b)
{
    Value first = reader->get(b);
    Value second = reader->get(a);
    return second.x == first.x &&
           second.y == first.y &&
           second.z == first.z;
}

#pragma float_control(pop)
