// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0057d5f0  unit: RBX::FixedCameraCommand  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0057d5f0
//
// 0057d5f0  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 0057d5f3  8b8188020000         mov eax, dword ptr [ecx + 0x118]
// 0057d5f9  8b5004               mov edx, dword ptr [eax + 4]
// 0057d5fc  81c188020000         add ecx, 0x118
// 0057d602  ffd2                 call edx
// 0057d604  33c9                 xor ecx, ecx
// 0057d606  3988d4010000         cmp dword ptr [eax + 0x13c], ecx
// 0057d60c  0f94c1               sete cl
// 0057d60f  8ac1                 mov al, cl
// 0057d611  c3                   ret 

struct Camera {
    char padding[0x13c];
    int state;
};

struct CameraSource {
    virtual void unused();
    virtual Camera* getCamera();
};

struct Context {
    char padding[0x118];
    CameraSource source;
};

struct FixedCameraCommand {
    char padding[0x0c];
    Context* context;
    bool isChecked();
};

bool FixedCameraCommand::isChecked() {
    return context->source.getCamera()->state == 0;
}
