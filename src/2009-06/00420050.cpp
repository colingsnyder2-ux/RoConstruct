// from server: 91% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00424f80  unit: CRobloxTreeCtrlNode  size: 199 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00424f80
//
// 00424f80  57                   push edi
// 00424f81  8bf9                 mov edi, ecx
// 00424f83  83bf8000000000       cmp dword ptr [edi + 0x80], 0
// 00424f8a  0f84b5000000         je 0x425045
// 00424f90  8b4f58               mov ecx, dword ptr [edi + 0x58]
// 00424f93  8b01                 mov eax, dword ptr [ecx]
// 00424f95  8b9050010000         mov edx, dword ptr [eax + 0x150]
// 00424f9b  ffd2                 call edx
// 00424f9d  85c0                 test eax, eax
// 00424f9f  0f8488000000         je 0x42502d
// 00424fa5  8b470c               mov eax, dword ptr [edi + 0xc]
// 00424fa8  8b4f58               mov ecx, dword ptr [edi + 0x58]
// 00424fab  50                   push eax
// 00424fac  8b01                 mov eax, dword ptr [ecx]
// 00424fae  8b9050010000         mov edx, dword ptr [eax + 0x150]
// 00424fb4  ffd2                 call edx
// 00424fb6  8bc8                 mov ecx, eax
// 00424fb8  e8f3feffff           call 0x424eb0
// 00424fbd  84c0                 test al, al
// 00424fbf  746c                 je 0x42502d
// 00424fc1  55                   push ebp
// 00424fc2  8b2d142e8000         mov ebp, dword ptr [0x802e14]
// 00424fc8  56                   push esi
// 00424fc9  8b775c               mov esi, dword ptr [edi + 0x5c]
// 00424fcc  85f6                 test esi, esi
// 00424fce  742d                 je 0x424ffd
// 00424fd0  53                   push ebx
// 00424fd1  8a5e55               mov bl, byte ptr [esi + 0x55]
// 00424fd4  c6465501             mov byte ptr [esi + 0x55], 1
// 00424fd8  8b8680000000         mov eax, dword ptr [esi + 0x80]
// 00424fde  8b4e58               mov ecx, dword ptr [esi + 0x58]
// 00424fe1  8b5120               mov edx, dword ptr [ecx + 0x20]
// 00424fe4  50                   push eax
// 00424fe5  6802400000           push 0x4002
// 00424fea  6802110000           push 0x1102
// 00424fef  52                   push edx
// 00424ff0  ffd5                 call ebp
// 00424ff2  885e55               mov byte ptr [esi + 0x55], bl
// 00424ff5  8b765c               mov esi, dword ptr [esi + 0x5c]
// 00424ff8  85f6                 test esi, esi
// 00424ffa  75d5                 jne 0x424fd1
// 00424ffc  5b                   pop ebx
// 00424ffd  8b8780000000         mov eax, dword ptr [edi + 0x80]
// 00425003  8b4f58               mov ecx, dword ptr [edi + 0x58]
// 00425006  6a00                 push 0
// 00425008  50                   push eax
// 00425009  50                   push eax
// 0042500a  83c154               add ecx, 0x54
// 0042500d  e8be7f2b00           call 0x6dcfd0
// 00425012  8b8780000000         mov eax, dword ptr [edi + 0x80]
// 00425018  8b4f58               mov ecx, dword ptr [edi + 0x58]
// 0042501b  8b5120               mov edx, dword ptr [ecx + 0x20]
// 0042501e  50                   push eax
// 0042501f  6a00                 push 0
// 00425021  6814110000           push 0x1114
// 00425026  52                   push edx
// 00425027  ffd5                 call ebp
// 00425029  5e                   pop esi
// 0042502a  5d                   pop ebp
// 0042502b  5f                   pop edi
// 0042502c  c3                   ret 
// 0042502d  8b4f58               mov ecx, dword ptr [edi + 0x58]
// 00425030  8b01                 mov eax, dword ptr [ecx]
// 00425032  8b9780000000         mov edx, dword ptr [edi + 0x80]
// 00425038  8b804c010000         mov eax, dword ptr [eax + 0x14c]
// 0042503e  6a02                 push 2
// 00425040  6a00                 push 0
// 00425042  52                   push edx
// 00425043  ffd0                 call eax
// 00425045  5f                   pop edi
// 00425046  c3                   ret 

extern "C" long (__stdcall *SendMessageA)(void *, unsigned int, unsigned int, long);
extern "C" void __cdecl _ReadWriteBarrier();
#pragma intrinsic(_ReadWriteBarrier)

struct Context {
    bool contains(void *);
};

struct Tree {
    void update(int, int, int);
};

#define V(n) virtual void v##n();
struct Control {
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
    V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
    V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49)
    V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59)
    V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67) V(68) V(69)
    V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77) V(78) V(79)
    V(80) V(81) V(82)
    virtual void update(int, int, int);
    virtual Context *context();

    char padding04[28];
    void *window;
    char padding24[48];
    Tree tree;
};
#undef V

struct Node {
    char padding00[12];
    void *object;
    char padding10[69];
    volatile unsigned char flag;
    char padding56[2];
    Control *control;
    Node *next;
    char padding60[32];
    int item;

    void update();
};

void Node::update()
{
    if (item) {
        bool accepted = false;
        if (control->context()) {
            void *value = object;
            accepted = control->context()->contains(value);
        }
        if (accepted) {
            long (__stdcall *send)(void *, unsigned int, unsigned int, long) =
                SendMessageA;
            Node *node = next;
            while (node) {
                unsigned char saved = node->flag;
                node->flag = 1;
                _ReadWriteBarrier();
                int value = node->item;
                void *window = node->control->window;
                send(window, 0x1102, 0x4002, value);
                node->flag = saved;
                node = node->next;
            }
            control->tree.update(item, item, 0);
            int value = item;
            void *window = control->window;
            send(window, 0x1114, 0, value);
        } else {
            control->update(item, 0, 2);
        }
    }
}
