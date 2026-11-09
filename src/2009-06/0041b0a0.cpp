// from server: 100% by EspClaude
// roc 2009-06 0041b0a0  unit: CInstanceRecord  size: 141 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0041b0a0
//
// 0041b0a0  56                   push esi
// 0041b0a1  57                   push edi
// 0041b0a2  8bf9                 mov edi, ecx
// 0041b0a4  e8b7941b00           call 0x5d4560
// 0041b0a9  8b35ace98900         mov esi, dword ptr [0x89e9ac]
// 0041b0af  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0041b0b3  85c0                 test eax, eax
// 0041b0b5  7406                 je 0x41b0bd
// 0041b0b7  3b442414             cmp eax, dword ptr [esp + 0x14]
// 0041b0bb  7406                 je 0x41b0c3
// 0041b0bd  ffd6                 call esi
// 0041b0bf  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0041b0c3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0041b0c7  3b4c2418             cmp ecx, dword ptr [esp + 0x18]
// 0041b0cb  745b                 je 0x41b128
// 0041b0cd  85c0                 test eax, eax
// 0041b0cf  750a                 jne 0x41b0db
// 0041b0d1  ffd6                 call esi
// 0041b0d3  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0041b0d7  85c0                 test eax, eax
// 0041b0d9  7404                 je 0x41b0df
// 0041b0db  8b00                 mov eax, dword ptr [eax]
// 0041b0dd  eb02                 jmp 0x41b0e1
// 0041b0df  33c0                 xor eax, eax
// 0041b0e1  8b542410             mov edx, dword ptr [esp + 0x10]
// 0041b0e5  3b5010               cmp edx, dword ptr [eax + 0x10]
// 0041b0e8  7202                 jb 0x41b0ec
// 0041b0ea  ffd6                 call esi
// 0041b0ec  8b442410             mov eax, dword ptr [esp + 0x10]
// 0041b0f0  8b08                 mov ecx, dword ptr [eax]
// 0041b0f2  51                   push ecx
// 0041b0f3  8bcf                 mov ecx, edi
// 0041b0f5  e8f69d1b00           call 0x5d4ef0
// 0041b0fa  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0041b0fe  85c0                 test eax, eax
// 0041b100  750a                 jne 0x41b10c
// 0041b102  ffd6                 call esi
// 0041b104  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0041b108  85c0                 test eax, eax
// 0041b10a  7404                 je 0x41b110
// 0041b10c  8b08                 mov ecx, dword ptr [eax]
// 0041b10e  eb02                 jmp 0x41b112
// 0041b110  33c9                 xor ecx, ecx
// 0041b112  8b542410             mov edx, dword ptr [esp + 0x10]
// 0041b116  3b5110               cmp edx, dword ptr [ecx + 0x10]
// 0041b119  7206                 jb 0x41b121
// 0041b11b  ffd6                 call esi
// 0041b11d  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0041b121  8344241004           add dword ptr [esp + 0x10], 4
// 0041b126  eb8b                 jmp 0x41b0b3
// 0041b128  5f                   pop edi
// 0041b129  5e                   pop esi
// 0041b12a  c21000               ret 0x10
// copied from an identical function in another client (function ??$setSelection@V?$_Vector_const_iterator@PAVInstance@RBX@@V?$allocator@PAVInstance@RBX@@@std@@@std@@@Selection@RBX@@QAEXV?$_Vector_const_iterator@PAVInstance@RBX@@V?$allocator@PAVInstance@RBX@@@std@@@std@@0@Z)

