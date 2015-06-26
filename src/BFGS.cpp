#include "BFGS.hpp"

namespace optimus {

VectorXd bfgs(unsigned int niter,
              double epsilon,
              BacktrackingLineSearch line_search,
              VectorXd guess,
              MatrixXd hessian,
              std::function<double (VectorXd)> f,
              std::function<VectorXd (VectorXd)> df) {
  VectorXd x = guess;
  MatrixXd hx = hessian.inverse();
  VectorXd dx = VectorXd::Zero(2);

  for (auto i = 0; i < niter; i++) {
    VectorXd new_dx = df(x);
    VectorXd search_dir = hx * (-new_dx);

    if (search_dir.dot(new_dx) >= 0) {
      // Not a descent direction.
      hx = MatrixXd::Identity(x.size(), x.size());
      search_dir = -new_dx;
    }

    if (new_dx.norm() <= epsilon) {
      break;
    }

    auto alpha = line_search.step_size(f, new_dx, x, search_dir);
    auto step = search_dir * alpha;

    if (alpha * alpha <= epsilon) {
      break;
    }

    x = x + step;

    auto y = new_dx - dx;
    auto denom = step.dot(y);

    if (denom * denom <= epsilon) {
      hx = MatrixXd::Identity(x.size(), x.size());
    } else {
      hx = hx + ((step.transpose() * y + y.transpose() * hx * y) / ((step.transpose() * y) * (step.transpose() * y)))(0)*(step * step.transpose()) - (hx * y * step.transpose() + step * y.transpose() * hx) / (step.transpose() * y);
    }

    dx = new_dx;
  }

  return x;
}

}  // namespace optimus
