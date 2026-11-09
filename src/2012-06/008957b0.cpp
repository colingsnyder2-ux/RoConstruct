// from server: 59% by atomic.potato
extern "C" void __cdecl f00895710(float, char*);

struct RBX_BlockBlockContact {
    void f(float);
};

void RBX_BlockBlockContact::f(float value) {
    char buffer[8];
    *(float*)buffer = value;
    buffer[4] = 0;
    f00895710(value, buffer + 3);
}
