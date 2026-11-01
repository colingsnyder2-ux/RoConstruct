// from server: 100% by king_originala
#pragma optimize("", off)

struct VChunk {
    char pad[8];
};

struct Pair {
    void* first;
    void* second;
};

struct Releaser {
    char pad[4];
    void release(VChunk*, int);
};

struct Collector {
    char pad[8];
    void append(char*);
};

extern char* __cdecl firstPart(VChunk*);
extern char* __cdecl secondPart(VChunk*);
extern char* __cdecl thirdPart(VChunk*);

struct S {
    char pad[12];
    Releaser releaser;
    Collector collector;
    VChunk* chunk;
    void* other;

    Pair* first(Pair*);
    Pair* second(Pair*);
    Pair combine(Pair, Pair);
    void f();
};

void S::f()
{
    Pair a;
    Pair firstTemporary;
    Pair b;
    Pair secondTemporary;
    a = *first(&secondTemporary);
    b = *second(&firstTemporary);
    combine(b, a);
    collector.append(firstPart(chunk));
    collector.append(secondPart(chunk));
    collector.append(thirdPart(chunk));
    releaser.release(chunk, 1);
    chunk = 0;
    other = 0;
}
