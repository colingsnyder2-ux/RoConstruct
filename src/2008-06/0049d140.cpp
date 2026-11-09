// from server: 100% by king_originala
extern "C" void __cdecl releaseMemory(void *);

struct Pointer {
    void *value;
    __forceinline ~Pointer();
};

struct Base {
    Pointer pointer;
    char padding[28];
    void cleanup();
    __forceinline ~Base();
};

struct Member {
    void *object;
    bool criticalSection;
    ~Member();
};

struct S : Base {
    Member member;
    ~S();
};

__forceinline Pointer::~Pointer()
{
    releaseMemory(value);
}

__forceinline Base::~Base()
{
    cleanup();
}

S::~S()
{
}
