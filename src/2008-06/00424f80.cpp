// from server: 100% by king_originala
extern "C" long (__stdcall *SendMessageA)(void *, unsigned int, unsigned int, long);
extern "C" void __cdecl _ReadWriteBarrier();
#pragma intrinsic(_ReadWriteBarrier)

struct Context {
    bool contains(void *);
};

struct Tree {
    void update(int, int, int);
};

#define V(n) virtual void v##n();
struct Control {
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
    V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
    V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49)
    V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59)
    V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67) V(68) V(69)
    V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77) V(78) V(79)
    V(80) V(81) V(82)
    virtual void update(int, int, int);
    virtual Context *context();

    char padding04[28];
    void *window;
    char padding24[48];
    Tree tree;
};
#undef V

struct Node {
    char padding00[12];
    void *object;
    char padding10[69];
    volatile unsigned char flag;
    char padding56[2];
    Control *control;
    Node *next;
    char padding60[32];
    int item;

    void update();
};

void Node::update()
{
    if (item) {
        bool accepted = false;
        if (control->context()) {
            void *value = object;
            accepted = control->context()->contains(value);
        }
        if (accepted) {
            long (__stdcall *send)(void *, unsigned int, unsigned int, long) =
                SendMessageA;
            Node *node = next;
            while (node) {
                unsigned char saved = node->flag;
                node->flag = 1;
                _ReadWriteBarrier();
                int value = node->item;
                void *window = node->control->window;
                send(window, 0x1102, 0x4002, value);
                node->flag = saved;
                node = node->next;
            }
            control->tree.update(item, item, 0);
            int value = item;
            void *window = control->window;
            send(window, 0x1114, 0, value);
        } else {
            control->update(item, 0, 2);
        }
    }
}
