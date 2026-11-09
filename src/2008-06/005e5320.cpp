// from server: 100% by king_originala
struct Listener;

struct SimJob {
    void* object;
    void clearObject();
};

extern "C" void __cdecl detach(Listener* listener, void** owner);

void SimJob::clearObject() {
    if (object) {
        void* owner = this;
        detach(reinterpret_cast<Listener*>(static_cast<char*>(object) + 4),
               &owner);
        object = 0;
    }
}
