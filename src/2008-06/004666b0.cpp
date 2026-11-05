// from server: 100% by king_originala
struct Argument
{
    unsigned char storage[16];
    ~Argument();
};

struct Owner
{
    void g();
};

struct CSelectionCaption
{
    void f(int, Argument);
};

void CSelectionCaption::f(int, Argument)
{
    reinterpret_cast<Owner*>(
        reinterpret_cast<char*>(this) - 0x194)->g();
}
