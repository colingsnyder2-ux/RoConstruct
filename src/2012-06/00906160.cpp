// from server: 43% by atomic.potato
struct IndexedMesh {
    char pad0[0xc];
    int count;
    char pad1[0x10];
    IndexedMesh* back;
    void setBack(IndexedMesh*);
    void removeChild(IndexedMesh*);
    void addChild(IndexedMesh*);
    void clearChildren();
    IndexedMesh* getChild(int);
    void update();
};

extern "C" {
    int __stdcall sub_5A3210(int, int);
    void __stdcall sub_905D50(void*);
    void __stdcall sub_905FD0();
    void __stdcall sub_9060C0();
    void __stdcall sub_961440();
    void __stdcall sub_972290(int, int);
}

extern unsigned char byte_E580B3;
extern void* ptr_E5809C;

void IndexedMesh::setBack(IndexedMesh* p) {
    if (p == this->back) return;
    if (this->back) {
        sub_905FD0();
        sub_961440();
        while (this->count > 0) {
            int idx = this->count - 1;
            IndexedMesh* child = (IndexedMesh*)sub_5A3210((int)&this->pad0[0], idx);
            if (byte_E580B3) {
                if (child->back != this) {
                    if (ptr_E5809C) {
                        if (!((char (__stdcall*)(int, int, int))ptr_E5809C)(0x4e, 0xbf2cb0, 0xbf30c0)) {
                            sub_972290(byte_E580B3, 0xbf3030);
                        }
                    } else {
                        sub_972290(byte_E580B3, 0xbf3030);
                    }
                }
            }
            sub_961440();
        }
    }
    this->back = p;
    if (p) {
        if (p->back) {
            IndexedMesh* b = p->back;
            if (b->back) {
                sub_961440();
            } else {
                sub_905D50(b);
                sub_961440();
            }
        }
        for (int i = 0; i < p->count; i++) {
            IndexedMesh* child = (IndexedMesh*)sub_5A3210((int)&p->pad0[0], i);
            sub_9060C0();
        }
    }
}
