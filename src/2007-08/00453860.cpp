// from server: 100% by EspClaude
// from server: 49% by colin
// roc 2007-08 00453860  unit: CRobloxReportView  size: 197 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00453860
// 00453860  6aff                 push -1
// 00453862  68a8137400           push 0x7413a8
// 00453867  64a100000000         mov eax, dword ptr fs:[0]
// 0045386d  50                   push eax
// 0045386e  53                   push ebx
// 0045386f  56                   push esi
// 00453870  57                   push edi
// 00453871  a188518b00           mov eax, dword ptr [0x8b5188]
// 00453876  33c4                 xor eax, esp
// 00453878  50                   push eax
// 00453879  8d442410             lea eax, [esp + 0x10]
// 0045387d  64a300000000         mov dword ptr fs:[0], eax
// 00453883  8b8118fdffff         mov eax, dword ptr [ecx - 0x2e8]
// 00453889  8b908c010000         mov edx, dword ptr [eax + 0x18c]
// 0045388f  81c118fdffff         add ecx, 0xfffffd18
// 00453895  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0045389d  ffd2                 call edx
// 0045389f  8bb8a8000000         mov edi, dword ptr [eax + 0xa8]
// 004538a5  8bcf                 mov ecx, edi
// 004538a7  e8a4032100           call 0x663c50
// 004538ac  8bf0                 mov esi, eax
// 004538ae  83ee01               sub esi, 1
// 004538b1  7823                 js 0x4538d6
// 004538b3  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004538b7  56                   push esi
// 004538b8  8bcf                 mov ecx, edi
// 004538ba  e841de2000           call 0x661700
// 004538bf  399898000000         cmp dword ptr [eax + 0x98], ebx
// 004538c5  7407                 je 0x4538ce
// 004538c7  83ee01               sub esi, 1
// 004538ca  79eb                 jns 0x4538b7
// 004538cc  eb08                 jmp 0x4538d6
// 004538ce  56                   push esi
// 004538cf  8bcf                 mov ecx, edi
// 004538d1  e8aadf2000           call 0x661880
// 004538d6  8b742428             mov esi, dword ptr [esp + 0x28]
// 004538da  85f6                 test esi, esi
// 004538dc  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 004538e4  742a                 je 0x453910
// 004538e6  8d4604               lea eax, [esi + 4]
// 004538e9  83c9ff               or ecx, 0xffffffff
// 004538ec  f00fc108             lock xadd dword ptr [eax], ecx
// 004538f0  751e                 jne 0x453910
// 004538f2  8b16                 mov edx, dword ptr [esi]
// 004538f4  8b4204               mov eax, dword ptr [edx + 4]
// 004538f7  8bce                 mov ecx, esi
// 004538f9  ffd0                 call eax
// 004538fb  8d4e08               lea ecx, [esi + 8]
// 004538fe  83caff               or edx, 0xffffffff
// 00453901  f00fc111             lock xadd dword ptr [ecx], edx
// 00453905  7509                 jne 0x453910
// 00453907  8b06                 mov eax, dword ptr [esi]
// 00453909  8b5008               mov edx, dword ptr [eax + 8]
// 0045390c  8bce                 mov ecx, esi
// 0045390e  ffd2                 call edx
// 00453910  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00453914  64890d00000000       mov dword ptr fs:[0], ecx
// 0045391b  59                   pop ecx
// 0045391c  5f                   pop edi
// 0045391d  5e                   pop esi
// 0045391e  5b                   pop ebx
// 0045391f  83c40c               add esp, 0xc
// 00453922  c20c00               ret 0xc

#include <intrin.h>

class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0)
        {
            dispose();
            weak_release();
        }
    }
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
    long use_count_;
    long weak_count_;
};

class shared_count {
public:
    sp_counted_base* pi_;
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};

template<class T> class shared_ptr {
public:
    T* px;
    shared_count pn;
    T* get() const { return px; }
};

class Item;

class Record {
public:
    char pad_0[0x98];
    Item* item;
};

class Records {
public:
    int GetCount();
    Record* GetAt(int index);
    void RemoveAt(int index);
};

class ReportCtrl {
public:
    char pad_0[0xa8];
    Records* records;
};

class ViewBase {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();
    virtual void vfunc_53();
    virtual void vfunc_54();
    virtual void vfunc_55();
    virtual void vfunc_56();
    virtual void vfunc_57();
    virtual void vfunc_58();
    virtual void vfunc_59();
    virtual void vfunc_60();
    virtual void vfunc_61();
    virtual void vfunc_62();
    virtual void vfunc_63();
    virtual void vfunc_64();
    virtual void vfunc_65();
    virtual void vfunc_66();
    virtual void vfunc_67();
    virtual void vfunc_68();
    virtual void vfunc_69();
    virtual void vfunc_70();
    virtual void vfunc_71();
    virtual void vfunc_72();
    virtual void vfunc_73();
    virtual void vfunc_74();
    virtual void vfunc_75();
    virtual void vfunc_76();
    virtual void vfunc_77();
    virtual void vfunc_78();
    virtual void vfunc_79();
    virtual void vfunc_80();
    virtual void vfunc_81();
    virtual void vfunc_82();
    virtual void vfunc_83();
    virtual void vfunc_84();
    virtual void vfunc_85();
    virtual void vfunc_86();
    virtual void vfunc_87();
    virtual void vfunc_88();
    virtual void vfunc_89();
    virtual void vfunc_90();
    virtual void vfunc_91();
    virtual void vfunc_92();
    virtual void vfunc_93();
    virtual void vfunc_94();
    virtual void vfunc_95();
    virtual void vfunc_96();
    virtual void vfunc_97();
    virtual void vfunc_98();
    virtual ReportCtrl* GetReportCtrl();
    char pad_4[0x2e4];
};

class ItemListener {
public:
    virtual void onItemRemoved(int parent, shared_ptr<Item> item) = 0;
};

class CRobloxReportView : public ViewBase, public ItemListener {
public:
    virtual void onItemRemoved(int parent, shared_ptr<Item> item);
};

void CRobloxReportView::onItemRemoved(int parent, shared_ptr<Item> item)
{
    Records* records = GetReportCtrl()->records;
    for (int i = records->GetCount() - 1; i >= 0; i--)
    {
        if (records->GetAt(i)->item == item.get())
        {
            records->RemoveAt(i);
            break;
        }
    }
}
