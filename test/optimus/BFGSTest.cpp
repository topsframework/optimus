/***********************************************************************/
/*  Copyright 2015 Optimus                                             */
/*                                                                     */
/*  This program is free software; you can redistribute it and/or      */
/*  modify it under the terms of the GNU  General Public License as    */
/*  published by the Free Software Foundation; either version 3 of     */
/*  the License, or (at your option) any later version.                */
/*                                                                     */
/*  This program is distributed in the hope that it will be useful,    */
/*  but WITHOUT ANY WARRANTY; without even the implied warranty of     */
/*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the      */
/*  GNU General Public License for more details.                       */
/*                                                                     */
/*  You should have received a copy of the GNU General Public License  */
/*  along with this program; if not, write to the Free Software        */
/*  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,         */
/*  MA 02110-1301, USA.                                                */
/***********************************************************************/

#include "gmock/gmock.h"

#include "BFGS.hpp"

using optimus::bfgs;
using optimus::BacktrackingLineSearch;

using ::testing::DoubleNear;

TEST(BFGS, ShouldOptimizeASimpleFunction) {
  auto f = [] (const VectorXd &x) -> double {
    return x(0)*x(0) + x(1)*x(1) - x(0) + x(1);
  };

  auto df = [] (const VectorXd &x) -> VectorXd {
    auto new_x = VectorXd(x.size());
    new_x(0) = 2.0*x(0) - 1;
    new_x(1) = 2.0*x(1) + 1;
    return new_x;
  };

  auto x = VectorXd(2);
  x(0) = 10.1;
  x(1) = 201.2;

  auto line_search = optimus::BacktrackingLineSearch(1, 0.5, 0.5, 100);
  MatrixXd hx = MatrixXd::Identity(x.size(), x.size());
  auto opt = optimus::bfgs(1000, 0.00000000000001,  line_search, x, hx, f, df);
  ASSERT_THAT(f(opt), DoubleNear(-0.5, 0.000001));
}

TEST(BFGS, ShouldOptimizeBohachevskyFunction) {
  auto f = [] (const VectorXd &x) -> double {
    return x(0)*x(0) + 2*x(1)*x(1) - 0.3*cos(3*3.14*x(0))
           - 0.4*cos(4*3.14*x(1)) + 0.7;
  };

  auto df = [] (const VectorXd &x) -> VectorXd {
    auto new_x = VectorXd(x.size());
    new_x(0) = 2*x(0) + 3*3.14*0.3*sin(3*3.14*x(0));
    new_x(1) = 4*x(1) + 4*3.14*0.4*sin(4*3.14*x(1));
    return new_x;
  };

  auto x = VectorXd(2);
  x(0) = 10.1;
  x(1) = 201.2;

  auto line_search = optimus::BacktrackingLineSearch(1, 0.5, 0.5, 100);
  MatrixXd hx = MatrixXd::Identity(x.size(), x.size());
  auto opt = optimus::bfgs(1000, 0.00000000000001,  line_search, x, hx, f, df);
  ASSERT_THAT(f(opt), DoubleNear(0.0, 0.000001));
}

TEST(BFGS, ShouldOptimizeSphereFunction) {
  auto f = [] (const VectorXd &x) -> double {
    double result = 0;
    for (auto i = 0; i < 10; i++) {
      result += x(i)*x(i);
    }
    return result;
  };

  auto df = [] (const VectorXd &x) -> VectorXd {
    auto new_x = VectorXd(x.size());
    for (auto i = 0; i < 10; i++) {
      new_x(i) = 2*x(i);
    }
    return new_x;
  };

  auto x = VectorXd(10);
  x(0) = 10.1;
  x(1) = 201.2;
  x(2) = 10.1;
  x(3) = 201.2;
  x(4) = 10.1;
  x(5) = 201.2;
  x(6) = 10.1;
  x(7) = 201.2;
  x(8) = 10.1;
  x(9) = 201.2;

  auto line_search = optimus::BacktrackingLineSearch(1, 0.5, 0.5, 100);
  MatrixXd hx = MatrixXd::Identity(x.size(), x.size());
  auto opt = optimus::bfgs(1000, 0.00000000000001,  line_search, x, hx, f, df);
  ASSERT_THAT(f(opt), DoubleNear(0.0, 0.000001));
}

TEST(BFGS, ShouldOptimizeSumSquareFunction) {
  auto f = [] (const VectorXd &x) -> double {
    double result = 0;
    for (auto i = 0; i < 10; i++) {
      result += (i+1)*x(i)*x(i);
    }
    return result;
  };

  auto df = [] (const VectorXd &x) -> VectorXd {
    auto new_x = VectorXd(x.size());
    for (auto i = 0; i < 10; i++) {
      new_x(i) = 2*(i+1)*x(i);
    }
    return new_x;
  };

  auto x = VectorXd(10);
  x(0) = 10.1;
  x(1) = 201.2;
  x(2) = 10.1;
  x(3) = 201.2;
  x(4) = 10.1;
  x(5) = 201.2;
  x(6) = 10.1;
  x(7) = 201.2;
  x(8) = 10.1;
  x(9) = 201.2;

  auto line_search = optimus::BacktrackingLineSearch(1, 0.5, 0.5, 100);
  MatrixXd hx = MatrixXd::Identity(x.size(), x.size());
  auto opt = optimus::bfgs(1000, 0.00000000000001,  line_search, x, hx, f, df);
  ASSERT_THAT(f(opt), DoubleNear(0.0, 0.000001));
}
