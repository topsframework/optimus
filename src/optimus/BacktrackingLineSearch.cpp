#include "optimus/BacktrackingLineSearch.hpp"

namespace optimus {

BacktrackingLineSearch::BacktrackingLineSearch(double alpha, double tau, double c, unsigned int niter)
    : _alpha(alpha), _tau(tau), _c(c), _niter(niter) {
}

double BacktrackingLineSearch::step_size(std::function<double (VectorXd&)> f, VectorXd &df, VectorXd &x, VectorXd &direction) {
  auto m = direction.dot(df);
  auto t = -_c * m;
  auto fx = f(x);
  auto step = _alpha;
  for (auto i = 0; i < _niter; i++) {
    VectorXd new_x = x + direction*step;
    if ((fx - f(new_x)) > step * t) {
      break;
    }
      step = step * _tau;
  }
  return step;
}

}  // namespace optimus
