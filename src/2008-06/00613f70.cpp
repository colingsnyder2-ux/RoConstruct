// from server: 100% by colin
struct Link {
    char reserved0[0x14];
    Link* parent;
    char reserved1[0x10];
    char* flag28;
    char* flag2c;

    void reset();
};

void Link::reset()
{
    if (flag28 && flag28[4])
        return;

    if (parent) {
        parent->reset();
    } else if (flag2c) {
        flag2c[8] = 1;
    }

    if (flag28)
        flag28[4] = 1;
}
