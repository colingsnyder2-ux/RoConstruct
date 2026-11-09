// from server: 100% by king_originala
struct Event {
    int type;
    int reserved;
    int key;
};

struct KeyButton {
    char pad[0x18];
    int key;
    bool pressed;

    void* sub_642210(void* result, Event* event);
    void* sub_64EF90(void* result, Event* event);
};

void* KeyButton::sub_64EF90(void* result, Event* event) {
    if (event->type == 10 && event->key == key)
        pressed = true;

    if (event->type == 11 && event->key == key)
        pressed = false;

    sub_642210(result, event);
    return result;
}
