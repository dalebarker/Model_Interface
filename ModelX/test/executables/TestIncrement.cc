
#include "model/Traits.h"
#include "oops/runs/Run.h"
#include "test/interface/Increment.h"

int main(int argc,  char ** argv) {
  oops::Run run(argc, argv);
  test::Increment<xxxx::Traits> tests;
  run.execute(tests);
  return 0;
};

