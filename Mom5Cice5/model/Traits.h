
#ifndef XXXX_MODEL_XXXXTRAITS_H_
#define XXXX_MODEL_XXXXTRAITS_H_

#include <string>

#include "model/Geometry.h"
#include "model/Increment.h"
#include "model/State.h"
#include "model/Variables.h"

namespace xxxx {

struct Traits {
  static std::string name() {return "XXXX";}

  typedef xxxx::Geometry            Geometry;
  typedef xxxx::Variables           Variables;
  typedef xxxx::State               State;
  typedef xxxx::Increment           Increment;
};

}  // namespace xxxx

#endif  // XXXX_MODEL_XXXXTRAITS_H_
