// from server: 100% by Xemicl
// roc 2012-06 006cfa30  unit: boost::io::too_many_args  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006cfa30
//
// 006cfa30  dd442404             fld qword ptr [esp + 4]
// 006cfa34  83ec08               sub esp, 8
// 006cfa37  dd1c24               fstp qword ptr [esp]
// 006cfa3a  e8717c2a00           call 0x9776b0
// 006cfa3f  8bc8                 mov ecx, eax
// 006cfa41  e86ab92a00           call 0x97b3b0
// 006cfa46  c20800               ret 8
// copied from an identical function in another client (function ?setThreadShare@TaskSchedulerSettings@RBX@@QAEXN@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class TaskScheduler {
public:
	static TaskScheduler& singleton();
	void setThreadShare(double v);
};
class TaskSchedulerSettings {
public:
	void setThreadShare(double v);
};
void TaskSchedulerSettings::setThreadShare(double v)
{
	TaskScheduler::singleton().setThreadShare(v);
}
}