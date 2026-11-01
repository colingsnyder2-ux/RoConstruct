// from server: 100% by king_originala
struct Result {
    void finish();
};

struct Component {
    virtual void unused();
    virtual Result* get();
};

struct Workspace {
    char padding0[0x288];
    Component component;
    char padding1[0x144];
    unsigned char flag;

    void reset();
};

void Workspace::reset()
{
    flag = 0;
    component.get()->finish();
}
