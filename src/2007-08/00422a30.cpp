// from server: 35% by colin
// from server: 37% by tester
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" const char* __stdcall c_str_helper(const void*);
extern "C" char* __stdcall strncpy_helper(char*, const char*, unsigned int);

struct RefCounted {
    long refcount;
    long weakrefcount;
    virtual void destroy();
    virtual void destroy2();
};

struct Inner {
    virtual void* getSomething(void* out);
};

struct Node {
    char pad0[0xc];
    unsigned char flags;
    char pad1[0xf];
    char* dest;
    char pad2[0x8];
    int field2c;
    char pad3[0x4];
    Inner* inner;
};

struct TreeCtrl {
    char pad0[0xc];
    void* field0c;
    char pad1[0x20];
    Node* node;
};

struct StringHolder {
    char pad0[0x10];
    RefCounted* ptr;
};

struct LocalString {
    char pad0[0x10];
    RefCounted* ptr;
};

extern "C" void __stdcall unknown_77e6a8(void*);
extern "C" void* __stdcall unknown_77e978(void*, void*, void*);

struct CRobloxTreeCtrlNode {
    void __cdecl func(Node* node);
};

void CRobloxTreeCtrlNode::func(Node* node) {
    if (node->flags & 1) {
        Inner* inner = ((TreeCtrl*)this)->node->inner;
        void* out = 0;
        void* result = inner->getSomething(&out);
        RefCounted* rc = *(RefCounted**)result;
        RefCounted* rc2 = *(RefCounted**)((char*)result + 4);
        if (rc2) {
            _InterlockedExchangeAdd(&rc2->refcount, 1);
        }
        LocalString ls;
        ls.ptr = rc;
        if (rc2) {
            if (_InterlockedExchangeAdd(&rc2->refcount, -1) == 1) {
                rc2->destroy();
                if (_InterlockedExchangeAdd(&rc2->weakrefcount, -1) == 1) {
                    rc2->destroy2();
                }
            }
        }
        void* h = ((TreeCtrl*)this)->field0c;
        unknown_77e6a8((char*)h + 0xc8);
        unknown_77e978(node->dest, (void*)0, node->dest);
        ls.ptr = 0;
    }
    if (node->flags & 0x40) {
        char al = ((char (__thiscall*)(CRobloxTreeCtrlNode*))0x422770)(this);
        node->field2c = (al != 0) ? 1 : 0;
    }
}
