// from server: 65% by atomic.potato
extern "C" void CallVtable(void*, int);

struct LaserTool {
    void* vtable;
    char data[0x9c];

    int f(int);
};

int LaserTool::f(int value) {
    CallVtable(*(void**)this, 0);
    const char* source = (const char*)value;
    CallVtable((char*)this + 0xa0, (int)source);
    return (int)source;
}