// from server: 100% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <vector>
namespace RBX {class Instance {};struct Selection {
 void clearSelection();void addToSelection(Instance*);
 template<class Iterator>void setSelection(Iterator first,Iterator last){clearSelection();for(;first!=last;first++)addToSelection(*first);}
};}
RBX::Selection* selectionFrom(RBX::Instance*);
struct __POSITION;typedef __POSITION* POSITION;
struct CXTPReportRecord {char prefix[0x54];RBX::Instance* instance;};
struct CXTPReportRow {
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void slot4();
virtual void slot5();
virtual void slot6();
virtual void slot7();
virtual void slot8();
virtual void slot9();
virtual void slot10();
virtual void slot11();
virtual void slot12();
virtual void slot13();
virtual void slot14();
virtual void slot15();
virtual void slot16();
virtual void slot17();
virtual void slot18();
virtual void slot19();
virtual void slot20();
virtual void slot21();
virtual void slot22();
virtual void slot23();
 virtual CXTPReportRecord* GetRecord()const;
};
struct CXTPReportSelectedRows {POSITION GetFirstSelectedRowPosition();CXTPReportRow* GetNextSelectedRow(POSITION&);};
struct CXTPReportControl {char pad[0x128];CXTPReportSelectedRows* rows;CXTPReportSelectedRows* GetSelectedRows()const{return rows;}};
struct CSettingsExplorer {
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void slot4();
virtual void slot5();
virtual void slot6();
virtual void slot7();
virtual void slot8();
virtual void slot9();
virtual void slot10();
virtual void slot11();
virtual void slot12();
virtual void slot13();
virtual void slot14();
virtual void slot15();
virtual void slot16();
virtual void slot17();
virtual void slot18();
virtual void slot19();
virtual void slot20();
virtual void slot21();
virtual void slot22();
virtual void slot23();
virtual void slot24();
virtual void slot25();
virtual void slot26();
virtual void slot27();
virtual void slot28();
virtual void slot29();
virtual void slot30();
virtual void slot31();
virtual void slot32();
virtual void slot33();
virtual void slot34();
virtual void slot35();
virtual void slot36();
virtual void slot37();
virtual void slot38();
virtual void slot39();
virtual void slot40();
virtual void slot41();
virtual void slot42();
virtual void slot43();
virtual void slot44();
virtual void slot45();
virtual void slot46();
virtual void slot47();
virtual void slot48();
virtual void slot49();
virtual void slot50();
virtual void slot51();
virtual void slot52();
virtual void slot53();
virtual void slot54();
virtual void slot55();
virtual void slot56();
virtual void slot57();
virtual void slot58();
virtual void slot59();
virtual void slot60();
virtual void slot61();
virtual void slot62();
virtual void slot63();
virtual void slot64();
virtual void slot65();
virtual void slot66();
virtual void slot67();
virtual void slot68();
virtual void slot69();
virtual void slot70();
virtual void slot71();
virtual void slot72();
virtual void slot73();
virtual void slot74();
virtual void slot75();
virtual void slot76();
virtual void slot77();
virtual void slot78();
virtual void slot79();
virtual void slot80();
virtual void slot81();
virtual void slot82();
virtual void slot83();
virtual void slot84();
virtual void slot85();
virtual void slot86();
virtual void slot87();
virtual void slot88();
virtual void slot89();
virtual void slot90();
virtual void slot91();
virtual void slot92();
virtual void slot93();
virtual void slot94();
virtual void slot95();
virtual void slot96();
virtual void slot97();
virtual void slot98();
virtual void slot99();
virtual void slot100();
 virtual CXTPReportControl* GetReportControl();
 char prefix[0x3c0-4];RBX::Instance* context;
 void OnSelectionChanged(void*,long*);
};
void CSettingsExplorer::OnSelectionChanged(void*,long*){
 RBX::Selection* selection=selectionFrom(context);
 std::vector<RBX::Instance*> instances;
 CXTPReportSelectedRows* rows=GetReportControl()->GetSelectedRows();
 POSITION position=rows->GetFirstSelectedRowPosition();
 while(position){
  CXTPReportRow* row=rows->GetNextSelectedRow(position);
  CXTPReportRecord* record=row->GetRecord();
  RBX::Instance* instance=record->instance;
  instances.push_back(instance);
 }
 const std::vector<RBX::Instance*>& collected=instances;
 selection->setSelection(collected.begin(),collected.end());
}