// from server: 100% by colin
extern void G1_func_005ba850(void*);

struct Wrapper_005e05c0 {
    void invoke();
};

void Wrapper_005e05c0::invoke() {
    G1_func_005ba850((char*)this + 8);
}
