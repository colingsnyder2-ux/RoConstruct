// from server: 59% by colin
extern "C" long __stdcall RegQueryValueExA(void*, const char*, unsigned long*, unsigned long*, unsigned char*, unsigned long*);

struct CIDEDocManager {
    int func_00448420(char* a, unsigned long* b, unsigned long* c);
};

int CIDEDocManager::func_00448420(char* a, unsigned long* b, unsigned long* c)
{
    unsigned long type = *c;
    unsigned long size = *b;
    unsigned char* data = (unsigned char*)a;
    long result;
    *c = 0;
    result = RegQueryValueExA(*(void**)this, 0, 0, &type, data, &size);
    if (result != 0)
        return result;
    if (type == 1 || type == 2) {
        if (a != 0) {
            if (data != 0) {
                if (data[size - 1] != 0) {
                    *c = size;
                    return 0;
                }
            } else {
                *a = 0;
            }
        }
        *c = size;
        return 0;
    }
    return 13;
}
