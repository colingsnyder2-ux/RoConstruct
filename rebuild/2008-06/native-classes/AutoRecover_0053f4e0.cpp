// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: callee arities adjusted to match the pushes seen in the disassembly.
extern "C" int __fastcall fn_00540660(void* self, int unusedEdx, int a1, int a2);
extern "C" void* __fastcall fn_00540630(Fn540630Self* self, int unusedEdx, void* out);
extern "C" int __fastcall fn_00545d40(void* self, int unusedEdx, int a1, int a2, int a3);
extern "C" int __fastcall fn_00540710(void* self, int unusedEdx, int a1, int a2, int a3);
// SortedVertex::operator!=
extern "C" bool __fastcall fn_00540f20(void* self, int unusedEdx, void* other);

// INFERRED: owner object with a sub-object at +0xC
struct Fn0053f4e0Obj {
    char pad[0xc];
    char sub[1];
};

struct Fn0053f4e0Pair {
    int a;
    int b;
};

extern "C" bool __fastcall fn_0053f4e0(Fn0053f4e0Obj* self, int unusedEdx, int arg1)
{
    Fn0053f4e0Pair t10;
    Fn0053f4e0Pair t18;
    Fn0053f4e0Pair v8;   // SortedVertex
    Fn0053f4e0Pair t20;
    Fn0053f4e0Pair t28;
    Fn0053f4e0Pair t30;

    Fn0053f4e0Pair* p = (Fn0053f4e0Pair*)fn_00540660(self->sub, 0, (int)&t10, arg1);
    Fn0053f4e0Pair* q = (Fn0053f4e0Pair*)fn_00540630(self->sub, 0, (int)&t18, p->a, p->b);
    fn_00545d40(&v8, 0, (int)&v8, q->a, q->b);

    int r = fn_00540660(self->sub, 0, (int)&t20, 0);
    if (fn_00540f20(&v8, 0, (void*)r)) {
        t28.a = v8.a;
        t28.b = v8.b;
        fn_00540710(self->sub, 0, (int)&t30, t28.a, t28.b);
        return true;
    }
    return false;
}
