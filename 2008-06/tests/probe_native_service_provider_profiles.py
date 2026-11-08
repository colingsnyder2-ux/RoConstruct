# Compatibility entry point; implementation is in matching/.
exec(compile((__import__('pathlib').Path(__file__).parent / 'matching' / 'probe_native_service_provider_profiles.py').read_bytes(), __file__, 'exec'))
