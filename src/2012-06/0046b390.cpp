// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct PropertyDescriptor;

struct Notifier
{
	void raisePropertyChanged(const PropertyDescriptor* desc);
};

extern const PropertyDescriptor desc_Prop;

struct CRenderSettings
{
	char pad0[0xe1];
	unsigned char value_;
	char pad1[0x144 - 0xe2];
	Notifier notifier;

	void setProp(unsigned char value);
};

void CRenderSettings::setProp(unsigned char value)
{
	if (value != value_)
	{
		value_ = value;
		notifier.raisePropertyChanged(&desc_Prop);
	}
}