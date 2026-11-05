// from server: 37% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall _invalid_parameter_noinfo();

struct NodeRef {
    void* vptr;
    long refcount;
};

struct Node {
    char pad[0x0c];
    void* data;
    NodeRef* ref;
};

struct Lock {
    void* vptr;
    void lock();
    void unlock();
};

struct TreeCtrl {
    char pad[0x30];
    Lock* lock;
};

struct CRobloxTreeCtrlNode {
    void func(NodeRef* ref);
};

void CRobloxTreeCtrlNode::func(NodeRef* ref)
{
    TreeCtrl* ctrl = *(TreeCtrl**)((char*)this + 0x30);
    Lock* lock = (Lock*)((char*)ctrl + 0xb0);
    int count = 0;
    NodeRef* cur = ref;
    NodeRef* end = *(NodeRef**)((char*)this + 0x38);

    lock->lock();

    while (count < 10) {
        Node* node = (Node*)cur->vptr;
        NodeRef* next = (NodeRef*)node->data;
        NodeRef* saved = next;

        if (next != end) {
            if (next == *(NodeRef**)((char*)this + 0x38)) {
                _invalid_parameter_noinfo();
            }

            NodeRef* tmp = (NodeRef*)node->ref;
            if (tmp != 0) {
                _InterlockedExchangeAdd(&tmp->refcount, 1);
            }

            void* out;
            void* args[2];
            args[0] = node;
            args[1] = cur;
            ((void (__thiscall*)(void*, void*, void*, void*))0x421700)(this, &out, args, 0);

            lock->unlock();

            ((void (__thiscall*)(void*, void*))0x4239b0)(this, &out);

            if (tmp != 0) {
                if (_InterlockedExchangeAdd(&tmp->refcount, -1) == 1) {
                    ((void (__thiscall*)(void*))((void**)tmp->vptr)[1])(tmp);
                    if (_InterlockedExchangeAdd(&tmp->refcount, -1) == 1) {
                        ((void (__thiscall*)(void*))((void**)tmp->vptr)[2])(tmp);
                    }
                }
            }

            count++;
            cur = saved;
        } else {
            lock->unlock();
            break;
        }
    }
}
