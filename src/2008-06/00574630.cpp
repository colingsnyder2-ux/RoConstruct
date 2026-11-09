// from server: 100% by tester
typedef void (__thiscall *StringDestructor)(void *);
typedef void (__cdecl *FreeFunction)(void *);

extern StringDestructor destroyString;
extern FreeFunction releaseMemory;

struct StringStorage
{
    char storage[28];
    ~StringStorage();
};

inline StringStorage::~StringStorage()
{
    destroyString(this);
}

struct Base
{
    char storage[0x144];
    ~Base();
};

struct S : Base
{
    StringStorage text;
    __declspec(noinline) ~S();
    void *destroy(unsigned int flags);
};

S::~S()
{
}

void *S::destroy(unsigned int flags)
{
    this->~S();
    if (flags & 1)
        releaseMemory(this);
    return this;
}
