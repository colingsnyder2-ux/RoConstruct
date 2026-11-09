// from server: 27% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall _invalid_parameter_noinfo();

struct CSelectionPropGrid;

struct RefCounted {
    void* vptr;
    long ref1;
    long ref2;
    void AddRef();
    void Release();
};

struct Node {
    Node* next;
    Node* prev;
};

struct List {
    Node* head;
    Node* tail;
};

struct CSelectionPropGrid {
    char pad0[4];
    void* field4;
    char pad8[4];
    void* fieldC;
    void method_439d10(void** out1, void** out2);
    void method_5392b0(void* a, void* b, void* c);
};

extern "C" void* __cdecl func_49d670(void* a, void* b);

void CSelectionPropGrid::method_5392b0(void* a, void* b, void* c) {}

void CSelectionPropGrid::method_439d10(void** out1, void** out2) {}

void CSelectionPropGrid_method_43ab60(CSelectionPropGrid* self, void* arg) {
    void* local1 = 0;
    void* local2 = 0;
    void* local3 = 0;
    void* local4 = 0;
    void* local5 = 0;
    void* local6 = 0;

    void* v = *(void**)((char*)arg + 0xc);
    local6 = v;

    self->method_439d10(&local1, &local2);

    if (local1 != 0 && local1 != self) {
        _invalid_parameter_noinfo();
    }

    void* ebx = self->field4;
    void* esi = local2;

    if (esi != ebx) {
        void* ebp = func_49d670(&local3, arg);

        void* edi = local3;
        if (edi == 0) {
            _invalid_parameter_noinfo();
        }

        if (esi == *(void**)((char*)edi + 4)) {
            _invalid_parameter_noinfo();
        }

        void* edi2 = *(void**)((char*)esi + 0x18);
        if (*(unsigned int*)((char*)esi + 0x14) > (unsigned int)edi2) {
            _invalid_parameter_noinfo();
        }

        void* ecx = local2;
        if (esi == *(void**)((char*)ecx + 4)) {
            _invalid_parameter_noinfo();
        }

        void* ebx2 = (char*)esi + 0x10;
        void* esi2 = *(void**)((char*)ebx2 + 4);
        if ((unsigned int)esi2 > *(unsigned int*)((char*)ebx2 + 8)) {
            _invalid_parameter_noinfo();
        }

        local4 = esi2;

        if (esi2 != edi2) {
            void* eax = *(void**)ebp;
            while (*(void**)esi2 != eax) {
                esi2 = (char*)esi2 + 8;
                if (esi2 == edi2) break;
            }
        }

        void* edi3 = local5;
        if (edi3 != 0) {
            volatile long* p = (volatile long*)((char*)edi3 + 4);
            if (_InterlockedExchangeAdd(p, -1) == 1) {
                void** vt = *(void***)edi3;
                void (*fn)(void*) = (void (*)(void*))vt[1];
                fn(edi3);
                volatile long* p2 = (volatile long*)((char*)edi3 + 8);
                if (_InterlockedExchangeAdd(p2, -1) == 1) {
                    void** vt2 = *(void***)edi3;
                    void (*fn2)(void*) = (void (*)(void*))vt2[2];
                    fn2(edi3);
                }
            }
        }

        void* eax2 = local4;
        void* ecx2 = local2;
        if (eax2 == *(void**)((char*)ecx2 + 4)) {
            _invalid_parameter_noinfo();
        }

        void* edi4 = *(void**)((char*)ebx2 + 8);
        if (*(unsigned int*)((char*)ebx2 + 4) > (unsigned int)edi4) {
            _invalid_parameter_noinfo();
        }

        if (ebx2 != 0 && ebx2 != ebx2) {
            _invalid_parameter_noinfo();
        }

        if (esi2 != edi4) {
            void* edx = local4;
            void* eax3 = local2;
            if (edx == *(void**)((char*)eax3 + 4)) {
                _invalid_parameter_noinfo();
            }
            self->method_5392b0(ebx2, ebx2, esi2);
        }
    }
}
