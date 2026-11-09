// from server: 100% by EspClaude
// from server: 72% by EspClaude
// roc 2009-06 005aac20  unit: seg_005a0000  size: 889 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005aac20
//
// 005aac20  55                   push ebp
// 005aac21  8bec                 mov ebp, esp
// 005aac23  6aff                 push -1
// 005aac25  68a70d8600           push 0x860da7
// 005aac2a  64a100000000         mov eax, dword ptr fs:[0]
// 005aac30  50                   push eax
// 005aac31  64892500000000       mov dword ptr fs:[0], esp
// 005aac38  81eca0000000         sub esp, 0xa0
// 005aac3e  898d58ffffff         mov dword ptr [ebp - 0xa8], ecx
// 005aac44  8b450c               mov eax, dword ptr [ebp + 0xc]
// 005aac47  50                   push eax
// 005aac48  8d4de8               lea ecx, [ebp - 0x18]
// 005aac4b  51                   push ecx
// 005aac4c  8b4d08               mov ecx, dword ptr [ebp + 8]
// 005aac4f  e87c16fdff           call 0x57c2d0
// 005aac54  8b15bc2da400         mov edx, dword ptr [0xa42dbc]
// 005aac5a  83e201               and edx, 1
// 005aac5d  7532                 jne 0x5aac91
// 005aac5f  a1bc2da400           mov eax, dword ptr [0xa42dbc]
// 005aac64  83c801               or eax, 1
// 005aac67  a3bc2da400           mov dword ptr [0xa42dbc], eax
// 005aac6c  c745fc00000000       mov dword ptr [ebp - 4], 0
// 005aac73  b9b02da400           mov ecx, 0xa42db0
// 005aac78  e893100000           call 0x5abd10
// 005aac7d  68606b8900           push 0x896b60
// 005aac82  e874ee1600           call 0x719afb
// 005aac87  83c404               add esp, 4
// 005aac8a  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 005aac91  6a00                 push 0
// 005aac93  8b8d58ffffff         mov ecx, dword ptr [ebp - 0xa8]
// 005aac99  83c124               add ecx, 0x24
// 005aac9c  e8efafedff           call 0x485c90
// 005aaca1  50                   push eax
// 005aaca2  b9b02da400           mov ecx, 0xa42db0
// 005aaca7  e814f3efff           call 0x4a9fc0
// 005aacac  c745e400000000       mov dword ptr [ebp - 0x1c], 0
// 005aacb3  eb09                 jmp 0x5aacbe
// 005aacb5  8b4de4               mov ecx, dword ptr [ebp - 0x1c]
// 005aacb8  83c101               add ecx, 1
// 005aacbb  894de4               mov dword ptr [ebp - 0x1c], ecx
// 005aacbe  8b8d58ffffff         mov ecx, dword ptr [ebp - 0xa8]
// 005aacc4  83c124               add ecx, 0x24
// 005aacc7  e8c4afedff           call 0x485c90
// 005aaccc  3945e4               cmp dword ptr [ebp - 0x1c], eax
// 005aaccf  7d58                 jge 0x5aad29
// 005aacd1  8d55e8               lea edx, [ebp - 0x18]
// 005aacd4  52                   push edx
// 005aacd5  8b45e4               mov eax, dword ptr [ebp - 0x1c]
// 005aacd8  50                   push eax
// 005aacd9  8b8d58ffffff         mov ecx, dword ptr [ebp - 0xa8]
// 005aacdf  83c124               add ecx, 0x24
// 005aace2  e89962fbff           call 0x560f80
// 005aace7  8bc8                 mov ecx, eax
// 005aace9  e87275edff           call 0x482260
// 005aacee  d81d5c3b8b00         fcomp dword ptr [0x8b3b5c]
// 005aacf4  dfe0                 fnstsw ax
// 005aacf6  f6c405               test ah, 5
// 005aacf9  7a0c                 jp 0x5aad07
// 005aacfb  c78554ffffff01000000 mov dword ptr [ebp - 0xac], 1
// 005aad05  eb0a                 jmp 0x5aad11
// 005aad07  c78554ffffff00000000 mov dword ptr [ebp - 0xac], 0
// 005aad11  8b4de4               mov ecx, dword ptr [ebp - 0x1c]
// 005aad14  51                   push ecx
// 005aad15  b9b02da400           mov ecx, 0xa42db0
// 005aad1a  e831100000           call 0x5abd50
// 005aad1f  8a9554ffffff         mov dl, byte ptr [ebp - 0xac]
// 005aad25  8810                 mov byte ptr [eax], dl
// 005aad27  eb8c                 jmp 0x5aacb5
// 005aad29  0fb64518             movzx eax, byte ptr [ebp + 0x18]
// 005aad2d  85c0                 test eax, eax
// 005aad2f  0f841a010000         je 0x5aae4f
// 005aad35  c745e000000000       mov dword ptr [ebp - 0x20], 0
// 005aad3c  eb09                 jmp 0x5aad47
// 005aad3e  8b4de0               mov ecx, dword ptr [ebp - 0x20]
// 005aad41  83c101               add ecx, 1
// 005aad44  894de0               mov dword ptr [ebp - 0x20], ecx
// 005aad47  b9b02da400           mov ecx, 0xa42db0
// 005aad4c  e8df0f0000           call 0x5abd30
// 005aad51  3945e0               cmp dword ptr [ebp - 0x20], eax
// 005aad54  0f8df5000000         jge 0x5aae4f
// 005aad5a  8b55e0               mov edx, dword ptr [ebp - 0x20]
// 005aad5d  52                   push edx
// 005aad5e  b9b02da400           mov ecx, 0xa42db0
// 005aad63  e8e80f0000           call 0x5abd50
// 005aad68  0fb600               movzx eax, byte ptr [eax]
// 005aad6b  85c0                 test eax, eax
// 005aad6d  0f85d7000000         jne 0x5aae4a
// 005aad73  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 005aad76  e815afedff           call 0x485c90
// 005aad7b  8945dc               mov dword ptr [ebp - 0x24], eax
// 005aad7e  8b4ddc               mov ecx, dword ptr [ebp - 0x24]
// 005aad81  83c102               add ecx, 2
// 005aad84  894d8c               mov dword ptr [ebp - 0x74], ecx
// 005aad87  8b55dc               mov edx, dword ptr [ebp - 0x24]
// 005aad8a  83c201               add edx, 1
// 005aad8d  895588               mov dword ptr [ebp - 0x78], edx
// 005aad90  8b45dc               mov eax, dword ptr [ebp - 0x24]
// 005aad93  894584               mov dword ptr [ebp - 0x7c], eax
// 005aad96  8d4d8c               lea ecx, [ebp - 0x74]
// 005aad99  51                   push ecx
// 005aad9a  8d5588               lea edx, [ebp - 0x78]
// 005aad9d  52                   push edx
// 005aad9e  8d4584               lea eax, [ebp - 0x7c]
// 005aada1  50                   push eax
// 005aada2  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 005aada5  e89663fbff           call 0x561140
// 005aadaa  8b4de0               mov ecx, dword ptr [ebp - 0x20]
// 005aadad  51                   push ecx
// 005aadae  8b8d58ffffff         mov ecx, dword ptr [ebp - 0xa8]
// 005aadb4  83c130               add ecx, 0x30
// 005aadb7  e8240d0000           call 0x5abae0
// 005aadbc  8945d0               mov dword ptr [ebp - 0x30], eax
// 005aadbf  8b55d0               mov edx, dword ptr [ebp - 0x30]
// 005aadc2  8b02                 mov eax, dword ptr [edx]
// 005aadc4  50                   push eax
// 005aadc5  8b8d58ffffff         mov ecx, dword ptr [ebp - 0xa8]
// 005aadcb  83c13c               add ecx, 0x3c
// 005aadce  e8ad61fbff           call 0x560f80
// 005aadd3  8945cc               mov dword ptr [ebp - 0x34], eax
// 005aadd6  8b4dd0               mov ecx, dword ptr [ebp - 0x30]
// 005aadd9  8b5104               mov edx, dword ptr [ecx + 4]
// 005aaddc  52                   push edx
// 005aaddd  8b8d58ffffff         mov ecx, dword ptr [ebp - 0xa8]
// 005aade3  83c13c               add ecx, 0x3c
// 005aade6  e89561fbff           call 0x560f80
// 005aadeb  8945d8               mov dword ptr [ebp - 0x28], eax
// 005aadee  8b45d0               mov eax, dword ptr [ebp - 0x30]
// 005aadf1  8b4808               mov ecx, dword ptr [eax + 8]
// 005aadf4  51                   push ecx
// 005aadf5  8b8d58ffffff         mov ecx, dword ptr [ebp - 0xa8]
// 005aadfb  83c13c               add ecx, 0x3c
// 005aadfe  e87d61fbff           call 0x560f80
// 005aae03  8945d4               mov dword ptr [ebp - 0x2c], eax
// 005aae06  8b55d4               mov edx, dword ptr [ebp - 0x2c]
// 005aae09  52                   push edx
// 005aae0a  8d8578ffffff         lea eax, [ebp - 0x88]
// 005aae10  50                   push eax
// 005aae11  8b4d08               mov ecx, dword ptr [ebp + 8]
// 005aae14  e8f72eefff           call 0x49dd10
// 005aae19  50                   push eax
// 005aae1a  8b4dd8               mov ecx, dword ptr [ebp - 0x28]
// 005aae1d  51                   push ecx
// 005aae1e  8d956cffffff         lea edx, [ebp - 0x94]
// 005aae24  52                   push edx
// 005aae25  8b4d08               mov ecx, dword ptr [ebp + 8]
// 005aae28  e8e32eefff           call 0x49dd10
// 005aae2d  50                   push eax
// 005aae2e  8b45cc               mov eax, dword ptr [ebp - 0x34]
// 005aae31  50                   push eax
// 005aae32  8d8d60ffffff         lea ecx, [ebp - 0xa0]
// 005aae38  51                   push ecx
// 005aae39  8b4d08               mov ecx, dword ptr [ebp + 8]
// 005aae3c  e8cf2eefff           call 0x49dd10
// 005aae41  50                   push eax
// 005aae42  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 005aae45  e8c6080000           call 0x5ab710
// 005aae4a  e9effeffff           jmp 0x5aad3e
// 005aae4f  c745c800000000       mov dword ptr [ebp - 0x38], 0
// 005aae56  eb09                 jmp 0x5aae61
// 005aae58  8b55c8               mov edx, dword ptr [ebp - 0x38]
// 005aae5b  83c201               add edx, 1
// 005aae5e  8955c8               mov dword ptr [ebp - 0x38], edx
// 005aae61  8b8d58ffffff         mov ecx, dword ptr [ebp - 0xa8]
// 005aae67  83c118               add ecx, 0x18
// 005aae6a  e8c10e0000           call 0x5abd30
// 005aae6f  3945c8               cmp dword ptr [ebp - 0x38], eax
// 005aae72  0f8d11010000         jge 0x5aaf89
// 005aae78  8b45c8               mov eax, dword ptr [ebp - 0x38]
// 005aae7b  50                   push eax
// 005aae7c  8b8d58ffffff         mov ecx, dword ptr [ebp - 0xa8]
// 005aae82  83c118               add ecx, 0x18
// 005aae85  e8e60b0000           call 0x5aba70
// 005aae8a  8945c0               mov dword ptr [ebp - 0x40], eax
// 005aae8d  33c9                 xor ecx, ecx
// 005aae8f  75fc                 jne 0x5aae8d
// 005aae91  33d2                 xor edx, edx
// 005aae93  75fc                 jne 0x5aae91
// 005aae95  8b45c0               mov eax, dword ptr [ebp - 0x40]
// 005aae98  8b4808               mov ecx, dword ptr [eax + 8]
// 005aae9b  51                   push ecx
// 005aae9c  b9b02da400           mov ecx, 0xa42db0
// 005aaea1  e8aa0e0000           call 0x5abd50
// 005aaea6  8a10                 mov dl, byte ptr [eax]
// 005aaea8  8855c7               mov byte ptr [ebp - 0x39], dl
// 005aaeab  8b45c0               mov eax, dword ptr [ebp - 0x40]
// 005aaeae  8b480c               mov ecx, dword ptr [eax + 0xc]
// 005aaeb1  51                   push ecx
// 005aaeb2  b9b02da400           mov ecx, 0xa42db0
// 005aaeb7  e8940e0000           call 0x5abd50
// 005aaebc  8a10                 mov dl, byte ptr [eax]
// 005aaebe  8855bf               mov byte ptr [ebp - 0x41], dl
// 005aaec1  0fb645c7             movzx eax, byte ptr [ebp - 0x39]
// 005aaec5  0fb64dbf             movzx ecx, byte ptr [ebp - 0x41]
// 005aaec9  3bc1                 cmp eax, ecx
// 005aaecb  0f84b3000000         je 0x5aaf84
// 005aaed1  8b55c0               mov edx, dword ptr [ebp - 0x40]
// 005aaed4  8b02                 mov eax, dword ptr [edx]
// 005aaed6  50                   push eax
// 005aaed7  8b8d58ffffff         mov ecx, dword ptr [ebp - 0xa8]
// 005aaedd  83c13c               add ecx, 0x3c
// 005aaee0  e89b60fbff           call 0x560f80
// 005aaee5  8945b8               mov dword ptr [ebp - 0x48], eax
// 005aaee8  8b4dc0               mov ecx, dword ptr [ebp - 0x40]
// 005aaeeb  8b5104               mov edx, dword ptr [ecx + 4]
// 005aaeee  52                   push edx
// 005aaeef  8b8d58ffffff         mov ecx, dword ptr [ebp - 0xa8]
// 005aaef5  83c13c               add ecx, 0x3c
// 005aaef8  e88360fbff           call 0x560f80
// 005aaefd  894590               mov dword ptr [ebp - 0x70], eax
// 005aaf00  8b45b8               mov eax, dword ptr [ebp - 0x48]
// 005aaf03  50                   push eax
// 005aaf04  8d4d98               lea ecx, [ebp - 0x68]
// 005aaf07  51                   push ecx
// 005aaf08  8b4d08               mov ecx, dword ptr [ebp + 8]
// 005aaf0b  e8002eefff           call 0x49dd10
// 005aaf10  8b5590               mov edx, dword ptr [ebp - 0x70]
// 005aaf13  52                   push edx
// 005aaf14  8d45ac               lea eax, [ebp - 0x54]
// 005aaf17  50                   push eax
// 005aaf18  8b4d08               mov ecx, dword ptr [ebp + 8]
// 005aaf1b  e8f02defff           call 0x49dd10
// 005aaf20  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 005aaf23  e868adedff           call 0x485c90
// 005aaf28  8945a8               mov dword ptr [ebp - 0x58], eax
// 005aaf2b  8d4dac               lea ecx, [ebp - 0x54]
// 005aaf2e  51                   push ecx
// 005aaf2f  8d5598               lea edx, [ebp - 0x68]
// 005aaf32  52                   push edx
// 005aaf33  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 005aaf36  e845060000           call 0x5ab580
// 005aaf3b  0fb645c7             movzx eax, byte ptr [ebp - 0x39]
// 005aaf3f  85c0                 test eax, eax
// 005aaf41  7411                 je 0x5aaf54
// 005aaf43  8b4da8               mov ecx, dword ptr [ebp - 0x58]
// 005aaf46  894d94               mov dword ptr [ebp - 0x6c], ecx
// 005aaf49  8b55a8               mov edx, dword ptr [ebp - 0x58]
// 005aaf4c  83c201               add edx, 1
// 005aaf4f  8955a4               mov dword ptr [ebp - 0x5c], edx
// 005aaf52  eb0f                 jmp 0x5aaf63
// 005aaf54  8b45a8               mov eax, dword ptr [ebp - 0x58]
// 005aaf57  83c001               add eax, 1
// 005aaf5a  894594               mov dword ptr [ebp - 0x6c], eax
// 005aaf5d  8b4da8               mov ecx, dword ptr [ebp - 0x58]
// 005aaf60  894da4               mov dword ptr [ebp - 0x5c], ecx
// 005aaf63  c7855cffffff00000000 mov dword ptr [ebp - 0xa4], 0
// 005aaf6d  8d955cffffff         lea edx, [ebp - 0xa4]
// 005aaf73  52                   push edx
// 005aaf74  8d45a4               lea eax, [ebp - 0x5c]
// 005aaf77  50                   push eax
// 005aaf78  8d4d94               lea ecx, [ebp - 0x6c]
// 005aaf7b  51                   push ecx
// 005aaf7c  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 005aaf7f  e8bc61fbff           call 0x561140
// 005aaf84  e9cffeffff           jmp 0x5aae58
// 005aaf89  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005aaf8c  64890d00000000       mov dword ptr fs:[0], ecx
// 005aaf93  8be5                 mov esp, ebp
// 005aaf95  5d                   pop ebp
// 005aaf96  c21400               ret 0x14

