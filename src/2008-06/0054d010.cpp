// from server: 100% by king_originala
#pragma optimize("", off)

struct Result {
    unsigned int first;
    unsigned int second;
};

struct VChunk {
    char padding[8];
};

extern void* __cdecl firstPointer(void* value);
extern void* __cdecl secondPointer(void* value);
extern char* __cdecl chunkPointer(VChunk* value);

struct Releaser {
    unsigned int storage;
    void __thiscall release(VChunk* value, int flag);
};

struct Sink {
    unsigned int storage[2];
    void __thiscall accept(void* value);
};

struct Mesh {
    char padding[12];
    Releaser releaser;
    Sink sink;
    VChunk* value;
    unsigned int count;

    Result* __thiscall firstResult(Result* result);
    Result* __thiscall secondResult(Result* result);
    Result* __thiscall combine(Result* result, Result second, Result first);
    void finish();
};

void Mesh::finish()
{
    struct Locals {
        Result combined;
        Result secondTemporary;
        Result second;
        Result firstTemporary;
        Result first;
    } locals;

    locals.first = *firstResult(&locals.firstTemporary);
    locals.second = *secondResult(&locals.secondTemporary);
    combine(&locals.combined, locals.second, locals.first);

    sink.accept(firstPointer(value));
    sink.accept(secondPointer(value));
    sink.accept(chunkPointer(value));
    releaser.release(value, 1);

    value = 0;
    count = 0;
}
