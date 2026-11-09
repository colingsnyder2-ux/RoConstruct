// from server: 46% by atomic.potato
struct RBX_FileMeshDataV2 {
    void f_0072cd10(void* first, void* last);
void sub_00676210(void*);
};



void RBX_FileMeshDataV2::f_0072cd10(void* first, void* last)
{
    char* p = (char*)first;
    while (p != last) {
        sub_00676210(p + 8);
        p = *(char**)p;
    }
}
