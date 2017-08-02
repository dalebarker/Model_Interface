
#ifndef XXXX_MODEL_XXXXVARIABLES_H_
#define XXXX_MODEL_XXXXVARIABLES_H_

#include <ostream>
#include <string>

#include "util/Logger.h"
#include "model/Fortran.h"
#include "eckit/config/Configuration.h"
#include "util/ObjectCounter.h"
#include "util/Printable.h"

namespace xxxx {

// -----------------------------------------------------------------------------
/// Variables class to handle variables for XXXX model.

class Variables : public util::Printable,
              private util::ObjectCounter<Variables> {
 public:
  static const std::string classname() {return "xxxx::Variables";}

  explicit Variables(const eckit::Configuration & config) {
    using oops::Log;
    Log::debug() << "Variables config:" << config << std::endl;
    const eckit::Configuration * conf = &config;
    xxxx_var_create_f90(keyVar_, &conf);
  }
  explicit Variables(const int keyVar): keyVar_(keyVar) {}

  ~Variables() {xxxx_var_delete_f90(keyVar_);}

  Variables(const Variables & other) {xxxx_var_clone_f90(other.keyVar_, keyVar_);}

  int& toFortran() {return keyVar_;}
  const int& toFortran() const {return keyVar_;}

 private:
  void print(std::ostream &) const;
  int keyVar_;
};

// -----------------------------------------------------------------------------

}  // namespace xxxx

#endif  // XXXX_MODEL_XXXXVARIABLES_H_
