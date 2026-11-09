// from server: 100% by king_originala
struct Listener
{
    void invoke(const int& value);
};

struct Writer
{
    char padding[32];
    Listener listener;
    void write(int value);
};

void Writer::write(int value)
{
    int copy = value;
    listener.invoke(copy);
}
