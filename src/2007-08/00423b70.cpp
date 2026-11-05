// from server: 25% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    long refcount;
    long weakrefcount;
};

struct Inner {
    void* vptr;
    RefCounted* ptr;
};

struct Holder {
    void* vptr;
    RefCounted* ptr;
};

struct Node {
    char pad[0x0c];
    void* field_c;
};

struct TreeCtrl {
    char pad[0x30];
    void* field_30;
};

struct List {
    void* begin;
    void* end;
    void* cap;
};

extern "C" void __cdecl _invalid_parameter_noinfo();

void __stdcall sub_40D550(void*);
void __stdcall sub_40DB50(void*, void*, void*, void*);
void __stdcall sub_421510(void*, void*, void*, void*, void*, void*);
void __stdcall sub_4232D0(void*, void*);
void __stdcall sub_5595A0(void*);
void __stdcall sub_62FC62(void*);

void __stdcall sub_421AF0(void);

struct CRobloxTreeCtrlNode {
    void func();
};

void CRobloxTreeCtrlNode::func()
{
    List list;
    list.begin = 0;
    list.end = 0;
    list.cap = 0;

    TreeCtrl* tc = (TreeCtrl*)this;
    void* obj = tc->field_30;
    void* vtbl = *(void**)obj;
    void* (__stdcall *getter)(void*, void*) = *(void* (__stdcall**)(void*, void*))((char*)vtbl + 0x14c);

    Inner inner;
    getter(obj, &inner);

    RefCounted* rc = inner.ptr;
    if (rc) {
        _InterlockedExchangeAdd(&rc->refcount, 1);
    }

    sub_40D550(&list);

    if (rc) {
        if (_InterlockedExchangeAdd(&rc->refcount, -1) == 1) {
            void* v = rc->vptr;
            void (__stdcall *dtor)(void*) = *(void (__stdcall**)(void*))((char*)v + 4);
            dtor(rc);
            if (_InterlockedExchangeAdd(&rc->weakrefcount, -1) == 1) {
                void* v2 = rc->vptr;
                void (__stdcall *dtor2)(void*) = *(void (__stdcall**)(void*))((char*)v2 + 8);
                dtor2(rc);
            }
        }
    }

    Node* node = (Node*)this;
    void* p = *(void**)((char*)node->field_c + 0xc0);
    if (p) {
        sub_4232D0(&list, p);
    }

    sub_5595A0(&inner);

    void* end = list.end;
    void* begin = list.begin;
    if (begin > end) {
        _invalid_parameter_noinfo();
        end = list.end;
        begin = list.begin;
    }
    if (begin > end) {
        _invalid_parameter_noinfo();
    }

    void* tmp[4];
    tmp[0] = (void*)0x421af0;
    tmp[1] = 0;
    tmp[2] = this;
    tmp[3] = end;

    void* result = 0;
    sub_421510(&result, &begin, begin, &tmp, &end, 0);

    if (result) {
        sub_40DB50(result, begin, &tmp, end);
        sub_62FC62(end);
    }
}
