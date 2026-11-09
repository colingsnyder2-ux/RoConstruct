// from server: 47% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    char pad0[8];
    volatile long refcount;
};

struct Node {
    char pad0[4];
    Inner* ptr;
    char pad8[0x24];
    Node* self;
    Node* next;
};

struct Outer {
    Node* field0;
    Node* field4;
};

extern "C" void __stdcall sub_65bfe0(Outer* self, Node* a, Node* b);

Outer* __stdcall sub_65c070(Outer* self, Node* a, Node* b) {
    self->field0 = a;
    sub_65bfe0(self, a, b);
    if (a) {
        Node* p = (Node*)((char*)a + 0x2c);
        if (p) {
            p->self = a;
            Node* old = self->field4;
            if (old != p->next) {
                if (old) {
                    _InterlockedExchangeAdd(&old->ptr->refcount, 1);
                }
                Node* cur = p->next;
                if (cur) {
                    if (_InterlockedExchangeAdd(&cur->ptr->refcount, -1) == 1) {
                        void (*fn)(void) = *(void(**)(void))(*(int*)cur + 8);
                        fn();
                    }
                }
                p->next = old;
            }
        }
    }
    return self;
}
