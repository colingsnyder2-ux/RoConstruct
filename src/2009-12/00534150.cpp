// from server: 31% by atomic.potato
struct IdSerializer {
    char pad0[0x94];
    int field94;
    void deserialize(void* stream, int* out);
};

struct Helper {
    char __thiscall sub_52eb90(int* p, int a, int b);
};

extern "C" int __stdcall sub_533fa0(void* self, void* stream, int* out);
extern "C" int __stdcall sub_632470();
extern "C" void __stdcall sub_409390(void* self, void* p);
extern "C" void __stdcall sub_7f4878(void* a, void* b);
extern "C" void* __stdcall sub_98b6f4(const char* s);

void IdSerializer::deserialize(void* stream, int* out)
{
    sub_533fa0(pad0 + 0x94, stream, out);
    int v = sub_632470();
    if (*out != v) {
        *(int*)((char*)out + 4) = 0;
        if (!((Helper*)this)->sub_52eb90((int*)((char*)out + 4), 0x18, 1)) {
            char buf[0x20];
            sub_98b6f4("BitStream >> RBX::Guid::Data failed");
            sub_409390(buf, buf);
            sub_7f4878(buf, (void*)0xa904f0);
        }
    } else {
        *(int*)((char*)out + 4) = 0;
    }
}
