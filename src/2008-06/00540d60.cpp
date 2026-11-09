// from server: 100% by king_originala
struct VChunk { char pad[8]; };

struct S {
    char pad[0x18];
    VChunk* chunk;
    int count;

    VChunk** slot();
    void release(VChunk*);
    VChunk** otherSlot();
    char* get();
    void reset();
};

#pragma optimize("", off)
void S::reset()
{
    release(*slot());
    *slot() = chunk;
    count = 0;
    *otherSlot() = chunk;
    *(VChunk**)get() = chunk;
}
