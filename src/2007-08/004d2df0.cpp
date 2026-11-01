// from server: 68% by colin
struct G3D_VVector3_Table {
    void construct(float);
};

extern double G3D_VVector3_Table_time;
extern int G3D_VVector3_Table_time_init;
extern int G3D_VVector3_Table_count;
extern void* G3D_VVector3_Table_clock;

void G3D_VVector3_Table::construct(float f)
{
    *(int*)((char*)this + 0) = 0x797984;
    *(int*)((char*)this + 4) = 0;
    *(float*)((char*)this + 0xc) = f;
    *(int*)((char*)this + 8) = 0;
    *(int*)((char*)this + 0) = 0x79f15c;
    if (!(G3D_VVector3_Table_time_init & 1)) {
        G3D_VVector3_Table_time_init |= 1;
        G3D_VVector3_Table_time = *(double*)G3D_VVector3_Table_clock;
    }
    *(float*)((char*)this + 0x10) = (float)G3D_VVector3_Table_time;
    *(int*)((char*)this + 0x14) = 0x79f13c;
    *(int*)((char*)this + 0x18) = 0;
    G3D_VVector3_Table_count += 1;
}
