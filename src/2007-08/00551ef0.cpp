// from server: 50% by Intel
struct S {
    char pad0[0x4c];
    void* stream_buffer;

    void func();
};

void S::func()
{
    int cookie = 0;
    __try {
        cookie = -1;
        int (__thiscall *base_init)(S*) = (int (__thiscall*)(S*))0x551a20;
        base_init(this);
        cookie = 0;
        void* ptr = this->stream_buffer;
        if (ptr) {
            int (__thiscall *pubsync)(void*) = *(int (__thiscall**)(void*))0x77e604;
            pubsync(ptr);
        }
    }
    __finally {
    }
}
