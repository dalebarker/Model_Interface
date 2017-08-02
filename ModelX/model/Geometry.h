
#ifndef XXXX_MODEL_XXXXGEOMETRY_H_
#define XXXX_MODEL_XXXXGEOMETRY_H_

#include <ostream>
#include <string>

#include "model/Fortran.h"
#include "util/ObjectCounter.h"
#include "util/Printable.h"

namespace eckit {
  class Configuration;
}

namespace xxxx {

// -----------------------------------------------------------------------------
/// Geometry handles geometry for XXXX model.

class Geometry : public util::Printable,
                     private util::ObjectCounter<Geometry> {
 public:
  static const std::string classname() {return "xxxx::Geometry";}

  explicit Geometry(const eckit::Configuration &);
  Geometry(const Geometry &);
  ~Geometry();

  int& toFortran() {return keyGeom_;}
  const int& toFortran() const {return keyGeom_;}

 private:
  Geometry & operator=(const Geometry &);
  void print(std::ostream &) const;
  int keyGeom_;
};
// -----------------------------------------------------------------------------

}  // namespace xxxx

#endif  // XXXX_MODEL_XXXXGEOMETRY_H_
