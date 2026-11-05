// from server: 47% by Intel
struct SignalDesc {
    void fire(void* a1, void* a2);
};

void SignalDesc::fire(void* a1, void* a2) {
    __try {
        void* this_adjusted = 0;
        if (this != 0) {
            this_adjusted = (void*)((char*)this - 0x18);
        }
        void* vtable = *(void**)a2;
        void (__stdcall *func)(void*, void*) = (void (__stdcall*)(void*, void*))*(void**)vtable;
        func(a1, this_adjusted);
    }
    __except (0) {
    }
}
