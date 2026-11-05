// from server: 57% by Intel
struct RBX__A6AXABVHeartbeat$$signalVslot$callable {
    void* field0;
    void* field4;
    void* field8;
    void operator()(void* arg);
};

void RBX__A6AXABVHeartbeat$$signalVslot$callable::operator()(void* arg) {
    void* vtable = field0;
    void* func = *(void**)((char*)vtable + 8);
    void* this_ptr = *(void**)((char*)vtable + 4);
    ((void(__stdcall*)(void*, void*))func)(this_ptr, arg);
}
