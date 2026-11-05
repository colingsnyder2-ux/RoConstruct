// from server: 100% by Yeetserama
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD

struct CutVerb {
    char pad[0x1c];
    int field_1c;
    int field_20;
};

struct StringAssign {
    void assign(const StringAssign& other);
};

extern "C" char s_77e690[];
void (__thiscall *g_assign_fn)(StringAssign*, const StringAssign&) =
    (void (__thiscall *)(StringAssign*, const StringAssign&))(int)s_77e690;

CutVerb* func_0040f4f0(CutVerb* first, CutVerb* last, CutVerb* dest)
{
    if (first != last) {
        do {
            g_assign_fn((StringAssign*)dest, *(StringAssign*)first);
            dest->field_1c = first->field_1c;
            dest->field_20 = first->field_20;
            first = (CutVerb*)((char*)first + 0x24);
            dest = (CutVerb*)((char*)dest + 0x24);
        } while (first != last);
    }
    return dest;
}
