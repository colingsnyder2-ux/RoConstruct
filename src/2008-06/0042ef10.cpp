// from server: 100% by king_originala
struct Message {
    char padding[0x18];
    unsigned int flags;
};

struct CMainFrame {
    char padding[0xF8];
    unsigned char enabled;
    unsigned char reserved;
    unsigned char blocked;

    void helper();
    void f(Message* message);
};

void CMainFrame::f(Message* message)
{
    helper();
    if (enabled && !blocked)
        message->flags |= 3;
}
