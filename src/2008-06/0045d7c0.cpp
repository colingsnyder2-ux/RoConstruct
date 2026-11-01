// from server: 100% by king_originala
extern "C" void __cdecl prepare();

struct Table {
    char padding[0x5c];
    int mode;

    void update(void* data, int width, int height);
    void updateMode2(void* data, int width, int height);
    void updateOther(void* data, int width, int height);
};

void Table::update(void* data, int width, int height)
{
    if (width <= 0)
        return;
    if (height <= 0)
        return;
    if (width > 8192)
        return;
    if (height > 8192)
        return;

    prepare();

    if (mode == 2)
        updateMode2(data, width, height);
    else
        updateOther(data, width, height);
}
