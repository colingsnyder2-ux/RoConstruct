// from server: 42% by Intel
struct CScriptReviewView {
    int UpdateItemsJob(void* param);
};

extern "C" int __stdcall sub_972290(int, int);
extern "C" int __stdcall PostMessageA(int, unsigned int, int, int);
extern "C" int __stdcall SetEvent(int);
extern "C" int __stdcall WaitForSingleObject(int, int);

int CScriptReviewView::UpdateItemsJob(void* param) {
    double val = *(double*)((char*)this + 0x230);
    val += *(double*)((char*)param + 8);
    *(double*)((char*)this + 0x238) = val;

    int state = *(int*)((char*)this + 0x228);
    if (state == 0) {
        if (*(char*)0xE580B3 == 0) {
            int func = *(int*)0xE5809C;
            if (func) {
                int result = ((int(__stdcall*)(int, int, int))func)(0x95, 0xB61280, 0xB53DD8);
                if (result) return 1;
            }
            int v = *(unsigned char*)0xE580B3;
            sub_972290(0xB61338, v);
        }
        int ptr = *(int*)((char*)this + 0x218);
        *(int*)((char*)this + 0x228) = 0;
        PostMessageA(*(int*)((char*)ptr + 0x20), 0x465, 0, 0);
        return 1;
    }
    if (state == 1) {
        SetEvent(*(int*)((char*)this + 0x21C));
        WaitForSingleObject(*(int*)((char*)this + 0x220), -1);
        *(int*)((char*)this + 0x228) = 2;
        return 1;
    }
    if (state == 2) {
        if (*(char*)0xE580B3 != 0) {
            int func = *(int*)0xE5809C;
            if (func) {
                int result = ((int(__stdcall*)(int, int, int))func)(0x9B, 0xB61280, 0xB51600);
                if (result) return 1;
            }
            int v = *(unsigned char*)0xE580B3;
            sub_972290(0xB612D0, v);
        }
    }
    return 1;
}
