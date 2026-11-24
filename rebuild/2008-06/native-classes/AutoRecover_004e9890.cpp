// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

extern "C" int __fastcall fn_004e7880(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_004e8b80(void* self, int unusedEdx, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
extern "C" int __fastcall fn_004d7e30(void* self, int unusedEdx);
extern "C" int __fastcall fn_004e5e10(void* self, int unusedEdx, int newSize);
extern "C" void* __cdecl fn_00508530(unsigned int size);

// INFERRED: G3D Table<MeshDirectedEdgeKey, Array<int>> node, 0x1c bytes
struct EdgeNode {
    unsigned int hashCode;
    unsigned int key;
    char value[16];
    EdgeNode* next;
};

// INFERRED: Array<int> copy source, 16 bytes with vtable (vtable 0x826c14)
struct EdgeValue {
    virtual ~EdgeValue() {}
    int a, b, c;
};

struct EdgeTable {
    int unused0;
    int numElements;
    EdgeNode** bucket;
    unsigned int numBuckets;
};

extern "C" void __fastcall fn_004e9890(EdgeTable* self, int unusedEdx, unsigned int* key, EdgeValue* value)
{
    unsigned int code = *key;
    unsigned int b = code % self->numBuckets;
    EdgeNode* n = self->bucket[b];

    if (n == 0) {
        EdgeNode* nn = (EdgeNode*)fn_00508530(0x1c);
        if (nn) {
            EdgeValue tmp(*value);
            n = (EdgeNode*)(size_t)fn_004e8b80(nn, 0, *(int*)&tmp, ((int*)&tmp)[1], ((int*)&tmp)[2], ((int*)&tmp)[3], code, 0, *key);
            self->bucket[b] = (EdgeNode*)(size_t)n;
        } else {
            self->bucket[b] = 0;
        }
        ++self->numElements;
        return;
    }

    int count = 1;
    bool first = true;
    do {
        bool same = first && code == n->hashCode;
        if (code == n->hashCode && n->key == code) {
            EdgeValue* dst = (EdgeValue*)n->value;
            if (dst != value) {
                fn_004d7e30(dst, 0);
                fn_004e7880(dst, 0, (int)value);
            }
            return;
        }
        first = same;
        n = n->next;
        ++count;
    } while (n);

    if (!first && count > 5 && (unsigned int)self->numBuckets < (unsigned int)(self->numElements * 4 * 5 / 4 * 1)) {
        fn_004e5e10(self, 0, self->numBuckets * 2 + 1);
    }

    b = code % self->numBuckets;
    EdgeNode* nn = (EdgeNode*)fn_00508530(0x1c);
    EdgeNode* result = 0;
    if (nn) {
        EdgeValue tmp(*value);
        result = (EdgeNode*)(size_t)fn_004e8b80(nn, 0, *(int*)&tmp, ((int*)&tmp)[1], ((int*)&tmp)[2], ((int*)&tmp)[3], code, (int)(size_t)self->bucket[b], *key);
    }
    self->bucket[b] = result;
    ++self->numElements;
}
