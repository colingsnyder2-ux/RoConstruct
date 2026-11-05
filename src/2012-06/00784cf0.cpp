// from server: 100% by tajop

struct Any { void assign(const unsigned*); };
struct Variant { const void* type; Any value; };
extern int once_flag;
void init_type();
void call_once(int&, void (*)());
const void* get_type();
struct S {
    char a[0x2c];
    unsigned count;
    char b[0x90 - 0x30];
    unsigned* values;
    bool f(unsigned, Variant&) const;
};
bool S::f(unsigned index, Variant& out) const {
    bool ok;
    if (index < count) {
        index = values[index];
        ok = true;
    } else {
        ok = false;
    }
    call_once(once_flag, init_type);
    out.type = get_type();
    out.value.assign(&index);
    return ok;
}
