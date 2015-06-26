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

#include "optimus/BFGS.hpp"

namespace optimus {

VectorXd bfgs(unsigned int niter,
              double epsilon,
              const BacktrackingLineSearch &line_search,
              const VectorXd &guess,
              const MatrixXd &hessian,
              std::function<double (const VectorXd&)> f,
              std::function<VectorXd (const VectorXd&)> df) {
  VectorXd x = guess;
  MatrixXd hx = hessian.inverse();
  VectorXd dx = VectorXd::Zero(x.size());

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
      hx = hx + ((step.transpose() * y + y.transpose() * hx * y)
                  / ((step.transpose() * y) * (step.transpose() * y)))(0)
                *(step * step.transpose())
              - (hx * y * step.transpose() + step * y.transpose() * hx)
                / (step.transpose() * y);
    }

    dx = new_dx;
  }

  return std::move(x);
}

}  // namespace optimus
