// from server: 100% by king_originala
struct Lock {
    void enter();
    void leave();
};

struct Array {
    void* data;
    int count;
    int capacity;
};

void __cdecl process1(Array*);
void __cdecl process2(Array*);
void __cdecl process3(Array*);

struct S {
    char pad0[0xe0];
    Lock lock1;
    char pad1[0x107];
    Lock lock2;
    char pad2[0x67];
    int count;
    char pad3[0x20];
    Array array1;
    Array array2;
    Array array3;

    void prepare();
    void update(int, int);
    void finish();
    void f(int, int);
};

void S::f(int a, int b) {
    lock2.enter();
    prepare();
    update(a, b);
    finish();
    lock1.enter();
    process1(&array1);
    process2(&array2);
    process3(&array3);
    lock1.leave();
    lock2.leave();
    count = array1.count;
}
