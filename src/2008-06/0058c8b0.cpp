// from server: 100% by king_originala
struct Check {
    void verify();
};

extern char enabledName[];
extern "C" Check* __stdcall getCheck(int, const char*);

struct State {
    char storage[20];
    void clear();
};

struct S {
    char padding[0x165];
    bool enabled;
    char alignment[2];
    State first;
    State second;
    State third;

    void start();
    void stop();
    void setEnabled(bool value);
};

void S::setEnabled(bool value)
{
    getCheck(1, enabledName)->verify();

    if (value != enabled) {
        enabled = value;
        if (value) {
            start();
        } else {
            stop();
            first.clear();
            second.clear();
            third.clear();
        }
    }
}
