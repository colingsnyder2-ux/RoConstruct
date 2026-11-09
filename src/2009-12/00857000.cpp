// from server: 56% by atomic.potato
struct S
{
    void f();
};

struct T
{
    int pad0[31];
    T* field7c;
};

struct U
{
    int pad0[26];
    T* field208;
};

void Call(T*, int, int);

void S::f()
{
    U* p = (U*)this;
    T* q = p->field208;
    if (q != 0 && q->field7c == (T*)((char*)this + 0x178))
    {
        q->field7c = 0;
        Call((T*)((char*)q + 0x68), 0, -1);
    }
}
