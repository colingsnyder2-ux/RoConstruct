// from server: 29% by colin
struct RefCounted {
    void AddRef();
    void Release();
};

struct Node {
    Node* next;
    Node* prev;
    void* data;
};

struct List {
    Node* head;
    void* pad;
    void clear();
};

struct SceneManager {
    char pad0[0x14];
    List list14;
    void* ptr18;
    char pad1c[0x8];
    List list24;
    char pad2c[0x4];
    void method_4ffef0();
    void method_4f07c0(void*);
    void method_4f1790(void*);
    void method_4f23b0(void*);
    void method_4f1920(void*);
    void method_4f2870(void*, double);
    void method_4d1860(void*);
    void method_438eb0();
    void method_60cd80();
    void method_62fc62(void*);
    void method_4f2d40(double, int);
};

extern "C" {
    long __stdcall InterlockedDecrement(long volatile*);
    long __stdcall InterlockedIncrement(long volatile*);
    void __stdcall _invalid_parameter_noinfo();
}

extern double g_79f570;
extern int g_897a60;
extern void* g_77e6d8;
extern void* g_77d2e8;
extern void* g_77d2ec;

void SceneManager::method_4f2d40(double a, int b)
{
    method_4ffef0();
    double v = a * g_79f570;
    void* p18 = ptr18;
    Node* n = *(Node**)p18;
    List* l14 = &list14;
    double total = v + 0.0;
    Node* cur = n;
    Node* end = *(Node**)p18;
    while (cur != end) {
        if (l14 != 0 && l14 != &list14) {
            _invalid_parameter_noinfo();
        }
        if (cur != 0 && cur != *(Node**)&list14) {
            _invalid_parameter_noinfo();
        }
        void* tmp;
        method_4d1860(&tmp);
        if (tmp != 0) {
            void* obj = tmp;
            void* vt = *(void**)obj;
            void* fn = *(void**)((char*)vt + 0x18);
            void* inner;
            ((void (__thiscall*)(void*, void**))fn)(obj, &inner);
            if (inner != 0) {
                InterlockedDecrement((long*)((char*)inner + 4));
                if (inner != 0) {
                    Node* nn = *(Node**)((char*)inner + 8);
                    while (nn != 0) {
                        void* o = nn->data;
                        void* vv = *(void**)o;
                        void* ff = *(void**)((char*)vv + 4);
                        ((void (__thiscall*)(void*))ff)(o);
                        Node* save = nn;
                        nn = nn->next;
                        method_62fc62(save);
                    }
                    void* vv2 = *(void**)inner;
                    void* ff2 = *(void**)vv2;
                    ((void (__thiscall*)(void*, int))ff2)(inner, 1);
                }
            }
            inner = 0;
        }
        void* vt2 = *(void**)tmp;
        void* fn2 = *(void**)((char*)vt2 + 0x14);
        void* inner2;
        ((void (__thiscall*)(void*, void**))fn2)(tmp, &inner2);
        if (inner2 != 0) {
            InterlockedDecrement((long*)((char*)inner2 + 4));
            if (inner2 != 0) {
                Node* nn = *(Node**)((char*)inner2 + 8);
                while (nn != 0) {
                    void* o = nn->data;
                    void* vv = *(void**)o;
                    void* ff = *(void**)((char*)vv + 4);
                    ((void (__thiscall*)(void*))ff)(o);
                    Node* save = nn;
                    nn = nn->next;
                    method_62fc62(save);
                }
                void* vv2 = *(void**)inner2;
                void* ff2 = *(void**)vv2;
                ((void (__thiscall*)(void*, int))ff2)(inner2, 1);
            }
            inner2 = 0;
        }
        void* tmp2;
        method_4d1860(&tmp2);
        if (tmp2 != 0) {
            InterlockedIncrement((long*)((char*)tmp2 + 4));
            method_4f1920(tmp2);
        } else {
            method_4f1790(&tmp2);
            method_4f23b0(&tmp2);
        }
        if (tmp2 != 0) {
            InterlockedDecrement((long*)((char*)tmp2 + 4));
            if (tmp2 != 0) {
                Node* nn = *(Node**)((char*)tmp2 + 8);
                while (nn != 0) {
                    void* o = nn->data;
                    void* vv = *(void**)o;
                    void* ff = *(void**)((char*)vv + 4);
                    ((void (__thiscall*)(void*))ff)(o);
                    Node* save = nn;
                    nn = nn->next;
                    method_62fc62(save);
                }
                void* vv2 = *(void**)tmp2;
                void* ff2 = *(void**)vv2;
                ((void (__thiscall*)(void*, int))ff2)(tmp2, 1);
            }
            tmp2 = 0;
        }
        method_438eb0();
        if (tmp != 0) {
            InterlockedDecrement((long*)((char*)tmp + 4));
            if (tmp != 0) {
                Node* nn = *(Node**)((char*)tmp + 8);
                while (nn != 0) {
                    void* o = nn->data;
                    void* vv = *(void**)o;
                    void* ff = *(void**)((char*)vv + 4);
                    ((void (__thiscall*)(void*))ff)(o);
                    Node* save = nn;
                    nn = nn->next;
                    method_62fc62(save);
                }
                void* vv2 = *(void**)tmp;
                void* ff2 = *(void**)vv2;
                ((void (__thiscall*)(void*, int))ff2)(tmp, 1);
            }
            tmp = 0;
        }
        cur = cur->next;
    }
    void* p18b = ptr18;
    void* p4 = *(void**)((char*)p18b + 4);
    method_4f07c0(p4);
    void* p18c = ptr18;
    *(void**)((char*)p18c + 4) = p18c;
    void* l14b = *(void**)&list14;
    *(void**)((char*)&list14 + 8) = 0;
    *(void**)l14b = l14b;
    void* l14c = *(void**)&list14;
    *(void**)((char*)l14c + 8) = l14c;
    void* p24 = *(void**)((char*)&list24 + 4);
    method_4f07c0(p24);
    void* l24b = *(void**)&list24;
    *(void**)((char*)l24b + 4) = l24b;
    void* l24c = *(void**)&list24;
    *(void**)((char*)&list24 + 8) = 0;
    *(void**)l24c = l24c;
    void* l24d = *(void**)&list24;
    *(void**)((char*)l24d + 8) = l24d;
    if (g_897a60 > 1) {
        void* p0c = *(void**)((char*)this + 0xc);
        Node* n2 = *(Node**)p0c;
        Node* end2 = *(Node**)p0c;
        while (n2 != end2) {
            if (l14 != 0 && l14 != &list14) {
                _invalid_parameter_noinfo();
            }
            if (n2 != 0 && n2 != *(Node**)&list14) {
                _invalid_parameter_noinfo();
            }
            method_4f2870(*(void**)((char*)n2 + 0x18), a);
            method_60cd80();
            method_4ffef0();
            if (total <= a) {
                n2 = n2->next;
            } else {
                break;
            }
        }
    }
}
