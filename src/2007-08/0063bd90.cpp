// from server: 100% by colin
struct Inner {
    void f1();
    void f2();
};

struct Outer {
    int GetCount();
    Inner* GetAt(int index);
    void RemoveAll();
};

struct Tail {
    char pad[0x20];
    void Clear(int a, int b);
};

void Outer::RemoveAll()
{
    int i = 0;
    while (i < GetCount()) {
        Inner* p = GetAt(i);
        p->f1();
        p->f2();
        i++;
    }
    ((Tail*)((char*)this + 0x20))->Clear(0, -1);
}
