// from server: 100% by king_originala
struct PartChunk {
    void* value;
    PartChunk(void* source);
    ~PartChunk();
};

struct Bucket {
    unsigned char padding[4];
    void* value;
    PartChunk f();
};

#pragma optimize("", off)
PartChunk Bucket::f()
{
    return PartChunk(value);
}
#pragma optimize("", on)
