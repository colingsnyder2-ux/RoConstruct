// from server: 41% by Intel
struct UTuple {
    int field_0x78;
    int field_0xa4;
};

struct shared_ptr {
    int data;
};

struct function {
    int func;
};

struct UTuple$$A6A {
    shared_ptr* sp;
    function* func;
};

UTuple$$A6A* get_uttuple_data(UTuple* this_ptr) {
    shared_ptr* v1 = (shared_ptr*)((int)this_ptr + 0xa4);
    function* v2 = (function*)((int)v1->data + 0x24);
    return (UTuple$$A6A*)((int)v2 + 0x78);
}
