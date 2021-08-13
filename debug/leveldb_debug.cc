
#include <cassert>
#include <iostream>
#include "leveldb/db.h"

using namespace std;

int main(){
  leveldb::DB* db;
  leveldb::Options options;
  options.create_if_missing = true;

  leveldb::Status status = leveldb::DB::Open(options,"/Users/smartkeyerror/leveldb", &db);

  leveldb::WriteOptions writeOptions;
  writeOptions.sync = true;

  std::string name = "smartkeyerror";
  std::string email = "smartkeyerror@gmail.com";

  for (int i = 0; i < 10000; i++) {
    status = db->Put(writeOptions, name, email);
    assert(status.ok());
  }

  leveldb::ReadOptions readOptions;

  string result;
  status = db->Get(readOptions, name, &result);
  assert(status.ok());
  std::cout << email << std::endl;

  return 0;
}