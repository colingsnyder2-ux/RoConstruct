// from server: 33% by atomic.potato
// roc 2011-06 007fe100  unit: RBX::VCEvent::?$sp_counted_impl_p  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007fe100

struct S {
};

void __cdecl f(void* a, void* b, void* c, void* d) {
    char* ecx = (char*)b;
    char* edx = (char*)c;
    if (ecx != edx) {
        do {
            void* eax = d;
            void* v = *(void**)ecx;
            bool r = ((bool (__cdecl*)(void*, void*))d)(v, eax);
            ecx = (char*)b;
            if (r) break;
            ecx += 8;
            b = ecx;
        } while (ecx != edx);
    }
    *(void**)a = ecx;
}
