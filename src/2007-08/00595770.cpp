// from server: 100% by colin
struct Inner {
    char pad[0x318];
    void* field318;
};

struct Mid {
    char pad[0x188];
    Inner* field188;
};

struct Outer {
    char pad[0xc];
    Mid* fieldc;
    bool method();
};

extern "C" void* __cdecl func_00631392(void*);
extern "C" bool (__thiscall *func_0077e708)(void*, void*);

bool Outer::method()
{
    Mid* m = this->fieldc;
    Inner* i = m->field188;
    void* p = i->field318;
    if (p != 0) {
        void* q = func_00631392(p);
        return func_0077e708((void*)0x8a59f0, q);
    }
    return false;
}
