// from server: 40% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl _invalid_parameter_noinfo();

struct RefCounted {
    void* vptr;
    long refcount;
};

struct Obj8C {
    char pad[0x8c];
};

struct Obj90 {
    char pad[0x8c];
    Obj8C* ptr8c;
};

struct Inner {
    char pad[0xc];
    unsigned int field_c;
    unsigned int field_10;
};

struct InnerHolder {
    char pad[0x8c];
    Inner* ptr8c;
};

struct Main {
    char pad[0x8c];
    Obj90* field90;
    char pad2[4];
};

struct VPartInstance {
    char pad[0x8c];
    Obj90* field90;
    char pad2[4];
    void FilteredSelection(void* arg);
};

extern "C" void* __cdecl func_0041bdf0(void* p);
extern "C" void __cdecl func_00402500(void* dst, void* src);
extern "C" void __cdecl func_00433d70(void* ecx, void* arg);
extern "C" void __cdecl func_005d1a50(void* ecx, void* arg);
extern "C" void __cdecl func_005d39d0(void* ecx, void* arg);
extern "C" void __cdecl func_006089b0(void* dst, void* a, void* b);
extern "C" void* __cdecl func_00719c7a(void* a, void* b, void* c, void* d, void* e);

extern void* __cdecl sub_6089b0(void* dst, void* a, void* b);

void VPartInstance::FilteredSelection(void* arg) {
    void* esi = arg;
    func_005d1a50(this, esi);
    if (this->field90 != 0) {
        return;
    }
    void* eax = *(void**)((char*)esi + 8);
    void* r = func_0041bdf0(eax);
    void* tmp;
    sub_6089b0(&tmp, r, 0);
    void* edx = *(void**)tmp;
    void* p = (char*)tmp + 4;
    this->field90 = (Obj90*)edx;
    func_00402500((char*)this + 0x94, p);
    void* old = tmp;
    if (old != 0) {
        void* rc = (char*)old + 4;
        if (_InterlockedExchangeAdd((volatile long*)rc, -1) == 1) {
            void** vt = *(void***)old;
            void (*f1)(void*) = (void (*)(void*))vt[1];
            f1(old);
            void* rc2 = (char*)old + 8;
            if (_InterlockedExchangeAdd((volatile long*)rc2, -1) == 1) {
                void** vt2 = *(void***)old;
                void (*f2)(void*) = (void (*)(void*))vt2[2];
                f2(old);
            }
        }
    }
    if (this->field90 == 0) {
        return;
    }
    Obj8C* o8c = this->field90->ptr8c;
    Inner* first = (Inner*)o8c;
    unsigned int edi = first->field_c;
    if (edi > first->field_10) {
        _invalid_parameter_noinfo();
    }
    void* ebp = *(void**)first;
    while (1) {
        Obj8C* o8c2 = this->field90->ptr8c;
        Inner* cur = (Inner*)o8c2;
        unsigned int ebx = cur->field_10;
        if (cur->field_c > ebx) {
            _invalid_parameter_noinfo();
        }
        void* esi2 = *(void**)cur;
        if (ebp != 0 && ebp == esi2) {
            // equal
        } else {
            _invalid_parameter_noinfo();
        }
        if (edi == ebx) {
            break;
        }
        void* eax2;
        if (ebp != 0) {
            eax2 = *(void**)ebp;
        } else {
            _invalid_parameter_noinfo();
            eax2 = 0;
            if (edi < *(unsigned int*)((char*)eax2 + 0x10)) {
            } else {
                _invalid_parameter_noinfo();
            }
        }
        void* v = *(void**)edi;
        void* res = func_00719c7a(v, (void*)0x9dbe40, (void*)0x9df950, 0, 0);
        if (res != 0) {
            func_00433d70((char*)this + 0x98, &res);
        }
        if (ebp == 0) {
            _invalid_parameter_noinfo();
            if (edi < *(unsigned int*)((char*)0 + 0x10)) {
            } else {
                _invalid_parameter_noinfo();
            }
        }
        edi += 8;
    }
    func_005d39d0(this->field90, (char*)this + 0x8c);
}
