# Compatibility entry point; implementation is in matching/.
__file__ = str(__import__('pathlib').Path(__file__).parent / 'matching' / 'record_native_primitive_filtered_donor.py')
exec(compile(open(__file__, 'rb').read(), __file__, 'exec'))
