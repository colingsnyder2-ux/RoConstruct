// roc 2012-06 004d51a0  unit: Ogre::RbxSceneManagerFactory  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004d51a0
//
// 004d51a0  56                   push esi
// 004d51a1  8bf1                 mov esi, ecx
// 004d51a3  6880c9e100           push 0xe1c980
// 004d51a8  8d4e04               lea ecx, [esi + 4]
// 004d51ab  ff155826b200         call dword ptr [0xb22658]
// 004d51b1  68107cb600           push 0xb67c10
// 004d51b6  8d4e20               lea ecx, [esi + 0x20]
// 004d51b9  ff158c26b200         call dword ptr [0xb2268c]
// 004d51bf  b801000000           mov eax, 1
// 004d51c4  6689463c             mov word ptr [esi + 0x3c], ax
// 004d51c8  c6463e00             mov byte ptr [esi + 0x3e], 0
// 004d51cc  5e                   pop esi
// 004d51cd  c3                   ret 
// copied from an identical function in another client (function ?initialize@S@@QAEXXZ)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct String {
    char data[28];
};

typedef String& (__thiscall *CopyString)(String*, const String&);
typedef String& (__thiscall *AssignText)(String*, const char*);

extern CopyString copyString;
extern AssignText assignText;
extern const String managerName;
extern const char managerDescription[];

struct S {
    unsigned int reserved;
    String name;
    String description;
    unsigned short flags;
    unsigned char extra;

    void initialize();
};

void S::initialize()
{
    copyString(&name, managerName);
    assignText(&description, managerDescription);
    flags = 1;
    extra = 0;
}