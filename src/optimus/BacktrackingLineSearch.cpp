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

#include "optimus/BacktrackingLineSearch.hpp"

namespace optimus {

BacktrackingLineSearch::BacktrackingLineSearch(double alpha,
                                               double tau,
                                               double c,
                                               unsigned int niter)
    : _alpha(alpha), _tau(tau), _c(c), _niter(niter) {
}

double BacktrackingLineSearch::step_size(std::function<double (const VectorXd&)> f,
                                         const VectorXd &dfx,
                                         const VectorXd &x,
                                         const VectorXd &direction) const {
  auto m = direction.dot(dfx);
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
