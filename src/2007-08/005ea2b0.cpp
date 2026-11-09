// from server: 32% by Intel





extern "C" int __stdcall sub_5e6120(int* out, int val);
extern "C" int __stdcall sub_5b4070(void* thisptr);
extern "C" int __stdcall sub_5e9a30(int* ptr);
extern "C" int __stdcall sub_62fc62(int* arr);

extern "C" void __stdcall sub_77e8f4();

struct FlagStandService {
    char pad_0[0xe8];
    void* field_e8;
    char pad_1[8];
    int field_f0;

    int __stdcall sub_5ea2b0(int* arg_4);
    void sub_77e6d8();
};

int __stdcall FlagStandService::sub_5ea2b0(int* arg_4) {
    int result = 0;
    __try {
        FlagStandService* thisptr = this;
        if (thisptr->field_f0 != 0) {
            void* v1 = thisptr->field_e8;
            void* v2 = *(void**)((char*)v1 + 4);
            void* v3 = *(void**)v1;
            
            if (v1 != 0 || v1 == v2) {
                sub_77e6d8();
            }
            
            if (v3 != v2) {
                if (v1 != 0) {
                    sub_77e6d8();
                }
                if (v3 != *(void**)((char*)v1 + 4)) {
                    sub_77e6d8();
                }
            }
            
            int* v4 = (int*)((char*)v2 + 8);
            int v5 = *(int*)((char*)v4 + 0x294);
            int* v6 = (int*)((char*)v2 + 8);
            int* out = (int*)((char*)thisptr + 0x14);
            
            sub_5e6120(out, v5);
            
            if (v5 == *out) {
                if (v3 == *(void**)((char*)v1 + 4)) {
                    sub_77e6d8();
                }
                sub_5e9a30(v6);
                if (sub_5e9a30(v6) == 0) {
                    if (v3 == *(void**)((char*)v1 + 4)) {
                        sub_77e6d8();
                    }
                    sub_5b4070(v6);
                }
            }
            
            if (v3 == *(void**)((char*)v1 + 4)) {
                sub_77e6d8();
            }
            
            v1 = *(void**)v3;
            result = (int)v1;
        }
        
        int v7 = *(int*)((char*)thisptr + 0x1c);
        int v8 = *(int*)((char*)thisptr + 0x20);
        
        if (v7 == 0) {
            sub_62fc62(arg_4);
        } else {
            int v9 = *arg_4;
            int v10 = v8 - v9;
            int v11 = v10 >> 2;
            
            if (v11 != 0) {
                sub_77e8f4();
                int v12 = 0;
                int v13 = v12 / v11;
                int v14 = *arg_4;
                int v15 = v8 - v14;
                int v16 = v15 >> 2;
                
                if (v13 < v16) {
                    v13 = 0;
                }
                
                int* v17 = (int*)(v14 + v13 * 4);
                if (*v17 == 0) {
                    sub_62fc62(arg_4);
                }
            }
            
            result = *(int*)(*(int*)(*arg_4 + result * 4));
        }
    } __except(1) {
    }
    
    return result;
}
