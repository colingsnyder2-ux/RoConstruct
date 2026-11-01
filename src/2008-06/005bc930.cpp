// from server: 100% by king_originala
struct EventHandler {
    void* table;
    unsigned int f();
};

struct LaserTool {
    char storage[0x158];
    EventHandler handler;
    void setValue(const unsigned int* value);
    void update();
};

void LaserTool::update()
{
    unsigned int value = handler.f();
    setValue(&value);
}
