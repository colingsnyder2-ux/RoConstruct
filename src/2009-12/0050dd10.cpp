// from server: 47% by atomic.potato
extern "C" void __stdcall sub_98B6F0();
extern "C" void __stdcall sub_98B6E4();
extern "C" void __stdcall sub_50CEA0(void*);

struct String {
    void* pad[4];
    String();
    String(const String&);
    ~String();
};

struct Player {
    void func(int, int, int, int, int, int, int);
};

void Player::func(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    String s;
    sub_98B6F0();
    sub_50CEA0(this);
    sub_98B6E4();
}
