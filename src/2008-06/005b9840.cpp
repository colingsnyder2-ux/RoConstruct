// from server: 100% by king_originala
extern "C" int __stdcall releaseHandle(void *, int);
extern "C" void __cdecl checkResult(int);

struct Referent {
    unsigned char padding[8];
    int references;
};

struct Reference {
    Referent *object;
    void *control;
    void reset();
};

struct S {
    unsigned char padding[0x134];
    Reference reference;
    void *handle;

    void release(int, int);
};

void S::release(int, int)
{
    if (handle) {
        checkResult(releaseHandle(handle, 0));
        handle = 0;
    }

    if (reference.object) {
        --reference.object->references;
        reference.reset();
    }
}
