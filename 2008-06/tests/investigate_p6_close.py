# Compatibility entry point; implementation is in runtime/.
exec(compile((__import__('pathlib').Path(__file__).parent / 'runtime' / 'investigate_p6_close.py').read_bytes(), __file__, 'exec'))
