// from server: 100% by king_originala
struct Reader {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual float get(void* object) = 0;
};

struct S {
    unsigned char padding[24];
    Reader* reader;
    bool equal(void* first, void* second);
};

#pragma float_control(precise, off, push)
bool S::equal(void* first, void* second)
{
    float value = reader->get(first);
    return reader->get(second) == value;
}
#pragma float_control(pop)
