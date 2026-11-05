// from server: 23% by colin
// roc 2007-08 00409660  unit: VCApp::?$CComObject  size: 598 bytes

struct VCComObject {
    int CreateInstance(int a, int b, int c);
};

extern "C" void __stdcall SysFreeString(void*);
extern "C" int __stdcall SetForegroundWindow(void*);

extern "C" int __cdecl sub_408D90(int, void*);
extern "C" int __cdecl sub_408C00(void*, int);
extern "C" int __cdecl sub_409310(int);
extern "C" int __cdecl sub_429220(int, int, int);
extern "C" int __cdecl sub_44A010();
extern "C" int __cdecl sub_62FF02();
extern "C" int __cdecl sub_62FF38(int, int);
extern "C" int __cdecl sub_62FF3E();
extern "C" int __cdecl sub_62FF44();
extern "C" int __cdecl sub_62FF4A();
extern "C" int __cdecl sub_62FF50();

int VCComObject::CreateInstance(int a, int b, int c)
{
    int v14 = 0;
    int v28 = 0;
    int v24 = 0;
    int v20 = 0;
    int v1c = 0;
    int v18 = 0;
    int v10 = 0;
    int v8 = 0;
    int v4 = 0;

    sub_62FF44();
    sub_62FF3E();

    sub_408D90(a, &v14);

    int esi = sub_409310(a - 16);
    if (esi != 0) {
        SysFreeString((void*)v14);
        if (v24 != 0) {
            *(int*)(v24 + 4) = v28;
        }
        if (v1c != 0) {
            sub_62FF38(v20, 0);
        }
        return esi;
    }

    int eax = sub_62FF02();
    int ecx = *(int*)(eax + 4);

    if (b == 0) {
        int r = sub_408C00(&v8, 0);
        if (r != 0) {
            sub_429220(0x790290, 0x7852B8, r);
            SysFreeString((void*)v14);
            if (v24 != 0) {
                *(int*)(v24 + 4) = v28;
            }
            if (v1c != 0) {
                sub_62FF38(v20, 0);
            }
            return (int)esi;
        }
        int edi = v8;
        goto L_4097C5;
    }

    if (b == 2) {
        int obj = sub_44A010();
        int* vtbl = *(int**)obj;
        int edi = *(int*)(obj + 0x78);
        int (__stdcall *fn)(void*) = (int (__stdcall *)(void*))vtbl[0x68/4];
        int r = fn((void*)obj);
        if (r != 0) {
            int* vtbl2 = *(int**)obj;
            int (__stdcall *fn2)(void*, int*) = (int (__stdcall *)(void*, int*))vtbl2[0x6c/4];
            int r2 = fn2((void*)obj, &r);
            if (r2 != 0) {
                sub_62FF50();
                sub_62FF4A();
                SetForegroundWindow(*(void**)(r2 + 0x20));
            }
        }
        if (edi != 0) {
            int* vtbl3 = *(int**)edi;
            int (__stdcall *fn3)(void*) = (int (__stdcall *)(void*))vtbl3[4/4];
            fn3((void*)edi);
        }
        if (c != 0) {
            *(int*)c = edi;
            if (edi != 0) {
                int* vtbl4 = *(int**)edi;
                int (__stdcall *fn4)(void*) = (int (__stdcall *)(void*))vtbl4[4/4];
                fn4((void*)edi);
            }
            esi = 0;
        } else {
            esi = (int)0x80004003;
        }
        if (edi != 0) {
            int* vtbl5 = *(int**)edi;
            int (__stdcall *fn5)(void*) = (int (__stdcall *)(void*))vtbl5[8/4];
            fn5((void*)edi);
        }
        SysFreeString((void*)v14);
        if (v24 != 0) {
            *(int*)(v24 + 4) = v28;
        }
        if (v1c != 0) {
            sub_62FF38(v20, 0);
        }
        return esi;
    }

    sub_429220(0x790290, 0x7852D4, 0x57);
    SysFreeString((void*)v14);
    if (v24 != 0) {
        *(int*)(v24 + 4) = v28;
    }
    if (v1c != 0) {
        sub_62FF38(v20, 0);
    }
    return (int)esi;

L_4097C5:
    {
    int edi = v8;
    if (edi != 0) {
        int* vtbl = *(int**)edi;
        int (__stdcall *fn)(void*) = (int (__stdcall *)(void*))vtbl[4/4];
        fn((void*)edi);
    }
    if (c != 0) {
        *(int*)c = edi;
        if (edi != 0) {
            int* vtbl2 = *(int**)edi;
            int (__stdcall *fn2)(void*) = (int (__stdcall *)(void*))vtbl2[4/4];
            fn2((void*)edi);
        }
        esi = 0;
    } else {
        esi = (int)0x80004003;
    }
    if (edi != 0) {
        int* vtbl3 = *(int**)edi;
        int (__stdcall *fn3)(void*) = (int (__stdcall *)(void*))vtbl3[8/4];
        fn3((void*)edi);
    }
    SysFreeString((void*)v14);
    if (v24 != 0) {
        *(int*)(v24 + 4) = v28;
    }
    if (v1c != 0) {
        sub_62FF38(v20, 0);
    }
    return esi;
    }
}
