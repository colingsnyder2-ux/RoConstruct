// from server: 100% by king_originala
struct ChatEnter {
    volatile unsigned long table;
    unsigned char padding[0x84];
    volatile unsigned long field88;
    volatile unsigned long field8c;
    volatile unsigned long field90;
    volatile unsigned long table94;
    volatile unsigned long field98;
    volatile unsigned long field9c;
    volatile unsigned long fielda0;
    volatile unsigned long fielda4;

    void initializeBase();
    ChatEnter* initialize();
};

ChatEnter* ChatEnter::initialize()
{
    initializeBase();
    field88 = 0;
    table = 0x80e1ac;
    field8c = 0;
    field90 = 0;
    field98 = 0;
    table94 = 0x80e068;
    field9c = 0;
    fielda0 = 0;
    fielda4 = 0;
    return this;
}
