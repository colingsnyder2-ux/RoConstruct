// from server: 54% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall _invalid_parameter_noinfo();

struct RefCounted {
    virtual void unknown1();
    virtual void unknown2();
    virtual void unknown3();
    long refcount1;
    long refcount2;
};

struct Node {
    int key;
    int value;
};

struct NodeList {
    Node* begin;
    Node* end;
    Node* capacity;
};

struct TreeCtrl {
    char pad[0x104];
    NodeList* list;
    bool Find(int* key, RefCounted* ref);
};

extern "C" void* __cdecl sub_49D670(void* out, void* in);

bool TreeCtrl::Find(int* key, RefCounted* ref) {
    void* tmp;
    NodeList* nl;
    Node* begin;
    Node* end;
    Node* it;
    bool result;

    sub_49D670(&tmp, key);

    nl = this->list;
    end = nl->end;
    if (nl->begin > end) {
        _invalid_parameter_noinfo();
    }

    nl = this->list;
    begin = nl->begin;
    if (nl->begin > nl->end) {
        _invalid_parameter_noinfo();
    }

    nl = this->list;
    it = nl->begin;
    if (it > nl->end) {
        _invalid_parameter_noinfo();
    }

    while (it != end && it->key != *(int*)tmp) {
        it++;
    }

    if (nl != 0 && nl != this->list) {
        _invalid_parameter_noinfo();
    }

    result = (it != begin);

    if (ref != 0) {
        if (_InterlockedExchangeAdd(&ref->refcount1, -1) == 1) {
            ref->unknown2();
            if (_InterlockedExchangeAdd(&ref->refcount2, -1) == 1) {
                ref->unknown3();
            }
        }
    }

    return result;
}
