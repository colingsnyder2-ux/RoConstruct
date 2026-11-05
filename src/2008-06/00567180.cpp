// from server: 100% by king_originala
struct Listener {
    void invoke(void** value);
};

struct Selection {
    char padding[0x15c];
    Listener listener;

    void notify(void* value);
};

void Selection::notify(void* value)
{
    listener.invoke(&value);
}
