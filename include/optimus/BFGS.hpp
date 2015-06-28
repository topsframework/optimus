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

#ifndef OPTIMUS_BFGS_
#define OPTIMUS_BFGS_

// External headers
#include <Eigen/Dense>

// Optimus headers
#include "BacktrackingLineSearch.hpp"

using Eigen::VectorXd;
using Eigen::MatrixXd;

namespace optimus {

/**
 * @class BFGS
 * @brief Class that represents a BFGS optimizer.
 *
 * In numerical optimization, the Broyden–Fletcher–Goldfarb–Shanno (BFGS)
 * algorithm is an iterative method for solving unconstrained nonlinear
 * optimization problems.
 *
 * The BFGS method approximates Newton's method, a class of hill-climbing
 * optimization techniques that seeks a stationary point of a (preferably
 * twice continuously differentiable) function. For such problems, a necessary
 * condition for optimality is that the gradient be zero. Newton's method and
 * the BFGS methods are not guaranteed to converge unless the function has a
 * quadratic Taylor expansion near an optimum. These methods use both the first
 * and second derivatives of the function. However, BFGS has proven to have
 * good performance even for non-smooth optimizations.
 *
 * [Wikipedia]: https://en.wikipedia.org/wiki/Broyden–Fletcher–Goldfarb–Shanno_algorithm
 */
class BFGS {
 public:

  /**
   * Builds a new optimizer.
   * @param niter maximum number of iterations
   * @epsilon threshold
   * @hessian an initial hessian
   * @f objective function
   * @df partial derivatives
   */
  BFGS(unsigned int niter,
       double epsilon,
       const BacktrackingLineSearch &line_search,
       const VectorXd &guess,
       const MatrixXd &hessian,
       std::function<double (const VectorXd&)> f,
       std::function<VectorXd (const VectorXd&)> df);

  /**
   * Minimizes the objective function
   * @return a local minimum point
   */
  VectorXd minimize() const;
 private:
  unsigned int _niter;
  double _epsilon;
  const BacktrackingLineSearch _line_search;
  const VectorXd _guess;
  const MatrixXd _hessian;
  std::function<double (const VectorXd&)> _f;
  std::function<VectorXd (const VectorXd&)> _df;
};

}  // namespace optimus

#endif  // OPTIMUS_BFGS_
