// from server: 100% by colin
struct VItem {
    struct GetSet {
        virtual void f0();
        virtual void f1();
        virtual void f2();
        virtual void f3();
        virtual void f4();
        virtual void f5();
        virtual void f6();
        virtual void f7();
        virtual void f8();
        virtual void f9();
        virtual void f10();
        virtual void f11();
        virtual void f12(int, void*);
    };
    void setValue(void* object, int value);
};

void VItem::setValue(void* object, int value) {
    GetSet* node = *(GetSet**)((char*)object + 4);
    if (node) {
        do {
            void** vtbl = *(void***)this;
            void (__thiscall *fn)(void*, GetSet*, int) = (void (__thiscall *)(void*, GetSet*, int))vtbl[12];
            fn(this, node, value);
            node = *(GetSet**)node;
        } while (node);
    }
}
