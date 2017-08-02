
#include "model/Traits.h"
#include "oops/runs/Run.h"
#include "test/interface/Geometry.h"

int main(int argc,  char ** argv) {
  oops::Run run(argc, argv);
  test::Geometry<xxxx::Traits> tests;
  run.execute(tests);
  return 0;
};

