// from server: 69% by atomic.potato
struct VTextureIdHolder {
    char pad_000[0x144];
    char m_flag;
    char pad_145[0xB];
    void* m_ptr;
    void release();
};

extern "C" void __stdcall sub_006f2f60(void*);
extern "C" void __fastcall sub_004a5c00(void*);

void VTextureIdHolder::release()
{
    if (m_ptr) {
        sub_006f2f60(m_ptr);
        sub_004a5c00(&m_ptr);
    }
}

void __fastcall func_005f6160(VTextureIdHolder* self, int, int type)
{
    if (type == 0xc197f8) {
        if (self->m_flag == 0) {
            self->release();
        }
    }
}
