// from server: 100% by king_originala
extern "C" void __cdecl release(void *);

struct S {
    char padding0[0x24];
    void *allocation;
    char padding1[8];
    void *begin;
    void *end;
    void *capacity;

    void cleanup();
    void finish();
};

void S::cleanup()
{
    if (begin)
        release(begin);

    begin = 0;
    end = 0;
    capacity = 0;

    release(allocation);
    finish();
}
