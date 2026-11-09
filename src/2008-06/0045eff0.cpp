// from server: 100% by king_originala
struct EventHandler
{
    int get();
};

struct StatsItem
{
    char storage[0x158];
    EventHandler handler;

    void update(const int* value);
    void f();
};

void StatsItem::f()
{
    int value = handler.get();
    update(&value);
}
