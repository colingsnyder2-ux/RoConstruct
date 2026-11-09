// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Check {
    void verify();
};
extern "C" Check* __stdcall getCheck(int, const char*);
struct Desc;
extern Desc desc_userId;

struct Player {
    char padding[0xc8];
    int userId;
    void raisePropertyChanged(const Desc&);
    void setUserId(int value);
};

void Player::setUserId(int value)
{
    if (value != userId) {
        getCheck(3, "set a Player's ID")->verify();
        userId = value;
        raisePropertyChanged(desc_userId);
    }
}
