#pragma once
// 2008-06 RBX::getRealTime (util/Timer.cpp), 005f2000: QueryPerformanceCounter(&t); QueryPerformanceFrequency(&f);
// returns (double)t / (double)f on the x87 stack (fild / fild / fdivp, ret). No arguments (plain ret, cdecl free
// function). The name is the later openrbx-client attribution of the matched analog (?getRealTime@RBX@@YANXZ);
// callers 005548a3 / 005548f7 / 00554eed / 00554f50 / 005551ba / 005551cc / 005551f8 / 00555260 / 00575ba8 / 00575d66.
namespace RBX
{
	double getRealTime();
}
