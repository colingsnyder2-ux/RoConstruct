// from server: 93% by atomic.potato
extern "C" void __cdecl G1_func_005622C0(void*);

struct Server {
    void* field_0;

    void __cdecl func_00562A40(void* arg);
};

void Server::func_00562A40(void* arg) {
    void* ptr = this->field_0;
    if (ptr) {
        ptr = reinterpret_cast<char*>(ptr) + 0x2C;
    } else {
        ptr = 0;
    }
    G1_func_005622C0(&ptr);
    if (ptr) {
        ptr = reinterpret_cast<char*>(ptr) - 0x2C;
        this->field_0 = ptr;
    } else {
        this->field_0 = 0;
    }
}
