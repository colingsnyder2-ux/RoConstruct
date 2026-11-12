import json,sqlite3,tempfile,unittest
from pathlib import Path
from roc.draft_getter_queue import measured_sources
from roc.draft_merger import content_hash,proof_key
class MeasuredSourceTests(unittest.TestCase):
 def test_review_source_provenance_freshness_and_hash(self):
  with tempfile.TemporaryDirectory() as temp, sqlite3.connect(':memory:') as db:
   root=Path(temp); folder=root/'work/draft-merger'; folder.mkdir(parents=True)
   db.executescript('CREATE TABLE contents(sha256 TEXT,bytes BLOB); CREATE TABLE review_proposals(id TEXT,sha256 TEXT,source TEXT);')
   raw=b'proposal'; sha=content_hash(raw)
   db.execute('INSERT INTO review_proposals VALUES(?,?,?)',('p',sha,raw.decode()))
   unit=dict(candidate_sha256=sha,proposals=['p'])
   report=dict(summary=dict(stale=False,frozen_inventory_key=proof_key({})),units=[unit])
   path=folder/'native-review-latest.json'; path.write_text(json.dumps(report))
   self.assertEqual(list(measured_sources(root,db)),[(unit,raw)])
   unit['proposals']=['other']; path.write_text(json.dumps(report))
   self.assertEqual(list(measured_sources(root,db)),[])
   unit['proposals']=['p']; report['summary']['stale']=True; path.write_text(json.dumps(report))
   self.assertEqual(list(measured_sources(root,db)),[])
   report['summary']['stale']=False; path.write_text(json.dumps(report))
   header=root/'rebuild/2008-06/native-headers/Foo.h'; header.parent.mkdir(parents=True); header.write_text('new input')
   self.assertEqual(list(measured_sources(root,db)),[])
 def test_archived_source_hash_is_checked(self):
  with tempfile.TemporaryDirectory() as temp, sqlite3.connect(':memory:') as db:
   root=Path(temp); folder=root/'work/draft-merger'; folder.mkdir(parents=True)
   db.execute('CREATE TABLE contents(sha256 TEXT,bytes BLOB)')
   sha=content_hash(b'original'); db.execute('INSERT INTO contents VALUES(?,?)',(sha,b'tampered'))
   report=dict(summary=dict(stale=False,frozen_inventory_key=proof_key({})),units=[dict(candidate_sha256=sha)])
   (folder/'native-latest.json').write_text(json.dumps(report))
   self.assertEqual(list(measured_sources(root,db)),[])
if __name__=='__main__': unittest.main()
