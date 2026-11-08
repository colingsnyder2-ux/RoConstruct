# Compatibility entry point; implementation is in regression/.
exec(compile((__import__('pathlib').Path(__file__).parent / 'regression' / 'compare_cylinder_reference.py').read_bytes(), __file__, 'exec'))
