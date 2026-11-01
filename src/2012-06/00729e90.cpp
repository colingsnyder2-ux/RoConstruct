// from server: 22% by Intel
struct Workspace {
    int dummy;
};

extern "C" int __stdcall sub_726360(int);
extern "C" int __cdecl sub_720F50(int, int, int, int, int, int, int);
extern "C" int __stdcall sub_729040(int, int);

int __cdecl Workspace_Constructor(Workspace* this_ptr, int a2, int a3, int a4, int a5, int a6, int a7)
{
    int v10 = 0;
    int v14 = 0;
    int v54 = 0;
    int v58 = 0;
    int v60 = 0;
    int v64 = 0;
    int v68 = 0;
    int v72 = 0;
    int v76 = 0;
    int v80 = 0;
    int v84 = 0;
    int v88 = 0;
    int v92 = 0;
    int v96 = 0;
    int v100 = 0;
    int v104 = 0;
    int v108 = 0;
    int v112 = 0;
    int v116 = 0;
    int v120 = 0;
    int v124 = 0;
    int v128 = 0;
    int v132 = 0;
    int v136 = 0;
    int v140 = 0;
    int v144 = 0;
    int v148 = 0;
    int v152 = 0;
    int v156 = 0;

    sub_726360(a2);

    int* stack_buffer = &v54;
    int v160 = 0x7891B0;
    int v164 = 0;
    v54 = 0;
    v58 = 0;
    v60 = a3;
    v64 = a4;
    v68 = 0xDAE608;
    v72 = 0;
    v76 = 1;

    int eax = sub_720F50(v54, v58, v60, v64, v68, v72, v76);
    int edx = eax;
    edx = -edx;
    edx = (edx - edx) & 0xDAE608;
    v54 = edx;

    int v168 = *(int*)a2;
    sub_729040(v168, 0xBA5660);

    return 0;
}
