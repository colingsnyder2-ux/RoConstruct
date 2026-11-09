// from server: 39% by TrollStein
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall _invalid_parameter_noinfo();

struct Vec3 {
    float x, y, z;
};

struct RefCounted {
    void* vptr;
    long refCount;
    long weakCount;
};

struct Camera {
    char pad[0x228];
    void* cameraThing;
};

struct Workspace {
    char pad[0xc];
    Camera* camera;
};

struct Command {
    void* vptr;
    Workspace* workspace;
};

struct SomeList {
    void* vptr;
    void* begin;
    void* end;
};

struct SomeContainer {
    char pad[0xf4];
    SomeList list;
};

struct SomeObj {
    char pad[0xf8];
    void* begin;
    void* end;
};

struct SomeManager {
    char pad[0x228];
    void* thing;
};

extern "C" void* __cdecl sub_5623C0(void* self, int idx);
extern "C" void* __cdecl sub_55E610(void* self);
extern "C" void* __cdecl sub_5307A0(void* self, void* arg);
extern "C" void* __cdecl sub_5095D0(void* self, void* arg);
extern "C" void* __cdecl sub_50A500();
extern "C" void* __cdecl sub_59B6C0(void* self);
extern "C" void* __cdecl sub_59B7F0(void* self, void* arg);
extern "C" void* __cdecl sub_561B10(void* self, int arg);
extern "C" void* __cdecl sub_58C810(void* self);
extern "C" void* __cdecl sub_4108B0(void* self, int arg);

extern float g_797e9c;
extern float g_8bd12c;
extern float g_8bd130;
extern float g_8bd134;
extern int g_8bd138;

void __stdcall Command_doIt(Command* self, void* dataState)
{
    Vec3 pos;
    Vec3 sum;
    int i;
    int count;
    SomeObj* obj;
    SomeContainer* container;
    SomeManager* mgr;
    RefCounted* rc;
    void* tmp;

    obj = (SomeObj*)sub_5623C0(&self->workspace, 1);
    if (obj->begin != 0) {
        if ((((char*)obj->end - (char*)obj->begin) >> 2) >= 1) {
            container = (SomeContainer*)sub_5623C0(&self->workspace, 1);
            container = (SomeContainer*)((char*)container + 0xf4);
            if (container->list.begin == 0 || ((char*)container->list.end - (char*)container->list.begin) >> 2 == 0) {
                _invalid_parameter_noinfo();
            }
            {
                void** p = (void**)container->list.begin;
                void* v = *p;
                void* vt = *(void**)v;
                void (*fn)(void*, void*) = *(void (**)(void*, void*))((char*)vt + 0x58);
                fn(v, &pos);
            }
            sub_55E610(container);
            count = (int)sub_55E610(container);
            if (count > 1) {
                i = 1;
                do {
                    if (container->list.begin == 0 || ((char*)container->list.end - (char*)container->list.begin) >> 2 <= 1) {
                        _invalid_parameter_noinfo();
                    }
                    {
                        void** p = (void**)((char*)container->list.begin + 4);
                        void* v = *p;
                        void* vt = *(void**)v;
                        void (*fn)(void*, void*) = *(void (**)(void*, void*))((char*)vt + 0x58);
                        fn(v, &sum);
                    }
                    sub_5307A0(&pos, &sum);
                    i++;
                    count = (int)sub_55E610(container);
                } while (i < count);
            }
            pos.x = (pos.x + sum.x) * g_797e9c;
            pos.y = (pos.y + sum.y) * g_797e9c;
            pos.z = (pos.z + sum.z) * g_797e9c;
        } else {
            goto use_global;
        }
    } else {
use_global:
        if ((g_8bd138 & 1) == 0) {
            g_8bd138 |= 1;
            g_8bd12c = 0.0f;
            g_8bd130 = 0.0f;
            g_8bd134 = 0.0f;
        }
        pos.x = g_8bd12c;
        pos.y = g_8bd130;
        pos.z = g_8bd134;
    }

    mgr = (SomeManager*)((char*)self->workspace->camera + 0x228);
    {
        void* v = mgr->thing;
        void* vt = *(void**)v;
        void* (*fn)(void*, int) = *(void* (**)(void*, int))((char*)vt + 4);
        void* r = fn(v, 0);
        sub_59B6C0(r);
    }
    tmp = sub_50A500();
    sub_5095D0(&pos, tmp);

    {
        void* v = mgr->thing;
        void* vt = *(void**)v;
        void* (*fn)(void*, int) = *(void* (**)(void*, int))((char*)vt + 4);
        void* r = fn(v, 0);
        sub_59B7F0(r, &pos);
    }

    {
        void* r = sub_561B10(self->workspace->camera, 0xb);
        sub_58C810(r);
    }

    rc = (RefCounted*)dataState;
    sub_4108B0(rc, -1);
    {
        void* vt = *(void**)rc;
        void (*fn)(void*, int) = *(void (**)(void*, int))((char*)vt + 4);
        rc->refCount = -1;
        fn(rc, 1);
    }
    sub_4108B0(rc, -1);
    {
        void* vt = *(void**)rc;
        void (*fn)(void*, int) = *(void (**)(void*, int))((char*)vt + 4);
        rc->refCount = -1;
        fn(rc, 1);
    }

    if (rc != 0) {
        if (_InterlockedExchangeAdd(&rc->refCount, -1) == 1) {
            void* vt = *(void**)rc;
            void (*fn)(void*) = *(void (**)(void*))((char*)vt + 4);
            fn(rc);
            if (_InterlockedExchangeAdd(&rc->weakCount, -1) == 1) {
                void* vt2 = *(void**)rc;
                void (*fn2)(void*) = *(void (**)(void*))((char*)vt2 + 8);
                fn2(rc);
            }
        }
    }
}
