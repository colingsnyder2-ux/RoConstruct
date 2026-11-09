// from server: 100% by king_originala
struct Listener {
    void attach(void** owner);
};

struct SimJob {
    void* object;
    void setObject(void* value);
};

extern "C" void __cdecl detach(Listener* listener, void** owner);

void SimJob::setObject(void* value) {
    if (object) {
        void* owner = this;
        detach(reinterpret_cast<Listener*>(static_cast<char*>(object) + 4),
               &owner);
        object = 0;
    }

    void* next = value;
    if (next) {
        value = this;
        reinterpret_cast<Listener*>(static_cast<char*>(next) + 4)->attach(&value);
        object = next;
    }
}
