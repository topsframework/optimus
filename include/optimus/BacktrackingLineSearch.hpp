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

#ifndef OPTIMUS_BACKTRACKING_LINE_SEARCH_
#define OPTIMUS_BACKTRACKING_LINE_SEARCH_

#include <Eigen/Dense>

using Eigen::VectorXd;
using Eigen::MatrixXd;

namespace optimus {

/**
 * @class BacktrackingLineSearch
 * @brief Class that represent the backtracking line search strategy
 *
 * In (unconstrained) minimization, a backtracking line search, a search
 * scheme based on the Armijo–Goldstein condition, is a line search method
 * to determine the maximum amount to move along a given search direction.
 * It involves starting with a relatively large estimate of the step size
 * for movement along the search direction, and iteratively shrinking the
 * step size (i.e., "backtracking") until a decrease of the objective function
 * is observed that adequately corresponds to the decrease that is expected,
 * based on the local gradient of the objective function.
 *
 * [Wikipedia](https://en.wikipedia.org/wiki/Backtracking_line_search)
 */
class BacktrackingLineSearch {
 public:
  /**
   * Builds a new searcher.
   * @param alpha maximum candidate step size value alpha > 0
   * @param tau search control parameter \f$tau \in (0, 1)\f$
   * @param c search control parameter \f$c \in (0, 1)\f$
   * @param niter maximum number of iterations
   */
  BacktrackingLineSearch(double alpha,
                         double tau,
                         double c,
                         unsigned int niter);

  /**
   * Calculates the step size
   * @param f objective function
   * @param dfx partial derivatives applied to x
   * @param direction gradient direction
   * @return a step size
   */
  double step_size(std::function<double (const VectorXd&)> f,
                   const VectorXd &dfx,
                   const VectorXd &x,
                   const VectorXd &direction) const;

 private:
  double _alpha;
  double _tau;
  double _c;
  unsigned int _niter;
};

}  // namespace optimus

#endif  // OPTIMUS_BACKTRACKING_LINE_SEARCH_
