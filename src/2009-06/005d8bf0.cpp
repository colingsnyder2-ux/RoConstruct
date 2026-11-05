// from server: 100% by TrollStein
// roc 2009-06 005d8bf0  unit: VAuthoringSettings::?$BoundPropGetSet  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005d8bf0

struct S {
    void f();
};

extern "C" void* (__thiscall *sub_89e4a8)(void*, const char*);

void S::f() {
    sub_89e4a8((void*)0xa445f8, (const char*)0x8d5714);
}
