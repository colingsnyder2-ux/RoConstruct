// from server: 100% by king_originala
struct Source {
    int first();
    int second();
};

struct ScoreHud {
    char padding[0x14c];
    int firstValue;
    int secondValue;

    void update(int unused, Source* source);
};

void ScoreHud::update(int unused, Source* source)
{
    firstValue = source ? source->first() : 0;
    secondValue = source ? source->second() : 0;
}
