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

#include <Eigen/Dense>

#include "BacktrackingLineSearch.hpp"

using Eigen::VectorXd;
using Eigen::MatrixXd;

namespace optimus {

class BFGS {
 public:
  BFGS(unsigned int niter,
       double epsilon,
       const BacktrackingLineSearch &line_search,
       const VectorXd &guess,
       const MatrixXd &hessian,
       std::function<double (const VectorXd&)> f,
       std::function<VectorXd (const VectorXd&)> df);

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
