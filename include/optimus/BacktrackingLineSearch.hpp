#ifndef OPTIMUS_BACKTRACKING_LINE_SEARCH_
#define OPTIMUS_BACKTRACKING_LINE_SEARCH_

#include <Eigen/Dense>

using Eigen::VectorXd;
using Eigen::MatrixXd;

namespace optimus {

class BacktrackingLineSearch {
 public:
  BacktrackingLineSearch(double alpha, double tau, double c, unsigned int niter);

  double step_size(std::function<double (VectorXd&)> f, VectorXd &df, VectorXd &x, VectorXd &direction);

 private:
  double _alpha;
  double _tau;
  double _c;
  unsigned int _niter;
};

}  // namespace optimus

#endif  // OPTIMUS_BACKTRACKING_LINE_SEARCH_
