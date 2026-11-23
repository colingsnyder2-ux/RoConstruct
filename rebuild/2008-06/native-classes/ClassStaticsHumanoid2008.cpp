// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native HUMAN::HumanoidState::transitionTable (inactive): 11 states x 18 inputs, the exe .rdata at 0084a92c
// (the 12th row there is other data). INFERRED row count: rows 0..10 are state transitions, row 11 ends with a float.
#include "humanoid/HumanoidState.h"

namespace RBX
{
	namespace HUMAN
	{
		const int HumanoidState::transitionTable[][18] = {
			{11, 13, 13, 13, 10, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 1, 13, 1},
			{11, 13, 13, 13, 10, 13, 13, 6, 13, 13, 13, 13, 13, 13, 13, 13, 13, 2},
			{11, 13, 13, 13, 10, 13, 0, 13, 13, 13, 3, 13, 13, 13, 3, 3, 13, 3},
			{11, 13, 13, 13, 10, 13, 0, 13, 13, 13, 13, 5, 13, 13, 13, 13, 13, 4},
			{11, 13, 13, 13, 10, 13, 0, 13, 9, 13, 13, 6, 13, 13, 13, 13, 13, 5},
			{11, 13, 13, 13, 10, 13, 0, 13, 9, 13, 3, 13, 13, 13, 13, 6, 13, 6},
			{11, 2, 13, 13, 10, 13, 0, 13, 9, 13, 3, 13, 13, 13, 13, 7, 13, 7},
			{11, 2, 8, 13, 10, 13, 13, 13, 9, 13, 3, 13, 6, 13, 13, 13, 6, 8},
			{11, 2, 13, 6, 10, 13, 13, 13, 9, 13, 3, 13, 6, 13, 13, 13, 6, 9},
			{11, 2, 13, 13, 10, 13, 0, 13, 13, 6, 9, 9, 13, 13, 13, 13, 13, 10},
			{11, 2, 13, 13, 13, 6, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 11}};
	}
}
