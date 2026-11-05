// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD /fp:fast
extern "C" void (__cdecl *_invalid_parameter_noinfo)();

struct Node {
    char pad[72];
    Node* next;
};

struct Container {
    char pad[16];
    Node** end;
};

struct Iterator {
    Container** owner;
    Node** current;

    bool operator!=(const Iterator& other) const;
    Iterator operator++(int);
    Node* operator*() const;
};

inline bool Iterator::operator!=(const Iterator& other) const
{
    if (!owner || owner != other.owner)
        _invalid_parameter_noinfo();
    return current != other.current;
}

inline Iterator Iterator::operator++(int)
{
    Iterator old = *this;
    if (!owner)
        _invalid_parameter_noinfo();
    Container* container = owner ? *owner : 0;
    if (current >= container->end)
        _invalid_parameter_noinfo();
    ++current;
    return old;
}

inline Node* Iterator::operator*() const
{
    if (!owner)
        _invalid_parameter_noinfo();
    Container* container = owner ? *owner : 0;
    if (current >= container->end)
        _invalid_parameter_noinfo();
    return *current;
}

#define SLOT(n) virtual void slot##n();

struct Device {
    SLOT(0) SLOT(1) SLOT(2) SLOT(3) SLOT(4)
    SLOT(5) SLOT(6) SLOT(7) SLOT(8) SLOT(9)
    SLOT(10) SLOT(11) SLOT(12) SLOT(13) SLOT(14)
    SLOT(15) SLOT(16) SLOT(17) SLOT(18) SLOT(19)
    SLOT(20) SLOT(21) SLOT(22) SLOT(23) SLOT(24)
    SLOT(25) SLOT(26) SLOT(27) SLOT(28) SLOT(29)
    SLOT(30) SLOT(31) SLOT(32) SLOT(33) SLOT(34)
    SLOT(35) SLOT(36) SLOT(37) SLOT(38) SLOT(39)
    SLOT(40) SLOT(41) SLOT(42) SLOT(43) SLOT(44)
    SLOT(45) SLOT(46) SLOT(47) SLOT(48) SLOT(49)
    SLOT(50) SLOT(51) SLOT(52)
    virtual void mode(int);
    SLOT(54) SLOT(55) SLOT(56) SLOT(57)
    virtual void state(int);
};

struct S {
    SLOT(0) SLOT(1) SLOT(2) SLOT(3) SLOT(4)
    virtual void render(Node*, int, int, int);
    char pad[48];
    Device* device;

    void f(Iterator first, Iterator last, int a, int b,
           int flags, bool x, bool y, bool z);
};

#undef SLOT

void S::f(Iterator first, Iterator last, int a, int b,
          int flags, bool x, bool y, bool z)
{
    while (first != last) {
        Node* node = *first++;
        render(node, a, 0, b);
        node = node->next;
        if (!node || !(flags & 1))
            continue;

        if (z) {
            device->mode(3);
            render(node, a, 0, b);
            device->mode(2);
            device->state(0);
            render(node, a, 0, b);
            device->state(2);
            device->mode(1);
        } else if ((x || y) && !(x && y)) {
            render(node, a, 0, b);
        } else {
            device->state(0);
            render(node, a, 0, b);
            device->state(2);
        }
    }
}
