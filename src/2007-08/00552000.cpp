// from server: 57% by Intel
extern "C" int __stdcall pubsync(void*);

struct S {
    char padding0[0x4c];
    void* buffer;

    void func();
};

void S::func()
{
    __try {
        int v = 0;
        if (buffer) {
            v = pubsync(buffer);
        }
    } __finally {
    }
}
