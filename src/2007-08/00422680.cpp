// from server: 40% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct CRobloxTreeCtrlNode;

struct RefCounted {
    void* vptr;
    long refcount;
    long refcount2;
};

struct Inner {
    void* vptr;
    void* ptr;
};

struct Outer {
    void* vptr;
    void* ptr;
};

struct TreeCtrl {
    void* vptr;
    void* getItem(int* out);
};

struct Node {
    char pad[0x2c];
    unsigned char flags;
    char pad2[3];
    TreeCtrl* tree;
    void func(int a, int b, int c);
};

void __stdcall helper1(void*);
void __stdcall helper2(void*);

void Node::func(int a, int b, int c)
{
    Inner inner;
    Outer outer;
    void* item;
    bool matched;

    this->tree->getItem((int*)&inner);

    outer.vptr = inner.vptr;
    outer.ptr = inner.ptr;
    if (outer.ptr != 0) {
        _InterlockedExchangeAdd((volatile long*)((char*)outer.ptr + 4), 1);
    }

    helper1(&inner);

    if (outer.ptr != 0) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)outer.ptr + 4), -1) == 1) {
            (*(void (__stdcall**)(void*))outer.ptr)(outer.ptr);
            if (_InterlockedExchangeAdd((volatile long*)((char*)outer.ptr + 8), -1) == 1) {
                (*(void (__stdcall**)(void*))((*(void***)outer.ptr)[2]))(outer.ptr);
            }
        }
    }

    matched = (*(void**)&item == (void*)0x8c14bc);
    helper2(&inner);

    if (matched) {
        this->tree->vptr = this->tree->vptr;
        this->flags |= 1;
        (*(void (__stdcall**)(void*))((*(void***)this->tree)[0x154/4]))(this->tree);
    }
}
