// from server: 100% by colin
struct Holder {
    void* vtable;
    void* data;
};

struct AnyValue {
    void* type;
    Holder* holder;
};

void assign_range(AnyValue* first, AnyValue* last, AnyValue* src) {
    while (first != last) {
        first->type = src->type;
        Holder* h = src->holder;
        void* newdata;
        if (h) {
            newdata = ((void* (__thiscall*)(Holder*))((void**)h->vtable)[2])(h);
        } else {
            newdata = 0;
        }
        Holder* old = first->holder;
        first->holder = (Holder*)newdata;
        if (old) {
            ((void (__thiscall*)(Holder*, int))((void**)old->vtable)[0])(old, 1);
        }
        first++;
    }
}
