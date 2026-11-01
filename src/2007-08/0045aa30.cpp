// from server: 90% by colin
struct S {
    char pad[0x58];
    int mode;
    char pad2[0x0C];
    int handle;
    char pad3[0x08];
    int field_68;
    char sub_45a880();
    char sub_45a800();
    int sub_450ec0();
    int sub_52dce0(void*);
    void f();
};

void S::f()
{
    char result;
    if (this->mode == 2)
        result = this->sub_45a880();
    else
        result = this->sub_45a800();
    if (!result) {
        int ecx = this->handle;
        if (ecx != 0) {
            S* p = (S*)((char*)this + 0x54);
            int r = ((S*)ecx)->sub_450ec0();
            if (r != 0) {
                ((S*)r)->sub_52dce0(p);
            }
        }
    }
}
