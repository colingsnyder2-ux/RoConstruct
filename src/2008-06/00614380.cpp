// from server: 100% by king_originala
struct Link;

struct Attachment {
    char reserved[4];
    Link* owner;
};

struct State {
    char reserved[0x90];
    int stamp;
};

extern int counter;

struct Link {
    char reserved0[0x10];
    State* state;
    Link* parent;
    char reserved1[0x10];
    char* flag28;
    char* flag2c;
    char reserved2[4];
    Attachment* attachment;

    __declspec(noinline) void reset();
    void f(Attachment*);
};

void Link::reset()
{
    if (flag28 && flag28[4])
        return;

    if (parent)
        parent->reset();
    else if (flag2c)
        flag2c[8] = 1;

    if (flag28)
        flag28[4] = 1;
}

void Link::f(Attachment* value)
{
    if (attachment && attachment != value)
        attachment->owner = 0;

    if (parent) {
        attachment = value;
        value->owner = this;

        if (!flag28 || !flag28[4]) {
            if (parent)
                parent->reset();
            else if (flag2c)
                flag2c[8] = 1;

            if (flag28)
                flag28[4] = 1;
        }

        State* destination = state;
        int stamp = ++counter;
        if (stamp == 0x7fffffff)
            counter = stamp = 1;
        destination->stamp = stamp;
    }
}
