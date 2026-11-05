// from server: 97% by Intel
struct OgreRbxMeshPartAdapter {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    void func();
};

void OgreRbxMeshPartAdapter::func() {
    int* edx = reinterpret_cast<int*>(field_8);
    int* esi = reinterpret_cast<int*>(field_C);
    if (edx != esi) {
        int* eax = esi;
        if (esi) {
            int* edi;
            do {
                edi = reinterpret_cast<int*>(*eax);
                *edx = reinterpret_cast<int>(edi);
                edi = reinterpret_cast<int*>(*(eax + 1));
                *(edx + 1) = reinterpret_cast<int>(edi);
                eax += 2;
                edx += 2;
            } while (eax != esi);
        }
        field_C = reinterpret_cast<int>(edx);
    }
}
