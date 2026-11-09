// from server: 48% by Intel
struct VTable0 {
    void (__thiscall *func_194)(void*);
    void (__thiscall *func_17c)(void*);
};

struct VTable1 {
    void (__thiscall *func_0)(void*, int);
};

struct Object0 {
    VTable0* vftable;
};

struct Object1 {
    VTable1* vftable;
};

struct XTP_REPORTRECORDITEM_DRAWARGS {
    Object0* field0;
    Object1* field4;
    int field8;
    int fieldC;

    void __thiscall func_009a63c0(int arg);
};

void __thiscall XTP_REPORTRECORDITEM_DRAWARGS::func_009a63c0(int arg)
{
    Object0* obj0 = this->field0;
    void (__thiscall *vfunc_194)(void*) = obj0->vftable->func_194;
    vfunc_194(obj0);

    Object1* obj1 = this->field4;
    void (__thiscall *vfunc_17c)(void*) = obj0->vftable->func_17c;
    int result = ((int (__thiscall *)(void*))vfunc_17c)(obj0);

    void (__thiscall *vfunc_0)(void*, int) = obj1->vftable->func_0;
    vfunc_0(obj1, result);
}
