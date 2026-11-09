// from server: 84% by colin
// roc 2007-08 00501500  unit: G3D::Shader  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00501500
//
// 00501500  e819f51200           call 0x630a1e
// 00501505  83c434               add esp, 0x34
// 00501508  c20400               ret 4

extern "C" void __cdecl helper_630a1e();

struct Shader {
    void method(int);
};

void Shader::method(int) {
    helper_630a1e();
}
