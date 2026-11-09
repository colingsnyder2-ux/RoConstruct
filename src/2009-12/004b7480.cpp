// from server: 40% by atomic.potato
// roc 2009-12 004b7480  unit: Ogre::RbxMaterialAdapter  size: 201 bytes

struct RbxString {
    char pad[4];
    char* ptr;
    unsigned int len;
    unsigned int cap;
};

struct RbxMaterialAdapter {
    char pad0[0x14];
    int hasName;
};

extern "C" int __stdcall isalpha(int c);
extern "C" void* __stdcall sub_98b578(void*, const void*, int);
extern "C" void* __stdcall sub_98b59c(void*, void*, void*, void*);
extern "C" void __stdcall sub_98b6e4(void*);
extern "C" void __stdcall sub_98b6f0(void*, void*);

RbxString* __fastcall RbxMaterialAdapter_GetName(RbxMaterialAdapter* self, void* edx, RbxString* out, RbxString* name);

RbxString* __fastcall RbxMaterialAdapter_GetName(RbxMaterialAdapter* self, void* edx, RbxString* out, RbxString* name)
{
    RbxString* result = out;
    if (self->hasName != 0) {
        char* p;
        if (name->cap >= 0x10)
            p = name->ptr;
        else
            p = (char*)name + 4;
        if (isalpha((unsigned char)p[0]) && p[1] == ':')
            goto copy;
        if (p[0] == '/')
            goto copy;
        if (p[0] == '\\')
            goto copy;
        {
            RbxString tmp;
            sub_98b578(&tmp, self, '/');
            sub_98b59c(out, &tmp, name, 0);
            sub_98b6e4(&tmp);
        }
        return result;
    }
copy:
    sub_98b6f0(out, name);
    return result;
}
