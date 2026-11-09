// from server: 59% by atomic.potato
// roc 2011-06 007fe0c0  unit: RBX::VCEvent::?$sp_counted_impl_p  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007fe0c0

typedef unsigned int DWORD;

struct S {
    void __cdecl f(void* first, void* last, void* result, void* fn);
};

void S::f(void* first, void* last, void* result, void* fn)
{
    char* p = (char*)first;
    char* e = (char*)last;
    if (p != e) {
        do {
            void* obj = *(void**)p;
            ((void (__stdcall*)(void*, void*))fn)(obj, result);
            p += 8;
        } while (p != e);
    }
    *(void**)result = first;
    *((void**)result + 1) = last;
}
