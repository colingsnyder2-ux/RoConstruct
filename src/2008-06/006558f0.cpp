// from server: 100% by king_originala
extern "C" void __cdecl release(void *);

struct Owner {
    void *pointer;
    ~Owner();
};

struct Container {
    Owner owner;
    char storage[20];
    void tidy();
    ~Container();
};

struct MemberA {
    char storage[32];
    ~MemberA();
};

struct MemberB {
    char storage[32];
    ~MemberB();
};

struct MemberC {
    char storage[32];
    ~MemberC();
};

struct ScoreHud {
    Container container;
    MemberA a;
    MemberB b;
    MemberC c;
    ~ScoreHud();
};

inline Owner::~Owner()
{
    release(pointer);
}

inline Container::~Container()
{
    tidy();
}

ScoreHud::~ScoreHud()
{
}
