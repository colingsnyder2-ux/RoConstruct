// from server: 100% by king_originala
void __cdecl operator delete(void*) throw();

struct Base
{
    char storage[0x130];
    ~Base();
};

struct Head
{
    void* pointer;
    ~Head();
};

struct Container
{
    Head head;
    char storage[0x1c];

    void clear();
    ~Container();
};

struct S : Base
{
    Container container;
    ~S();
};

__forceinline Head::~Head()
{
    delete static_cast<char*>(pointer);
}

__forceinline Container::~Container()
{
    clear();
}

S::~S()
{
}
