#ifndef OPTIMUS_BFGS_
#define OPTIMUS_BFGS_

#include <Eigen/Dense>

#include "BacktrackingLineSearch.hpp"

using Eigen::VectorXd;
using Eigen::MatrixXd;

namespace optimus {

VectorXd bfgs(unsigned int niter,
              double epsilon,
              BacktrackingLineSearch line_search,
              VectorXd guess,
              MatrixXd hessian,
              std::function<double (VectorXd)> f,
              std::function<VectorXd (VectorXd)> df);

}  // namespace optimus

#endif  // OPTIMUS_BFGS_
