// from server: 100% by king_originala
struct Base {
    char storage[0x58];
    ~Base();
};

struct Member {
    ~Member();
};

void __cdecl operator delete(void *);

struct S : Base {
    Member member;
    S *destroy(unsigned int flags);
};

S *S::destroy(unsigned int flags)
{
    this->S::~S();
    if (flags & 1)
        operator delete(this);
    return this;
}
