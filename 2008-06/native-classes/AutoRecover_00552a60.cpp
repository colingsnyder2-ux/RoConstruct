// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: iterator type is an 8-byte POD; element type is a node holding a deque-like
// container at +0xc and an index at +0x24.
struct Fn552a60Iter {
    int a;
    int b;
};

extern "C" int __fastcall fn_00540630(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_00540660(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_00552e60(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_005529b0(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_00552ec0(void* self, int unusedEdx);
extern "C" int __fastcall fn_005528e0(void* self, int unusedEdx, int a1, int a2);

// INFERRED: iterator helpers (compare, increment, dereference), container size/back
extern "C" int __fastcall fn_00540f20(void* self, int unusedEdx, int a1);
extern "C" void __fastcall fn_00541160(void* self, int unusedEdx);
extern "C" int* __fastcall fn_005462c0(void* self, int unusedEdx);
extern "C" char* __fastcall fn_00541180(void* self, int unusedEdx);
extern "C" unsigned __fastcall fn_00546320(void* self, int unusedEdx);
extern "C" int* __fastcall fn_00552e90(void* self, int unusedEdx);

extern "C" int __fastcall fn_00552a60(char* self, int unusedEdx)
{
    int total = 0;
    Fn552a60Iter it;
    Fn552a60Iter endIt;

    fn_00540630(self + 8, 0, (int)&it);
    for (;;) {
        int e = fn_00540660(self + 8, 0, (int)&endIt);
        if (!(unsigned char)fn_00540f20(&it, 0, e))
            break;
        int* p = fn_005462c0(&it, 0);
        p[0x24 / 4] = 0;
        fn_00541160(&it, 0);
    }

    Fn552a60Iter it2;
    Fn552a60Iter endIt2;
    fn_00540630(self + 8, 0, (int)&it2);
    for (;;) {
        int e = fn_00540660(self + 8, 0, (int)&endIt2);
        if (!(unsigned char)fn_00540f20(&it2, 0, e))
            break;
        char* node = fn_00541180(&it2, 0);
        while (*(unsigned*)(node + 0x24) < fn_00546320(node + 0xc, 0)) {
            int* slot = (int*)fn_00552e60(node + 0xc, 0, *(int*)(node + 0x24));
            int other = *slot;
            char* found = (char*)fn_005529b0(self, 0, other);
            if (found != node) {
                int* last = fn_00552e90(node + 0xc, 0);
                int* dst = (int*)fn_00552e60(node + 0xc, 0, *(int*)(node + 0x24));
                *dst = *last;
                fn_00552ec0(node + 0xc, 0);
                total += fn_005528e0(self, 0, other, (int)found);
            } else {
                *(int*)(node + 0x24) += 1;
            }
        }
        fn_00541160(&it2, 0);
    }
    return total;
}
