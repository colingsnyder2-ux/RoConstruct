// from server: 100% by king_originala
extern int g_946274;

struct StandardOut {
    void sub_5F9C30(int, void *, int, int, int);
    void sub_5F8B60(int, void *, int, int, int);
    void print_exception(int rethrow);
};

void StandardOut::print_exception(int rethrow)
{
    volatile int type = 0;
    StandardOut *output = this;
    char buffer[132];

    try {
        output->sub_5F9C30(0, buffer, 0, type, rethrow);
    } catch (...) {
        if (g_946274 == 0) {
            output->sub_5F9C30(0, buffer, 0, type, rethrow);
        } else if (g_946274 == 1) {
            output->sub_5F8B60(0, buffer, 0, type, rethrow);
        }
    }
}
