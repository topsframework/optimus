#include "gmock/gmock.h"

#include "BFGS.hpp"

using optimus::bfgs;
using optimus::BacktrackingLineSearch;

using ::testing::DoubleNear;

TEST(BFGS, ShouldOptimizeASimpleFunction) {
  auto f = [] (VectorXd x) -> double {
    return x(0)*x(0) + x(1)*x(1) - x(0) + x(1);
  };

  auto df = [] (VectorXd x) -> VectorXd {
    auto new_x = VectorXd(x.size());
    new_x(0) = 2.0*x(0) - 1;
    new_x(1) = 2.0*x(1) + 1;
    return new_x;
  };

  auto x = VectorXd(2);
  x(0) = 10.1;
  x(1) = 201.2;

  auto opt = optimus::bfgs(1000, 0.00000000000001,  optimus::BacktrackingLineSearch(1, 0.5, 0.5, 100), x, MatrixXd::Identity(x.size(), x.size()), f, df);
  ASSERT_THAT(f(opt), DoubleNear(-0.5, 0.000001));
}

TEST(BFGS, ShouldOptimizeBohachevskyFunction) {
  auto f = [] (VectorXd x) -> double {
    return x(0)*x(0) + 2*x(1)*x(1) - 0.3*cos(3*3.14*x(0)) - 0.4*cos(4*3.14*x(1)) + 0.7;
  };

  auto df = [] (VectorXd x) -> VectorXd {
    auto new_x = VectorXd(x.size());
    new_x(0) = 2*x(0) + 3*3.14*0.3*sin(3*3.14*x(0));
    new_x(1) = 4*x(1) + 4*3.14*0.4*sin(4*3.14*x(1));
    return new_x;
  };

  auto x = VectorXd(2);
  x(0) = 10.1;
  x(1) = 201.2;

  auto opt = optimus::bfgs(1000, 0.00000000000001,  optimus::BacktrackingLineSearch(1, 0.5, 0.5, 100), x, MatrixXd::Identity(x.size(), x.size()), f, df);
  ASSERT_THAT(f(opt), DoubleNear(0.0, 0.000001));
}
