// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stddef.h>

namespace G3D {
class System {
public:
    static void* malloc(size_t n);
};
}

// INFERRED: 16-byte value with a vptr, copy-constructed by fn_004e7880 and destroyed by fn_004d7e30.
struct TblValue;
extern "C" int __fastcall fn_004e7880(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_004d7e30(void* self, int unusedEdx);

struct TblValue {
    int d[3];
    virtual void anchor() {}
    TblValue(const TblValue& o) { fn_004e7880(this, 0, (int)&o); }
};

// INFERRED: hash node of G3D::Table: hash, key, value, next (0x1c bytes)
struct TblNode {
    unsigned hashCode;
    unsigned key;
    TblValue value;
    TblNode* next;
};

// INFERRED: G3D::Table layout
struct TblTable {
    int pad0;
    int _size;
    TblNode** bucket;
    unsigned numBuckets;
};

// node constructor: (key, value by value, hash, next)
extern "C" int __fastcall fn_004e8880(void* self, int unusedEdx, unsigned key, TblValue value, unsigned hash, TblNode* next);
extern "C" void __fastcall fn_004e5e10(void* self, int unusedEdx, int newSize);

extern "C" void __fastcall fn_004e9210(TblTable* self, int unusedEdx, const unsigned* key, const TblValue* value)
{
    unsigned code = *key;
    unsigned b = code % self->numBuckets;
    TblNode* node = self->bucket[b];

    if (node == 0) {
        TblNode* n = (TblNode*)G3D::System::malloc(sizeof(TblNode));
        if (n) {
            fn_004e8880(n, 0, *key, *value, code, (TblNode*)0);
            self->bucket[b] = n;
        } else {
            self->bucket[b] = 0;
        }
        ++self->_size;
        return;
    }

    int len = 1;
    bool allSame = true;
    do {
        allSame = allSame && (code == node->hashCode);
        if (code == node->hashCode && node->key == code) {
            if (&node->value != value) {
                fn_004d7e30(&node->value, 0);
                fn_004e7880(&node->value, 0, (int)value);
            }
            return;
        }
        node = node->next;
        ++len;
    } while (node);

    if (!allSame && len > 5 && (int)self->numBuckets < self->_size * 20) {
        fn_004e5e10(self, 0, (int)(self->numBuckets * 2 + 1));
    }

    b = code % self->numBuckets;
    TblNode* n = (TblNode*)G3D::System::malloc(sizeof(TblNode));
    if (n) {
        fn_004e8880(n, 0, *key, *value, code, self->bucket[b]);
        self->bucket[b] = n;
    } else {
        self->bucket[b] = 0;
    }
    ++self->_size;
}
