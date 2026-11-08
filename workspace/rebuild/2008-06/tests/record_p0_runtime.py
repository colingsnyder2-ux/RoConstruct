# Compatibility entry point; implementation is in runtime/.
exec(compile((__import__('pathlib').Path(__file__).parent / 'runtime' / 'record_p0_runtime.py').read_bytes(), __file__, 'exec'))
