// from server: 100% by king_originala
extern void (__thiscall *destroyString)(void *);

struct String {
    char storage[0x20];
    ~String() { destroyString(this); }
};

struct Base {
    char storage[0x140];
    ~Base();
};

struct S : Base {
    String first;
    String second;
    ~S();
};

S::~S()
{
}
