// from server: 100% by Intel
struct IdSerializer {
    int* data;
    int value;
    void Set();
};

void IdSerializer::Set() {
    *data = value;
}
