// from server: 100% by colin
struct Geometry {
    char pad0[8];
    int m_field8;
    int m_fieldC;
};

void sub_005b4630(Geometry* self, int* a, int* b);

void f(Geometry* self)
{
    int r = ((int (__thiscall*)(Geometry*))*(int*)(*(int*)self + 0xc))(self);
    if (r == 0) {
        int* p1 = (int*)(self->m_fieldC + 0x10);
        int* p2 = (int*)(self->m_field8 + 0x10);
        sub_005b4630(self, p2, p1);
    } else {
        int* p1 = (int*)(self->m_fieldC + 8);
        int* p2 = (int*)(self->m_field8 + 8);
        sub_005b4630(self, p2, p1);
    }
}
