// from server: 100% by colin
namespace ns_ROCX000005 {
// from server: 100% by tester
struct S {
    char* f();
};

char* S::f() {
    return reinterpret_cast<char*>(this) - 0x120;
}
}
