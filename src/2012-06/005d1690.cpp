// from server: 49% by Intel
struct SceneUpdater {
    int f(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8,
          int a9, int a10, int a11, int a12, int a13, int a14, int a15, float a16);
};

int SceneUpdater::f(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8,
                    int a9, int a10, int a11, int a12, int a13, int a14, int a15, float a16)
{
    int* this_ptr = (int*)this;
    this_ptr[1] = a2;
    this_ptr[2] = a1;
    this_ptr[3] = a3;
    this_ptr[4] = a4;
    this_ptr[5] = a11;
    this_ptr[6] = a12;
    this_ptr[7] = a5;
    this_ptr[8] = a6;
    this_ptr[9] = a13;
    this_ptr[10] = a7;
    this_ptr[11] = a8;
    *(float*)(this_ptr + 9) = a16;
    this_ptr[0] = 0xB81BD0;
    this_ptr[13] = a9;
    this_ptr[14] = a10;
    return 0;
}
