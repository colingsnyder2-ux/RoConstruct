// from server: 100% by EspClaude
// from server: 90% by Intel
// roc 2007-08 0076c820  unit: seg_00760000  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0076c820
//
// 0076c820  6a01                 push 1
// 0076c822  682c010000           push 0x12c
// 0076c827  686c797800           push 0x78796c
// 0076c82c  68f4010000           push 0x1f4
// 0076c831  6864797800           push 0x787964
// 0076c836  33c9                 xor ecx, ecx
// 0076c838  6858797800           push 0x787958
// 0076c83d  51                   push ecx
// 0076c83e  b830af4100           mov eax, 0x41af30
// 0076c843  50                   push eax
// 0076c844  b9d0af8b00           mov ecx, 0x8bafd0
// 0076c849  e802d3caff           call 0x419b50
// 0076c84e  6830757700           push 0x777530
// 0076c853  e8cb44ecff           call 0x630d23
// 0076c858  59                   pop ecx
// 0076c859  c3                   ret 

// from server: 79% by colin
// roc 2007-08 0076c820  unit: seg_00760000  size: 58 bytes
// 2007-08 hand variant, take 2: the target pushes the ADDRESS of extern functions/tables
// (relocated symbols), not the value loaded out of extern pointers.

extern "C" int __cdecl sub_630D23(void*);  // caller pops: pop ecx

// The target pushes 0 then the callback address: one 8-byte by-value argument.
struct CallbackArg { void (*fn)(); int extra; };

struct Registrar {
    int registerItem(CallbackArg, void*, void*, int, void*, int, int);
};

extern void callback();          // 0x41af30
extern char tableA[];             // 0x787958
extern char tableB[];             // 0x787964
extern char tableC[];             // 0x78796c
extern Registrar theRegistrar;   // 0x8bafd0 (this for the call)
extern char cleanupTarget[];     // 0x777530

void sub_76C820()
{
    CallbackArg arg = { callback, 0 };
    theRegistrar.registerItem(arg, tableA, tableB, 0x1F4, tableC, 0x12C, 1);
    sub_630D23(cleanupTarget);
}
