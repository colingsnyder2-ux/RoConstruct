// from server: 100% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// Codegen analog: target ret 0x1c and call 00687860 prove the argument mapping.
// The target loads 360.0f from 0084e97c and passes 0.0f as the preceding argument.
class MeshGeneratorAnalog {
public:
    void* generate(void*, void*, void*, float, float, int, int, float, float);
    void* generate(void*, void*, void*, float, float, int, int);
};
void* MeshGeneratorAnalog::generate(void* a, void* b, void* c,
                                   float d, float e, int f, int g) {
    return generate(a, b, c, d, e, f, g, 0.0f, 360.0f);
}
