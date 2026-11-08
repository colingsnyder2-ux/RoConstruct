import importlib.util
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch

SCRIPT = Path(__file__).resolve().parents[1] / 'rebuild/2008-06/tests/native_provider_queue.py'
spec = importlib.util.spec_from_file_location('native_provider_queue', SCRIPT)
queue = importlib.util.module_from_spec(spec)
spec.loader.exec_module(queue)
SYMBOL = '?start@Service@RBX@@QAEXXZ'


def error(obj='Caller.obj', code='2019'):
    return f'{obj} : error LNK{code}: unresolved external symbol "public: void __thiscall RBX::Service::start(void)" ({SYMBOL}) referenced in function "caller"'


class ProviderQueueTests(unittest.TestCase):
    def test_deduplicate_requesters(self):
        rows = queue.parse_errors('\n'.join([error(), error(), error('Other.obj', '2001')]))
        self.assertEqual(len(rows), 1)
        self.assertEqual(rows[0]['requesters'], ['Caller.obj', 'Other.obj'])
        self.assertEqual(rows[0]['symbol'], SYMBOL)

    def test_leads_are_not_providers_and_object_failures_visible(self):
        with tempfile.TemporaryDirectory() as folder:
            base = Path(folder)
            log = base / 'link.log'
            log.write_text(error())
            (base / 'Service.cpp').write_text('void Service::start() {}\n')
            result = queue.inventory(log, [base], [base])
            self.assertEqual(result['queue'][0]['status'], 'source_lead_only')
            self.assertEqual(result['queue'][0]['source_leads'][0]['line'], 1)
            (base / 'Service.obj').write_bytes(b'broken' + SYMBOL.encode('ascii'))
            result = queue.inventory(log, [base], [base])
            self.assertEqual(len(result['scan_errors']), 1)
            with patch.object(queue.rebuild, 'coff_externals', return_value={SYMBOL: True}):
                result = queue.inventory(log, [base], [base])
            self.assertEqual(result['queue'][0]['status'], 'object_definition_found')
            self.assertEqual(len(result['queue'][0]['object_definitions'][0]['sha256']), 64)

    def test_default_search_includes_organized_sources(self):
        with tempfile.TemporaryDirectory() as folder:
            base = Path(folder)
            moved = base / 'App/src/v8datamodel'
            moved.mkdir(parents=True)
            (moved / 'Service.cpp').write_text('void Service::start() {}\n')
            (base / 'native-classes').mkdir()
            log = base / 'link.log'
            log.write_text(error())
            result = queue.inventory(log, [], queue.default_source_dirs(base))
            self.assertEqual(result['queue'][0]['status'], 'source_lead_only')
            self.assertEqual(result['queue'][0]['source_leads'][0]['path'], str(moved / 'Service.cpp'))

    def test_2001_without_reference_and_constructor(self):
        line = 'a.obj : error LNK2001: unresolved external symbol "public: __thiscall RBX::Thing::Thing(void)" (??0Thing@RBX@@QAE@XZ)'
        self.assertEqual(len(queue.parse_errors(line)), 1)
        self.assertEqual(queue.source_terms(queue.parse_errors(line)[0]['display']), {('Thing', 'Thing')})


    def test_library_provider_and_undefined_not_misreported(self):
        with tempfile.TemporaryDirectory() as folder:
            base = Path(folder)
            log = base / 'link.log'
            log.write_text(error())
            archive = base / 'providers.lib'
            archive.write_bytes(b'archive')
            with patch.object(queue.libs, 'archive_members', return_value=[('candidate.obj', SYMBOL.encode())]):
                with patch.object(queue.rebuild, 'coff_externals', return_value={SYMBOL: False}):
                    result = queue.inventory(log, [base], [])
                    self.assertEqual(result['queue'][0]['status'], 'no_provider_found')
                with patch.object(queue.rebuild, 'coff_externals', return_value={SYMBOL: True}):
                    result = queue.inventory(log, [base], [])
                    self.assertEqual(result['queue'][0]['status'], 'library_definition_found')
                    self.assertEqual(result['queue'][0]['library_definitions'][0]['member'], 'candidate.obj')
                    self.assertEqual(result['libraries_scanned'], 1)

    def test_short_import_object_reported_as_unscanned(self):
        with tempfile.TemporaryDirectory() as folder:
            base = Path(folder)
            log = base / 'link.log'
            log.write_text(error())
            (base / 'imports.lib').write_bytes(b'archive')
            with patch.object(queue.libs, 'archive_members', return_value=[('import.obj', b'\x00\x00\xff\xff' + SYMBOL.encode())]):
                result = queue.inventory(log, [base], [])
            self.assertEqual(result['queue'][0]['status'], 'no_provider_found')
            self.assertIn('unsupported short import object', result['scan_errors'][0]['error'])

    def test_plain_c_symbol(self):
        row, = queue.parse_errors('main.obj : error LNK2001: unresolved external symbol _missing')
        self.assertEqual(row['symbol'], '_missing')
        self.assertEqual(row['requesters'], ['main.obj'])

    def test_template_member(self):
        self.assertIn(('TToolVerb', 'newMouseCommand'), queue.source_terms('RBX::TToolVerb<class RBX::ArrowTool,class RBX::RunStateVerb>::newMouseCommand(void)'))


if __name__ == '__main__':
    unittest.main()
