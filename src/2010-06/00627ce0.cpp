// from server: 39% by atomic.potato
extern "C" int __stdcall rand(void);
extern "C" void __stdcall _invalid_parameter_noinfo(void);

struct Node {
    char pad0[0x18];
    Node* field18;
    char pad1c[0x10];
    int* field2c;
};

struct Iter {
    Node* field0;
    Node* field4;
};

struct Container {
    Node* field0;
    char pad4[0x14];
    Node* field18;
    void __cdecl method(Node* a, Node* b, Iter* out);
};

extern "C" void __stdcall sub_4e5a00(Iter* it);
extern "C" void __stdcall sub_622f80(void);
extern "C" void __stdcall sub_625cd0(void* p);
extern "C" void* __stdcall sub_7a7934(void* p);

void Container::method(Node* a, Node* b, Iter* out)
{
    Node* esi = this->field0;
    Node* ebx = this->field18->field18;
    Node* edi;
    int* ecx;
    void* eax;
    float f;

    for (;;) {
        edi = this->field18;
        eax = this->field0;
        if (esi != 0 && esi != eax) {
            _invalid_parameter_noinfo();
        }
        if (ebx == edi) {
            return;
        }
        if (esi == 0) {
            _invalid_parameter_noinfo();
            eax = 0;
            if (ebx == *(Node**)((char*)eax + 0x18)) {
                _invalid_parameter_noinfo();
            }
        } else {
            eax = *(void**)esi;
            if (ebx == *(Node**)((char*)eax + 0x18)) {
                _invalid_parameter_noinfo();
            }
        }
        ecx = *(int**)((char*)ebx + 0x2c);
        if (ecx[2] != 0) {
            sub_4e5a00((Iter*)&esi);
            ebx = *(Node**)((char*)&esi + 4);
            esi = *(Node**)&esi;
            continue;
        }
        f = (float)rand() * *(float*)0xa209e8;
        if (f < *(float*)0xa209ec) {
            sub_4e5a00((Iter*)&esi);
            ebx = *(Node**)((char*)&esi + 4);
            esi = *(Node**)&esi;
            continue;
        }
        if (esi == 0) {
            _invalid_parameter_noinfo();
            eax = 0;
            if (ebx == *(Node**)((char*)eax + 0x18)) {
                _invalid_parameter_noinfo();
            }
        } else {
            eax = *(void**)esi;
            if (ebx == *(Node**)((char*)eax + 0x18)) {
                _invalid_parameter_noinfo();
            }
        }
        edi = *(Node**)((char*)ebx + 0x2c);
        eax = *(void**)edi;
        if (eax != 0) {
            sub_625cd0(sub_7a7934(eax));
            *(void**)edi = 0;
        }
        sub_622f80();
        esi = *(Node**)&esi;
        ebx = *(Node**)((char*)&esi + 4);
    }
}
