// from server: 100% by Xemicl
﻿// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
void __cdecl helper(void* buffer, void* state, int value);
struct S {
    char padding[0x40];
    char buffer[0x4c];
    void* state;
    void prepare(int value);
    void f(int value);
};
void S::f(int value)
{
    prepare(value);
    try {
        helper(buffer, state, value);
    } catch (...) {
    }
}
