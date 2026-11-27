// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// from server: 93% by tajop
// roc 2012-06 007a3030  unit: RBX::Controller  size: 236 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007a3030
//
// 007a3030  56                   push esi
// 007a3031  57                   push edi
// 007a3032  8bf9                 mov edi, ecx
// 007a3034  85ff                 test edi, edi
// 007a3036  743f                 je 0x7a3077
// 007a3038  8b4738               mov eax, dword ptr [edi + 0x38]
// 007a303b  85c0                 test eax, eax
// 007a303d  740e                 je 0x7a304d
// 007a303f  8b4838               mov ecx, dword ptr [eax + 0x38]
// 007a3042  85c9                 test ecx, ecx
// 007a3044  7409                 je 0x7a304f
// 007a3046  e895d1cfff           call 0x4a01e0
// 007a304b  eb02                 jmp 0x7a304f
// 007a304d  8bc7                 mov eax, edi
// 007a304f  85c0                 test eax, eax
// 007a3051  7424                 je 0x7a3077
// 007a3053  6a00                 push 0
// 007a3055  680851d600           push 0xd65108
// 007a305a  68e801d600           push 0xd601e8
// 007a305f  6a00                 push 0
// 007a3061  50                   push eax
// 007a3062  e8e1031e00           call 0x983448
// 007a3067  83c414               add esp, 0x14
// 007a306a  85c0                 test eax, eax
// 007a306c  7409                 je 0x7a3077
// 007a306e  8bc8                 mov ecx, eax
// 007a3070  e86bb3d1ff           call 0x4be3e0
// 007a3075  eb02                 jmp 0x7a3079
// 007a3077  33c0                 xor eax, eax
// 007a3079  8d8850010000         lea ecx, [eax + 0x150]
// 007a307f  8b01                 mov eax, dword ptr [ecx]
// 007a3081  8b5004               mov edx, dword ptr [eax + 4]
// 007a3084  ffd2                 call edx
// 007a3086  8bf0                 mov esi, eax
// 007a3088  e8a304caff           call 0x443530
// 007a308d  83b88c00000003       cmp dword ptr [eax + 0x8c], 3
// 007a3094  7520                 jne 0x7a30b6
// 007a3096  80b89600000000       cmp byte ptr [eax + 0x96], 0
// 007a309d  7517                 jne 0x7a30b6
// 007a309f  8b442410             mov eax, dword ptr [esp + 0x10]
// 007a30a3  80780600             cmp byte ptr [eax + 6], 0
// 007a30a7  7407                 je 0x7a30b0
// 007a30a9  b801000000           mov eax, 1
// 007a30ae  eb1f                 jmp 0x7a30cf
// 007a30b0  0fb64007             movzx eax, byte ptr [eax + 7]
// 007a30b4  eb15                 jmp 0x7a30cb
// 007a30b6  8b442410             mov eax, dword ptr [esp + 0x10]
// 007a30ba  80780200             cmp byte ptr [eax + 2], 0
// 007a30be  7407                 je 0x7a30c7
// 007a30c0  b801000000           mov eax, 1
// 007a30c5  eb08                 jmp 0x7a30cf
// 007a30c7  0fb64003             movzx eax, byte ptr [eax + 3]
// 007a30cb  f7d8                 neg eax
// 007a30cd  1bc0                 sbb eax, eax
// 007a30cf  83be4801000006       cmp dword ptr [esi + 0x148], 6
// 007a30d6  89442410             mov dword ptr [esp + 0x10], eax
// 007a30da  7431                 je 0x7a310d
// 007a30dc  85c0                 test eax, eax
// 007a30de  742d                 je 0x7a310d
// 007a30e0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007a30e4  dd4008               fld qword ptr [eax + 8]
// 007a30e7  51                   push ecx
// 007a30e8  d88fb8000000         fmul dword ptr [edi + 0xb8]
// 007a30ee  8bce                 mov ecx, esi
// 007a30f0  da4c2414             fimul dword ptr [esp + 0x14]
// 007a30f4  d80d80efb500         fmul dword ptr [0xb5ef80]
// 007a30fa  d91c24               fstp dword ptr [esp]
// 007a30fd  e8ce8aeeff           call 0x68bbd0
// 007a3102  ff87b4000000         inc dword ptr [edi + 0xb4]
// 007a3108  5f                   pop edi
// 007a3109  5e                   pop esi
// 007a310a  c20800               ret 8
// 007a310d  c787b400000000000000 mov dword ptr [edi + 0xb4], 0
// 007a3117  5f                   pop edi
// 007a3118  5e                   pop esi
// 007a3119  c20800               ret 8

extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);
extern "C" char g_d601e8[];
extern "C" char g_d65108[];
extern "C" const float g_b5ef80;

struct Instance {
    char pad0[0x38];
    Instance* parent;
    Instance* getRootAncestor();
};

struct Camera {
    char pad0[0x148];
    int cameraType;
    void apply(float value);
};

struct CameraHolder {
    virtual void slot0();
    virtual Camera* get();
};

struct Workspace {
    char pad0[0x150];
};

struct DataModel {
    Workspace* getWorkspace();
};

struct Settings {
    char pad0[0x8c];
    int mode;
    char pad1[6];
    char flag;
};

extern "C" Settings* __cdecl sub_443530();

struct StepEvent {
    char pad0[8];
    double dt;
};

struct InputState {
    char pad0[2];
    bool a;
    bool b;
    char pad1[2];
    bool c;
    bool d;
};

struct Controller : Instance {
    char pad1[0xb4 - 0x3c];
    int count;
    float speed;
    void method(const StepEvent* e, const InputState* in);
};

void Controller::method(const StepEvent* e, const InputState* in)
{
    Workspace* ws;
    Instance* root;
    DataModel* dm;
    if (!this) goto none;
    {
        Instance* p = parent;
        if (p) {
            Instance* q = p->parent;
            if (q) p = q->getRootAncestor();
            root = p;
        } else {
            root = this;
        }
    }
    if (!root) goto none;
    dm = (DataModel*)__RTDynamicCast(root, 0, g_d601e8, g_d65108, 0);
    if (dm) {
        ws = dm->getWorkspace();
    } else {
none:
        ws = 0;
    }
    Camera* cam = ((CameraHolder*)((char*)ws + 0x150))->get();
    Settings* s = sub_443530();
    int v;
    if (s->mode == 3 && s->flag == 0) {
        v = in->c ? 1 : (in->d ? -1 : 0);
    } else {
        v = in->a ? 1 : (in->b ? -1 : 0);
    }
    if (cam->cameraType != 6 && v != 0) {
        cam->apply((float)e->dt * speed * v * g_b5ef80);
        count++;
        return;
    }
    count = 0;
}
