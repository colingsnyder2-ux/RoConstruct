// from server: 67% by colin
struct PropBase {
    int field0;
    int field4;
    int field8;
    int fieldC;
};

struct Prop {
    char pad[0xE8];
    void* ptrE8;
    int method(int arg);
};

extern "C" void* __stdcall sub_53E7A0(void*);
extern "C" void* __fastcall sub_443240(void*);

int Prop::method(int arg)
{
    void* p = this->ptrE8;
    if (p != 0) {
        PropBase* b = *(PropBase**)(arg + 0xC);
        void* q = sub_53E7A0((char*)b->field4 + 4);
        if (q != 0) {
            void* r = sub_443240(q);
            if (r != 0) {
                void* s = (char*)(*(int*)(arg + 4)) + 4;
                return (int)sub_53E7A0(s);
            }
        }
    }
    return 0;
}
