
#ifndef XXXX_MODEL_XXXXFIELDS_H_
#define XXXX_MODEL_XXXXFIELDS_H_

#include <ostream>
#include <string>

#include <boost/shared_ptr.hpp>

#include "model/Geometry.h"
#include "model/Variables.h"
#include "util/DateTime.h"
#include "util/Duration.h"
#include "util/ObjectCounter.h"
#include "util/Printable.h"

// Forward declarations
namespace eckit {
  class Configuration;
}

namespace xxxx {

// -----------------------------------------------------------------------------
/// Class to represent a FieldSet for the XXXX model
class Fields : public util::Printable,
                 private util::ObjectCounter<Fields> {
 public:
  static const std::string classname() {return "xxxx::Fields";}

// Constructors and basic operators
  Fields(const Geometry &, const Variables &, const util::DateTime &);
  Fields(const Fields &, const Geometry &);
  Fields(const Fields &, const Variables &);
  Fields(const Fields &, const bool);
  Fields(const Fields &);
  ~Fields();

  void zero();
  void zero(const util::DateTime &);
  Fields & operator=(const Fields &);
  Fields & operator+=(const Fields &);
  Fields & operator-=(const Fields &);
  Fields & operator*=(const double &);
  void axpy(const double &, const Fields &);
  double dot_product_with(const Fields &) const;
  void schur_product_with(const Fields &);
  void random();

// Interpolate to given location
//  void interpolate(const LocQG &, GomQG &) const;
//  void interpolateTL(const LocQG &, GomQG &) const;
//  void interpolateAD(const LocQG &, const GomQG &);

// Interpolate full fields
  void changeResolution(const Fields &);
  void add(const Fields &);
  void diff(const Fields &, const Fields &);

// Utilities
  void read(const eckit::Configuration &);
  void write(const eckit::Configuration &) const;
  double norm() const;
  boost::shared_ptr<const Geometry> geometry() const {return geom_;}

  const util::DateTime & time() const {return time_;}
  util::DateTime & time() {return time_;}

  int & toFortran() {return keyFlds_;}
  const int & toFortran() const {return keyFlds_;}

  bool isForModel(const bool) const;

 private:
  void print(std::ostream &) const;
  int keyFlds_;
  boost::shared_ptr<const Geometry> geom_;
  boost::shared_ptr<const Variables> vars_;
  util::DateTime time_;
};
// -----------------------------------------------------------------------------

}  // namespace xxxx
#endif  // XXXX_MODEL_XXXXFIELDS_H_
