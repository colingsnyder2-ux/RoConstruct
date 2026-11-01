// from server: 100% by atomic.potato
struct CInsertObjectDialog {
    char pad[0x74];
    void* field_74;
    void destruct();
};

extern "C" void (__fastcall *sub_77ddbc)(void*);
extern "C" void __fastcall sub_630412(void*);

void CInsertObjectDialog::destruct() {
    *(void**)this = (void*)0x787b84;
    sub_77ddbc(&field_74);
    sub_630412(this);
}
