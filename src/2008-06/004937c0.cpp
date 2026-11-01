// from server: 100% by tester
struct Sec { void enter(); };
Sec* __stdcall getSec(int, const char*);
struct Base { void setName(const void* n); };
struct Player : Base {
    void setName(const void* n);
};
void Player::setName(const void* n) {
    getSec(3, "set a Player's name")->enter();
    Base::setName(n);
}