// from server: 100% by EspClaude
// roc 2008-06 00549050  unit: seg_00540000  size: 900 bytes
// roc-flags: /Od /GS- /EHsc /MD /fp:fast

struct Vector3 {
    float x, y, z;
    Vector3();
};
struct Plane {
    float distance(const struct Point2& p) const;
};
struct Point2 {
    float a, b, c;
    Point2();
};
struct Frame {
    Point2 project(int b) const;
    Vector3 toWorld(const Vector3& v) const;
};
struct Tri { int a, b, c; };
struct Edge { int a, b, c, d; };

template <class T> struct Array {
    T* data; int num; int cap;
    int size() const;
    T& operator[](int i);
    void append(const T& a, const T& b);
    void append(const T& a, const T& b, const T& c);
};
struct BoolArray {
    BoolArray();
    ~BoolArray();
    void resize(int n, bool v);
    int size() const;
    bool& operator[](int i);
};

class Mesh {
public:
    char pad[0x18];
    Array<Edge> edges;
    Array<Plane> planes;
    Array<Tri> tris;
    Array<Vector3> verts;
    void build(const Frame& frame, int b, Array<unsigned int>& indices, Array<Vector3>& outVerts, bool caps);
};

void Mesh::build(const Frame& frame, int b, Array<unsigned int>& indices, Array<Vector3>& outVerts, bool caps)
{
    Point2 p = frame.project(b);
    static BoolArray front;
    front.resize(planes.size(), false);
    for (int i = 0; i < planes.size(); i++) {
        front[i] = planes[i].distance(p) < 0.0f;
    }
    if (caps) {
        for (int j = 0; j < front.size(); j++) {
            if (!front[j]) {
                int n = outVerts.size();
                indices.append(n, n + 1, n + 2);
                const Vector3* v0;
                const Tri* t;
                const Vector3* v1;
                const Vector3* v2;
                t = &tris[j];
                v0 = &verts[t->a];
                v1 = &verts[t->b];
                v2 = &verts[t->c];
                outVerts.append(frame.toWorld(*v0), frame.toWorld(*v1), frame.toWorld(*v2));
            }
        }
    }
    for (int k = 0; k < edges.size(); k++) {
        bool f0;
        bool f1;
        const Edge* e;
        e = &edges[k];
        do {} while (0);
        do {} while (0);
        f0 = front[e->c];
        f1 = front[e->d];
        if (f0 != f1) {
            const Vector3& w = verts[e->a];
            const Vector3& q = verts[e->b];
            Vector3 u = frame.toWorld(w);
            Vector3 v = frame.toWorld(q);
            int y = outVerts.size();
            outVerts.append(u, v);
            unsigned int f, n;
            if (f0) {
                f = y;
                n = y + 1;
            } else {
                f = y + 1;
                n = y;
            }
            indices.append(f, n, 0);
        }
    }
}
