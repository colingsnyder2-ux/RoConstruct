// from server: 100% by king_originala
#pragma optimize("", off)

struct VChunk;

struct S {
    char pad[0x18];
    VChunk* pointer;
    unsigned int state;

    char* getPointer();
    void release(VChunk*);
    char* getLink();
    char* get();
    void reset();
};

void S::reset()
{
    release(*reinterpret_cast<VChunk**>(getPointer()));
    *reinterpret_cast<VChunk**>(getPointer()) = pointer;
    state = 0;
    *reinterpret_cast<VChunk**>(getLink()) = pointer;
    *reinterpret_cast<VChunk**>(get()) = pointer;
}
