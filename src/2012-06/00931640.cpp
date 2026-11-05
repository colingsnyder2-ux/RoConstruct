// from server: 32% by 41k
struct RBX {
    struct CellFaceFacePair {
        void* field_e0;
        void* field_2c;

        void someFunction();
    };
};

extern "C" void someOtherFunction(void*);
extern "C" void yetAnotherFunction(void*);
extern "C" void yetYetAnotherFunction(void*);

void RBX::CellFaceFacePair::someFunction() {
    this->field_e0 = (void*)0xbfef8c;
    if (this->field_e0) {
        void (*func)(void*) = (void (*)(void*))*(void**)((char*)this->field_e0 + 4);
        func((void*)1);
        this->field_e0 = (void*)0;
    }
    if (this->field_2c) {
        someOtherFunction(this->field_2c);
        yetAnotherFunction(this->field_2c);
        yetYetAnotherFunction((void*)-1);
    }
}
