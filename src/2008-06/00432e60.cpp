// from server: 100% by king_originala
struct Rect
{
    int left, top, right, bottom;
};

struct Pane;

struct PaneTable
{
    void* unused[23];
    int (__thiscall *create)(Pane*, const char*, const char*,
                            unsigned long, const Rect*, void*,
                            unsigned int, void*);
};

struct Pane
{
    PaneTable* table;
    char padding[28];
    void* window;

    void configure(void*, void*);
};

struct Manager
{
    Pane* getPane();
};

extern char* func_00411360();

extern "C" long (__stdcall *SendMessageA)(
    void*, unsigned int, unsigned int, long);

struct CMultiPlayerPane
{
    char padding[84];
    Pane* pane;

    int create(const char*, const char*, unsigned long,
               const Rect*, void*, unsigned int, void*);
    int initialize(void*, void*);
};

int CMultiPlayerPane::initialize(void* parent, void* context)
{
    Rect rect = { 0, 0, 0, 0 };

    if (!create(0, 0, 0x50000000, &rect, parent, 1002, 0))
        return 0;

    pane = reinterpret_cast<Manager*>(func_00411360())->getPane();

    rect.left = 0;
    rect.top = 0;
    rect.right = 0;
    rect.bottom = 0;

    if (!pane->table->create(pane, 0, 0, 0x50000000,
                             &rect, this, 1003, 0))
        return 0;

    pane->configure(context, parent);
    SendMessageA(pane->window, 0x364, 0, 0);
    return 1;
}
