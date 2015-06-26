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

class BacktrackingLineSearch {
 public:
  BacktrackingLineSearch(double alpha,
                         double tau,
                         double c,
                         unsigned int niter);

  double step_size(std::function<double (const VectorXd&)> f,
                   const VectorXd &df,
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
