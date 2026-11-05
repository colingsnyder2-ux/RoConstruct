// from server: 100% by king_originala
struct Pair {
    int first;
    int second;
};

struct Event {
    char reserved0[0x0c];
    int enabled;
    Pair primary;
    char reserved1[0x20];
    Pair secondary;
};

struct CRobloxTreeCtrl {
    char reserved0[0xb8];
    unsigned char flagB8;
    char reserved1[0x28];
    unsigned char flagE1;
    char reserved2[0x42];
    int active;

    void process(Pair* value, int mode);
    void handle(Event* event, int* result);
};

void CRobloxTreeCtrl::handle(Event* event, int* result)
{
    *result = 0;
    if (!flagE1 && !flagB8 && active) {
        if (event->secondary.second)
            process(&event->secondary, 1);
        if (event->primary.second && event->enabled)
            process(&event->primary, 0);
    }
}
