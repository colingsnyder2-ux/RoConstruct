// from server: 100% by colin
struct BoundPropGetSet {
    void* vtable;
    void* field4;
    void setVtable();
};

void BoundPropGetSet::setVtable() {
    *(void**)((char*)this + 4) = (void*)0xa1ac90;
}
