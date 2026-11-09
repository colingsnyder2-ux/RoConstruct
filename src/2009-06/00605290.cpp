// from server: 27% by atomic.potato
extern "C" void* __stdcall sub_718A38(unsigned int size);
extern "C" void __stdcall sub_718A32(void* p);
extern "C" void __stdcall sub_7052B0(void* p);
extern "C" void __stdcall sub_705300(void* p);
extern "C" void __stdcall sub_4D1460(void* p);
extern "C" void __stdcall sub_678350(void* p);

struct S {
    void* field0;
    void f();
};

void S::f()
{
    if (this->field0 == 0) {
        sub_7052B0(&this->field0);
        if (this->field0 == 0) {
            void* p = sub_718A38(0x34);
            if (p != 0) {
                sub_678350(p);
            } else {
                p = 0;
            }
            void* old = this->field0;
            this->field0 = p;
            if (old != 0) {
                sub_4D1460(old);
                sub_718A32(old);
            }
        }
        sub_705300(&this->field0);
    }
}
