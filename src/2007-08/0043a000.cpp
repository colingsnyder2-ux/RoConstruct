// from server: 54% by tester
struct SeparateStage {
    void* field0;
    void* field4;
    void reset();
};

extern "C" void __stdcall invalid_parameter_noinfo();

struct Item {
    void* field0;
    void* field4;
    void* field8;
    void* fieldC;
};

struct Iter {
    Item* first;
    Item* last;
};

struct Result {
    void* f0;
    void* f4;
    void* f8;
};

void __stdcall callback(void*);

Result* __cdecl copy_items(Result* out, Iter* src, Iter* end, void* a, void* b, void (__stdcall *fn)(void*));

Result* __cdecl copy_items(Result* out, Iter* src, Iter* end, void* a, void* b, void (__stdcall *fn)(void*))
{
    Item* first = src->first;
    Item* last = src->last;
    while (first != end->first) {
        if (first == 0 || first == src->last) {
            invalid_parameter_noinfo();
        }
        if (last != end->last) {
            if (first == 0) {
                invalid_parameter_noinfo();
            }
            if (last == first->field4) {
                invalid_parameter_noinfo();
            }
            fn(last->fieldC);
            SeparateStage* s = (SeparateStage*)&src;
            s->reset();
            last = src->last;
            first = src->first;
        }
    }
    out->f0 = fn;
    out->f4 = b;
    out->f8 = a;
    return out;
}
