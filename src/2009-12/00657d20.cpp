// from server: 100% by colin
namespace ns_ROCX000000 {
// from server: 100% by tester
struct S {
    char* f();
};

char* S::f() {
    return reinterpret_cast<char*>(this) - 0x94;
}
}
