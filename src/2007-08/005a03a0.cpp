// from server: 100% by atomic.potato
struct Name {
    void mutex();
};

struct Base {
    char pad[0xe8];
    Name name;
};

struct FactoryProduct : Base {
    void construct();
    void tail();
};

void FactoryProduct::construct() {
    *(int*)((char*)this + 0x00) = 0x7b37bc;
    *(int*)((char*)this + 0x04) = 0x7b37b4;
    *(int*)((char*)this + 0x10) = 0x7b37ac;
    *(int*)((char*)this + 0x14) = 0x7b379c;
    *(int*)((char*)this + 0x2c) = 0x7b378c;
    *(int*)((char*)this + 0x44) = 0x7b377c;
    *(int*)((char*)this + 0x5c) = 0x7b376c;
    *(int*)((char*)this + 0x74) = 0x7b375c;
    *(int*)((char*)this + 0x8c) = 0x7b374c;
    name.mutex();
    *(int*)((char*)this + 0x00) = 0x7b36e4;
    *(int*)((char*)this + 0x04) = 0x7b36dc;
    *(int*)((char*)this + 0x10) = 0x7b36d4;
    *(int*)((char*)this + 0x14) = 0x7b36c4;
    *(int*)((char*)this + 0x2c) = 0x7b36b4;
    *(int*)((char*)this + 0x44) = 0x7b36a4;
    *(int*)((char*)this + 0x5c) = 0x7b3694;
    *(int*)((char*)this + 0x74) = 0x7b3684;
    *(int*)((char*)this + 0x8c) = 0x7b3674;
    tail();
}
