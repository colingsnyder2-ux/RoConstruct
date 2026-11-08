# Compatibility entry point; implementation is in matching/.
exec(compile((__import__('pathlib').Path(__file__).parent / 'matching' / 'record_native_services_maps.py').read_bytes(), __file__, 'exec'))
