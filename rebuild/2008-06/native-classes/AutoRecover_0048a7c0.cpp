// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>

// INFERRED: 16-byte zero-initialised element (four floats), array layout {data, num, numAllocated}
struct V4 {
    float x, y, z, w;
    V4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}
};

struct V4Array {
    V4* data;
    int num;
    int numAllocated;
};

// reallocates storage; copies up to the given element count
extern "C" void __fastcall fn_00489aa0(V4Array* self, int unusedEdx, int copyCount);

// INFERRED: G3D Array<V4>::resize(n, shrinkIfNecessary); the growth factors are guessed constants
extern "C" void __fastcall fn_0048a7c0(V4Array* self, int unusedEdx, int n, bool shrinkIfNecessary)
{
    int oldNum = self->num;
    self->num = n;

    // INFERRED: function-local static (guard at 0x96fb94, value at 0x96fb90)
    static int minElements = 10;

    int num = self->num;
    int alloc = self->numAllocated;

    if (num > alloc) {
        if (alloc == 0) {
            self->numAllocated = n;
        } else if (num < minElements) {
            self->numAllocated = minElements;
        } else {
            float factor = 3.0f;
            if ((unsigned)(alloc * 16) > 400000u) {
                factor = 1.5f;
            } else if ((unsigned)(alloc * 16) > 64000u) {
                factor = 2.0f;
            }
            self->numAllocated = (int)(factor * (float)alloc) - alloc + num;
            if (self->numAllocated < minElements) {
                self->numAllocated = minElements;
            }
        }
        fn_00489aa0(self, 0, oldNum);
    } else if (num <= alloc / 3 && shrinkIfNecessary && num > minElements) {
        if (num >= oldNum) {
            num = oldNum;
        }
        fn_00489aa0(self, 0, num);
    }

    for (int i = oldNum; i < self->num; ++i) {
        new (&self->data[i]) V4();
    }
}
