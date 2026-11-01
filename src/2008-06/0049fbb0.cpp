// from server: 100% by king_originala
struct Object {
    virtual ~Object();
};

struct Owner {
    unsigned long reserved;
    Object* pointer;
    ~Owner();
};

inline Owner::~Owner()
{
    if (pointer)
        delete pointer;
}

struct Base {
    virtual ~Base();
    unsigned char reserved[20];
};

inline Base::~Base()
{
}

struct Member {
    unsigned char reserved[40];
    ~Member();
};

struct __declspec(novtable) Middle : Base {
    Member member;
    ~Middle();
};

inline Middle::~Middle()
{
}

struct __declspec(novtable) S : Middle {
    Owner first;
    Owner second;
    Owner third;
    Owner fourth;
    ~S();
};

S::~S()
{
}
