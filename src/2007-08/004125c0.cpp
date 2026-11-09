// from server: 48% by colin
// roc 2007-08 004125c0  unit: VCContent::?$CComObject  size: 213 bytes
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS /MD

extern "C" void* __cdecl sub_62FEF6(unsigned int size);
extern "C" void __stdcall sub_77E674(void* p, int a, int b);

extern unsigned int dword_8B5188;
extern unsigned int dword_8BAE44;
extern unsigned int dword_786EB0;
extern unsigned int dword_786E8C;

struct VCContentCComObject {
    int __stdcall CreateInstance(int a, int b, int* c);
};

int __stdcall VCContentCComObject::CreateInstance(int a, int b, int* c)
{
    int hr;
    void* p;

    if (c == 0)
        return (int)0x80004003;

    *c = 0;
    hr = (int)0x8007000E;

    p = sub_62FEF6(0x94);
    if (p != 0) {
        *(int*)((char*)p + 8) = 0;
        sub_77E674((char*)p + 0xc, 3, 1);
        *(unsigned int*)p = dword_786EB0;
        *(unsigned int*)((char*)p + 4) = dword_786E8C;
        {
            unsigned int* v = (unsigned int*)dword_8BAE44;
            unsigned int* vt = (unsigned int*)*v;
            typedef void (__stdcall *Fn)(void*);
            ((Fn)vt[1])(v);
        }
    } else {
        p = 0;
    }

    if (p != 0) {
        *(int*)((char*)p + 8) += 1;
        *(int*)((char*)p + 8) += -1;
        {
            unsigned int* vt = (unsigned int*)*(unsigned int*)p;
            typedef int (__stdcall *Fn2)(void*, int, int*);
            hr = ((Fn2)vt[0])(p, a, c);
        }
        if (hr != 0) {
            unsigned int* vt2 = (unsigned int*)*(unsigned int*)p;
            typedef void (__stdcall *Fn3)(void*, int);
            ((Fn3)vt2[4])(p, 1);
        }
    }

    return hr;
}
