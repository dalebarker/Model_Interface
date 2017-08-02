
#include <iostream>

#include "model/Variables.h"
#include "model/Fortran.h"

// -----------------------------------------------------------------------------
namespace xxxx {
// -----------------------------------------------------------------------------

void Variables::print(std::ostream & os) const {
  int nv;
  int nl;
  xxxx_var_info_f90(keyVar_, nv, nl);
  os << nv;
  if (nl == 1) os << " with LBC";
  ASSERT(nl == 0 || nl == 1);
}

// -----------------------------------------------------------------------------

}  // namespace xxxx
