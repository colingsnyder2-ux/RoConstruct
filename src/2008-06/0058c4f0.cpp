// from server: 100% by king_originala
struct Container {
    char storage[20];
    void clear();
};

struct S {
    char padding0[0x130];
    int value;
    char padding1[0x34];
    Container first;
    Container second;
    Container third;

    void reset();
    void update(int clearState, int newValue);
};

void S::update(int clearState, int newValue)
{
    if (clearState) {
        reset();
        first.clear();
        second.clear();
        third.clear();
        value = 0;
    }
    if (newValue)
        value = newValue;
}
