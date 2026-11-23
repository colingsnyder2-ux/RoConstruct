// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: std::map/set hinted insert with checked-iterator asserts; layout from disassembly only. Not compiled or diffed.
extern "C" int __fastcall fn_006922f0(void* self, int unusedEdx, int a1, int a2, int a3, int a4);
extern "C" int __fastcall fn_0068d2c0(void* self, int unusedEdx);
extern "C" int __fastcall fn_0068d210(void* self, int unusedEdx);
extern "C" int* __fastcall fn_00693dc0(void* self, int unusedEdx, int a1, int a2);
extern "C" void __cdecl _invalid_parameter_noinfo(void);

struct Node { char pad[8]; Node* next; unsigned key; };
struct Head { char pad[8]; Node* first; unsigned key; };

struct Tree {
    void* proxy;        // 0x00
    char pad[0x14];
    Head* head;         // 0x18
    unsigned size;      // 0x1c
};

struct Iter { void* proxy; Node* node; Node* extra; Head* head; };

extern "C" int* __fastcall fn_006976f0(Tree* self, int unusedEdx, int* ret, void* proxy, Node* node, unsigned* key)
{
    if (self->size == 0) {
        fn_006922f0(self, 0, (int)ret, 1, (int)self->head, (int)key);
        return ret;
    }
    Head* head = self->head;
    if (proxy == 0 || proxy != self->proxy)
        _invalid_parameter_noinfo();
    if ((void*)node == (void*)head->first) {
        if (*key < ((unsigned*)node)[3]) {
            fn_006922f0(self, 0, (int)ret, 1, (int)node, (int)key);
            return ret;
        }
    } else {
        if (proxy == 0 || proxy != self->proxy)
            _invalid_parameter_noinfo();
        if ((void*)node == (void*)self->head) {
            Node* n = *(Node**)((char*)self->head + 8);
            if (((unsigned*)n)[3] < *key) {
                fn_006922f0(self, 0, (int)ret, 0, (int)n, (int)key);
                return ret;
            }
        } else if (((unsigned*)node)[3] > *key) {
            Iter it = { proxy, 0, node, 0 };
            fn_0068d2c0(&it, 0);
            Node* p = it.extra;
            if (((unsigned*)p)[3] < *key) {
                bool isNil = *((char*)p->next + 0x39) != 0;
                fn_006922f0(self, 0, (int)ret, isNil ? 0 : 1, (int)p, (int)key);
                return ret;
            }
        } else if (((unsigned*)node)[3] < *key) {
            Iter it = { proxy, 0, node, self->head };
            fn_0068d210(&it, 0);
            bool isNil = *((char*)node->next + 0x39) != 0;
            fn_006922f0(self, 0, (int)ret, isNil ? 0 : 1, (int)node, (int)key);
            return ret;
        }
    }
    int* r = fn_00693dc0(self, 0, (int)ret, (int)key);
    ret[0] = r[0];
    ret[1] = r[1];
    return ret;
}
