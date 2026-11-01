// from server: 37% by atomic.potato
struct Vec {
    int* begin;
    int  size;
    int  cap;
    void push_back(int* v);
    void insert(int* pos, int* v);
    void reserve(int n);
};

struct Obj {
    virtual bool check();
};

struct List {
    int   count;
    int   pad0;
    int   pad1;
    int   pad2;
    int   pad3;
    int   pad4;
    int   pad5;
    int   pad6;
    int   pad7;
    int   pad8;
    int   pad9;
    int   pad10;
    int   pad11;
    int   pad12;
    int   count2;
    Obj** items;
};

struct Kernel {
    char  pad0[0x18];
    List* list;
    char  pad1[4];
    Vec   vec;
    void  method(int* arg);
};

extern "C" void __stdcall sub_7a1d80(int* p, int* v);
extern "C" void __stdcall sub_54db30(Vec* v, int n);

void Vec::push_back(int* v) {
    if (size < cap) {
        int* p = begin + size;
        if (p) *p = (int)v;
        size++;
    } else {
        insert(begin + size, v);
    }
}

void Vec::insert(int* pos, int* v) {
    int* b = begin;
    if (pos >= b && pos < b + size) {
        reserve(size + 1);
        begin[size - 1] = (int)v;
    } else {
        reserve(size + 1);
        begin[size - 1] = (int)v;
    }
}

void Vec::reserve(int n) {
    if (n > cap) {
        int old = cap;
        cap = n;
        sub_54db30(this, old);
    }
}

void Kernel::method(int* arg) {
    List* l = list;
    for (int i = 0; i < l->count; i++) {
        sub_7a1d80((int*)l->items[i], arg);
    }
    if (vec.cap != 0) {
        if (vec.size < 0) {
            vec.size = 0;
            if (vec.cap == 0) vec.cap = 0;
            else vec.cap = 10;
            sub_54db30(&vec, vec.cap);
        }
    }
    if (*(char*)&arg) {
        for (int j = 0; j < l->count2; j++) {
            Obj* o = l->items[j];
            if (!o->check()) {
                vec.push_back((int*)o);
            }
        }
    }
}
