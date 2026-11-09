// from server: 100% by atomic.potato
struct RefObj {
    int attach(void* owner);
    void detach(int handle);
};

struct Geometry {
    char pad0[0xd0];
    RefObj* slot;
    char pad1[0x28];
    int current;
    void setTarget(int value);
};

void Geometry::setTarget(int value) {
    if (this->current != value) {
        int handle = 0;
        if (this->slot != 0) {
            handle = this->slot->attach(this);
        }
        this->current = value;
        if (handle != 0) {
            this->slot->detach(handle);
        }
    }
}
