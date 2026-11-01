// from server: 83% by atomic.potato
struct CXTPCustomizeSheet {
    char pad0[0x94];
    int field_94;
    char pad1[0x11c];
    void* field_1b4;
    char pad2[0x4];
    void* field_b8;
};

extern "C" void __stdcall sub_7f3ae8(int);
extern "C" void* __stdcall sub_7f4730(int, int);
extern "C" void __stdcall sub_7f3ede(void*);
void* __fastcall sub_83fe70(CXTPCustomizeSheet* self);

void __fastcall sub_83ff50(CXTPCustomizeSheet* self)
{
    sub_7f3ae8(1);
    void* p = sub_7f4730(self->field_94, 0x69);
    sub_7f3ede(p);
    void* cb = sub_83fe70(self);
    *(int*)(*(int*)((char*)cb + 0x74) + 0x28) = self->field_94;
}
