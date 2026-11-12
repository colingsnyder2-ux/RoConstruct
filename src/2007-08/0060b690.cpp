// from server: 100% by EspClaude
// from server: 64% by colin
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 roc_claude_261e7a664a560df3.cpp

// Candidate translation unit (score above; library headers required).
// Codegen analog of RBX::Clump::setSleepStatus (rbxgs v8world/Clump.cpp body) for the Aug 2007 client.
// Layout from target bytes: sleepStatus at +0 (cmp edi,[esi]), rootPrimitive at +0x24,
// Primitive::body at +0x64; Velocity::zero() is an inline static local built by an out-of-line ctor.
namespace G3D { class Vector3 { public: float x, y, z; }; }
namespace RBX {
	namespace Sim { enum AssemblyState { AWAKE, SLEEPING_CHECKING, SLEEPING_DEEPLY }; }
	class Velocity
	{
	public:
		G3D::Vector3 linear;
		G3D::Vector3 rotational;
		Velocity();
		static const Velocity& zero() { static Velocity v; return v; }
	};
	class Body
	{
	public:
		void resetAccumulators();
		void setVelocity(const Velocity& worldVelocity);
	};
	class Primitive
	{
		char pad0[0x64];
		Body* body;
	public:
		Body* getBody() const { return body; }
	};
	class Clump
	{
		Sim::AssemblyState sleepStatus;
		char pad4[0x20];
		Primitive* rootPrimitive;
	public:
		Body* getRootBody() const { return rootPrimitive->getBody(); }
		void setSleepStatus(Sim::AssemblyState _set);
	};

	void Clump::setSleepStatus(Sim::AssemblyState _set)
	{
		if (_set != sleepStatus)
		{
			switch (_set)
			{
			case Sim::AWAKE:
				getRootBody()->resetAccumulators();
				break;
			case Sim::SLEEPING_CHECKING:
				getRootBody()->setVelocity(Velocity::zero());
				break;
			case Sim::SLEEPING_DEEPLY:
				getRootBody()->setVelocity(Velocity::zero());
				break;
			}

			sleepStatus = _set;
		}
	}
}
