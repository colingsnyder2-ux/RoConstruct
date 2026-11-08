# Compatibility entry point; implementation is in matching/.
exec(compile((__import__('pathlib').Path(__file__).parent / 'matching' / 'compare_p4_reverb.py').read_bytes(), __file__, 'exec'))
