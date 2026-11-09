// roc 2012-06 00a31be0  unit: CXTPDockingPaneBase  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a31be0
//
// 00a31be0  c701a806c200         mov dword ptr [ecx], 0xc206a8
// 00a31be6  e9c53aa2ff           jmp 0x4556b0
// auto-matched from its assembly shape

struct B_func_00a31be0 { virtual ~B_func_00a31be0(); };
struct S_func_00a31be0 : B_func_00a31be0 { ~S_func_00a31be0(); };
S_func_00a31be0::~S_func_00a31be0()
{
}
