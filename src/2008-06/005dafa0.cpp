// from server: 100% by king_originala
extern "C" void* __stdcall makeDescriptor(const char*, int);

struct Base {
    virtual ~Base();
    char storage[0x34];
    Base(void*);
};

struct Value {
    void* type;
    int data;
    Value();
    ~Value();
};

struct Member {
    int a;
    int b;
    int c;
};

struct S : Base {
    Member member;
    Value value0;
    Value value1;

    S(Member, const char*, void*, void*, int);
    virtual ~S();
    void initialize(void*, void*);
};

S::S(Member m, const char* name, void* first, void* second, int flags)
    : Base(makeDescriptor(name, flags)),
      member(m), value0(), value1()
{
    initialize(first, second);
}
