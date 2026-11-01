// from server: 100% by king_originala
struct Chunk;

struct ChunkVTable {
    void *unused[10];
    void (__thiscall *initialize)(Chunk *);
};

struct StrongPointer {
    void *value;
    void assign(void *);
};

struct Chunk {
    ChunkVTable *vtable;
    unsigned char padding[200];
    void *cached;
    StrongPointer get();
};

StrongPointer Chunk::get()
{
    volatile int temporary = 0;
    if (cached == 0)
        vtable->initialize(this);

    StrongPointer result;
    result.value = 0;
    result.assign(cached);
    return result;
}
